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
    vector d(n+1, vector<int>(n+1));
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    function<void(int, int, int)>dfs = [&](int v, int pa, int from){
        for (auto x: g[v]){
            if (x == pa) continue;
            d[from][x] = d[from][v]+1;
            dfs(x, v, from);
        }
    };

    for (int i = 1; i<=n; i++) dfs(i, i, i);

    vector<int>p(n);
    iota(p.begin(), p.end(), 1);
    vector<int>mn;
    int ans = oo;
    do{
        bool bad = 0;
        for (int i = 0; i<n; i++){
            if (p[i] == i+1){
                bad = 1;
                break;
            }
        }
        if (bad) continue;
        int curr = 0;
        for (int i = 0; i<n; i++){
            curr += d[i+1][p[i]];
        }
        if (curr < ans){
            ans = curr;
            mn = p;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << "\n";
    debug(mn);
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