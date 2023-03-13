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
    int n; long long k; cin >> n >> k;
    vector<vector<int>>g(n+1);
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<n; i++){
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int>G(n+1);
    vector<T>dp(n+1, {-oo, -oo});
    vector<int>depth(n+1);
    vector<vector<T>>pref(n+1), suf(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        if (v != 1) dp[v] = T{a[v] - depth[v], -v};
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
            dp[v] = max(dp[v], dp[x]);
        }
        int s = (int)g[v].size();
        auto &L = pref[v];
        auto &R = suf[v];
        L.assign(s, {-oo, -oo});
        R.assign(s, {-oo, -oo});
        for (int i = 0; i<s; i++){
            if (i) L[i] = L[i-1];
            if (g[v][i] != pa) L[i] = max(L[i], dp[g[v][i]]);
        }
        for (int i = s-1; i>=0; i--){
            if (i < s-1) R[i] = R[i+1];
            if (g[v][i] != pa) R[i] = max(R[i], dp[g[v][i]]);
        }
    };
    function<void(int, int, int)>up = [&](int v, int pa, int idx){
        if (v != pa){
            dp[v] = T{dp[pa].first - 1, dp[pa].second};
            dp[v] = max(dp[v], T{a[pa] - 1, -pa});
            if (idx) {
                dp[v] = max(dp[v], T{pref[pa][idx-1].first + depth[v] - 2, pref[pa][idx-1].second});
            }
            if (idx < (int)g[pa].size()-1) {
                dp[v] = max(dp[v], T{suf[pa][idx+1].first + depth[v] - 2, suf[pa][idx+1].second});
            }
            T curr = max(T{pref[v].back().first + depth[v], pref[v].back().second}, dp[v]);
            debug(v, pref[v].back(), dp[v], curr);
            G[v] = -curr.second;
        }
        int c = 0;
        for (auto x: g[v]){
            if (x != pa) up(x, v, c);
            c++;
        }
    };
    dfs(1, 1);
    G[1] = -dp[1].second;
    dp.assign(n+1, {-oo, -oo});
    up(1, 1, 0);
    debug(G);
    vector<int>prev(n+1, -1), D(n+1);
    function<void(int)>dfs2 = [&](int v){
        if (D[v] == k){
            cout << v << "\n";
            exit(0);
        }
        int x = G[v];
        if (prev[x] != -1){
            debug(v, x, D[x], D[v]);
            vector<int>cycle;
            int u = v;
            while (u != x){
                cycle.emplace_back(v);
                u = prev[u];
            }
            cycle.emplace_back(x);
            reverse(cycle.begin(), cycle.end()); //cycle[0] -> D[x], chcemy k
            k -= D[x];
            k %= (int)cycle.size();
            debug(cycle);
            cout << cycle[k] << "\n";
            exit(0);
        }
        D[x] = D[v]+1;
        prev[x] = v;
        dfs2(x);
    };
    prev[1] = 1;
    dfs2(1);
    assert(false);
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