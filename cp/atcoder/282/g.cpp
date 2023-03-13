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

void solve(){
    int n, k, mod;
    cin >> n >> k >> mod;
    vector dp(n+2, vector<vector<int>>(n+1, vector<int>(n+1)));
    for (int i = 0; i<=n; i++){
        for (int j = 0; j<=n; j++){
            if (i == 0 || j == 0){
                dp[0][i][j] = 0;
            } else {
                dp[0][i][j] = 1;
            }
        }
    }
    auto ask = [&](int ck, int a, int b, int c, int d){
        if (a > c || b > d) return 0LL;
        int ans = dp[ck][c][d] - dp[ck][a-1][d] - dp[ck][c][b-1] + dp[ck][a-1][b-1];
        ans %= mod;
        if (ans < 0) ans += mod;
        return ans;
    };
    auto add = [&](int &a, int b){
        a += b;
        if (a >= mod) a-=mod;
    };
    for (int i = 1; i<n; i++){
        vector new_dp(n+2, vector<vector<int>>(n+1, vector<int>(n+1)));
        for (int ck = 0; ck <= i; ck++){
            
            for (int currA = 1; currA <= i+1; currA++){
                for (int currB = 1; currB <= i+1; currB++){
                    //<<
                    add(new_dp[ck+1][currA][currB], ask(ck, 1, 1, currA-1, currB-1));
                    //>>
                    add(new_dp[ck+1][currA][currB], ask(ck, currA, currB, n, n));
                    //<>   
                    add(new_dp[ck][currA][currB],   ask(ck, 1, currB, currA-1, n));
                    //><
                    add(new_dp[ck][currA][currB],   ask(ck, currA, 1, n, currB-1));   
                }   
            }
        }
        /*
        for (int ck = 0; ck <= i+1; ck++){
            cerr << "------------ ck " << ck << "\n";
            for (int A = 1; A <= n; A++){
                for (int B = 1; B <= n; B++){
                    cerr << new_dp[ck][A][B] << " ";
                }
                cerr << "\n";
            }
        }
        */
        for (int ck = 0; ck <= i; ck++){
            for (int A = 1; A <= n; A++){
                for (int B = 1; B <= n; B++){
                    dp[ck][A][B] = new_dp[ck][A][B] + dp[ck][A-1][B] + dp[ck][A][B-1] - dp[ck][A-1][B-1];
                    dp[ck][A][B] %= mod;
                    if (dp[ck][A][B] < 0) dp[ck][A][B] += mod;
                }
            }
        }
    }
    cout << dp[k][n][n] << "\n";
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