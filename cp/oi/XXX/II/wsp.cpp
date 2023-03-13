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
    int n, m, k; cin >> n >> m >> k;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<vector<int>>g(n+1);
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
    }    
    k++;
    vector<int>dp((1<<k)+3), new_dp;
    vector<int>ans(n+1);
    for (int i = n; i>=1; i--){
        int old = 0;
        new_dp.assign((1<<k)+3, 0);
        for (auto x: g[i]) old += (1<<(x-i));
        for (int mask = 0; mask<(1<<k); mask++){
            if (mask&1) new_dp[mask] = dp[(old|mask)>>1] + a[i];
            else new_dp[mask] = dp[mask>>1];
        }
        dp.swap(new_dp);
        ans[i] = dp[1];
    }
    for (int i = 1; i<=n; i++) cout << ans[i] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}