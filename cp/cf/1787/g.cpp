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

struct Tree{
    vector<T>tab;
    vector<int> lazy;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, {oo, oo});
        lazy.assign(2*size, 0);
    }

    void set(int x, int lx, int rx, int pos, T val){
        if (lx == rx) {
            tab[x] = val;
            return;
        }
        int m = (lx+rx)/2;
        if (pos <= m) set(2*x, lx, m, pos, val);
        else set(2*x+1, m+1, rx, pos, val);
        tab[x] = min(tab[2*x], tab[2*x+1]);
    }

    void push(int x, int lx, int rx){
        if (!lazy[x] || lx == rx) return;
        tab[2*x].first += lazy[x];
        tab[2*x+1].first += lazy[x];
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        push(x, lx, rx);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tab[x].first += v;
            lazy[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        update(2*x, lx, m, l, r, v);
        update(2*x+1, m+1, rx, l, r, v);
        tab[x] = min(tab[2*x], tab[2*x+1]);
    }

    T query(int x, int lx, int rx, int l, int r){
        push(x, lx, rx);
        if (lx > r || rx < l) return {oo, oo};
        if (lx >= l && rx <= r) return tab[x];
        int m = (lx+rx)/2;
        return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>>g(n+1);
    vector<vector<tuple<int, int, int>>>edges(n+1);
    for (int i = 1; i<n; i++){
        int a, b, w, c; cin >> a >> b >> w >> c;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        edges[c].emplace_back(a, b, w);
    }
    vector<tuple<int, int, int>>rep;
    vector<int>deg(n+1), leaf, depth(n+1), high(n+1), par(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        par[v] = pa;
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
        }
    };
    auto lca = [&](int a, int b){
        while (a != b){
            if (depth[a] > depth[b]) swap(a, b);
            b = par[b];
        }
        return a;
    };
    dfs(1, 1);
    for (int c = 1; c <= n; c++){
        int sum = 0;
        for (auto &[a, b, w]: edges[c]){
            if (depth[a] < depth[b]) swap(a, b);
            high[a] = c;
            deg[a]++; deg[b]++;
            sum += w;
        }
        leaf.clear();
        for (auto [a, b, w]: edges[c]){
            // debug(a, b, w);
            if (deg[a] == 1) leaf.emplace_back(a);
            if (deg[b] == 1) leaf.emplace_back(b);
            deg[a] = 0; deg[b] = 0;
        }
        // debug(c, leaf);
        if ((int)leaf.size() == 2){
            rep.emplace_back(lca(leaf[0], leaf[1]), c, sum);
        }
    }
    int m = (int)rep.size(), k = 0;
    stable_sort(rep.begin(), rep.end());
    vector<int>pos(n+1, -1), L(n+1, -1), R(n+1, -1);
    Tree t(n+2);
    for (auto [l, c, w]: rep){
        // debug(l, c, w);
        pos[c] = ++k;
        if (L[l] == -1) L[l] = k;
        R[l] = k;
        t.set(1, 0, t.size-1, k, {0, -w});
    }
    while (q--){
        int p, v; cin >> p >> v;
        int coef = (p ? -1 : 1);
        if (L[v] != -1) t.update(1, 0, t.size-1, L[v], R[v], coef);
        if (pos[high[v]] != -1) t.update(1, 0, t.size-1, pos[high[v]], pos[high[v]], coef);
        T curr = t.query(1, 0, t.size-1, 1, m);
        if (curr.first == 0) cout << -curr.second << "\n";
        else cout << "0\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}