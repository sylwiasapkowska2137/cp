//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void kmp(vector<int>&pi, string&s, int&n){
	for (int i = 1; i<n; i++){
		int j = pi[i-1];
		while (j && s[i]!=s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
}

const LL INF = 1e18;
int n;

vector<vector<long long>>power(int b, vector<vector<long long>>&graf){
	if (!b) {
		vector<vector<long long>>ans(n, vector<long long>(n, INF));
		for (int i = 0; i<n; i++) ans[i][i] = 0;
		return ans;
	}
	vector<vector<long long>>curr = power(b/2, graf);
	vector<vector<long long>>nowy(n, vector<long long>(n, INF));
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			for (int k = 0; k<n; k++){
				nowy[i][j] = min(nowy[i][j], curr[i][k]+curr[k][j]);
			}
		}
	}
	curr = nowy;
	if (b&1){
		nowy.assign(n, vector<long long>(n, INF));
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				for (int k = 0; k<n; k++){
					nowy[i][j] = min(nowy[i][j], curr[i][k]+graf[k][j]);
				}
			}
		}
		curr = nowy;
	}
	return curr;
}

void solve(){
	int m; cin >> n >> m;
	vector<string>s(n);
	vector<vector<long long>>graf(n+1, vector<long long>(n+1, INF));
	for (int i = 0; i<n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i<n; i++){
		string t = s[i];
		t.push_back('%');
		for (int j = 0; j<n; j++){
			t += s[j];
			t.push_back('#');
		}
		int S = (int)t.size();
		//debug(t);
		vector<int>pi(S, 0);
		kmp(pi, t, S);
		//debug(pi);
		int x = 0;
		for (int j = 0; j<S; j++){
			if (t[j] == '#'){
				if (i == x) graf[i][x] = (int)s[i].size()-pi[pi[j-1]-1];
				else graf[i][x] = (int)s[i].size()-pi[j-1];
				x++;
			}
		}
	}
	/*
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			cerr << graf[i][j] << " ";
		}
		cerr << "\n";
	}
	*/
	m--;
	vector<vector<long long>>curr = power(m, graf);
	long long ans = INF;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			ans = min(ans, curr[i][j]+(int)s[j].size());
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
