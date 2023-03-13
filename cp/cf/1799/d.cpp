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
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<int>cold(k+1), hot(k+1);
    for (int i = 1; i<=k; i++) cin >> cold[i];
    for (int i = 1; i<=k; i++) cin >> hot[i];
    // vector<int>last(k+1, -1), prev(n+1, -1);
    // for (int i = 1; i <= n; i++){
    //     prev[i] = last[a[i]];
    //     last[a[i]] = i;
    // }
    vector<vector<int>>dp(n+1, vector<int>(n+1, oo));
    dp[0][0] = 0;
    //dp[i][mniejsze last]
    for (int i = 1; i<=n; i++){
        for (int last = 0; last < i; last++){
            //dokladamy na ten drugi
            dp[i][last] = min(dp[i][last], dp[i-1][last] + (a[i] == a[i-1] ? hot[a[i]] : cold[a[i]])); 
            dp[i][i-1] = min(dp[i][i-1], dp[i-1][last] + (a[i] == a[last] ? hot[a[i]] : cold[a[i]]));
        }
    }
    int ans = oo;
    for (int i = 0; i<n; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}