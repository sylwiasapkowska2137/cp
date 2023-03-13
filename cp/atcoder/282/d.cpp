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
    vector<vector<int>>g(n+1);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>color(n+1), vis(n+1);
    vector<int>cnt = {0, 0};
    function<void(int)>dfs = [&](int v){
        vis[v] = 1;
        cnt[color[v]]++;
        for (auto x: g[v]){
            if (!vis[x]){
                color[x] = color[v]^1;
                dfs(x);
            } else {
                if (color[x] == color[v]){
                    cout << "0\n";
                    exit(0);
                }
            }
        }
    };
    int ans = n*(n-1)/2 - m;
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            cnt = {0, 0};
            dfs(i);
            ans -= (cnt[0] * (cnt[0] - 1)/2 + cnt[1] * (cnt[1] - 1) /2);
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