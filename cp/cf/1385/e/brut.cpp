//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n+1);
	vector<pair<int, int>>dir, edges;
	for (int i = 0; i<m; i++){
		int t, a, b; cin >> t >> a >> b;
		if (t){
			dir.emplace_back(a, b);
		} else {
			edges.emplace_back(a, b);
		}
	}
	int nr = 0;
	vector<int>vis;
	bool cycle = 0;

	function<void(int)> dfs = [&](int v){
		vis[v] = nr;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			} else if (vis[x] == nr){
				cycle = 1;
			}
		}
	};

	int x = (int)edges.size();
	for (int mask = 0; mask<(1LL<<x); mask++){
		for (int i = 1;i<=n; i++){
			g[i].clear();
		}
		for (auto [a, b]:dir) g[a].emplace_back(b);
		for (int i = 0; i<x; i++){
			if (mask&(1<<i)){
				g[edges[i].first].emplace_back(edges[i].second);
			} else {
				g[edges[i].second].emplace_back(edges[i].first);
			}
		}
		vis.assign(n+1, 0);
		nr = 0;
		cycle = 0;
		for (int i = 1; i<=n; i++){
			if (!vis[i]){
				nr++;
				dfs(i);
			}
		}
		if (!cycle){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
