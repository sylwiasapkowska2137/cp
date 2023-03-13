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

// #define int long long
typedef pair<int, int> T;
// const int oo = 1e18, oo2 = 1e9+7, K = 30;
const long long mod = 1e9+7;

void add(int &a, int b){
    a += b; 
    if (a >= mod) a-=mod;
}

int mul(int a, int b){
    return ((long long)a*(long long)b)%mod;
}   

void solve(){
    int n, k; cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector dp(n+1, vector<vector<int>>(n+2, vector<int>(k+2)));
    dp[0][0][0] = 1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j <= i; j++){
            for (int ck = 0; ck <= k; ck++){
                int curr = ck + j*(a[i] - (i ? a[i-1] : 0));
                if (curr > k) continue;
                //dodajemy a[i] do wlasnej grupy - otwieramy ją i od razu ją zamykamy
                add(dp[i+1][j][curr], dp[i][j][ck]);
                //dodajemy a[i] do jakiejs istniejacej grupy, i nie zamykamy jej
                if (j) add(dp[i+1][j][curr], mul(j, dp[i][j][ck]));
                //dodajemy a[i] do jakiejs istniejacej grupy, ale zamykamy ją
                if (j) add(dp[i+1][j-1][curr], mul(dp[i][j][ck], j));
                //zaczynamy nową grupe o min=a[i]
                add(dp[i+1][j+1][curr], dp[i][j][ck]);
            }
        }
    }
    int ans = 0;
    for (int ck = 0; ck <= k; ck++){
        add(ans, dp[n][0][ck]);
    }
    cout << ans << "\n";
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