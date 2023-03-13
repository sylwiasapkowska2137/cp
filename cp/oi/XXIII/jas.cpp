//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using namespace __gnu_pbds;

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
const int mod = 1e9+7;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int mul(int a, int b){
    return (a*b)%mod;
}

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

void solve(){
    int n; cin >> n;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<int>dp(n+1);
    // dp[i] = add2(mul(i-1, C2(i-1) + 1), mul(i, dp[i-1])); --> w wersji dla sasiednich swapow hshshs
    for (int i = 2; i<=n; i++){
        dp[i] = mul(i, dp[i-1]);
        /*
        if (i&1){
            //zadne sie nie powtarzają -> na wszystkich pozycjach cos sie zmienia
            add(dp[i], mul(i-1, (i+1)/2));
        } else {
            //raz na wszystkich pozycjach cos sie zmienia
            //i-2 razy jedna pozycja jest fixed
            // add(dp[i], i/2);
            // add(dp[i], mul(i-2, i/2));
            //---->
            add(dp[i], mul(i-1, i/2));
        }
        */
        add(dp[i], mul(i-1, (i+1)/2));
    }   
    debug(dp);
    int ans = 0; 
    int left = n-1;
    ordered_set s;
    for (int i = 1; i<=n; i++) s.insert(i);
    for (int i = 1; i<=n; i++){
        int k = s.order_of_key(a[i])+1;
        s.erase(a[i]);
        add(ans, mul(k-1, dp[left]));
        add(ans, mul(k-1, (left+2)/2));
        left--;
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}