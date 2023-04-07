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
const int oo = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<T>>g(n+1);
    for (int i = 0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    vector<T>poly(n+1);
    vector<bool>vis(n+1);
    long double ans = (long double)oo;
    long double eps = 1e-9;
    vector<int>valid;
    function<void(int)>dfs = [&](int v){
        vis[v] = 1;
        valid.emplace_back(v);
        for (auto [x, c]: g[v]){
            if (!vis[x]){
                poly[x].first = -poly[v].first;
                poly[x].second = c - poly[v].second;
                dfs(x);
            } else {
                //solve the equation
                //curr.first * x + curr.second = poly[x].first * x + poly[x].second
                //x (curr.first - poly[x].first) = poly[x].second - curr.second;
                T curr = {-poly[v].first, c - poly[v].second};
                debug(v, x, curr, poly[x], poly[v]);
                if (curr.first == poly[x].first) {
                    if (curr.second != poly[x].second){
                        cout << "NO\n";
                        exit(0);
                    }
                    continue;
                }
                long double now = (long double)(poly[x].second - curr.second)/(long double)(curr.first - poly[x].first);
                debug(x, v, now);
                if (abs(ans - oo) < eps) {
                    ans = now;
                } else {
                    if (abs(now - ans) > eps){
                        cout << "NO\n";
                        exit(0);
                    }
                }
            }
        }
    };
    
    cout << fixed << setprecision(15);
    vector<long double>ret(n+1);
    vector<bool>vis2(n+1, 0);
    auto solve = [&](long double curr, int from){
        function<void(int)>restore = [&](int v){
            vis2[v] = 1;
            for (auto [x, c]: g[v]){
                if (!vis2[x]){
                    ret[x] = (long double)c - ret[v];
                    restore(x);
                }
            }
        };
        ret[from] = curr;
        restore(from);
        for (auto u: valid) vis2[u] = 0;
    };
    vector<long double>out(n+1);
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            ans = (long double)oo;
            poly[i].first = 1;
            dfs(i);
            debug(valid);
            if (abs(ans - oo) < eps){ 
                vector<int>now;
                for (auto u: valid){
                    if (poly[u].first == -1) now.emplace_back(poly[u].second);
                    else now.emplace_back(-poly[u].second);
                }
                sort(now.begin(), now.end());
                debug(now);
                ans = (long double)(now[(int)now.size()/2]);
            }
            solve(ans, i);
            valid.clear();
        }
    }
    cout << "YES\n";
    for (int i = 1; i<=n; i++) cout << ret[i] << " ";
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