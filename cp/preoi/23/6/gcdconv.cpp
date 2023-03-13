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
const int mx = 2e5+2;
int prime[mx], c[mx], D[mx], d[mx], C[mx];

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

void sub(int &a, int b){
    a -= b;
    if (a < 0) a += mod;
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

int reduce(int x){
    int prev = -1, y = x;
    while (y > 1){
        if (prime[y] == prev){
            x/=prime[y];
            x/=prime[y];
            prev = -1;
        } else {
            prev = prime[y];
        }
        y/=prime[y];
    }
    return x;
}

void solve(){
    for (int i = 2; i<mx; i++){
        if (!prime[i]){
            prime[i] = i;
            for (int j = i*i; j<mx; j+=i){
                if (!prime[j]){
                    prime[j] = i;
                }
            }
        }
    }
    int n; cin >> n;
    for (int i = 0; i<n; i++){
        int x; cin >> x;
        x = reduce(x);
        add(c[x], x);
    }
    
    //gcd conv - C[i] = sum over all c[j], such that i|j
    for (int i = 1; i<mx; i++){
        for (int j = i; j<mx; j+=i){
            add(C[i], c[j]);
        }
        D[i] = mul(C[i], C[i]);
    }
    int ans = 0;
    for (int i = mx-1; i>=1; i--){
        d[i] = D[i];
        for (int j = i+i; j<mx; j+=i){
            sub(d[i], d[j]);
        }
        add(ans, mul(d[i], power(mul(i, i), mod-2)));
    }
    sub(ans, n);
    ans = mul(ans, power(2, mod-2));
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}