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
    int n, m; cin >> n >> m;
    vector<vector<T>>g(n+1);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    int k; cin >> k;
    vector<int>bad(m);
    for (int i = 0; i<k; i++){
        int x; cin >> x;
        bad[x-1] = 1;
    }
    
    vector<int>vis(n+1);
    int c = 1, r = 1;
    function<void(int)>dfs = [&](int v){
        vis[v] = c;
        for (auto [x, i]: g[v]){
            if (!bad[i] && !vis[x]){
                dfs(x);
            }
        }
    };
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            dfs(i);
            c++;
        }
    }
    debug(vis);
    vector<vector<T>>G(n+1);
    for (int v = 1; v<=n; v++) {
        for (auto [x, i]: g[v]){
            if (vis[x] != vis[v] && bad[i]){
                G[vis[x]].emplace_back(vis[v], i);
                debug(x, v);
                r = vis[x];
            }
        }
    }
    int odd = 0;
    for (int i = 1; i<=n; i++){
        if ((int)G[i].size()&1){
            odd++;
        }
    }
    if (odd <= 2) cout << "Yes\n";
    else cout << "No\n";
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