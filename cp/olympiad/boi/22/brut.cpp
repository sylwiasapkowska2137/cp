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
    vector<vector<int>>g(n+1);
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    int all = accumulate(a.begin(), a.end(), 0LL);
    for (int rep = 1; rep <= n; rep++){
        set<T>s;
        int sum = a[rep];
        vector<bool>used(n+1);
        used[rep] = 1;
        for (auto x: g[rep]){
            s.insert({a[x], x});
        }
        while (s.size() && s.begin()->first <= sum){
            auto [val, v] = *s.begin();
            s.erase(s.begin());
            used[v] = 1;
            sum += val;
            for (auto x: g[v]){
                if (!used[x]){
                    s.insert(T{a[x], x});
                }
            }
        }
        if (sum == all) cout << 1;
        else cout << 0;
    }
    cout << "\n";
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