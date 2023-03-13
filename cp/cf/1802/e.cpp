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

struct TreeMax{
    vector<int>tab;
    int size = 1, N;

    TreeMax(int n){
        N = n-2;
        while (size < n) size*=2;
        tab.assign(2*size+2, -oo);
    }

    void clear(){
        tab.assign(2*size, -oo);
    }

    void update(int x, int v){
        x += size;
        tab[x] = max(tab[x], v);
        while (x){
            x/=2;
            tab[x] = max(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = -oo;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }

    int bez(int x){
        return max(query(0, x-1), query(x+1, N+1));
    }
};

void solve(){
    int n; cin >> n;
    vector<vector<int>>tab(n), mn(n);
    vector<int>s;
    vector<int>mx(n);
    for (int i = 0; i<n; i++){
        int k; cin >> k;
        tab[i].emplace_back(-oo);
        for (int j = 0; j<k; j++){
            int x; cin >> x;
            tab[i].emplace_back(x);
            s.emplace_back(x);
        }
    }
    s.emplace_back(-oo);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    vector<pair<int, T>>ord;
    for (int i = 0; i<n; i++){
        mn[i].emplace_back(-oo);
        for (int j = 1; j<(int)tab[i].size(); j++){
            tab[i][j] = lower_bound(s.begin(), s.end(), tab[i][j]) - s.begin();
            ord.emplace_back(tab[i][j], T{i, j});
            mn[i].emplace_back(max(mn[i].back(), tab[i][j]));
            mx[i] = max(mx[i], tab[i][j]);
        }    
        debug(i, tab[i], mn[i]);
    }
    sort(ord.begin(), ord.end(), [&](auto x, auto y){
        return x.first == y.first ? x.second.second > y.second.second : x.first < y.first;
    });
    int M = (int)s.size()+2;
    // vector<int>dp(M);
    TreeMax dp2(M+2);
    dp2.update(0, 0);
    map<T, int>dp;
    for (auto [val, pos]: ord){
        auto [i, j] = pos;
        if (mn[i][j-1] < val){
            dp[{val, i}] = max(dp[{val, i}], dp2.query(0, val-1) + 1);
        }
        if (j != 1) {//to nie jest pierwszy element
            if (mn[i][j-1] >= val){
                // cerr << "skip\n";
            } else {
                //istnieje mniejszy element na lewo
                dp[{val, i}] = max(dp[{val, i}], dp[{mn[i][j-1], i}]+1);
            }
        }
        if (j == (int)tab[i].size()-1 || val == mx[i]){
            // debug(val, dp[{val, i}]);
            dp2.update(val, dp[{val, i}]);
        }
        debug(val, i, j, dp[{val, i}]);
        // debug(dp);
    }
    int ans = dp2.query(0, M);
    for (auto x: dp) ans = max(ans, x.second);
    cout << ans << "\n";
    // exit(0);
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