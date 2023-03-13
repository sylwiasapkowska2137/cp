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

void solve(){
    int n, m, p; cin >> n >> m >> p;
    vector<vector<T>>g(n+1);
    vector<int>w(n+1);
    for (int i = 1; i<=n; i++) cin >> w[i];
    for (int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    typedef tuple<int, int, int, int> F;
    priority_queue<F, vector<F>, greater<F>>pq;
    pq.push({0, -p, 1, 0});
    vector<vector<T>>dp(n+1, vector<T>(n+1, {oo, oo}));
    dp[1][0] = {0, p};
    while (pq.size()){
        auto [change, cost, v, mx] = pq.top();
        debug(v, mx, cost, change);
        pq.pop();
        if (dp[v][mx] < make_pair(change, cost)) continue;
        mx = (w[v] > w[mx] ? v : mx);
        for (auto [x, c]: g[v]){
            int ile = max(0LL, (c + cost + w[mx] - 1)/w[mx]) ;
            if (dp[x][mx] > make_pair(change+ile, cost+c-ile*w[mx])){
                dp[x][mx] = {change + ile, cost+c-ile*w[mx]};
                pq.push({dp[x][mx].first, dp[x][mx].second, x, mx});
            }
        }
    }
    int ans = oo;
    for (int i = 1; i<=n; i++){
        ans = min(ans, dp[n][i].first);
    }
    if (ans == oo) ans = -1;
    cout << ans << "\n";
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