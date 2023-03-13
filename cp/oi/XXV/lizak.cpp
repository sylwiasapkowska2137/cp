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

struct event{
    int l, r, y, add;
    event(){}
    event(int _l, int _r, int _y, int _add){
        l = _l, r = _r, y = _y, add = _add;
    }
};

void solve(){
    vector<vector<pair<char, int>>>a(2);
    for (int rep = 0; rep < 2; rep++){
        int n; cin >> n;
        a[rep].resize(n);
        for (int i = 0; i<n; i++) cin >> a[rep][i].first >> a[rep][i].second;
    }
    int ans = 0;
    for (auto c: {'T', 'W'}){
        int mx1 = 0, mx2 = 0;
        for (auto [d, cnt]: a[0]){
            if (d == c) {
                mx1 = max(mx1, cnt);
            }
        }
        for (auto [d, cnt]: a[1]){
            if (d == c) {
                mx2 = max(mx2, cnt);
            }
        }
        ans = max(ans, min(mx1, mx2));
    }

    //co najmniej dwa
    for (int rep = 0; rep < 2; rep++){
        for (int i = 0; i<(int)a[rep].size(); i++){
            int A = 0, B = 0;
            int R1 = 0, R2 = 0;
            if (a[rep][i].first == 'T') R1 += a[rep][i].second;
            else R2 += a[rep][i].second;
            for (int j = i; j<(int)a[rep].size(); j++){
                if (a[rep][j].first == 'T') A += a[rep][j].second;
                else B += a[rep][j].second;
                if (i != j){
                    if (a[rep][j].first == 'T') R1 += a[rep][j].second;
                    else R2 += a[rep][j].second;
                    debug(A-R1, B-R2, A, B);
                    if (a[rep][j].first == 'T') R1 -= a[rep][j].second;
                    else R2 -= a[rep][j].second;
                }
            }
        }
        cerr << "\n";
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