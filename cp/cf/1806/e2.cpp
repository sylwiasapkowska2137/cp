//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using namespace __gnu_pbds;
 
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
const int oo = 1e18, oo2 = 1e9+7, K = 18;
const int s = 500;
 
struct chash { // large odd number for C
    const uint64_t C = (int64_t)(4e18 * acos(0)) | 71;
    int64_t operator()(int64_t x) const { return __builtin_bswap64(x * C); }
};
void solve(){
    int n, q; cin >> n >> q;
    vector<int>a(n+1), par(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<vector<int>>g(n+1);
    for (int i = 2; i<=n; i++){
        cin >> par[i];
        g[par[i]].emplace_back(i);
    }
    vector<int>depth(n+1), sum(n+1);
    function<void(int)>dfs = [&](int v){
        sum[v] += sum[par[v]];
        sum[v] += a[v] * a[v];
        for (auto x: g[v]){
            if (x == par[v]) continue;
            depth[x] = depth[v]+1;
            dfs(x);
        }
    };
    dfs(1);
    gp_hash_table<long long, long long, chash> cnt({},{},{},{},{1<<25});
    while (q--){
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        if (cnt.find((x<<32)+y) != cnt.end()){
            cout << cnt[(x<<32)+y] << "\n";
            continue;
        }
        int curr = 0;
        int X = x, Y = y;
        bool ok = 0;
        while (x != y){
            if (x > y) swap(x, y);
            if (cnt.find((x<<32)+y) != cnt.end()){
                curr += cnt[(x<<32)+y];
                ok = 1;
                break;
            }
            curr += a[x] * a[y];
            x = par[x];
            y = par[y];
        }
        if (!ok) curr += sum[x];
        x = X;
        y = Y;
        cout << curr << "\n";
        while (x != y){
            if (x > y) swap(x, y);
            if (cnt.find((x<<32)+y) != cnt.end()){
                break;
            }
            cnt[(x<<32)+y] = curr;
            curr -= a[x] * a[y];
            x = par[x];
            y = par[y];
        }       
    }
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