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
const int mod = 998244353;

int binsearch(int m, int n){
    //return x = n^{1/m} --> x^m = n
    int l = 1, r = oo;
    int ans = 1;
    while (r >= l){
        int mid = (l+r)/2;
        int curr = 1;
        bool ok = 1;
        bool big = 0;
        for (int i = 0; i<m; i++){
            if (curr > (n + mid-1)/mid){
                if (i != m-1) ok = 0;
                else big = 1;
                break;
            }
            curr *= mid;
        }
        if (!ok || big || curr >= n) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

void solve(){
    int n, a, b; cin >> n >> a >> b;
    debug(binsearch(3, 8));
    debug(binsearch(2, 16));
    debug(binsearch(4, 5));
    int ans = oo;
    for (int m = 1; m <= 63; m++){
        int x = binsearch(m, n+1);
        debug(m, n+1, x);
        for (int f = 0; f <= m; f++){
            int ilo = 1;
            bool ok = 0;
            for (int rep = 0; rep<f; rep++){
                if ((x-1) > (n + ilo-1)/ilo){
                    ok = 1;
                    break;
                }
                ilo *= (x-1);
                if (ilo > n) {
                    ok = 1;
                    break;
                }
            } 
            for (int rep = f; rep < m; rep++){
                if (x > (n + ilo-1)/ilo){
                    ok = 1;
                    break;
                }
                ilo *= x;
                if (ilo > n) {
                    ok = 1;
                    break;
                }
            }
            if (ok){
                ans = min(ans, m*(a-b) + b * (f * (x-1) + (m-f) * x));
            }
        }
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