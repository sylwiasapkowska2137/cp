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

set<T>s;

struct DSU{
    vector<int>rep, sz;
    vector<bool>ans;
    vector<vector<int>>tab;

    void clear(int v){
        v = f(v);
        debug(v, tab[v]);
        for (auto x: tab[v]){
            ans[x] = 0;
        }
        tab[v].clear();
    }

    DSU(int n, vector<int>&a){
        rep.assign(n+1, 0);
        tab.resize(n+1);
        ans.assign(n+1, 1);
        for (int i = 1; i<=n; i++) tab[i].emplace_back(i);
        iota(rep.begin(), rep.end(), 0);
        sz = a;
    }

    int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}

    bool u(int a, int b){
        a = f(a);b = f(b);
        if (a == b) return 0;
        if ((int)tab[a].size() < (int)tab[b].size()) swap(a, b);
        s.erase({sz[a], a});
        s.erase({sz[b], b});
        for (auto x: tab[b]) tab[a].emplace_back(x);
        tab[b].clear();
        sz[a] += sz[b];
        rep[b] = a;
        s.insert({sz[a], a});
        return 1;
    }

};

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n+1);
    map<int, vector<int>>event;
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        event[a[i]].emplace_back(i);
    }
    vector<T>edges;
    vector<vector<int>>g(n+1);
    for (int i = 0; i<m; i++) {
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    sort(edges.begin(), edges.end(), [&](auto x, auto y){
        return max(a[x.first], a[x.second]) < max(a[y.first], a[y.second]);
    });
    DSU dsu(n+2, a);
    int ptr = -1;
    vector<int>b = a;
    sort(b.begin(), b.end());
    for (auto [w, curr]: event){
        for (auto v: curr) s.insert({dsu.sz[v], v});
        while (ptr+1 < (int)edges.size() && max(a[edges[ptr+1].first], a[edges[ptr+1].second]) <= w) {
            ptr++;
            debug(edges[ptr]);
            dsu.u(edges[ptr].first, edges[ptr].second);
        }
        debug(w);
        if (b.back() == w) break;
        int nxt = b[upper_bound(b.begin(), b.end(), w) - b.begin()];
        debug(w, nxt);
        while ((int)s.size() && s.begin()->first < nxt){
            int v = s.begin()->second;
            debug(v);
            s.erase(s.begin());
            dsu.clear(v);
        }
    }
    for (int i = 1; i<=n; i++) cout << (dsu.ans[i] ? 1 : 0);
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}