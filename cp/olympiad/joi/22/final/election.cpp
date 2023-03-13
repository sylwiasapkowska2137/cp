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
typedef long double ld;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
 
void solve(){
    int n, k; cin >> n >> k;
    vector<T>tab;
    int cnt = 0;
    tab.emplace_back(-oo, -oo);
    for (int i = 1; i<=n; i++){
        int x, y; cin >> x >> y;
        if (y == -1) y = oo2;
        else cnt++;
        tab.emplace_back(x, y);
    }
    sort(tab.begin(), tab.end(),[](auto x, auto y){return x.second == y.second ? x.first < y.first : x.second < y.second;});
    ld ans = oo;
    //dp[i][j] - min wynik, gdzie j - (dla ustalonego col) = ile mi glosow brakuje (innych niz col) do k?
    for (int col = 0; col <= min(k, cnt); col++){
        vector dp(n+2, vector<ld>(n+2, oo));
        dp[0][0] = 0;
        for (int i = 1; i<=n; i++){
            auto [a, b] = tab[i];
            for (int j = 0; j <= i; j++){
                dp[i][j] = min( (j ? dp[i-1][j-1] + (ld)(a)/(ld)(col+1) : (ld)oo),
                                (j != i && i-j <= col ? dp[i-1][j] + (ld)(b)/(ld)(i-j) : dp[i-1][j])
                                );
                // debug(i, ck, dp[i][ck]);
            }
        }
        ans = min(ans, dp[n][k-col]);
    }
    cout << fixed << setprecision(17) << ans << "\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
 
    return 0;
}