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
const int mod = 1e9+7, I = 500000004;
const int mx = 2e5+7; 
int p[mx], cnt[mx], curr[mx], used[mx], sq[mx], prime[mx];
vector<int>divs[mx];
vector<T>what[mx];
int ans = 0;

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

int mul(int a, int b){
    return (long long)a * (long long)b % mod;
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
        if (p[y] == prev){
            x/=p[y];
            x/=p[y];
            prev = -1;
        } else {
            prev = p[y];
        }
        y/=p[y];
    }
    return x;
}

int sub2(int a, int b){
    a -= b;
    if (a < 0) a+=mod;
    return a;
}

void sub(int &a, int b){
    a -= b;
    if (a < 0) a+=mod;
}

vector<int>valid;
void solve(int i){
    if (what[i].empty()) return;
    // debug(i, what[i]);
    int sum = 0, now = 0;
    for (auto &[num, ile]: what[i]) {
        used[num] = mul(num, ile);
    }
    valid.clear();
    for (auto &[num, ile]: what[i]){
        add(sum, used[num]);
        for (auto &x: divs[num]){
            valid.emplace_back(x);
            add(curr[x], used[num]);
            add(sq[x], mul(num, used[num]));
        }
    }
    for (auto x: valid){
        int tmp = mul(sub2(mul(curr[x], curr[x]), sq[x]), I);
        // debug(x, curr[x], sq[x], tmp, prime[x]);
        if (prime[x]&1) sub(now, tmp);
        else add(now, tmp);
        curr[x] = 0;
        used[x] = 0;
        sq[x] = 0;
    }
    add(ans, now);
}

void solve(){
    //-----------
    for (long long i = 2; i<mx; i++){
        if (!p[i]){
            p[i] = i;
            for (long long j = i*i; j<mx; j+=i){
                if (!p[j]) {
                    p[j] = i;
                }
            }
        }
    }
    for (int i = 1; i<mx; i++){
        for (int d = 1; d*d <= i; d++){
            if (i % d == 0){
                divs[i].emplace_back(d);
                if (i/d != d) divs[i].emplace_back(i/d);
            }
        }
        // debug(i, divs[i]);
    }
    for (int i = 1; i<mx; i++){
        int x = i;
        while (x > 1){
            prime[i]++;
            x/=p[x];
        }
    }
    //---------- 

    int n; cin >> n;
    for (int i = 1; i<=n; i++){
        int x; cin >> x;
        cnt[reduce(x)]++;
    }
    for (int i = 1; i<mx; i++){
        for (auto &x: divs[i]){
            if (cnt[i]) {
                what[x].emplace_back(i/x, cnt[i]);
            }
        }   
    }
    for (int i = 1; i<mx; i++){
        solve(i);
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