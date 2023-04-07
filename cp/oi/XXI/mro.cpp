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
    int n, t, k; cin >> n >> t >> k;
    vector<int>a(t+1);
    a[0] = -oo;
    for (int i = 1; i<=t; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<int>>g(n+1);
    T what;
    for (int i = 1; i<n; i++){
        int x, y; cin >> x >> y;
        if (i == 1) what = {x, y};
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<T>push(n+1, {-1, -1});
    push[what.first] = {k, k};
    push[what.second] = {k, k};
    for (int rep: vector<int>{what.first, what.second}){
        queue<int>q;
        q.push(rep);
        while (q.size()){
            int v = q.front(); q.pop();
            int m = (int)g[v].size()-1;
            for (auto x: g[v]){
                if (push[x].first == -1){
                    push[x] = {min(oo2, push[v].first * m), min(oo2, push[v].second * m + m-1)};
                    q.push(x);
                }
            }
        }
    }
    int ans = 0;
    a.emplace_back(oo);
    debug(a);
    debug(push);
    for (int v = 1; v <= n; v++){
        if ((int)g[v].size() == 1){
            int l = upper_bound(a.begin(), a.end(), push[v].first-1) - a.begin();
            int r = upper_bound(a.begin(), a.end(), push[v].second) - a.begin() - 1;
            debug(v, push[v], l, r);  
            if (a[l] >= push[v].first && a[r] <= push[v].second){
                ans += (r-l+1);
            }
        }
    }
    cout << ans*k << "\n";
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