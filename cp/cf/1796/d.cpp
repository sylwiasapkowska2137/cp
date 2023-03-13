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
    int k, x; cin >> k >> x;
    vector<int> a(n+1), pref(n+1);
    vector<vector<int>>dp(n+1, vector<int>(k+3, 0));
    for (int i = 1; i<=n; i++){
        cin >> a[i];    
        pref[i] = pref[i-1] + a[i];
    }
    for (int s = 1; s <= k+1; s++){
        for (int i = s; i<=n; i++){
            dp[i][s] = max(0LL, dp[i-1][s] + a[i] - x);
        }
    }
    int ans = 0;
    if (!k){
        for (int i = 1; i<=n; i++){
            ans = max(ans, dp[i][1]);
        }
        cout << ans << "\n";
        return;
    }
    if (x > 0){
        for (int i = 1; i<=n; i++){
            for (int j = i; j >= max(1LL, i-k+1); j--){
                int curr = pref[i] - pref[j-1] + (i-j+1) * x + dp[j-1][1];
                ans = max(ans, curr);
            }
            // int curr = pref[i] - pref[max(0LL, i-k)] + min(i, k) * x + dp[max(0LL, i-k)][1];
            // ans = max(ans, curr);
        }
    } else {
        for (int i = 1; i<=n; i++){
            int left = max(0LL, k - (n - i));
            for (int j = 1; j<=k+1; j++){
                ans = max(ans, 2LL * left * x + dp[i][j]);
                left = max(0LL, left-1);
            }
        }
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