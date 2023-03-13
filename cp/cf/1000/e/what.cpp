//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>g(n+1);
    vector<T>edges;
    for (int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>depth(n+1), dp(n+1);
    //dp[v] = number of back edges passing over the edge between v and its parent
    //dp[v] = (# of back-edges up from v) - (# of back-edges down from v) + (sum of dp[x])
    //in dfs tree we both add and subtract edges in the subtree of v (by adding dp)
    //edge is a bridge iff dp[v] = 0
    set<T>bad;
    depth[1] = 1;
    function<void(int, int)>dfs = [&](int v, int pa){
        for (auto x: g[v]){
            if (depth[x] == 0){
                depth[x] = depth[v]+1;
                dfs(x, v);
                dp[v] += dp[x];
            } else {
                if (depth[x] > depth[v]){ //back edge down
                    dp[v]--;
                } else { //back edge up
                    dp[v]++;
                }
            }
        }
        dp[v]--;
        if (v != 1 && dp[v] == 0){
            debug(v, pa);
            bad.insert({v, pa});
            bad.insert({pa, v});
        }
    };
    dfs(1, 1);
    // return;
    debug(dp);
    debug(bad);
    vector<int>nr(n+1, -1);
    int what = 0;
    function<void(int)>DFS = [&](int v){
        nr[v] = what;
        for (auto x: g[v]){
            if (bad.find({v, x}) != bad.end()) continue;
            if (nr[x] == -1) DFS(x);
        }
    };
    for (int i = 1; i<=n; i++){
        if (nr[i] == -1){
            what++;
            DFS(i);
        }
    }
    debug(nr);
    vector<vector<int>>G(n+1);
    for (auto [a, b]:edges){
        if (nr[a] != nr[b]){
            G[nr[a]].emplace_back(nr[b]);
            G[nr[b]].emplace_back(nr[a]);
            debug(nr[a], nr[b]);
        }
    }
    vector<int>d(n+1);
    function<void(int, int)>depth_dfs = [&](int v, int pa){
        for (auto x: G[v]){
            if (x == pa) continue;
            d[x] = d[v]+1;
            depth_dfs(x, v);
        }
    };
    int N = *max_element(nr.begin(), nr.end());
    int L = -1;
    T mx;
    for (int st: {1, 2}){
        debug(st);
        if (st == 2) st = L;
        d.assign(n+1, 0);
        depth_dfs(st, st);
        mx = {-oo, -oo};
        for (int i = 1; i<=N; i++) mx = max(mx, {d[i], i});
        L = mx.second;
    }
    cout << mx.first << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}