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
    auto check = [&](int k){
        vector<vector<int>>dp(n+1, vector<int>(2));
        //dp[v][1] = sciezka idzie w gore i w dol
        //dp[v][0] = v jest obecnym koncem sciezki przechodzacej przez v
        function<void(int, int)>dfs = [&](int v, int pa){
            for (auto x: g[v]){
                if (x == pa) continue;
                dfs(x, v);
            }
            if ((int)g[v].size() == 1){
                dp[v][0] = 1;
                return;
            }
            set<int>C, D;
            //sciezka z odpowiedzi nie musi byc pionowa(!!!)
            //case 2:
            int best = -oo, nd = -oo;
            for (auto x: g[v]){
                if (x == pa) continue;
                dp[v][0] = max(dp[v][0], dp[x][1]+1);
                if (dp[x][0] >= best){
                    nd = best;
                    best = dp[x][0];
                } else if (dp[x][0] >= nd){
                    nd = dp[x][0];
                }
            }
            dp[v][0] = max({best, nd+1});

            //case 3:
            
        };
        dfs(1, 1);
    };

    int L = 1, R = K, ans = K;
    while (R >= L){
        int mid = (L+R)/2;

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