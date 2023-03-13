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
const int mod = 1e9+7;

int add2(int a, int b){
    a += b;
    if (a >= mod) a-=mod;
    return a;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = "$"+s;
    vector<int>pref(n+1, 1);
    pref[0] = 0;
    auto ask = [&](int l, int r){
        if (l > r) return 0LL;
        int ans = pref[r] - pref[l-1];
        if (ans < 0) ans += mod;
        return ans;
    };
    for (int i = 1; i<n; i++){
        vector<int>new_dp(n+1);
        for (int curr = 1; curr <= i+1; curr++){
            if (s[i] == '<') new_dp[curr] = ask(1, curr-1);
            else new_dp[curr] = ask(curr, n);
        }
        // debug(i, new_dp);
        for (int k = 1; k <= n; k++) pref[k] = add2(pref[k-1], new_dp[k]);
    }
    cout << pref[n] << "\n";
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