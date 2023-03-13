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
    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = 0;
    vector<int>dp(n+1), sz(n+1);
    function<int(int, int)>dfs = [&](int v, int pa){
        sz[v] = 1;
        for (auto x: g[v]){
            if (x == pa) continue;
            sz[v] += dfs(x, v);
            dp[v] += dp[x];
        }
        dp[v] += sz[v];
        return sz[v];
    };
    function<void(int, int)>reroot = [&](int v, int pa){
        ans = max(ans, dp[v]);
        for (auto x: g[v]){
            if (x == pa) continue;
            int t = sz[x];
            int pv = dp[v], px = dp[x];
            dp[v] -= dp[x];
            dp[v] -= sz[x];
            dp[x] -= sz[x];
            dp[x] += dp[v] + n;
            sz[v] -= sz[x];
            sz[x] = n;

            reroot(x, v);

            dp[v] = pv;
            dp[x] = px;
            sz[v] += t;
            sz[x] = t;
        }
    };
    dfs(1, 1);
    debug(dp);
    reroot(1, 1);
    cout << ans << "\n";
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