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

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<T>>g(n+1);
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            int c; cin >> c;
            g[i].emplace_back(j, c);
        }
    }
    vector<vector<int>>dp;
    int ans = oo;
    vector<int>a(n+1);
    while (clock() <= 2.9 * CLOCKS_PER_SEC){
        for (int i = 1; i<=n; i++) a[i] = rand()%2;
        dp.assign(n+1, vector<int>(k+1, oo));
        dp[1][0] = 0;
        for (int len = 1; len <= k; len++){
            for (int u = 1; u <= n; u++){
                if (dp[u][len-1] == oo) continue;
                for (auto [x, c]: g[u]){
                    if (a[u] != a[x]){
                        dp[x][len] = min(dp[x][len], dp[u][len-1] + c);
                    }
                }
            }
        }
        ans = min(ans, dp[1][k]);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(2137);
    solve();

    return 0;
}