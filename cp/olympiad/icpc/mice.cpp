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
const ld oo = 1e18, oo2 = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<T>pos(n);
    cerr << fixed << setprecision(3);
    vector<int> hide(n);
    for (int i = 0; i<n; i++){
        cin >> pos[i].first >> pos[i].second >> hide[i];
    }
    const ld eps = 1e-7;
    ld m; cin >> m;
    auto dist = [&](int a, int b){
        T A = pos[a];
        T B = (b == -1 ? T{0, 0} : pos[b]);
        ld x = (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
        return sqrtl(x);
    };
    auto check = [&](ld c){
        vector<ld>v(n+1);
        v[0] = c;
        for (int i = 1; i<=n; i++) v[i] = v[i-1] * m;
        vector dp((1<<n), vector<ld>(n, oo));
        for (int i = 0; i<n; i++){
            dp[1<<i][i] = dist(i, -1)/c;
            if (dp[1<<i][i] > hide[i]) dp[1<<i][i] = oo;
        }
        for (int mask = 1; mask < (1<<n); mask++){
            for (int i = 0; i<n; i++){
                if (mask&(1<<i)){
                    for (int last = 0; last < n; last++){
                        if (last != i && (mask&(1<<i))){
                            if (abs(dp[mask^(1<<i)][last] - oo) < eps) continue;
                            ld now = dp[mask^(1<<i)][last] + dist(i, last)/v[__builtin_popcount(mask)-1];
                            if (now - eps <= hide[i]){
                                dp[mask][i] = min(dp[mask][i], now);
                            }   
                        }
                    }
                }
            }
            debug(mask, dp[mask]);
        }
        for (int last = 0; last < n; last++){
            if (abs(dp[(1<<n)-1][last] - oo) > eps){
                return true;
            }
        }
        return false;
    };
    // bool what = check(3);
    // debug(what);
    // return;
    ld L = eps, R = oo2;
    while (R - L > eps){
        ld mid = (L+R)/2;
        debug(mid);
        if (check(mid)){
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << fixed << setprecision(15) << L << "\n";
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