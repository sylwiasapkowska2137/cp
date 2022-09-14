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
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	
	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);

	function<int(int)> Find = [&](int a){
		if (a == rep[a]) return a;
		return rep[a] = Find(rep[a]);
	};

	function<bool(int, int)> Union = [&](int a, int b){
		a = Find(a);
		b = Find(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		rep[b] = a;
		sz[a] += sz[b];
		return 1;
	};

	pair<int, int>cycle;
	for (int i = 1; i<=n; i++){
		int a, b; cin >> a >> b;
		
		if (Union(a, b)){
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		} else cycle = {a, b};
	}
	debug(cycle);
	vector<int>no(n+1, 0), parent(n+1);

	function<void(int, int)> dfs = [&](int v, int pa){
		parent[v] = pa;
		for (auto x: g[v]){
			if (x != pa){
				dfs(x, v);
			}
		}
	};

	dfs(cycle.first, cycle.first);

	int v = cycle.second;
	int ile = 0;
	while (parent[v] != cycle.first){
		v = parent[v];
		no[v] = 1;
		ile++;
	}
	no[cycle.first] = 1;
	no[cycle.second] = 1;

	int cnt = 0;
	function<void(int, int)> dfs2 = [&](int v, int pa){
		parent[v] = pa;
		cnt++;
		for (auto x: g[v]){
			if (x != pa && !no[x]){
				dfs2(x, v);
			}
		}
	};

	int ans = 0;
	int s = 0, sq = 0;
	for (int i = 1; i<=n; i++){
		if (no[i]){
			cnt = 0;
			dfs2(i, i);
			ans += (cnt*(cnt-1)/2);
			s += cnt;
			sq += cnt*cnt;
		}
	}
	debug(ans);
	debug(s, sq);
	ans += s*s-sq;
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}