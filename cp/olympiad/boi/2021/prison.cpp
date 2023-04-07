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
    int n, d, tt; cin >> n >> d >> tt;
    vector<int>t(n+1);
    for (int i = 1; i<=n; i++) cin >> t[i];
    vector<int>prev(n+1, -oo);
    stack<int>s;
    for (int i = 1; i<=n; i++){
        while ((int)s.size() && s.top() - t[s.top()] < i - tt) s.pop();
        if ((int)s.size()) prev[i] = s.top();   
        if (t[i] <= tt) prev[i] = i;
        s.push(i);
    }
    debug(prev);
    // return;
    vector dp(n+1, vector<int>(d+2, oo));
    vector C(n+1, vector<int>(n+1, oo));
    for (int j = 0; j<=n; j++){
        //stawiamy przeszkode miedzy indeksem j a j+1
        int cnt = 0;
        for (int i = j+1; i<=n; i++){
            if (prev[i] > j) cnt++;
            C[j][i] = cnt;
            debug(j, i, C[j][i]);
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i<=n; i++){
        dp[i][1] = C[0][i];
        debug(dp[i][1]);
        for (int cd = 1; cd <= d+1; cd++){
            for (int j = 0; j<i; j++){
                dp[i][cd] = min(dp[i][cd], dp[j][cd-1] + C[j][i]);
            }
            debug(i, cd, dp[i][cd]);
        }
    }
    cout << dp[n][d+1] << "\n";
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