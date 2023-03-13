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
    int n, k; cin >> n >> k;
    vector<int>a(n+1);
    vector<vector<int>>g(n+1);
    int X = 0;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        X ^= a[i];
    }
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    if (X == 0) {
        cout << "YES\n";
        return;
    }
    if (k == 2){
        cout << "NO\n";
        return;
    }
    vector<int>sub(n+1);
    vector<int>is_x(n+1);
    bool ans = 0;
    function<void(int, int)>dfs = [&](int v, int pa){
        sub[v] = a[v];
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            is_x[v] += (is_x[x] ? 1 : 0);
            sub[v] ^= sub[x];
        }
        
        if (sub[v] == 0 && is_x[v]) ans = 1;
        if (is_x[v] > 1)  ans = 1;
        if (sub[v] == X) is_x[v]++;
    };
    dfs(1, 1);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}