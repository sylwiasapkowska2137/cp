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
    vector<string>tab;
    vector<pair<string, string>>edges;
    for (int i = 0; i<n; i++){
        string s, t; cin >> s >> t;
        edges.emplace_back(s, t);
        tab.emplace_back(s);
        tab.emplace_back(t); 
    }
    sort(tab.begin(), tab.end());
    tab.erase(unique(tab.begin(), tab.end()), tab.end());
    int S = (int)tab.size();
    vector<vector<int>>g(S+2);
    vector<int>vis(S+2);
    int cnt = 1;
    function<void(int)>dfs = [&](int v){
        vis[v] = cnt;
        for (auto x: g[v]){
            if (vis[x] == vis[v]){
                cout << "No\n";
                exit(0);
            }
            dfs(x);
        }
    };

    for (int i = 0; i<n; i++){
        int x = lower_bound(tab.begin(), tab.end(), edges[i].first) - tab.begin() + 1;
        int y = lower_bound(tab.begin(), tab.end(), edges[i].second) - tab.begin() + 1;
        g[x].emplace_back(y);
    }
    for (int i = 1; i<=S; i++){
        if (!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << "Yes\n";
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