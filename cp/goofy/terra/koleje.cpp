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

// #define int long long
// const int oo = 1e18, oo2 = 1e9+7, K = 20;
// const int mod = 998244353;
const int K = 20;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>>g(n+1), G(n+1);
	vector<tuple<int, int, int>>edges;
	map<pair<int, int>, int>cnt;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		if (a > b) swap(a, b);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
		edges.emplace_back(a, b, c);
		cnt[{a, b}]++;
	}
	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	function<int(int)>f = [&](int a){return rep[a] == a ? a : rep[a] = f(rep[a]);};
	function<void(int, int)>u = [&](int a, int b){
		a = f(a); b = f(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
	};

	vector<int>pre(n+1), low(n+1), vis(n+1), val(n+1);
	int t = 0;
	set<pair<int, int>>bridge;
	function<void(int, int)>dfs = [&](int v, int pa){
		vis[v] = 1;
		pre[v] = low[v] = t++;
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			if (vis[x]) low[v] = min(low[v], pre[x]);
			else {
				dfs(x, v);
				low[v] = min(low[v], low[x]);
				if (low[x] > pre[v]){
					auto [a, b] = make_pair(x, v);
					if (a > b) swap(a, b);
					if (cnt[{a, b}] == 1){
						// debug(a, b);
						bridge.insert({a, b});
					}
				}
			}
		}
	};
	dfs(1, 1);
	for (auto [a, b, c]:edges){
		if (bridge.find({a, b}) == bridge.end()){
			u(a, b);
		}
	}
	for (auto [a, b, c]:edges){
		if (bridge.find({a, b}) != bridge.end()){
			a = f(a);b = f(b);
			G[a].emplace_back(b, c);
			G[b].emplace_back(a, c);
		}
	}
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1);
	function<void(int, int)>DFS = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]:G[v]){
			if (x == pa) continue;
			depth[x] = depth[v] + 1;
			val[x] = c;
			DFS(x, v);
		}
	};
	int s = 1;
	for (int i = n; i>=1; i--) if (f(i) == i) s = i;
	DFS(s, s);

	auto lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a] - (1<<i) >= depth[b]){
				a = up[a][i];
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
	vector<int>U(n+1), D(n+1);
	for (int i = 0; i<q; i++){
		int a, b; cin >> a >> b;
		a = f(a); b = f(b);
		int l = lca(a, b);
		U[a]++;U[l]--;
		D[l]--;D[b]++;
	}
	function<void(int, int)>dfs2 = [&](int v, int pa){
		for (auto [x, c]:G[v]){
			if (x == pa) continue;
			dfs2(x, v);
			U[v] += U[x];
			D[v] += D[x];
		}
	};

	dfs2(s, s);
	long long ans = 0;
	for (int i = 1; i<=n; i++) ans += (long long)(min(U[i], D[i]))*(long long)val[i]; 
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
