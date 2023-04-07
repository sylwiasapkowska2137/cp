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
const int oo = 1e18, oo2 = 1e9+7, K = 5;
const int mod = 998244353;

void solve(){
    int n, k; cin >> n >> k;
    vector<int>a(k);
    for (int i = 0; i<k; i++) cin >> a[i];
    vector<vector<int>>g(n+1);
    vector<int>depth(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>par(n+1);
    function<void(int, int)>dfs = [&](int v, int pa){
        par[v] = pa;
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
        }
    };
    dfs(1, 1);
    vector<int>sum(n+1);
    bool ok = 1;
    int ans = oo;
    auto mark = [&](int a, int b){
        while (a != b){
            if (depth[a] < depth[b]) swap(a, b);
            sum[a]++;
            if (sum[a] >= 2) {
                ok = 0;
            }
            a = par[a];
        }
        sum[a]++;
        if (sum[a] >= 2) ok = 0;
        return a;
    };
    for (int mask = 0; mask < (1<<n); mask++){
        if (__builtin_popcountll(mask) != k) continue;
        vector<int>curr(k);
        int ptr = 0;
        for (int i = 0; i<n; i++){
            if (mask&(1<<i)){
                curr[ptr++] = i+1;
            }
        }
        vector<int>p(k);
        iota(p.begin(), p.end(), 0);
        // if (curr != vector<int>{3, 4}){
        //     continue;
        // }
        do{
            sum.assign(n+1, 0);
            int D = 0;
            ok = 1;
            for (int i = 0; i<k; i++){
                //a[i] z curr[p[i]];
                int l = mark(a[i], curr[p[i]]);
                D += depth[a[i]] + depth[curr[p[i]]];
                D -= 2 * depth[l];
            }
            if (ok) {
                debug(curr, p, D, sum);
                ans = min(ans, 2*(n-k) - D);
            }
        } while (next_permutation(p.begin(), p.end()));
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}