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

typedef pair<int, int> T;
const int mx = 1e6+7;
bitset<mx>dp;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>g(n+1);
    for (int i = 0; i<m; i++){
        int k; cin >> k;
        int prev = -1;
        for (int j = 0; j<k; j++) {
            int x; cin >> x;
            if (prev != -1){
                g[prev].emplace_back(x);
                g[x].emplace_back(prev);
            }
            prev = x;
        }
    }   
    vector<bool>vis(n+1), color(n+1);
    vector<int> cnt(mx), a; 
    int c = 0, b = 0;
    function<void(int, int)>dfs = [&](int v, int pa){
        vis[v] = 1;
        if (color[v]) c++;
        else b++;
        for (auto x: g[v]){
            if (x == pa) continue;
            if (vis[x] && color[x] == color[v]) {
                cout << "impossible\n";
                exit(0);
            } 
            if (!vis[x]){
                color[x] = (color[v] == 0 ? 1 : 0);
                dfs(x, v);
            }
        }
    };
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            c = 0;b = 0;
            dfs(i, i);
            cnt[abs(c-b)]++;
        }
    }
    for (int i = 1; i<mx; i++){
        int x = (cnt[i]-1)/2;
        cnt[i] -= 2*x;
        while (cnt[i]--) a.emplace_back(i);
        assert(!x || 2*i < mx);
        if (x) cnt[2*i] += x;
    }
    debug(a);
    int s = accumulate(a.begin(), a.end(), 0);
    dp[0] = 1;
    for (auto x: a) dp |= (dp << x);
    // for (int i = 0; i<=s; i++) cerr << dp[i];
    // cerr << "\n";
    for (int A = s/2; A>=0; A--){
        if (dp[A]){
            cout << s-2*A << "\n";
            return;
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
