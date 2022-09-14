//sysia
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

const int MAX = 301, MAXN = 300*400+7;
vector<string>where[MAX];
vector<int>graf[MAXN], match;
vector<bool>vis;

bool dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (match[x] == -1){
			match[x] = v;
			match[v] = x;
			return 1;
		}
	}
	for (auto x: graf[v]){
		if (!vis[match[x]] && dfs(match[x])){
			match[x] = v;
			match[v] = x;
			return 1;
		}
	}
	return 0;
}

void decompose(string &s, vector<string>&scaler, int K){
	int n = (int)s.size();
	for (int i = 0; i<n; i++){
		scaler.push_back(string{s[i]});
		where[K].push_back(string{s[i]});
	}
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			scaler.push_back(string{s[i], s[j]});
			where[K].push_back(string{s[i], s[j]});
		}
	}
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			for (int k = j+1; k<n; k++){
				scaler.push_back(string{s[i], s[j], s[k]});
				where[K].push_back(string{s[i], s[j], s[k]});
			}
		}
	}
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			for (int k = j+1; k<n; k++){
				for (int l = k+1; l<n; l++){
					scaler.push_back(string{s[i], s[j], s[k], s[l]});
					where[K].push_back(string{s[i], s[j], s[k], s[l]});
				}
			}
		}
	}
}

void solve(){
	int n; cin >> n;
	vector<string>tab(n);
	vector<string>scaler;
	for (int i = 0; i<n; i++){
		cin >> tab[i];
		decompose(tab[i], scaler, i);
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	//debug(scaler);	
	map<string, int>mapa;
	for (int i = 0; i<(int)scaler.size(); i++){
		mapa[scaler[i]] = i+n+1;
	}
	int N = n+(int)scaler.size()+1;
	//debug(N);

	//gen graph
	for (int i = 0; i<n; i++){
		//debug(where[i]);
		for (auto x: where[i]){
			graf[i].push_back(mapa[x]);
			graf[mapa[x]].push_back(i);
		}
	}
	//return;
	match.assign(N+1, -1);

	while (1){
		vis.assign(N+1, 0);
		bool change = 0;
		for (int i = 0; i<n; i++){
			if (match[i] == -1 && dfs(i)){
				change = 1;
			}
		}
		if (!change) break;
	}
	//debug(match);
	for (int i = 0; i<n; i++){
		if (match[i] == -1){
			cout << "-1\n";
			return;
		}
	}
	for (int i = 0; i<n; i++){
		cout << scaler[match[i]-n-1] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	
	return 0;
}
