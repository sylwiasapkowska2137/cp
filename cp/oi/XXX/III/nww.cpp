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
const int mx = 1e6+2;

int mul(int a, int b){
    return (a*b)%mod;
}

int add2(int a, int b){
    a += b;
    if (a >= mod) a-=mod;
    return a;
}

struct Tree{
    vector<int>tab, lazy;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 1);
        lazy.assign(2*size, 1);
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tab[x] = mul(tab[x], v);
            lazy[x] = mul(lazy[x], v);
            return;
        }
        push(x);
        int m = (lx+rx)/2;
        update(2*x, lx, m, l, r, v);
        update(2*x+1, m+1, rx, l, r, v);
        tab[x] = add2(tab[2*x], tab[2*x+1]);
    }

    int query(int x, int lx, int rx, int l, int r){
        if (lx > r || rx < l) return 0;
        if (lx >= l && rx <= r) return tab[x];
        push(x);
        int m = (lx+rx)/2;
        return add2(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
    }

    void push(int x){
        if (lazy[x] == 1) return;
        tab[2*x] = mul(tab[2*x], lazy[x]);
        tab[2*x+1] = mul(tab[2*x+1], lazy[x]);
        lazy[2*x] = mul(lazy[2*x], lazy[x]);
        lazy[2*x+1] = mul(lazy[2*x+1], lazy[x]);
        lazy[x] = 1;
    }
};

void solve(){
    vector<int>divisor(mx);
    vector<int>prime;
    int tt = 1000;
    for (int i = 2; i<mx; i++){
        if (!divisor[i]){
            divisor[i] = i;
            if (i <= tt){
                prime.emplace_back(i);
            }
            for (int j = i*i; j<mx; j+=i){
                if (!divisor[j]){
                    divisor[j] = i;
                }
            }
        }
    }
    int n, q; cin >> n >> q >> mod;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    //q = 1
    int l, r; cin >> l >> r;
    for (int rep = l; rep <= r; rep++){
        int x = a[rep];
        vector<int>what;
        while (x > 1){
            what.emplace_back(prime[x]);
            x/=prime[x];
        }  
        debug(a[rep], what);
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