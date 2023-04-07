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

struct person{
    int a;
    vector<int>s;
};

void solve(){
    int n, p, k; cin >> n >> p >> k;
    vector<person>tab(n+1);
    for (int i = 1; i<=n; i++) cin >> tab[i].a;
    for (int i = 1; i<=n; i++){
        for (int j = 0; j<p; j++){
            int x; cin >> x;
            tab[i].s.emplace_back(x);
        }
    }  
    sort(tab.begin()+1, tab.end(), [&](auto x, auto y){return x.a > y.a;});
    vector dp(n+1, vector<int>((1<<p), -oo));
    dp[0][0] = 0;
    for (int i = 1; i<=n; i++){
        for (int mask = 0; mask < (1<<p); mask++){
            //1. dokladamy do widowni, maska sie nie zmienia
            //2. dokladamy do druzyny na j-tą pozycje
            for (int j = 0; j<p; j++){
                if (mask&(1<<j)){
                    dp[i][mask] = max(dp[i][mask], dp[i-1][mask^(1<<j)] + tab[i].s[j]);
                }
            }
            int left = i - __builtin_popcount(mask);
            dp[i][mask] = max(dp[i][mask], dp[i-1][mask] + (left <= k ? tab[i].a : 0));
        }
        debug(i, dp[i]);
    }
    cout << dp[n][(1<<p)-1] << "\n";
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