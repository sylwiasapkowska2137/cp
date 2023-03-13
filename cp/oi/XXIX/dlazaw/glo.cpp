//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "glolib.h"
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

void __print(int x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ", "; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? ", " : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;

void solve(){
    int n = daj_n();
    vector<vector<int>>g(n+1);
    vector<int> par(n+1);
    par[1] = 1;
    for (int v = 2; v<=n; v++){
        int p = daj_przelozonego(v);
        g[p].emplace_back(v);
        par[v] = p;
        // cout << p << " " << v << "\n";
    }
    set<T>s;
    vector<int>leaf;
    vector<int>ptr(n+1, oo2);
    function<void(int)>dfs = [&](int v){
        for (auto x: g[v]){
            dfs(x);
            ptr[v] = min(ptr[v], ptr[x]);
        }
        if (g[v].empty()) {
            ptr[v] = (int)leaf.size();
            s.insert({ptr[v], v});
            leaf.emplace_back(v);
        }
    };
    dfs(1);
    vector<int>syn(n+1);
    // debug(ptr);
    vector<int>used(n+1);
    int v = leaf[0];
    used[1] = 1;
    for (int cnt = (int)leaf.size(); cnt >= 0; cnt-=2){
        int x = ruch(v);
        for (int tmp = v; !used[tmp] && tmp != 1; tmp = par[tmp]){
            used[tmp] = 1;
        }
        for (;!used[x] && x != 1; x = par[x]) {
            used[x] = 1;
        }
        // debug(x);
        while (used[g[x][syn[x]]]) syn[x]++;
        int u = g[x][syn[x]];
        auto it = s.lower_bound({ptr[u], -1});
        assert(it != s.end());
        v = it->second;
        s.erase(it);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
