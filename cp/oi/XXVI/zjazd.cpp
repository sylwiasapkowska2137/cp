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
int n;
typedef vector<vector<bool>> vbb;

bool check(vbb &dp, vector<int>a){
    for (int v = 1; v <= n; v++){
        bool ok = 1;
        for (auto x: a){
            ok &= (dp[x][v]);
            if (!ok) break;
        }
        if (ok) return true;
    }
    return false;
}

vbb mul(vbb &dp1, vbb &dp2){
    vbb dp(n+1, vector<bool>(n+1));
    for (int a = 1; a <= n; a++){
        for (int b = 1; b <= n; b++){
            for (int c = 1; c <= n; c++){
                if (dp1[a][c] && dp2[c][b]){
                    dp[a][b] = 1;
                    break;
                }
            }  
        } 
    }
    return dp;
}

void solve(){
    int m, k; cin >> n >> m >> k;
    vector dp(K, vbb(n+1, vector<bool>(n+1)));
    vector<int>a(k);
    for (int i = 0; i<k; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if ((int)a.size() == 1){
        cout << "TAK\n0\n";
        return;
    }
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        dp[0][x][y] = 1;
    }
    if (check(dp[0], a)) {
        cout << "TAK\n1\n";
        return;
    }
    int power = -1;
    for (int i = 1; i<K; i++){
        dp[i] = mul(dp[i-1], dp[i-1]);
        if (check(dp[i], a)) {
            debug(i);
            power = i-1;
            break;
        }
    }
    if (power == -1) {
        cout << "NIE\n";
        return;
    }
    bool any = 0;
    int mask = 0;
    vbb now(n+1, vector<bool>(n+1, 0));
    for (int i = 1; i<=n; i++) now[i][i] = 1;
    for (int i = power; i>=0; i--){
        vbb tmp = mul(now, dp[i]);
        if (!check(tmp, a)){            
            tmp.swap(now);
            mask += (1<<i);
        } else {
            debug(mask);
            any = 1;
        }
    }
    mask++;
    if (!any) mask = (1<<(power+1));
    cout << "TAK\n" << mask << "\n";
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