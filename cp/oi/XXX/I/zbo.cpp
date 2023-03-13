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
	int n, k; cin >> n >> k;
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1), depth2(n+1);

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			depth2[x] = depth2[v]+c;
			dfs(x, v);
		}
	};

	dfs(1, 1);

	function<int(int, int)>lca = [&](int a, int b){
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

	auto D = [&](int a, int b){
		return depth2[a] + depth2[b] - 2*depth2[lca(a, b)];
	};

	int s = sqrt(n);
	// #warning set s to sqrt
	vector<int>fix(n+1), sz, tab, dp(n+1), new_dp(n+1);
	int all;

	function<void(int, int)>dfs2 = [&](int v, int pa){
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			dfs2(x, v);
			sz[v] += sz[x];
			dp[v] += dp[x] + sz[x]*c;
		}
	};
	function<void(int, int)>reroot = [&](int v, int pa){
		new_dp[v] = dp[v];
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			
			int p = sz[x];
			int dv = dp[v], dx = dp[x];
			sz[v] -= p;
			sz[x] = all;
			dp[v] -= dp[x];
			dp[v] -= p*c;
			dp[x] += dp[v];
			dp[x] += sz[v] * c;

			reroot(x, v);

			sz[v] += p;
			sz[x] = p;
			dp[v] = dv;
			dp[x] = dx;
		}
	};
	tab.emplace_back(1);
	fix[1] = 1;
	vector<int>ans;
	while (k){
		for (int i = 0; i<min(s, k); i++, k--){
			int v; cin >> v;
			int curr = dp[v];
			for (auto x: tab) curr += D(x, v);
			ans.emplace_back(2*curr);
			tab.emplace_back(v);
			fix[v] = 1;
		}
		sz = fix;
		// debug(tab);
		// debug(sz);
		// solve for tab
		dp.assign(n+1, 0);
		dfs2(1, 1);
		// debug(sz);
		// debug(dp);
		all = sz[1];
		// debug(all);
		reroot(1, 1);
		dp = new_dp;
		// debug(dp);
		// exit(0);
		tab.clear();
	}
	for (int i = 0; i<(int)ans.size(); i++){
		if (i) ans[i] += ans[i-1];
		cout << ans[i] << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
