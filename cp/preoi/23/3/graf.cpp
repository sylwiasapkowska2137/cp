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

struct UF{
    vector<int>rep, sz;
    int n;

    UF(int N){
        n = N;
        rep.assign(n+1, 0);
        sz.assign(n+1, 1);
        iota(rep.begin(), rep.end(), 0);
    }

    int f(int a){return rep[a] == a ? a : rep[a] = f(rep[a]);}
    bool u(int a, int b){
        a = f(a);b = f(b);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        rep[b] = a;
        sz[a] += sz[b];
        return 1;
    }
    bool sameset(int a, int b){
        return f(a) == f(b);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<T>edges;
    vector<vector<T>>g(n+1);
    vector<int>in(n+1);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
        g[a].emplace_back(b, i);
        in[b]++;
    }
    int q; cin >> q;
    vector<int>que(q);
    vector<bool>deleted(m);
    for (int i = 0; i<q; i++){
        cin >> que[i];
        --que[i];
        deleted[que[i]] = 1;
        in[edges[que[i]].second]--;
    }
    // debug(in);
    reverse(que.begin(), que.end());
    vector<int>ret;
    UF dsu(n+1);
    int ans = n;
    for (int i = 0; i<m; i++){
        if (!deleted[i]){
            if (dsu.u(edges[i].first, edges[i].second)){
                ans--;
            }
        }
    }
    debug(ans);
    for (auto idx: que){
        auto [a, b] = edges[idx];
        ret.emplace_back(ans);
        if (dsu.u(a, b)) ans--;
    }
    reverse(ret.begin(), ret.end());
    for (auto x: ret) cout << x << "\n";
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