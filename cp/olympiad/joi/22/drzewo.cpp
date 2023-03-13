//Sylwia Sapkowska
#include <bits/stdc++.h>
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
const int oo = 1e18, oo2 = 1e9+7, K = 41;
const int mod = 998244353;

void solve(){
    int n, L; cin >> n >> L;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<int>par(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        par[v] = pa;
        for (auto x: g[v]){
            if (x != pa){
                dfs(x, v);
            }
        }
    };
    dfs(1, -1);
    int q; cin >> q;
    vector<vector<int>>what(n+1, vector<int>(K, 1));
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int v, d, w; cin >> v >> d >> w;
            for (int i = d; i >= 0 && v != -1; i--){
                what[v][i] = (what[v][i]*w)%L;
                v = par[v];
            }
        } else {
            int v; cin >> v;
            int ans = a[v], i;
            for (i = 0; i<K && par[v] != -1; i++){
                ans = (ans*what[v][i])%L;
                if (i + 1 < K) ans = (ans*what[v][i+1])%L;
                v = par[v]; 
            }
            while (i < K) ans = (ans*what[v][i++])%L;
            if (ans < 0) ans += L;
            cout << ans << "\n";
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