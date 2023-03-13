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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
int n;

struct Reach{
    vector<int>rep, pre, vis, post;
    vector<vector<int>>g;
    int cnt, tt = 0;

    Reach(){
        cnt = n+1;
        pre.assign(2*n+1, 0);
        post.assign(2*n+1, 0);
        rep.assign(2*n+1, 0);
        g.resize(2*n+1);
        iota(rep.begin(), rep.end(), 0);
    }

    int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}

    void u(int a, int b){
        a = f(a);b = f(b);
        if (a == b) return;
        rep[a] = cnt;
        rep[b] = cnt;
        g[cnt].emplace_back(a);
        g[cnt].emplace_back(b);
        cnt++;
    }

    void dfs(int v){
        vis[v] = 1;
        pre[v] = ++tt;
        for (auto x: g[v]) dfs(x);
        post[v] = ++tt;
    }

    void init(){
        vis.assign(cnt+1, 0);
        for (int i = cnt-1; i>=1; i--){
            if (!vis[i]){
                dfs(i);
            }
        }
    }
};

struct Tree{
    vector<T>tab;
    int size = 1;

    Tree(int nn){
        while (size < nn) size*=2;
        tab.resize(2*size);
    }

    void update(int x, T v){
        x += size;
        tab[x] = v;
        while (x){
            x/=2;
            tab[x] = max(tab[2*x], tab[2*x+1]);
        }
    }

    T query(int l, int r){
        T ans = {0, 0};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }
};

void solve(){
    int m, q; cin >> n >> m >> q;
    vector<int>p(n+1);
    for (int i = 1; i<=n; i++) cin >> p[i];
    vector<T>edges;
    for (int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
    }
    vector<int>used(m);
    vector<T>que;
    Reach tree;
    for (int i = 0; i<q; i++) {
        int t, v; cin >> t >> v;
        if (t == 2) used[--v] = 1;
        que.emplace_back(t, v);
    }
    for (int i = 0; i<m; i++) {
        if (!used[i]){
            tree.u(edges[i].first, edges[i].second);
        }
    }
    vector<int>id(q, -1);
    for (int i = q-1; i>=0; i--){
        auto [a, b] = que[i];
        if (a == 2) tree.u(edges[b].first, edges[b].second);
        else id[i] = tree.f(b);
    }
    tree.init();
    Tree t(4*n+3);
    for (int i = 1; i<=n; i++) {
        t.update(tree.pre[i], {p[i], tree.pre[i]});
    }
    for (auto x: id){
        if (x == -1) continue;
        T now = t.query(tree.pre[x], tree.post[x]);
        cout << now.first << "\n";
        t.update(now.second, {0, 0});
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}