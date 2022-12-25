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

const int nax = 1e5+7, K = 18;
const int oo = 1e9+7;
vector<vector<pair<int, int>>>g;
int up[nax][K];
pair<int, int>mn[2*nax][K];
vector<int>depth, fix, sz, lg, first, last;
vector<pair<int, int>> order;
vector<long long> dp, new_dp, depth2;
int all;

void init(int n){
    g.resize(n);
    depth.assign(n, 0);
    depth2.assign(n, 0);
    fix.assign(n, 0);
    sz.assign(n, 0);
    first.assign(n, -1);
    last.assign(n, -1);
    dp.assign(n, 0);
    new_dp.assign(n, 0);
    lg.resize(2*n+2);
    lg[1] = 0;
    for (int i = 2; i<(int)lg.size(); i++) lg[i] = lg[i/2]+1;
}

int query(int L, int R){
    int j = lg[R-L+1];
    return min(mn[L][j], mn[R - (1 << j) + 1][j]).second;
}

void dfs(int v, int pa){
    // up[v][0] = pa;
    order.emplace_back(depth[v], v);
    // for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
    for (auto [x, c]:g[v]){
        if (x == pa) continue;
        depth[x] = depth[v]+1;
        depth2[x] = depth2[v]+c;
        dfs(x, v);
        order.emplace_back(depth[v], v);
    }
}

int lca(int a, int b){
    int L = min(first[a], first[b]);
    int R = max(last[a], last[b]);
    return query(L, R);
}

long long D(int a, int b){
    // debug(a, b, lca(a, b));
	return depth2[a] + depth2[b] - 2*depth2[lca(a, b)];
}

void dfs2(int v, int pa){
    for (auto [x, c]:g[v]){
        if (x == pa) continue;
        dfs2(x, v);
        sz[v] += sz[x];
        dp[v] += dp[x] + (long long)sz[x]*(long long)c;
    }
}

void reroot(int v, int pa){
    new_dp[v] = dp[v];
    for (auto [x, c]:g[v]){
        if (x == pa) continue;
        
        int p = sz[x];
        long long dv = dp[v], dx = dp[x];
        sz[v] -= p;
        sz[x] = all;
        dp[v] -= (dp[x] + (long long)p*(long long)c);
        dp[x] += dp[v] + (long long)sz[v]*(long long)c;

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
    for (int i = 1; i<=2*n; i++) {
        for (int j = 0; j<K; j++){
            mn[i][j] = {oo, oo};
        }
    }
    // debug(order);
    for (int i = 0; i<(int)order.size(); i++){
        if (first[order[i].second] == -1){
            first[order[i].second] = i;
        }
    }
    for (int i = (int)order.size()-1; i>=0; i--){
        if (last[order[i].second] == -1){
            last[order[i].second] = i;
        }
    }
    for (int i = 0; i<(int)order.size(); i++){
        mn[i][0] = order[i];
    }
    for (int j = 1; (1<<j) <= (int)order.size(); j++){
        for (int i = 0; i+(1<<j)-1<(int)order.size(); i++){
            mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
        }
    }
	int s = 1000;
    vector<int>tab = {1};
    vector<long long> ans;
	fix[1] = 1;

	for (int i = 0; i<k; i++){
        int v; cin >> v;
        long long curr = dp[v];
        for (auto x: tab) curr += D(x, v);
        ans.emplace_back(2LL*curr);
        tab.emplace_back(v);
        fix[v] = 1;
		if ((int)tab.size() == s){
            sz = fix;
            dp.assign(n+1, 0);
            dfs2(1, 1);
            all = sz[1];
            reroot(1, 1);
            swap(dp, new_dp);
            tab.clear();
        }
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
