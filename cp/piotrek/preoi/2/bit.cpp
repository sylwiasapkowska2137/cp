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
const int mx = 2e5+7;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

int dp[mx], new_dp[mx];
vector<T>a;

void rec(int l, int r, int optl, int optr){
    if (l > r) return;
    int m = (l+r)/2;
    int opt = oo;
    new_dp[m] = -oo;
    for (int i = optl; i<=min(m-1, optr); i++){
        int t = dp[i] + a[m].first;
        if (new_dp[m] <= t){
            new_dp[m] = t;
            opt = i;
        }
    }
    rec(l, m-1, optl, opt);
    rec(m+1, r, opt, optr);
}

void solve(){
    int n, k; cin >> n >> k;
    a.resize(n+1);
    a[0] = {-oo, -oo};
    for (int i = 1; i<=n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [&](auto x, auto y){return x.second == y.second ? x.first > y.first : x.second < y.second;});
    //k = 1;
    for (int i = 1; i<=n; i++) dp[i] = a[i].first + 2 * a[i].second;
    for (int i = 2; i<=k; i++){
        rec(1, n, 0, n);
        swap(dp, new_dp);
    }
    int ans = 0;
    for (int i = k; i<=n; i++){
        // debug(i, dp[i]);
        ans = max(ans, dp[i] - 2*a[i].second);
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