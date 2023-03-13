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
const int mx = 2e4+5, nax = 1e5+7;
bitset<mx>reach[nax];

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n+1), in(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<vector<int>>g(n+1), G(n+1);
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    queue<int>q;
    for (int i = 1; i<=n; i++){
        a[i] = (int)g[i].size() - a[i];
        if (!a[i]) q.push(i);
    }
    while (q.size()){
        int v = q.front(); q.pop();
        a[v] = -1;
        for (auto x: g[v]){
            if (a[x] != -1){
                a[x]--;
                G[v].emplace_back(x);
                in[x]++;
                debug(v, x);
                if (!a[x]){
                    q.push(x);
                }
            }
        }
    }
    vector<int>topo;
    for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
    while (q.size()){
        int v = q.front();q.pop();
        topo.emplace_back(v);
        for (auto x: G[v]){
            in[x]--;
            if (!in[x]) {
                q.push(x);
            }
        }
    }
    debug(topo);
    int xd = 2e4;
    reverse(topo.begin(), topo.end());
    vector<int>from(n+1);
    for (int l = 1, r = l + xd-1; r <= nax; l += xd, r += xd){
        debug(l, r);
        for (auto v: topo){
            reach[v].reset();
            if (v >= l && v <= r) reach[v].set(v-l);
            for (auto x: G[v]) reach[v] |= reach[x];
            from[v] += reach[v].count();
        }
    }
    debug(from);
    long long ans = (long long)n*(n-1)/2;
    for (int i = 1; i<=n; i++) ans -= (long long)from[i];
    cout << ans+n << "\n";
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