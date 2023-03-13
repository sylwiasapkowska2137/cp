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
    vector<int>h(n+1);
    for (int i = 1; i<=n; i++) cin >> h[i];
    int ans = 0;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>dp(n+1);
    int r = 1;
    function<void(int, int)>dfs = [&](int v, int pa){
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            dp[v] = max(dp[v], dp[x]);
        }
        if (v == r){
            T two = {0, 0};
            for (auto x: g[v]){
                if (two.first <= dp[x]){
                    two.second = two.first;
                    two.first = dp[x];
                } else if (two.second <= dp[x]){
                    two.second = dp[x];
                }
            }
            if (two.first < h[v]) ans += (h[v] - two.first); 
            if (two.second < h[v]) ans += (h[v] - two.second); 
        } else if (dp[v] < h[v]){
            ans += (h[v]-dp[v]);
            dp[v] = h[v];
        }
        debug(v, dp[v], h[v], ans);
    };
    int H = *max_element(h.begin(), h.end());
    for (int v = 1; v <= n; v++){
        if (h[v] == H){
            r = v;
            dfs(v, v);
            break;
        }
    }
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