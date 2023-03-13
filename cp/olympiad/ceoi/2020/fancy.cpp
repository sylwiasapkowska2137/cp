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
const int mod = 1e9+7;

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

int mul(int a, int b){
    return (a*b)%mod;
}

int power(int a, int b){
    if (!b) return 1LL;
    int k = power(a, b/2);
    k = mul(k, k);
    if (b&1) k = mul(k, a);
    return k;
}


int pairs(int x){
    return x*(x-1)/2;
}

void solve(){
    int n; cin >> n;
    vector<int>h(n+1), w(n+1);
    for (int i = 1; i<=n; i++) cin >> h[i];
    vector<int>l(n+1), r(n+1);
    int sum = 1;
    for (int i = 1; i<=n; i++) {
        l[i] = sum;
        cin >> w[i];
        sum += w[i];
        r[i] = sum-1;
    }
    vector<T>sweep;
    for (int i = 1; i<=n; i++) sweep.emplace_back(h[i], i);
    sort(sweep.begin(), sweep.end());
    vector<int>ord(n+1);
    for (int i = 1; i<=n; i++) ord[sweep[i].second] = i;
    vector<int>s, left(n+1), right(n+1);


    int ans = 0;
    int pv = 0;
    vector<int>diff(n+1);
    for (int i = 1; i<=n; i++){
        if (sweep[i].size()){
            diff[i] = h[sweep[i].back()] - pv;
            pv = h[sweep[i].back()];
        }
    }
    for (int i = n; i>=1; i--){
        for (auto idx: sweep[i]){
            add(ans, mul(mul(diff[i], h[idx]), power(2, pairs(right[idx]-left[idx]+1))));
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