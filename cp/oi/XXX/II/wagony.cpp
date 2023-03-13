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
void __print(uint64_t x) {cerr << x;}

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
#define uint unsigned long long
typedef pair<int, int> T;
const uint mod = 1001;
unordered_map<int, uint64_t>cnt;
uint d, a, b;

uint cost(uint w, uint v){
    int f = (a%mod * w + b%mod * v) % mod;
    int s = (a%mod * v + b%mod * w) % mod;
    return min(f, s);
}

uint rec(uint &n){
    if (cnt.find(n) != cnt.end()) return cnt[n];
    uint ans = ULLONG_MAX;
    for (uint A = n/2, B = (n+1)/2; A > 0 && B-A <= d; A--, B++){
        ans = min(ans, rec(A) + rec(B) + cost(A, B));
    }
    cnt[n] = ans;
    return ans;
}

void solve(){
    uint n; cin >> n >> d >> a >> b;
    cnt[1] = 0;
    cout << rec(n) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}