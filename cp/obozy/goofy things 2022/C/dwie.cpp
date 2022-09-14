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

const int MAX = 1e6;
int syn[27][MAX];
int koniec[MAX];
int K = 1;
long long ans;
const int MAX2 = 2e5+7;
vector<int>later[MAX2];

int ti(char c){
	return (int)(c-'a');
}

void add(string &s, int idx){
	int v = 0;
	for (int i = 0; i<(int)s.size(); i++){
		if (!syn[ti(s[i])][v]) syn[ti(s[i])][v] = K++;
		later[idx].push_back(v);
		v = syn[ti(s[i])][v];
	}
	koniec[v] = 1;
}

void solve(){
	//a nie mowilam, mózg mi wypadł, nie widziales go nigdzie przypadkiem????
	int n; cin >> n;
	vector<string>T(n);
	for (int i = 0; i<n; i++){
		cin >> T[i];
		reverse(T[i].begin(), T[i].end());
		add(T[i], i);
	}
	
	for (int i = 0; i<n; i++){
		set<char>s;
		for (int j = (int)T[i].size()-1; j>=0; j--){
			s.insert(T[i][j]);
			for (auto c: s){
				if (koniec[syn[ti(c)][later[i][j]]]) ans++;
			}
		}
	}
	ans-=n;
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
