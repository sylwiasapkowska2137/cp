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
vector<T>edges;
vector<int>ans;

struct scccc{
    vector<vector<int>>g, gt;
    vector<int>post, valid, vis, numer;
    int curr = 0;

    void init(int N){
        g.resize(N);
        gt.resize(N);
        vis.assign(N, 0);
        numer.assign(N, 0);
    }

    void clear(){
        for (auto x: valid){
            vis[x] = 0;
            numer[x] = 0;
            g[x].clear();
            gt[x].clear();
        }
        post.clear();
        valid.clear();
    }

    void dfs(int v){
        vis[v] = 1;
        for (auto x: g[v]){
            if (!vis[x]){
                dfs(x);
            }
        }
        post.emplace_back(v);
    }

    void add(int a, int b){
        g[a].emplace_back(b);
        gt[b].emplace_back(a);
        valid.emplace_back(a);
        valid.emplace_back(b);
    }

    void dfs2(int v){
        vis[v] = 1;
        numer[v] = curr;
        for (auto x: gt[v]){
            if (!vis[x]){
                dfs2(x);
            }
        }
    }

    void scc(){
        curr = 0;
        for (auto x: valid){
            if (!vis[x]){
                dfs(x);
            }
        }
        reverse(post.begin(), post.end());
        for (auto v: post) vis[v] = 0;
        for (auto v: post){
            if (!vis[v]){
                curr++;
                dfs2(v);
            }
        }
    }
} scc;

int C2(int x){
    return x*(x-1)/2;
}

struct UF{
    vector<int>rep, indeg;
    int zero;

    void init(int n){
        zero = n;
        rep.assign(n+2, 0);
        indeg.assign(n+2, 0);
        iota(rep.begin(), rep.end(), 0);
    }

    int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}

    void add(int a, int v){
        a = f(a);
        if (indeg[a] == 0) zero--;
        indeg[a] += v;
        if (indeg[a] == 0) zero++;
    }

    bool u(int a, int b){
        a = f(a); b = f(b);
        if (a == b) return 0;
        if (!indeg[b]) zero--;        
        add(a, indeg[b]);
        rep[b] = a;
        return 1;
    }

    bool sameset(int a, int b){
        return f(a) == f(b);
    }
} dsu;

void rec(int l, int r, vector<int>&idx){
    if (l > r) return;
    if (l == r){
        dsu.add(edges[l].second, -1);
        for (auto i: idx){
            dsu.add(edges[i].second, 1);
            dsu.u(edges[i].first, edges[i].second);
            debug(dsu.indeg);
        }
        debug(l, idx, dsu.zero);
        ans[l] = dsu.zero;
        return;
    }
    int m = (l+r)/2;
    scc.clear();
    for (auto i: idx){
        if (i <= m){
            scc.add(dsu.f(edges[i].first), dsu.f(edges[i].second));
        }
    }
    scc.scc();
    vector<int>L, R;
    for (auto i: idx){
        if (i <= m && scc.numer[dsu.f(edges[i].first)] == scc.numer[dsu.f(edges[i].second)]){
            L.emplace_back(i);
        } else {
            R.emplace_back(i);
        }
    }
    rec(l, m, L);
    rec(m+1, r, R);
    L.clear();R.clear();
}

void solve(){
    int n, m; cin >> n >> m;
    scc.init(n+2);
    ans.resize(m+1);
    dsu.init(n);
    vector<T>now;
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        now.emplace_back(a, b);
    }
    vector<bool>deleted(m);
    int q; cin >> q;
    ans.resize(m+1);
    vector<int>que(q);
    for (int i = 0; i<q; i++){
        cin >> que[i];
        --que[i];
        deleted[que[i]] = 1;
    }
    for (int i = 0; i<m; i++) {
        if (!deleted[i]){
            que.emplace_back(i);
        }
    }
    reverse(que.begin(), que.end());
    for (auto x: que){
        edges.emplace_back(now[x]);
    }
    vector<int>idx(m);
    iota(idx.begin(), idx.end(), 0);
    rec(0, m, idx);
    reverse(ans.begin(), ans.end());
    debug(ans);
    for (int i = 2; i<=q+1; i++){
        if (i == m+1) cout << n << "\n";
        else cout << ans[i] << "\n";
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