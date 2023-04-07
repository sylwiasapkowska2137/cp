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
const int mod = 998244353;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = 10000;
    cout << n << "\n";
    vector<vector<int>>g(n+1);
    for (int i = 2; i<=n; i++){
        // int x = p(1, i-1);
        int x = i-1;
        g[x].emplace_back(i);
        cout << x << " ";
    }
    vector<vector<int>>up(n+1, vector<int>(K));
    vector<int>depth(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        up[v][0] = pa;
        for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
        for (auto x: g[v]){
            depth[x] = depth[v]+1;
            dfs(x, v);
        }
    };
    dfs(1, 1);
    auto lca = [&](int a, int b){
        if (depth[a] < depth[b]) swap(a, b);
        for (int i = K-1; i>=0; i--){
            if (depth[a] - (1<<i) >= depth[b]){
                a = up[a][i];
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

    auto dist = [&](int a, int b){
        return depth[a] + depth[b] - 2*depth[lca(a, b)];
    }; 
    cout << "\n";
    for (int i = 1; i<=n; i++){
        int a = p(1, 10);
        int b = p(1, 10);
        if (a > b) swap(a, b);
        cout << a << " " << b << "\n";
    }
    int q = p(1, 100);
    cout << q << "\n";
    while (q--){
        int a, b, c, d;
        while (1){
            a = p(1, n);
            b = p(1, n);
            c = p(1, n);
            d = p(1, n);
            if (dist(a, b) == dist(c, d)){
                break;
            }
        }
        cout << a << " " << b << " " << c << " " << d << "\n";
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