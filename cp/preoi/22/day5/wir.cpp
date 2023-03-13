//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using namespace __gnu_pbds;

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

typedef pair<int, int> T;
const int oo = 1e9+7;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    int n, que; cin >> n >> que;
    vector<int>c(n-2);
    for (int i = 0; i<(int)c.size(); i++) cin >> c[i];
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>par(n+1), dist(n+1, oo);
    function<void(int, int)>dfs = [&](int v, int pa){
        par[v] = pa;
        for (auto x: g[v]){
            if (x != pa){
                dfs(x, v);
            }
        }
    };
    dfs(1, 1);
    vector<int>rep(n+1), sz(n+1), now, numer(n+1, 1); 
    //numer[v] => numer koloru wierzcholka v, rep[c] -> reprezentant spojnego podgrafu koloru c
    sz[1] = n;
    rep[1] = 1;
    int cnt = 1;
    queue<T>q[2];
    function<void(int, int, int)>dfs2 = [&](int v, int pa, int nr){
        numer[v] = cnt;
        for (auto x: g[v]){
            if (x == pa || numer[x] != nr) continue;
            dfs2(x, v, nr);
        }
    };
    auto print = [&](){
        debug(que);   
        for (int i = 0; i < 2; i++){
            while (q[i].size()){
                q[i].pop();
            }
        }     
        q[0].push({que, 0});
        q[1].push({par[que], 0});
        dist[que] = 0;
        dist[par[que]] = 0;
        int sub[2] = {1, 1};
        now = {que, par[que]};
        while ((int)q[0].size() && (int)q[1].size()){
            for (int which = 0; which < 2; which++){
                auto [v, i] = q[which].front(); 
                q[which].pop();
                int x = g[v][i];
                if (dist[x] == oo && numer[x] == numer[v]){
                    dist[x] = dist[v] + 1;
                    now.emplace_back(x);
                    q[which].push(T{x, 0});
                    sub[which]++;
                }
                if (i + 1 < (int)g[v].size()) {
                    q[which].push(T{v, i+1});
                }
            }
        }  
        for (auto x: now) dist[x] = oo;
        now.clear();

        int high = rep[numer[par[que]]];
        int ans = ((int)q[0].size() ? sz[high] - sub[1] : sub[0]);
        sz[high] -= ans;
        sz[que] += ans;
        debug(sz, high, ans, sub[0], sub[1]);
        ++cnt;
        if (q[0].size()){
            //poddrzewo que jest wieksze -> naddrzewo jest mniejsze, zmieniamy jego numerki
            rep[cnt] = rep[numer[que]];
            rep[numer[que]] = que;
            dfs2(par[que], que, numer[par[que]]);
        } else {
            //naddrzewo que jest wieksz, poddrzewo que jest mniejsze
            rep[cnt] = que;
            dfs2(que, par[que], numer[que]);
        }
        debug(numer, rep);
        return ans;
    };
    ordered_set s;
    for (int i = 2; i<=n; i++) s.insert(i);
    s.erase(que);
    for (int i = 0; i<n-2; i++){
        int y = print();
        cout << y << "\n";
        int l = (y + c[i])%((int)s.size());
        if (l < 0) l += (int)s.size();
        que = *s.find_by_order(l);
        s.erase(que);
        debug(l, s, que);
    }
    cout << print() << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}