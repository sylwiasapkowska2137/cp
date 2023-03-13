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
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<vector<int>>g(n+1);
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            char c; cin >> c;
            if (c == 'Y'){
                g[i].emplace_back(j);
                // cerr << i << " " << j << "\n";
            }
        }
    }
    vector dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -oo)));
    for (int i = 1; i<=n; i++){
        dp[i][i][0] = a[i];
    }
    vector<vector<int>>pairs(n+1), unpairs(n+1);
    for (int len = 1; len <= n; len++){
        for (int v = 1; v <= n; v++){
            pairs[v].clear();
            unpairs[v].clear();
            for (int u = 1; u <= n; u++){
                if (dp[v][u][len-1] != -oo){
                    pairs[v].emplace_back(u);
                } else {
                    unpairs[v].emplace_back(u);
                }
            }
        }
        debug(len);
        for (int v = 1; v <= n; v++){
            debug(v, pairs[v]);
            for (auto u: pairs[v]){
                for (auto x: unpairs[u]){
                    dp[v][x][len] = max(dp[v][x][len], dp[v][u][len-1] + a[x]);
                }
            }
        }
    }
    int q; cin >> q;
    while (q--){
        int a, b; cin >> a >> b;
        int ans = -1;
        for (int len = 0; len <= n; len++){
            if (dp[a][b][len] != -oo){
                ans = len;
                break;
            }
        }
        if (ans == -1) cout << "Impossible\n";
        else cout << ans << " " << dp[a][b][ans] << "\n";
    }
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