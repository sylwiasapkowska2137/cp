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

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n+1), b(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=n; i++) cin >> b[i];
    for (int i = 1; i<=n; i++) a[i] = max(a[i], b[i]);
    auto check = [&](int mid){
        vector<int>left(n+1, mid);
        int todo = 0, extra = 0;
        for (int i = 1; i<=n; i++){
            int ile = (mid+a[i]-1)/a[i];
            if (ile <= m){
                extra += (m-ile);
                left[i] = 0;
            } else {
                left[i] -= m*a[i];
            }
        }
        for (int i = 1; i<=n; i++){
            if (left[i] > 0){
                int ile = (left[i]+b[i]-1)/b[i];
                extra -= ile;
                if (extra < 0) return false;
            }
        }
        return true;
    };
    
    int l = 0, r = oo, ans = 0;
    while (r >= l){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
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