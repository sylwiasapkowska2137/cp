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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

int mul(int a, int b){
    return (a*b)%mod;
}

int add2(int a, int b){
    a += b;
    if (a >= mod) a-=mod;
    return a;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }    
    bool ok = 1;
    vector<int>r(n+1), depth(n+1), h(n+1, 1);
    for (int i = 1; i<=n; i++) r[i] = p(0, mod-1);
    function<void(int, int)>dfs = [&](int v, int pa){
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
            h[v] = mul(h[v], add2(r[depth[x]], h[x]));
        }
    };
    dfs(1, 1);
    function<void(int, int)>symm = [&](int v, int pa){
        set<int>s;
        for (auto x: g[v]){
            if (x == pa) continue;
            if (s.find(h[x]) != s.end()) s.erase(h[x]);
            else s.insert(h[x]);
        }
        if (s.size() >= 2) {
            ok = 0;
            return;
        }
        if (s.size() == 1){
            int c = *s.begin();
            for (auto x: g[v]){
                if (x == pa) continue;
                if (h[x] == c){
                    //is x a symmetry??
                    symm(x, v);
                } 
            }
        }
    };
    symm(1, 1);
    cout << (ok ? "YES\n" : "NO\n");
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