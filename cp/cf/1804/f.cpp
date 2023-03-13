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

void solve(){
    int n, mm, q; cin >> n >> mm >> q;
    vector<vector<int>>g(n+1);
    for (int i = 0; i<mm; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>deg(n+1);
    for (int i = 1; i<=n; i++) deg[i] = (int)g[i].size();
    auto clear = [&](){
        for (int v = 1; v <= n; v++){
            while ((int)g[v].size() > deg[v]){
                g[v].pop_back();
            }
        }
    };
    vector<T>que(q+1);
    for (int i = 1; i<=q; i++) cin >> que[i].first >> que[i].second;
    vector<int>dist(n+1);
    auto eval = [&](int id){
        for (int i = 1; i <= id; i++){
            auto [a, b] = que[i];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        int ans = 0;
        queue<int>q;
        for (int rep = 0; rep < 5; rep++){
            int s = p(1, n);
            // debug(s);
            q.push(s);
            dist.assign(n+1, oo);
            dist[s] = 0;
            while ((int)q.size()){
                int v = q.front();q.pop();
                for (auto x: g[v]){
                    if (dist[x] == oo){
                        dist[x] = dist[v]+1;
                        ans = max(ans, dist[x]);
                        q.push(x);
                    }
                }
            }
        }
        clear();
        return ans;
    };

    vector<int>ans(q+1);

    function<void(int, int, int, int)>rec = [&](int l, int r, int a, int b){
        if (l > r) return;
        debug(l, r, a, b);
        if (a <= 2*b){
            for (int i = l; i<=r; i++){
                ans[i] = 2*b;
            }
            return;
        }
        int m = (l+r)/2;
        int curr = eval(m);
        debug(m, curr);
        ans[m] = curr;
        rec(l, m-1, a, curr);
        rec(m+1, r, curr, b);
    };

    rec(0, q, eval(0), eval(q));
    for (int i = 0; i<=q; i++) cout << ans[i] << " ";
    cout << "\n";
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