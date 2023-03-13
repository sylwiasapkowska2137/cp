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
vector<int>w;

struct event{
    int x, mx, cost, change;
    event(){}
    event(int _x, int _mx, int _cost, int _change){
        x = _x, mx = _mx, cost = _cost, change = _change;
    }
    // bool operator == (const event &he){
        // return 
        // return (x == he.x && mx == he.mx && change == he.change);
    // }
    bool operator < (const event&he) const{
        return (change == he.change ? (cost == he.cost ? w[mx] > w[he.mx] : cost > he.cost) : change < he.change);
    }
};

void solve(){
    int n, m, p; cin >> n >> m >> p;
    vector<vector<T>>g(n+1);
    w.assign(n+1, 0);
    for (int i = 1; i<=n; i++) cin >> w[i];
    for (int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    multiset<event>s;
    s.insert(event{1, 1, p, 0});
    vector<vector<T>>dp(n+1, vector<T>(n+1, {oo, oo}));
    dp[1][1] = {p, 0};
    auto better = [&](int mx, int cost1, int change1, int cost2, int change2){
        if (change1 == oo) return 1;
        if (cost1 >= cost2 && change1 <= change2) return 0;
        if (cost1 <= cost2 && change1 >= change2) return 1;
        if (cost1 > cost2){
            //change1 > change2
            if (change2 + (cost1 - cost2) * w[mx] >= change1) return 1;
            return 0;
        }
        if (change1 + (cost2 - cost1) * w[mx] > change2) return 0;
        return 1;
    };
    while (s.size()){
        auto [v, mx, cost, change] = *s.begin();
        // debug(v, mx, cost, change);
        s.erase(s.begin());
        //continue;
        for (auto [x, c]: g[v]){
            int nmax = (w[mx] > w[x] ? mx : x);
            int ile = max(0LL, (c-cost + w[mx] - 1)/w[mx]);
            if (better(nmax, dp[x][nmax].first, dp[x][nmax].second, cost-c+ile*w[mx], change + ile)){
                dp[x][nmax] = {cost-c+ile*w[mx], change + ile};
                s.insert(event{x, nmax, cost-c+ile*w[mx], change + ile});
            }
        }
    }
    int ans = oo;
    for (int i = 1; i<=n; i++){
        ans = min(ans, dp[n][i].second);
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