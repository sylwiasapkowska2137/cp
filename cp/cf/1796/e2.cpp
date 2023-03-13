//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {if (x == 1e18) cerr << "x"; else cerr << x;}
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
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<T>dp(n+1, {oo, oo}), dp2(n+1, {oo, oo}); //{len, ans} 
    //dp[v] = {dlugosc sciezki ktora wydluzylismy do v, druga najkrotsza sciezka w poddrzewie}
    auto comb = [&](T a, T b){
        if (a.first > b.first) swap(a, b); 
        //a.first <= b.first
        return T{min(a.first, b.first), min({b.second, a.second, max(a.first, b.first)})};
    };
    vector<vector<T>>pref(n+1);
    vector<vector<T>>suf(n+1);
    int ans = 1;
    function<void(int, int)>dfs = [&](int v, int pa){
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            dp[v] = comb(dp[v], dp[x]);
        }
        auto &L = pref[v];
        auto &R = suf[v];
        int s = (int)g[v].size();
        L.assign(s, {oo, oo});
        R.assign(s, {oo, oo});
        for (int i = 0; i<s; i++){
            if (i) L[i] = L[i-1];
            if (g[v][i] != pa) L[i] = comb(L[i], dp[g[v][i]]);
        }
        for (int i = s-1; i>=0; i--){
            if (i < s-1) R[i] = R[i+1];
            if (g[v][i] != pa) R[i] = comb(R[i], dp[g[v][i]]);
        }
        // debug(v, L, R);
        if (dp[v].first > oo2) dp[v].first = 0;
        dp[v].first++;
    };
    function<void(int, int, int)>up = [&](int v, int pa, int idx){
        if (pa != v){
            dp2[v] = dp2[pa];
            if (idx) dp2[v] = comb(dp2[v], pref[pa][idx-1]);
            if (idx < (int)g[pa].size()-1) dp2[v] = comb(dp2[v], suf[pa][idx+1]);
            
            if (dp2[v].first > oo2) dp2[v].first = 1;
            else dp2[v].first++;
            T curr = comb(dp2[v], pref[v].back());
            
            curr.first++;
            debug(v, pref[v].back(), dp2[v], curr);
            ans = max(ans, min(curr.first, curr.second));
        } 
        int c = 0;
        for (auto x: g[v]){
            if (x != pa) up(x, v, c);
            c++;
        }
    };
    dfs(1, 1);
    ans = max(ans, min(dp[1].first, dp[1].second));
    up(1, 1, 0);    
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