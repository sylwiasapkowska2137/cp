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
vector<T>bad;
set<vector<int>>s;

bool backtrack(int x1, int x2, int y1, int y2){
    if (max({x1, x2, y1, y2}) == 0) return 0; //przegrywajaca
    bool ans = 0;
    for (int c = 1; c <= x1; c++){
        if (!backtrack(x1-c, x2, y1, y2)) {
            ans = 1;
        }
    }
    for (int c = 1; c <= x2; c++){
        if (!backtrack(x1, x2-c, y1, y2)) {
            ans = 1;
        }
    }
    for (int c = 1; c <= y1; c++){
        if (!backtrack(x1, x2, y1-c, y2)) {
            ans = 1;
        }
    }
    for (int c = 1; c <= y2; c++){
        if (!backtrack(x1, x2, y1, y2-c)) {
            ans = 1;
        }
    }
    if (ans) {
        s.insert(vector<int>{x1, x2, y1, y2});
        // debug(x1, x2, y1, y2);
    }
    return ans;
}

void solve(){
    int a, b, n; cin >> a >> b >> n;
    int x1 = oo, x2 = -oo, y1 = -oo, y2 = oo;
    for (int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = max(y1, y);
        y2 = min(y2, y);
    }
    debug(x1-1, a-x2, b-y1, y2-1);
    bool now = backtrack(x1-1, a-x2, b-y1, y2-1);
    for (auto x: s){
        debug(x);
    }
    debug(now);
    if (now) cout << "Bajtek\n";
    else cout << "Bitek\n";
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