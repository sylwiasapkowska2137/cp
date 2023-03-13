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
    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<multiset<T>>paths(n+1); //dlugosci sciezek konczacych sie w dzieciach v
    vector<T>dp(n+1, {oo, oo}), koniec(n+1, {-1, -1});
    function<void(int, int)>dfs = [&](int v, int pa){
        if (v != 1 && (int)g[v].size() == 1) dp[v] = {0, v};
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
            if (dp[v].first > dp[x].first) dp[v] = {dp[x].first, x};
        }
        // debug(v, dp[v]);
        for (auto x: g[v]){
            if (x == pa || x == dp[v].second) continue;
            paths[v].insert({dp[x].first, x});
            koniec[x] = dp[x];
        }
        dp[v].first++;
        if (v == 1) koniec[v] = dp[v];
    };
    dfs(1, 1);
    multiset<int>all;
    for (int i = 1; i<=n; i++){
        if (koniec[i].first != -1) {
            all.insert(koniec[i].first);
        }
    }
    koniec = dp;
    int ans = 1;
    function<void(int, int)>reroot = [&](int v, int pa){
        ans = max(ans, *all.begin());
        debug(v, all);
        for (auto x: g[v]){
            if (x == pa) continue;
            debug(v, x);
            if (paths[v].empty()){
                //????
                continue;
            }
            auto [len, to] = *paths[v].begin();
            debug(len, to);
            //sciezka z x 
            all.erase(all.find(koniec[v].first));
            koniec[v].first--;
            all.insert(koniec[v].first);
            //
            T prev = koniec[v];
            koniec[v] = {len+1, to};
            all.erase(all.find(len));
            paths[v].erase(paths[v].begin());
            paths[x].insert({len+1, v});
            all.insert(len+1);

            reroot(x, v);
            
            //undo
            all.erase(all.find(len+1));
            all.insert(len);
            paths[x].erase(paths[x].find({len+1, v}));
            paths[v].insert({len, to});
            koniec[v] = prev;
            all.erase(all.find(koniec[v].first));
            koniec[v].first++;
            all.insert(koniec[v].first);
        }
    };
    reroot(1, 1);
    cout << ans << "\n";
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