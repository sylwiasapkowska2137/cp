//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
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
const int oo = 1e18, oo2 = 1e9+7, K = 20;
const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	pair<int, int>cycle;
	function<int(int)>f = [&](int a){return rep[a] == a ? a : rep[a] = f(rep[a]);};
	auto u = [&](int a, int b){
		a = f(a), b = f(b);
		if (a == b){
			return 0; 
		}
		if (sz[a] < sz[b]) swap(a, b);
		rep[b] = a;
		sz[a] += sz[b];
		return 1;
	};
	
	for (int i = 0; i<n; i++){
		int a, b; cin >> a >> b;
		if (u(a, b)){
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		} else {
			cycle = {a, b};
		}
	}
	// debug(cycle);
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1);

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	dfs(cycle.first, cycle.first);
	vector<int>color(n+1), sum(n+1);
	color[cycle.second]++;
	// color[cycle.first != 1 ? up[cycle.first][0] : 0]--;
	
	function<void(int, int)>DFS = [&](int v, int pa){
		for (auto x: g[v]){
			if (x == pa) continue;
			DFS(x, v);
			color[v] += color[x];
		}
	};

	DFS(cycle.first, cycle.first);
	vector<int>from(n+1);
	function<void(int, int)>DFS2 = [&](int v, int pa){
		if (color[v]) from[v] = v;
		for (auto x: g[v]){
			if (x == pa) continue;
			from[x] = from[v];
			DFS2(x, v);
		}
	};
	DFS2(cycle.first, cycle.first);

	auto lca = [&](int a, int b){
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[b] - (1<<i) >= depth[a]){
				b = up[b][i];
			}
		}
		if (a == b) return a;
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0];
	};

	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		if (from[a] != from[b]) cout << "No\n";
		else cout << "Yes\n";
		
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
