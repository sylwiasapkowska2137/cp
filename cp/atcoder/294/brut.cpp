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
    int len, n1, n2; cin >> len >> n1 >> n2;
    map<int, vector<T>>a, b;
    int L = 1;
    vector<int>s;
    for (int i = 0; i<n1; i++){
        int x, len; cin >> x >> len;
        a[x].emplace_back(L, L+len-1);
        s.emplace_back(L);
        s.emplace_back(L+len-1);   
        L += len;
    }
    L = 1;
    for (int i = 0; i<n2; i++){
        int x, len; cin >> x >> len;
        b[x].emplace_back(L, L+len-1);
        s.emplace_back(L);
        s.emplace_back(L+len-1);   
        L += len;
    }
    int ans = 0;
    for (auto [val, vec]: a){
        for (auto [l, r]: vec){
            for (auto [l2, r2]: b[val]){
                int L = max(l, l2);
                int R = min(r, r2);
                if (L <= R) ans += (R-L+1);
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