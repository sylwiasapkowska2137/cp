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
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<bool>vis(n+1), color(n+1);
    int b = 0, c = 0;
    vector<int>valid;
    function<void(int)>dfs = [&](int v){
        vis[v] = 1;
        valid.emplace_back(v);
        if (color[v]) b++;
        else c++;
        for (auto x: g[v]){
            if (vis[x]){
                if (color[x] == color[v]){
                    cout << "NIE\n";
                    exit(0);
                }
            } else {
                color[x] = (color[v] == 1 ? 0 : 1);
                dfs(x);
            }
        }
    };
    vector<int>ret(n+1);
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            dfs(i);
            for (auto x: valid){
                ret[x] = (b > c ? (color[x]^1)+1 : color[x] + 1);
            }
            b = 0; c = 0;
            valid.clear();
        }
    }
    if (k&1) {
        int ans = 0;
        for (int i = 1; i<=n; i++) ans += (ret[i] == 1);
        cout << ans << "\n";
        // for (int i = 1; i<=n; i++) cout << ret[i] << " ";
        // cout << "\n";
        return;
    }
    vector d(n+1, vector<int>(n+1, oo));
    for (int rep = 1; rep <= n; rep++){
        queue<int>q;
        auto &dist = d[rep];
        dist[rep] = 0;
        q.push(rep);
        while (q.size()){
            int v = q.front(); q.pop();
            for (auto x: g[v]){
                if (dist[x] == oo){
                    dist[x] = dist[v]+1;
                    q.push(x);
                }
            }
        }
    }
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            if (color[i] != color[j] && d[i][j] < k-1){
                g[i].emplace_back(j);
                // cerr << i << " " << j << "\n";
            }
        }
    }

    vector<int>match(n+1, -1);
    function<bool(int)>powieksz = [&](int v){
        vis[v] = 1;
        for (auto x: g[v]){
            if (match[x] == -1){
                match[v] = x;
                match[x] = v;
                return true;
            }
        }
        for (auto x: g[v]){
            if (!vis[match[x]] && powieksz(match[x])){
                match[x] = v;
                match[v] = x;
                return true;
            }
        }
        return false;
    };
    while (1){
        bool any = 0;
        vis.assign(n+1, 0);
        for (int i = 1; i<=n; i++){
            if (match[i] == -1 && powieksz(i)){
                any = 1;
            }
        }
        if (!any) break;
    }
    debug(match);
    queue<int>q;
    vis.assign(n+1, 0);
    ret.assign(n+1, -1);
    for (int v = 1; v<=n; v++) {
        if (match[v] == -1){
            ret[v] = (color[v] ? 1 : k);
            vis[v] = 1;
            for (auto x: g[v]){
                q.push(x);
            }
        }
    }
    auto fix = [&](){
        while (q.size()){
            int v = q.front(); q.pop();
            vis[v] = 1;
            debug(v);
            if (match[v] == -1) continue;
            ret[match[v]] = (color[match[v]] ? 1 : k);
            for (auto x: g[match[v]]){
                if (!vis[x]){
                    q.push(x);
                }
            }
        }
    };
    fix();
    while (1){
        bool any = 0;
        for (int i = 1; i<=n; i++){
            if (match[i] == -1) continue;
            if (ret[match[i]] == -1 && ret[i] == -1){
                ret[i] = (color[i] ? 1 : k);
                q.push(match[i]);
                any = 1;
                break;
            }
        }
        fix();
        if (!any) break;
    }
    debug(ret);
    for (int i = 1; i<=n; i++) {
        if (ret[i] == 1){
            q.push(i);
        }
    }
    while (q.size()){
        int v = q.front(); q.pop();
        for (auto x: g[v]){
            if (ret[x] == -1){
                ret[x] = ret[v]+1;
                q.push(x);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i<=n; i++) {
        if (ret[i] == 1 || ret[i] == k) {
            ans++;
        }
    }
    cout << ans << "\n";
    // for (int i = 1; i<=n; i++) cout << ret[i] << " ";
    // cout << "\n";
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