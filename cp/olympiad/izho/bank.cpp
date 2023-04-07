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

typedef pair<int, int> T;
const int oo = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n+1), b(m);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 0; i<m; i++) cin >> b[i];
    vector<int>dp((1<<m), oo);
    dp[0] = 0;
    for (int rep = 1; rep<=n; rep++){
        for (int mask = 0; mask < (1<<m); mask++) {
            if (dp[mask] == 0){
                dp[mask] = a[rep];
            } else {
                dp[mask] = oo;
            }
        }
        for (int mask = 0; mask < (1<<m); mask++){
            for (int i = 0; i<m; i++){
                if (mask&(1<<i)){
                    if (dp[mask^(1<<i)] >= b[i] && dp[mask^(1<<i)] != oo){
                        dp[mask] = dp[mask^(1<<i)] - b[i];
                    }
                }
            }
        }
    }
    for (int mask = 0; mask < (1<<m); mask++){
        if (dp[mask] == 0){
            cout << "YES\n";
            return;
        }
    }    
    cout << "NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}