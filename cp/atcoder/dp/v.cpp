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
int mod;

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

int mul(int a, int b){
    return ((a*b)%mod+mod)%mod;
}

void solve(){
    int n; cin >> n >> mod;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<vector<int>>pref(n+1), suf(n+1);
    vector<int>dp(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        dp[v] = 1;
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            dp[v] = mul(dp[v], dp[x]);
        }
        int s = (int)g[v].size();
        auto &L = pref[v];
        auto &R = suf[v];
        L.assign(s, 1); R.assign(s, 1);
        for (int i = 0; i<s; i++){
            if (i) L[i] = L[i-1];
            if (g[v][i] != pa) L[i] = mul(L[i], dp[g[v][i]]);
        }
        for (int i = s-1; i>=0; i--){
            if (i < s-1) R[i] = R[i+1];
            if (g[v][i] != pa) R[i] = mul(R[i], dp[g[v][i]]);
        }
        debug(v, L, R);
        add(dp[v], 1);
    };
    dfs(1, 1);
    vector<int>dp2(n+1);
    dp2[1] = 1;
    function<void(int, int, int)>up = [&](int v, int pa, int idx){
        if (v != pa){
            debug(v, g[v]);
            dp2[v] = dp2[pa];
            if (idx) dp2[v] = mul(dp2[v], pref[pa][idx-1]);
            if (idx < (int)g[pa].size()-1) dp2[v] = mul(dp2[v], suf[pa][idx+1]);
            debug(pa, v, dp2[pa], dp2[v]);
            add(dp2[v], 1);
        }
        
        int c = 0;
        for (auto x: g[v]){
            if (x != pa) up(x, v, c);
            c++;
        }
    };
    up(1, 1, 0);
    debug(dp);
    debug(dp2);
    for (int v = 1; v<=n; v++) cout << mul(dp[v]-1, dp2[v]) << "\n";
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