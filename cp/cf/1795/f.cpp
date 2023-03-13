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
    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int k; cin >> k;
    vector<int>a(k);
    for (int i = 0; i<k; i++) cin >> a[i];
    auto check = [&](int mid){
        vector<int>vis(n+1), left(n+1), d(n+1);
        for (int i = 0; i<k; i++){
            vis[a[i]] = 1;
            left[a[i]] = mid/k + (mid%k <= i ? 0 : 1);
        }
        bool ok = 1;
        function<void(int, int)>dfs = [&](int v, int pa){
            for (auto x: g[v]){
                if (x == pa) continue;
                dfs(x, v);
                if (!vis[x]) d[v] = max(d[v], d[x]+1);
            }  
            if (left[v]){
                if (d[v] >= left[v]){
                    left[v] = 0;
                } else {
                    if ((pa != v && vis[pa]) || v == pa){
                        ok = 0;
                        return;
                    }
                    left[pa] = left[v]-1;
                    vis[pa] = 1;
                    d[v] = -1; 
                }
            }
        };
        dfs(1, 1);
        return ok;
    };
    int L = 0, R = n-1, ans = 0;
    while (R >= L){
        int mid = (L+R)/2;
        if (check(mid)){
            ans = mid;
            L = mid+1;
        } else {
            R = mid-1;
        }
    }
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