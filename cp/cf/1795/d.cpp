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

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

int mul(int a, int b){
    return (a*b)%mod;
}

int f(int x){
    int a = 1;
    for (int i = 1; i<=x; i++) a = mul(a, i);
    return a;
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
    vector<int>a(n+1);
    int I = power(f(n/6), mod-2);
    int ans = mul(f(n/3), mul(I, I));
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<int>now;
    for (int i = 1; i<=n; i+=3){
        now = {a[i], a[i+1], a[i+2]};
        debug(now);
        sort(now.begin(), now.end());
        if (now[0] == now.back()){
            ans = mul(ans, 3);
        } else if (now[1] == now[0]){
            ans = mul(ans, 2);
        }
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