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
const int oo = 1e18, oo2 = 1e9+7, K = 19;

struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    int query(int l, int r){
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans += tab[l+1];
            if (r&1) ans += tab[r-1];
        }
        return ans;
    }

    void update(int x, int v){
        x += size;
        tab[x] += v;
        while (x){
            x/=2;
            tab[x] = tab[2*x] + tab[2*x+1];
        }
    }
};

void solve(){
    int n, M, q; cin >> n >> M >> q;  
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>ord(M+1);
    for (int i = 1; i<=M; i++) cin >> ord[i];
    vector<int>depth(n+1), pre(n+1);
    int tt = 0;
    vector up(n+1, vector<int>(K));
    function<void(int, int)>dfs = [&](int v, int pa){
        pre[v] = ++tt;
        up[v][0] = pa;
        for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
        }
    };
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
    dfs(1, 1);
    vector<T>p(q);
    Tree t(M+2);
    for (auto &[x, y]: p) cin >> x >> y;
    vector<int>ans(q);
    vector<vector<int>>which(n+1);
    vector<vector<T>>G(n+1);
    vector<int>X(n+1, -oo), Y(n+1, oo);
    for (int i = 1; i<=M; i++) which[ord[i]].emplace_back(i);
    function<void(int, int, vector<int>)>rec = [&](int l, int r, vector<int>que){
        if (l >= r || que.empty()) return;
        int m = (l+r)/2;
        vector<int>vt;
        for (int i = l; i<=r; i++) vt.emplace_back(ord[i]);
        sort(vt.begin(), vt.end(), [&](auto x, auto y){return pre[x] < pre[y];});
        int s = (int)vt.size();
        for (int i = 1; i<s; i++) vt.emplace_back(lca(vt[i-1], vt[i]));
        sort(vt.begin(), vt.end());
        vt.erase(unique(vt.begin(), vt.end()), vt.end());
        sort(vt.begin(), vt.end(), [&](auto x, auto y){return pre[x] < pre[y];});
        debug(vt);
        int sum = 0;
        auto add_edge = [&](int a, int b, int c){
            if (a == b) return;
            // cerr << a << " " << b << " " << c << "\n";
            G[a].emplace_back(b, c);
            G[b].emplace_back(a, c);
            sum += c;
        };
        vector<tuple<int, int, int>>sweep;
        function<void(int, int, int)>dfessa = [&](int v, int pa, int d){
            for (auto i: which[v]){
                if (i <= m) X[v] = max(X[v], i);
                if (i >= m) Y[v] = min(Y[v], i);
            }
            for (auto [x, c]: G[v]){
                if (x == pa) continue;
                dfessa(x, v, c);
                X[v] = max(X[v], X[x]);
                Y[v] = min(Y[v], Y[x]);
            }
            if (d != oo) {
                // debug(v, X[v]+1, Y[v]-1);
                if (X[v] + 1 <= Y[v]-1) {
                    sweep.emplace_back(X[v]+1, Y[v]-1, d);
                }
            }
        };
        for (int i = 0; i<(int)vt.size(); i++){
            int prev = vt[(i == 0 ? (int)vt.size()-1 : i-1)];
            int ll = lca(vt[i], prev);
            add_edge(vt[i], ll, depth[vt[i]] - depth[ll]);
        }
        for (auto v: vt) {
            X[v] = l-1;
            Y[v] = r+1;
        }
        debug(l, r, m, ord[m]);
        dfessa(ord[m], ord[m], oo);
        for (auto v: vt) {
            G[v].clear();
            Y[v] = oo;
            X[v] = -oo;
        }
        vector<int>L, R;
        for (auto i: que){
            if (p[i].first > m) R.emplace_back(i);
            else if (p[i].second < m) L.emplace_back(i);
            else sweep.emplace_back(p[i].first, p[i].second, -i);
        }
        
        sort(sweep.begin(), sweep.end(), [&](auto x, auto y){
            auto [x1, y1, c1] = x;
            auto [x2, y2, c2] = y;
            return y1 == y2 ? x1 == x2 ? c1 > c2 : x1 < x2 : y1 > y2;
        });
        for (auto [x, y, c]: sweep){
            debug(x, y, c);
            if (c > 0){
                t.update(x, c);
            } else {
                ans[-c] = sum - t.query(0, x);
            }
        }
        for (auto [x, y, c]: sweep){
            if (c > 0){
                t.update(x, -c);
            }
        }
        rec(l, m-1, L);
        rec(m+1, r, R);
    };
    vector<int>all(q);
    iota(all.begin(), all.end(), 0);
    rec(1, M, all);
    for (int i = 0; i<q; i++) cout << ans[i]+1 << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}