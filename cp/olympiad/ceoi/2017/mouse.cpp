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
    int n, t, m;
    cin >> n >> t >> m;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>dp(n+1), par(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        par[v] = pa;
        int mx = 0, mx2 = 0;
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            if (dp[x] >= mx){
                mx2 = mx;
                mx = dp[x];
            } else if (dp[x] >= mx2) {
                mx2 = dp[x];
            }
        }
        dp[v] = (int)g[v].size() - (v == t ? 0 : 1) + mx2;
    };
    dfs(t, t);
    debug(dp);
    int u = m;
    vector<int>path(n+1);
    while (1){
        path[u] = 1;
        if (u == par[u]) break;
        u = par[u];
    }
    vector<int>deg(n+1);
    for (int i = 1; i<=n; i++){
        for (auto x: g[i]){
            if (par[x] == i && !path[x]){
                deg[i]++; //ile wierzcholkow zbacza
            }
        }
    }
    auto check = [&](int mid){
        int v = m;
        int sum = 0;
        while (1){
            sum += deg[v];
            v = par[v];
            if (v == par[v]) break;
        }
        if (sum > mid) return false;
        v = m;
        int block = 0, need = 0;
        while (1){
            block++;
            int dont_care = 0;
            //rozwazyc zboczenie w dol w v
            for (auto x: g[v]){
                if (path[x]) continue;
                if (dp[x] + sum > mid) need++;
                else dont_care++;
            }
            sum -= dont_care; //slonik will win in mid moves anyway
            if (block < need) return false;
            v = par[v];
            if (v == par[v]) break;
        }
        return true;
    };
    int L = 0, R = 2*n, ans = 2*n;
    while (R >= L){
        int mid = (L+R)/2;
        if (check(mid)) {
            ans = mid;
            R = mid-1;
        } else {
            L = mid+1;
        }
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