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
const int mod = 1e9+7;

int mul(int a, int b){
    return (a*b)%mod;
}

int power(int a, int b){
    if (!b) return 1LL;
    int k = power(a, b/2);
    k = mul(k, k);
    if (b&1) k = mul(k, a);
    return k;
}

void sub(int &a, int b){
    a -= b;
    if (a < 0) a+=mod;
}

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

void solve(){
    int n; cin >> n;
    vector<int>f(n+1), finv(n+1);
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    } 
    /*
    f[0] = 1;
    finv[0] = 1;
    for (int i = 1; i<=n; i++){
        f[i] = mul(f[i-1], i);
        finv[i] = power(f[i], mod-2);
    }
    auto nck = [&](int n, int k){
        if (n < 0 || k < 0 || k > n) return 0;
        return mul(f[n], mul(finv[k], finv[n-k]));
    };
    */
    auto sum = [&](int x){
        return power(2, x-1);
    };
    vector<int>depth(n+1), cnt(n+1);
    vector<map<int, int>>d(n+1);
    vector<int>pot(n+1);
    pot[0] = 1;
    for (int i = 1; i<=n; i++) pot[i] = mul(pot[i-1], 2);
    auto change = [&](int v, int where, int ile){
        if (d[v][where]) sub(cnt[v], pot[d[v][where]-1]);
        d[v][where] += ile;
        add(cnt[v], pot[d[v][where]-1]);
    };
    function<void(int, int)>dfs = [&](int v, int pa){
        int sz = -1, big = -1;
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
            if ((int)d[x].size() >= sz){
                sz = (int)d[x].size();
                big = x;
            }
        }
        if (big == -1) {
            change(v, depth[v], 1);
            cnt[v]--;
            return;
        }
        d[v].swap(d[big]);
        add(cnt[v], cnt[big]);
        change(v, depth[v], 1);
        cnt[v]--;
        for (auto x: g[v]){
            if (x == pa || x == big) continue;
            for (auto &[cd, ile]: d[x]){
                change(v, cd, ile);
            }
        }
        debug(v, d[v]);
    };
    dfs(1, 1);
    debug(cnt);
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