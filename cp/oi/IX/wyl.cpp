//Sylwia Sapkowska
#include <bits/stdc++.h>
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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

int power(int a, int b, int mod){
    if (!b) return 1LL;
    int k = power(a, b/2, mod);
    k = (k*k)%mod;
    if (b&1) k = (k*a)%mod;
    return k;
}

void solve(){
    int n; cin >> n;
    vector<int>ord(n+1);
    for (int i = 1; i<=n; i++){
        int x; cin >> x;
        ord[x] = i;
    }
    int now = 0, k = n;
    vector<pair<int, int>>equiv;
    vector<int>rest(n+1, -1);
    int lcm = 1;
    for (int i = 1; i<n; i++){
        int dist = 0;
        while (now != ord[i]){
            dist++;
            now = now%n+1;
        }
        
        int d = __gcd(lcm, k);
        int ck = k/d; 
        dist %= ck;
        if (dist < 0) dist += ck;
        for (auto [a, m]: equiv){
            if (ck % m == 0 && (dist%m) != (a%m)){
                cout << "NIE\n";
                return;
            }
        }
        equiv.emplace_back(dist, ck);
        lcm = (lcm * k)/d;
        k--;
    }
    debug(equiv); 
    k = (int)equiv.size();
    vector<int>x(k), p(k);
    for (int i = 0; i<k; i++){
        x[i] = equiv[i].first;
        p[i] = equiv[i].second;
        for (int j = 0; j<i; j++){
            x[i] = power(p[i], p[j]-2, p[j]) * (x[i] - x[j]);
            x[i] %= p[i];
            if (x[i] < 0) x[i] += p[i];
        }
    }
    int ans = 0;
    int coeff = 1;
    for (int i = 0; i<k; i++){
        ans += x[i] * coeff;
        coeff *= p[i];
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