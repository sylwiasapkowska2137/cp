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
    vector<int>state(n+1);
    for (int i = 1; i<=n; i++) cin >> state[i];
    vector dp(n+1, vector<vector<int>>(2, vector<int>(2, oo)));
    //dp[v][2][2] = answer for subtree of v if we dont/do change the switch v-th camera and the state of v is off/on
    function<void(int, int)>dfs = [&](int v, int pa){
        for (int rep = 0; rep < 2; rep++){
            dp[v][rep][state[v] ^ rep] = rep;
            dp[v][rep][state[v] ^ rep ^ 1] = oo;
        }        
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            for (int rep = 0; rep < 2; rep++){
                int dp0 = dp[v][rep][0];
                int dp1 = dp[v][rep][1];
                dp[v][rep][0] = min({oo, dp0 + dp[x][0][rep], dp1 + dp[x][1][rep]});
                dp[v][rep][1] = min({oo, dp0 + dp[x][1][rep], dp1 + dp[x][0][rep]});
            }
        }
    };
    dfs(1, 1);
    int ans = min(dp[1][1][0], dp[1][0][0]);
    if (ans == oo) cout << "impossible\n";
    else cout << ans << "\n";
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