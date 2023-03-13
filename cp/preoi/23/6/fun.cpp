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
const int mod = 1e9+7;
const int mx = 10;
const int I = 500000004;
#warning mx = 2e5+7

int mul(int a, int b){
    return (a*b)%mod;
}

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

int sub2(int a, int b){
    a -= b;
    if (a < 0) a+=mod;
    return a;
}

int change(int x, int sq){
    int y = mul(x, x);
    return sub2(y, sq)*I;
}

int power(int a, int b){
    if (!b) return 1LL;
    int k = power(a, b/2);
    k = mul(k, k);
    if (b&1) k = mul(k, a);
    return k;
}

void solve(){
    int n; cin >> n;
    vector<int>cnt(mx), a(n+1);
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        #warning change a[i] to without sq
        cnt[a[i]]++;
    }
    vector<int>sum(mx), sq(mx);
    for (int i = 1; i<mx; i++){
        for (int j = i; j<mx; j+=i){
            sum[j] += cnt[i];
            sq[j] += mul(cnt[i], cnt[i]);
        }
    }
    int ans = 0;
    
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