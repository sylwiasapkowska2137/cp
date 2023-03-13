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
#ifndef DEBUG
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
    auto mul = [&](int a, int b){
        return (a*b)%m;
    };
    function<int(int, int)>power = [&](int a, int b){
        if (!b) return 1LL;
        int k = power(a, b/2);
        k = mul(k, k);
        if (b&1) k = mul(k, a);
        return k;;
    };
    struct edge{
        int a, b, c;
        edge(){}
        edge(int _a, int _b, int _c){a = _a, b = _b, c = _c;}
    };
    vector<edge>edges;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=n; i++){
        for (int j = i+1; j<=n; j++){
            int c = (power(a[i], a[j]) + power(a[j], a[i]))%m;
            if (c < 0) c += m;
            edges.emplace_back(i, j, c);
        }
    }
    sort(edges.begin(), edges.end(), [](auto x, auto y){return x.c > y.c;});
    struct UF{
        vector<int>rep, sz;
        int s;

        UF(int n){
            s = n;
            rep.assign(n+1, 0);
            iota(rep.begin(), rep.end(), 0);
            sz.assign(n+1, 1);
        }    

        int f(int a){
            return rep[a] == a ? a : rep[a] = f(rep[a]); 
        }

        bool u(int a, int b){
            a = f(a); b = f(b);
            if (a == b) return 0;
            if (sz[a] < sz[b]) swap(a, b);
            sz[a] += sz[b];
            rep[b] = a;
            return 1;
        }
    } dsu(n+2);
    int ans = 0;
    for (auto [a, b, c]: edges){
        if (dsu.u(a, b)){
            ans += c;
        }
    }
    cout << ans << "\n";
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