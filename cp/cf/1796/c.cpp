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
const int oo = 1e18, oo2 = 1e9+7, K = 23;
const int mod = 998244353;
int c[K][K];

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

int mul(int a, int b){
    return (a*b)%mod;
}

void solve(){
    int l, r; cin >> l >> r;
    int ans = 0;
    int L = l;
    while (L <= r){
        ans++;
        L *= 2;
    }
    int ret = 0;
    auto check = [&](int x, int i){
        for (int rep = 0; rep < i; rep++){
            x *= 3;
            if (x > r) return false;
        }
        int ck = i;
        while (x <= r){
            ck++;
            x *= 2;
        }
        return (ck == ans);
    };
    for (int i = 0; i<K; i++){
        int A = l, B = r, curr = -1;
        while (B >= A){
            int mid = (A+B)/2;
            if (check(mid, i)){
                curr = mid;
                A = mid+1;
            } else {
                B = mid-1;
            }
        }
        if (curr == -1) continue;
        debug(i, curr, curr-l+1, c[ans-1][i]);
        add(ret, mul(curr-l+1, c[ans-1][i]));
    }
    cout << ans << " " << ret << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    c[0][0] = 1;
    for (int i = 1; i<K; i++){
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j<i; j++){
            add(c[i][j], c[i-1][j]);
            add(c[i][j], c[i-1][j-1]);
        }
    }
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}