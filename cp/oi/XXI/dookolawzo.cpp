#include <vector>
#include <iostream>
#include <cassert>
#include <numeric>
// #pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void __print(int x) {cerr << x;}
void __print(uint16_t x) {cerr << x;}
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
const int oo = 2e9+7;

void solve(){
    int n, s; cin >> n >> s;
    vector<int>a(n), jump(n);
    int all = 0, mn = 0;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
        all += a[i];
        mn = max(mn, a[i]);
    }
    debug(a);
    for (int rep = 0; rep<s; rep++){
        int d; cin >> d;
        if (mn > d) {
            cout << "NIE\n";
            continue;
        }
        if (d >= all){
            cout << "1\n";
            continue;
        }
        int r = 1, sum = a[0];
        for (int l = 0; l < n; l++){
            while (sum + a[r] <= d){
                sum += a[r];
                r = (r == n-1 ? 0 : r+1);
            }
            jump[l] = r;
            sum -= a[l];
        }
        debug(d, jump);
        int ptr = 0;
        int ans = 0;
        for (int i = 0; i<=2*n; i++){
            ptr = jump[ptr];
        }
        int ss = 0;
        debug(ptr);
        while (ss < all){
            if (ptr < jump[ptr]) {
                for (int i = ptr; i < jump[ptr]; i++) ss += a[i];
            } else {
                ss += all;
                for (int i = jump[ptr]; i < ptr; i++) ss -= a[i];
            }
            debug(ptr, jump[ptr], ss);
            ptr = jump[ptr];
            ans++;
        }
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