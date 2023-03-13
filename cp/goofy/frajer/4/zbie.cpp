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
const int oo = 6969, oo2 = 1e9+7, K = 30;
#warning oo
const int mod = 998244353;

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<T>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    vector<int>sz(n+1), used(n+1);
    function<int(int, int)>dfsz = [&](int v, int pa){
        sz[v] = 1;
        for (auto [x, c]: g[v]){
            if (x == pa || used[x]) continue;
            sz[v] += dfsz(x, v);
        }
        return sz[v];
    };
    function<int(int, int, int)>find_centro = [&](int v, int pa, int ms){
        for (auto [x, c]: g[v]){
            if (x == pa || used[x]) continue;
            if (2*sz[x] > ms) return find_centro(x, v, ms);
        }
        return v;
    };
    vector<int>to_clear;
    vector<int>depth(n+1);
    vector<T>best(n+1, {-oo, -oo}), second(n+1, {-oo, -oo});
    int mx = -1;
    auto merge = [&](int where, T b){
        //porownac z best i second
        // debug(where, b, best[where], second[where]);
        if (b.first >= best[where].first){
            if (b.second == best[where].first){
                best[where].first = b.first;
            } else {
                second[where] = best[where];
                best[where] = b;
            }
        } else{ //b.first < best[where].first
            if (b.first >= second[where].first && b.second != best[where].second){
                second[where] = b; 
            }
        }
        // debug(best[where], second[where]);
    };
    function<void(int, int, int, int)>depth_dfs = [&](int v, int pa, int d, int from){
        to_clear.emplace_back(v);
        mx = max(mx, d);
        for (auto [x, c]: g[v]){
            if (x == pa || used[x]) continue;
            depth[x] = depth[v]+c;
            merge(d+1, {depth[x], from});
            depth_dfs(x, v, d+1, from);
        }
    };
    int ans = 0;
    function<void(int)>centroid = [&](int v){
        v = find_centro(v, v, dfsz(v, v));
        debug(v);
        mx = -1;
        to_clear = {v};
        best[0] = {0, v};
        for (auto [x, c]: g[v]){
            merge(1, {c, x});
            depth[x] = c;
            depth_dfs(x, v, 1, x);
        }
        debug(best);
        debug(second);
        
        exit(0);
        for (auto x: to_clear){
            depth[x] = 0;
        }
        to_clear.clear();
        for (int i = 1; i<=mx; i++) {
            best[i] = {-oo, -oo};
            second[i] = {-oo, -oo};
        }
        used[v] = 1;
        for (auto [x, c]: g[v]){
            if (!used[x]){
                centroid(x);
            }
        }
    };
    centroid(1);
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