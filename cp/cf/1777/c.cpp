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
    vector<int>a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int R = 0;
    vector<int>cnt(m+1);
    int bad = m;
    auto add = [&](int x){
        for (int d = 1; d*d <= x; d++){
            if (x % d == 0){
                if (d <= m){
                    cnt[d]++;
                    if (cnt[d] == 1) bad--;
                }
               
                if (d != x/d && x/d <= m) {
                    cnt[x/d]++;
                    if (cnt[x/d] == 1){
                        bad --;
                    }
                }
            }
        }
    };
    add(a[0]);

    auto remove = [&](int x){
        for (int d = 1; d*d <= x; d++){
            if (x % d == 0){
                if (d <= m){
                    cnt[d]--;
                    if (cnt[d] == 0) bad++;
                }
               
                if (d != x/d && x/d <= m) {
                    cnt[x/d]--;
                    if (cnt[x/d] == 0){
                        bad++;
                    }
                }
            }
        }
    };
    int ans = oo;
    for (int L = 0; L < n; L++){
        while (R+1 < n && bad > 0){
            R++;
            add(a[R]);
        }
        if (bad == 0){
            ans = min(ans, a[R] - a[L]);
        }
        remove(a[L]);
    }
    if (ans == oo) cout << "-1\n";
    else  cout << ans << "\n";
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