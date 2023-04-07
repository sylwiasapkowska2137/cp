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

void solve(){
    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = 0;
    vector<int>mn(n+1);
    iota(mn.begin(), mn.end(), 0);
    vector<int>sub(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        sub[v] = 1;
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            sub[v] += sub[x];
        }
        if (mn[v] == v) {
            swap(mn[v], mn[pa]);
            ans+=2;
        }
    };
    dfs(1, 1);
    if (mn[1] == 1) {
        swap(mn[1], mn[g[1][0]]);
    }
    for (int i = 1; i<=n; i++){
        if (mn[i] == i){
            assert(false);
        }
    }
    function<int(int, int)>get_centroid = [&](int v, int pa){
        for (auto x: g[v]){
            if (x == pa) continue;
            if (2*sub[x] > n) return get_centroid(x, v);
        }
        return v;
    };
    int c = get_centroid(1, 1);
    vector<vector<int>>sz(n+1);
    vector<int>depth(n+1);
    int ans2 = 0;
    function<void(int, int)>dfessa = [&](int v, int pa){
        sub[v] = 1;
        int mx = -1;
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfessa(x, v);
            sub[v] += sub[x];
            if (mx == -1 || sub[x] > sub[mx]){
                mx = x;
            }
        }
        ans2 += min(sub[v], n-sub[v]);
        if (v != c && mx != -1){
            swap(sz[v], sz[mx]);
            for (auto x: g[v]){
                if (x == pa || x == mx) continue;
                for (auto u: sz[x]) sz[v].emplace_back(u);
            }
        }
        sz[v].emplace_back(v);
    };
    debug(c);
    dfessa(c, c);
    sort(g[c].begin(), g[c].end(), [&](auto x, auto y){return sub[x] > sub[y];});
    for (auto x: g[c]){
        debug(x, sz[x]);
    }
    vector<int>mx(n+1);
    iota(mx.begin(), mx.end(), 0);
    priority_queue<T>pq;
    for (auto x: g[c]) pq.push({(int)sz[x].size(), x});
    for (int rep = 0; rep < 2; rep++){
        while (pq.size() >= 2){
            auto x = pq.top(); pq.pop();
            auto y = pq.top(); pq.pop();
            int a = sz[x.second].back();
            int b = sz[y.second].back();
            mx[a] = b;
            mx[b] = a;
            sz[x.second].pop_back();
            sz[y.second].pop_back();
            if (x.first > 1) pq.push({x.first-1, x.second});
            if (y.first > 1) pq.push({y.first-1, y.second});
        }
        pq.push({1, c});
    }
    if (n&1) {
        swap(mx[c], mx[g[c][0]]);
    }
    cout << ans << " " << 2*ans2 << "\n";
    for (int i = 1; i<=n; i++) cout << mn[i] << " ";
    cout << "\n";
    for (int i = 1; i<=n; i++) cout << mx[i] << " ";
    cout << "\n";
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