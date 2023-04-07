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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>>g(n+1);
    vector<T>edges;
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        edges.emplace_back(a, b);
    }
    int ans = -1;
    for (int mask = 1; mask < (1<<n); mask++){
        vector<int>dist(n+1, oo);
        queue<int>q;
        for (int i = 0; i<n; i++){
            if (mask&(1<<i)){
                dist[i+1] = 1;
                q.push(i+1);
            }
        }
        while (q.size()){
            int v = q.front();q.pop();
            for (auto x: g[v]){
                if (dist[x] == oo){
                    dist[x] = dist[v] + 1;
                    q.push(x);
                }
            }
        }
        bool bad = 0;
        for (auto [a, b]: edges){
            if (abs(dist[a] - dist[b]) != 1){
                bad = 1;
                break;
            }
        }
        if (!bad){
            int curr = 0;
            for (int i = 1; i<=n; i++){
                if (dist[i] == 1 || dist[i] == k){
                    curr++;
                }
            }
            ans = max(ans, curr);
        }
    }
    if (ans == -1) cout << "NIE\n";
    else  cout << ans << "\n";
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