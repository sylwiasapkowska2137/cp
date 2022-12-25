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

const int nax = 1e5+7, K = 20;
vector<vector<pair<int, int>>>g;
int up[nax][K];
vector<int>depth, fix, sz;
vector<long long> dp, new_dp, depth2;
int all;

void init(int n){
    g.resize(n);
    depth.assign(n, 0);
    depth2.assign(n, 0);
    fix.assign(n, 0);
    sz.assign(n, 0);
    dp.assign(n, 0);
    new_dp.assign(n, 0);
}

void dfs(int v, int pa){
    up[v][0] = pa;
    for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
    for (auto [x, c]:g[v]){
        if (x == pa) continue;
        depth[x] = depth[v]+1;
        depth2[x] = depth2[v]+c;
        dfs(x, v);
    }
}

int lca(int a, int b){
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
}

long long D(int a, int b){
	return depth2[a] + depth2[b] - 2*depth2[lca(a, b)];
}

void dfs2(int v, int pa){
    for (auto [x, c]:g[v]){
        if (x == pa) continue;
        dfs2(x, v);
        sz[v] += sz[x];
        dp[v] += dp[x] + sz[x]*c;
    }
}

void reroot(int v, int pa){
    new_dp[v] = dp[v];
    for (auto [x, c]:g[v]){
        if (x == pa) continue;
        
        int p = sz[x];
        int dv = dp[v], dx = dp[x];
        sz[v] -= p;
        sz[x] = all;
        dp[v] -= (dp[x] + p*c);
        dp[x] += dp[v] + sz[v]*c;

        reroot(x, v);

        sz[v] += p;
        sz[x] = p;
        dp[v] = dv;
        dp[x] = dx;
    }
}

void solve(){
	int n, k; cin >> n >> k;
    init(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	dfs(1, 1);
	int s = 500;
    vector<int>tab = {1};
    vector<long long> ans;
	fix[1] = 1;

	while (k){
		for (int i = 0; i<min(s, k); i++, k--){
			int v; cin >> v;
			long long curr = dp[v];
			for (auto x: tab) curr += D(x, v);
			ans.emplace_back(2*curr);
			tab.emplace_back(v);
			fix[v] = 1;
		}
		sz = fix;
		dp.assign(n+1, 0);
		dfs2(1, 1);
		all = sz[1];
		reroot(1, 1);
		swap(dp, new_dp);
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
