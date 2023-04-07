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
    int n, k; cin >> n >> k;
    vector<vector<int>>g(n+1);
    vector<int>state(n+1);
    for (int i = 1; i<=k; i++){
        int v; cin >> v;
        state[v] = 1;
    }
    vector dp(n+1, vector<int>(3));
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>sub(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        int all0 = 0;
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            sub[v] += sub[x];
            if (sub[x] > 0) all0 += dp[x][0];
        }
        dp[v][0] = all0;
        if (sub[v] > 0) dp[v][1] = 1;
        dp[v][2] = all0 + 1;
        if (state[v]){
            sub[v]++;
            // debug(all0);
            for (auto x: g[v]){
                if (x == pa) continue;
                debug(v, x, all0 - (sub[x] > 0 ? dp[x][0] : 0LL) + dp[x][2]);
                dp[v][0] = max(dp[v][0], all0 - (sub[x] > 0 ? dp[x][0] : 0LL) + dp[x][2]);
            }
            dp[v][1] = all0 + 1;
            dp[v][2] = -oo;
        } else {
            T best1[2] = {{-oo, -oo}, {-oo, -oo}};
            T best2[2] = {{-oo, -oo}, {-oo, -oo}};
            for (auto x: g[v]){
                if (x == pa) continue;
                int c = dp[x][1] - dp[x][0];
                if (sub[x] > 0){
                    if (c >= best1[0].first){
                        best1[1] = best1[0];
                        best1[0] = {c, x};
                    } else if (c > best1[1].first){
                        best1[1] = {c, x};
                    }
                }
                c = (sub[x] > 0 ? dp[x][2] - dp[x][0] : dp[x][2]);
                if (c >= best2[0].first){
                    best2[1] = best2[0];
                    best2[0] = {c, x};
                } else if (c > best2[1].first){
                    best2[1] = {c, x};
                }
                int d = (sub[x] > 0 ? dp[x][0] : 0LL);
                if (sub[x] > 0) dp[v][0] = max(dp[v][0], all0 - d + dp[x][1]);
                // if (sub[x] < k) dp[v][0] = max(dp[v][0], all0 - d + dp[x][2]);

                if (sub[x] > 0) dp[v][1] = max(dp[v][1], all0 - d + dp[x][1] + 1);
                debug(all0, x, all0 - d + dp[x][2] + 1);
                dp[v][2] = max(dp[v][2], all0 - d + dp[x][2] + 1);
            }
            // debug(v, dp[v][0]);
            for (int rep = 0; rep < 2; rep++){
                // debug(best1[rep], best2[rep]);
                if (best1[rep].second == -oo) continue;
                for (int rep2 = 0; rep2 < 2; rep2++){
                    if (best2[rep2].second == -oo) continue;
                    if (best1[rep].second != best2[rep2].second){
                        dp[v][0] = max(dp[v][0], all0 + best1[rep].first + best2[rep2].first);
                    }
                }
            }
        }
        if (state[pa]) dp[v][1] = -oo;
        debug(v, dp[v]);
    };
    dfs(1, 1);
    cout << 2*(n-k) - dp[1][0] << "\n";
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