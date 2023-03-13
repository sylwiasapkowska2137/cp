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

struct Hash{
    vector<int>h = {0}, p = {1}, inv = {1};
    int base, mod;

    int mul(int a, int b){
        return (a*b)%mod;
    }

    void add(int &a, int b){
        a += b;
        if (a >= mod) a -= mod;
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

    int add2(int a, int b){
        add(a, b);
        return a;
    }

    Hash(string s, int _b, int _m){
        base = _b, mod = _m;
        int n = (int)s.size();
        s = "$"+s;
        int I = power(base, mod-2);
        for (int i = 1; i<=n; i++){
            p.emplace_back(mul(p.back(), base));
            inv.emplace_back(mul(inv.back(), I));
            h.emplace_back(add2(h.back(), mul(s[i], p[i])));
        }
    }

    int ask(int a, int b){
        return mul(sub2(h[b], h[a-1]), inv[a-1]);
    }  
};

void solve(){
    string s; cin >> s;
   
    Hash H1(s, 2137, 1e9+7);
    Hash H2(s, 2137, 1e9+9);
    int n = (int)s.size(); 
    s = "$"+s;
    int L = 1, R = n;
    int ans = 0;
    while (R >= L){
        int a = L, b = R;
        while (a <= R && b >= L){
            if (H1.ask(L, a) == H1.ask(b, R) && H2.ask(L, a) == H2.ask(b, R)){
                if (a != R) {
                    ans += 2;
                    L = a+1;
                    R = b-1;
                } else {
                    ans++;
                    cout << ans << "\n";
                    return;
                }
                break;
            }
            a++;b--;
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}