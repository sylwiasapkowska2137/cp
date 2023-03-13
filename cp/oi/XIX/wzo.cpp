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

typedef pair<int, int> T;
const int mx = 5e5+7, K = 20;
int prime[mx];
vector<T>what[mx];

#define int long long
struct Hash{
    int base, mod, I;
    vector<int>h = {0}, inv = {1};

    int mul(int a, int &b){
        return (a*b)%mod;
    }

    void add(int &a, int b){
        a += b;
        if (a >= mod) a-=mod;
    }

    void sub(int &a, int b){
        a -= b;
        if (a < 0) a += mod;
    }

    int add2(int a, int b){
        a += b;
        if (a >= mod) a-=mod;
        return a;
    }

    int sub2(int a, int b){
        a -= b;
        if (a < 0) a += mod;
        return a;
    }

    int power(int a, int b){
        if (!b) return 1LL;
        int k = power(a, b/2);
        k = mul(k, k);
        if (b&1) k = mul(k, a);
        return k;
    }

    Hash(string &s, int _b, int _m){
        base = _b;mod = _m;
        I = power(base, mod-2);
        int n = (int)s.size();
        int p = 1;
        for (int i = 0; i<n; i++){
            p = mul(p, base);
            inv.emplace_back(mul(inv.back(), I));
            h.emplace_back(add2(h.back(), mul(s[i], p)));
        }
    }

    int ask(int a, int b){
        return mul(sub2(h[b], h[a-1]), inv[a]);
    }
};
#undef int

void solve(){
    int n; cin >> n;
    for (long long i = 2; i<=n; i++){
        if (!prime[i]){
            prime[i] = i;
            for (long long j = i*i; j<=n; j+=i){
                if (!prime[j]){
                    prime[j] = i;
                }
            }
        }
        int x = i;
        while (x > 1){
            int t = prime[x];
            int cnt = 0;
            while (x % t == 0){
                x/=t;
                cnt++;
            }
            what[i].emplace_back(t, cnt);
        }
    }
    
    string s; cin >> s;
    Hash H1(s, 2137, 1e9+7), H2(s, 2137, 1e9+9);
    int q; cin >> q;
    while (q--){
        int l, r; cin >> l >> r;
        if (H1.ask(l, r-1) == H1.ask(l+1, r) && H2.ask(l, r-1) == H2.ask(l+1, r)){
            cout << "1\n";
            continue;
        }
        //cel: bs po liczbach pierwszych w rozkladzie
        int ans = 1;
        for (auto [p, pot]: what[r-l+1]){
            int ile = 0;
            for (int b = 0; ile + (1<<b) <= pot; b++){
                ile += (1<<b);
                int k = pow(p, ile);
                if (H1.ask(l, r-k) == H1.ask(l+k, r) && H2.ask(l, r-k) == H2.ask(l+k, r)) break;
                ile -= (1<<b);
            }
            debug(p, pot, ile);
            ans *= pow(p, ile);
        }
        // for (auto k: what[r-l+1]){
            // if (H1.ask(l, r-k) == H1.ask(l+k, r) && H2.ask(l, r-k) == H2.ask(l+k, r)){
                // ans = k;
                // break;
            // }
        // }
        cout << ans << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}