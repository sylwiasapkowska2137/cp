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
int mod;

int mul(int a, int b){
    return (a*b)%mod;
}

void add(int &a, int b){
    a+=b;
    if (a >= mod) a-=mod;
}

int add2(int a, int b){
    a += b;
    if (a >= mod) a-=mod;
    return a;
}

typedef cd complex<double>;
vector<int> fft(vector<int>a){
    int n = (int)a.size();
    if (n == 1) return a;
    vector<int>L, R;
    for (int i = 0; i<n; i++){
        if (i&1) R.emplace_back(a[i]);
        else L.emplace_back(a[i]);
    }
    vector<int>e = fft(L);
    vector<int>o = fft(R);
}

void solve(){
    int n, q; cin >> n >> mod >> q;
    //n = 2^k, q^n \equiv 1 mod m -> m|q^n-1
    
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