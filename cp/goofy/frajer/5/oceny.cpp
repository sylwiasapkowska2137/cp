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

// #define int long long
typedef pair<int, int> T;
const int oo = 1e9+7, oo2 = 1e9+7, K = 30;
// const int mod = 998244353;

void solve(){
    int n; cin >> n;
    vector a(n+1, vector<int>(2));
    for (int rep = 0; rep < 2; rep++){
        for (int i = 1; i<=n; i++){
            cin >> a[i][rep];
        }
    }
    vector dp(n+1, vector<int>(2, oo));
    dp[1][0] = 0;
    dp[1][1] = 1;
    auto check = [&](int where, int x, int y){
        int curr = oo;
        if (a[where][0] < x && a[where][1] < y) curr = min(curr, dp[where][0]);
        if (a[where][1] < x && a[where][0] < y) curr = min(curr, dp[where][1]);
        return curr;
    };
    for (int i = 2; i<=n; i++){
        dp[i][0] = check(i-1, a[i][0], a[i][1]);
        dp[i][1] = check(i-1, a[i][1], a[i][0])+1;
    }
    int ans = min(dp[n][0], dp[n][1]);
    if (ans >= oo) cout << "NIE\n";
    else  cout << ans << "\n";
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