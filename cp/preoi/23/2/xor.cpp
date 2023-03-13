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

//nowa reprezentacja -> liczby na wierzcholkach, takie ze ich xor to waga krawedzi
//operacja -> swap dwoch liczb z wierzcholkow wzdluz krawedzi
//bity sa niezalezne (wowww)

void solve(){
    int n; cin >> n;
    vector<vector<tuple<int, int, int>>>g(n+1);
    for (int i = 1; i<n; i++){
        int x, y, a, b; cin >> x >> y >> a >> b;
        g[x].emplace_back(y, a, b);
        g[y].emplace_back(x, a, b);
    }
    vector<int>x(n+1), y(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        for (auto &[u, a, b]: g[v]){
            if (u == pa) continue;
            x[u] = x[v] ^ a;
            y[u] = y[v] ^ b;
            dfs(u, v);
        }
    };
    dfs(1, 1);
    vector<int>X(K), Y(K);
    for (int i = 1; i<=n; i++){
        for (int b = 0; b < K; b++){
            if (x[i]&(1<<b)){
                X[b]++;
            }
        }
    }
    for (int i = 1; i<=n; i++){
        for (int b = 0; b < K; b++){
            if (y[i]&(1<<b)){
                Y[b]++;
            }
        }
    }
    for (int i = 0; i<K; i++){
        if (X[i] == Y[i]) continue;
        if (X[i] + Y[i] == n){
            x[1] += (1<<i);
        } else {
            cout << "NIE\n";
            exit(0);
        }
    }
    dfs(1, 1);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x == y) cout << "TAK\n";
    else cout << "NIE\n";
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