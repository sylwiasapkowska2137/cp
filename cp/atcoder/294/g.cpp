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

struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    void update(int x, int v){
        x += size;
        tab[x] = v;
        while (x){
            x/=2;
            tab[x] = tab[2*x] + tab[2*x+1];
        }
    }

    int query(int l, int r){
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans += tab[l+1];
            if (r&1) ans += tab[r-1];
        }
        return ans;
    }
};

void solve(){
    int n; cin >> n;
    vector<vector<T>>g(n+1);
    vector<T>edges;
    vector<int>C;
    for (int i = 1; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        edges.emplace_back(a, b);
        C.emplace_back(c);
    }
    vector<int>depth(n+1), pre(n+1), post(n+1);
    int tt = 0;
    vector up(n+1, vector<int>(K));
    function<void(int, int)>dfs = [&](int v, int pa){
        pre[v] = ++tt;
        up[v][0] = pa;
        for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
        for (auto [x, c]: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
        }
        post[v] = ++tt;
    };
    dfs(1, 1);
    auto lca = [&](int a, int b){
        if (depth[a] > depth[b]) swap(a, b);
        for (int i = K-1; i>=0; i--){
            if (depth[b] - (1<<i) >= depth[a]){
                b = up[b][i];
            }
        }
        if (a == b) return a;
        for (int i = K-1; i>=0; i--){
            if (up[a][i] != up[b][i]){
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };

    Tree t(2*n+2);

    auto update = [&](int i, int w){
        auto [a, b] = edges[i-1];
        if (depth[a] > depth[b]) swap(a, b);
        //b glebiej;
        debug(b, w);
        t.update(pre[b], w);
        t.update(post[b], -w);
    };
    for (int i = 0; i<(int)C.size(); i++){
        update(i+1, C[i]);
    }
    auto query = [&](int a, int b){
        int l = lca(a, b);
        cout << t.query(0, post[a]-1) + t.query(0, post[b]-1) - 2 * t.query(0, post[l]-1) << "\n";
    };
    int q; cin >> q;
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int i, w; cin >> i >> w;
            update(i, w);
        } else {
            int a, b; cin >> a >> b;
            query(a, b);
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