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
const int oo = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>d(n+1), par(n+1);
    function<void(int, int)>dfessa = [&](int v, int pa){
        par[v] = pa;
        for (auto x: g[v]){
            if (x == pa) continue;
            d[x] = d[v]+1;
            dfessa(x, v);
        }
    };
    dfessa(1, 1);
    T curr = {-oo, -oo};
    for (int i = 1; i<=n; i++) curr = max(curr, T{d[i], i});
    int l = curr.second;
    d[l] = 0;
    dfessa(l, l);
    curr = {-oo, -oo};
    for (int i = 1; i<=n; i++) curr = max(curr, T{d[i], i});
    int r = curr.second;
    for (int i = curr.first/2; i>0; i--){
        r = par[r];    
    }
    vector<int>ret;
    auto check = [&](int m, bool f){
        vector<int>dp(n+1);
        function<void(int, int)>dfs = [&](int v, int pa){
            for (auto x: g[v]){
                if (x == pa) continue;
                dfs(x, v);
                dp[v] = max(dp[v], dp[x] + 1);
            }
        };
        dfs(r, r);
        int cnt = 0;
        for (int i = 1; i<=n; i++){
            if (dp[i] >= m){
                int tmp = 0;
                for (auto x: g[i]){
                    if (dp[x] >= m){
                        tmp++;
                    }
                }
                if (tmp == 1) {
                    if (f) {
                        ret.emplace_back(i);
                    }
                    cnt++;
                }
            }
        }
        debug(m, cnt);
        return (cnt <= k);
    };
    
    int L = 0, R = n, ans = n;
    while (R >= L){
        int m = (L+R)/2;
        if (check(m, 0)){
            ans = m;
            R = m-1;
        } else {
            L = m+1;
        }
    }
    check(ans, 1);
    if (ret.empty()){
        ret = {1, 2};
    }
    cout << ans << " " << (int)ret.size() << "\n";
    for (auto x: ret) cout << x << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}