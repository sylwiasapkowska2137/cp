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
const int oo = 1e18, oo2 = 1e9+7, K = 20;
const int mod = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<T>>g(n+1);
    vector<T>edges;
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
        g[a].emplace_back(b, i+n+1);
        g[b].emplace_back(a, i+n+1);
    }
    vector<int>vis(n+1), depth(n+1), up(n+1, -1), down(n+1, -1), cycle(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        vis[v] = 1;
        for (auto [x, i]: g[v]){
            if (x == pa) continue;
            if (!vis[x]){
                depth[x] = depth[v]+1;
                dfs(x, v);
            } else {
                if (depth[x] < depth[v]){
                    debug(x, v);
                    up[v] = i;
                    down[x] = i; 
                }
            }
        }
    }; dfs(1, 1);
    vis.assign(n+1, 0);
    function<void(int, int)>visit = [&](int v, int pa){
        vis[v] = 1;
        for (auto [x, i]:g[v]){
            if (x == pa) continue;
            if (!vis[x]){
                visit(x, v);
            }
        }
        if (up[v] != -1){
            cycle[v] = up[v];
        } else {
            cycle[v] = v;
            for (auto [x, i]: g[v]){
                if (depth[x] > depth[v]){
                    if (cycle[x] != x && down[x] == -1){ //jesli cycle[x] == x, to poprzedni wierzcholek byl punktem artykulacji, jesli istnieje krawedz niedrzewowa skierowana w dół z x, to w tym momencie przechodzimy z jednego "duzego" wierzcholka do drugiego (most????)
                        cycle[v] = cycle[x];
                    }
                }
            }
        } 
    }; visit(1, 1);
    debug(cycle);
    vector<int>s = cycle;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    int N = s.size()-1;
    vector<int>bad(N+1), cnt(N+1);
    vector<vector<int>>G(N+1), jump(N+1, vector<int>(K));
    for (int i = 1; i<=n; i++) cycle[i] = lower_bound(s.begin(), s.end(), cycle[i])-s.begin();
    
    for (int i = 1; i<=n; i++) {
        cnt[cycle[i]]++;
        if (cnt[cycle[i]] > 1) bad[cycle[i]] = 1;
    }
    debug(bad);
    for (auto [a, b]: edges){
        if (cycle[a] != cycle[b]){
            G[cycle[a]].emplace_back(cycle[b]);
            G[cycle[b]].emplace_back(cycle[a]);
            debug(cycle[a], cycle[b]);
        }
    }
    depth.assign(N+1, 0);
    function<void(int, int)>DFS = [&](int v, int pa){
        jump[v][0] = pa;
        for (int i = 1; i<K; i++) jump[v][i] = jump[jump[v][i-1]][i-1];
        for (auto x: G[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            bad[x] += bad[v];
            DFS(x, v);
        }
    }; DFS(1, 1);
    debug(bad);
    auto lca = [&](int a, int b){
        if (depth[a] < depth[b]) swap(a, b);
        for (int i = K-1; i>=0; i--){
            if (depth[a] - (1<<i) >= depth[b]){
                a = jump[a][i];
            }
        }
        if (a == b) return a;
        for (int i = K-1; i>=0; i--){
            if (jump[a][i] != jump[b][i]){
                a = jump[a][i];
                b = jump[b][i];
            }
        }
        return jump[a][0];
    };

    vector<int>p(2*N+3);
    p[0] = 1;
    for (int i = 1; i<(int)p.size(); i++) p[i] = (p[i-1] * 2LL)%oo2;
    int q; cin >> q;
    while (q--){
        int a, b; cin >> a >> b;
        a = cycle[a]; b = cycle[b];
        int l = lca(a, b);
        debug(a, b, l);
        int pp = bad[a] + bad[b] - 2*bad[l];
        if (cnt[l] > 1) pp++;
        debug(pp);
        cout << p[pp] << "\n";
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