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

const int oo = 1e9+7, K = 18;
vector<vector<pair<int, int>>>g;
vector<vector<int>>up;
vector<int>sub, vis, t, to_clear, par, sz, d;
vector<long long>ans, depth;
vector<pair<int, int>>curr;

void depth_dfs(int v, int pa){
	up[v][0] = pa;
	for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
	for (auto [x, c]:g[v]){
		if (x == pa) continue;
		depth[x] = depth[v]+c;
		d[x] = d[v]+1;
		depth_dfs(x, v);
	}
}

int lca(int a, int b){
	if (d[a] > d[b]) swap(a, b);
	for (int i = K-1; i>=0; i--){
		if (d[b] - (1<<i) >= d[a]){
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
}

int dfs(int v, int pa){
	sub[v] = 1;
	for (auto [x, c]: g[v]){
		if (x == pa || vis[x]) continue;
		sub[v] += dfs(x, v);
	}
	return sub[v];
}      

int get(int v, int ms, int pa){
	for (auto [x, c]: g[v]){
		if (x == pa || vis[x]) continue;
		if (sub[x]*2>ms) return get(x, ms, v);
	}
	return v;
}

void DFS(int v, int pa){
	if (t[v] != oo) to_clear.emplace_back(v);
	for (auto [x, c]:g[v]){
		if (x == pa || vis[x]) continue;
		DFS(x, v);
	}
}

void centroid(int v){
	v = get(v, dfs(v, v), v);
	// debug(v);
	DFS(v, v);
	debug(v, to_clear);
	long long all = 0;
	int ile = 1;
	for (int i = 0; i<(int)to_clear.size(); i++){
		int u = to_clear[i];
		int p = (i ? to_clear[i-1] : to_clear.back());
		if (lca(u, p) == v){
			curr.emplace_back(u, ile);
			ile = 0;
		}
		ile++;
	}
	debug(curr);
	exit(0);
	debug(ans);

	curr.clear();
	to_clear.clear();

	vis[v] = 1;
	for (auto [x, c]: g[v]){
		if (!vis[x]){
			centroid(x);
		}
	}
}

void solve(){
	int n, k; cin >> n >> k;
	g.resize(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	up.resize(n+1, vector<int>(K));
	d.assign(n+1, 0);
	sub.assign(n+1, 0);
	vis.assign(n+1, 0);
	t.assign(n+1, oo);
	par.assign(n+1, 0);
	sz.assign(n+1, 0);
	depth.assign(n+1, 0);
	ans.assign(n+1, 0);
	vector<int>now(k+2);
	for (int i = 2; i<=k+1; i++){
		int v; cin >> v;
		t[v] = i;
		now[i] = v;
	}
	depth_dfs(1, 1);
	centroid(1);
	long long sum = 0;
	debug(ans);
	for (int i = 1; i<=n; i++) ans[i] += ans[i-1];
	for (int i = 2; i<=k+1; i++){
		sum += depth[now[i]];
		// debug(ans[i]);
		long long res = sum * (i-1) - 2LL * ans[i];
		cout << 2*res << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
