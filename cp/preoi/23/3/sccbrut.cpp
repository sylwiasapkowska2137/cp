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
    vector<int>rep, sz;

    void init(int n){
        rep.assign(n, 0);
        sz.assign(n, 1);
        iota(rep.begin(), rep.end(), 0);
    }

    int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}

    bool u(int a, int b){
        a = f(a); b = f(b);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        rep[b] = a;
        return 1;
    }

    bool sameset(int a, int b){
        return f(a) == f(b);
    }
} dsu;

void rec(int l, int r, vector<int>&idx){
    if (l > r || idx.empty()) return;
    if (l == r){
        debug(l, idx);
        for (auto i: idx){
            if (dsu.sameset(edges[i].first, edges[i].second)) continue;
            int L = dsu.sz[dsu.f(edges[i].first)];
            int R = dsu.sz[dsu.f(edges[i].second)];
            ans[l] -= C2(L);
            ans[l] -= C2(R);
            dsu.u(edges[i].first, edges[i].second);
            L = dsu.sz[dsu.f(edges[i].second)];
            ans[l] += C2(L);
        }
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
    ans.resize(m);
    dsu.init(n+2);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
    }
    vector<int>idx(m);
    iota(idx.begin(), idx.end(), 0);
    rec(0, m-1, idx);
    debug(ans);
    for (int i = 1; i<m; i++) ans[i] += ans[i-1];
    for (int i = 0; i<m; i++) {
        cout << ans[i] << "\n";
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