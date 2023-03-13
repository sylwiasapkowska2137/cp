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

typedef pair<int, int> T;
const int oo = 1e9+7, mod = 1e9+7;

long long C2(long long a){
    return a*(a-1)/2;
}

void solve(){
    int n, m; cin >> n >> m;
    if (m <= n-1){
        cout << "BRAK\n";
        return;
    }
    vector<vector<int>>g(n+1), G(n+1);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<int>pre(n+1), low(n+1), dist(n+1, oo), cnt(n+1), valid;
    //low[v] = min czas wejscia wierzcholkow przechodzacych ponad wierzcholkiem v z poddrzewa v
    vector<long long>ret(n+1);
    vector<bool>vis(n+1);
    int tt = 0;
    vector<T>curr;
    set<T>s;
    auto solve = [&](vector<T>tab){
        int mx = 0, vv = 0;
        for (auto [a, b]: tab){
            G[a].emplace_back(b);
            G[b].emplace_back(a);
            valid.emplace_back(a);
            valid.emplace_back(b);
        }
        for (auto x: valid){
            if ((int)G[x].size() > mx){
                mx = (int)G[x].size();
                vv = x;
            }
        }
        queue<int>q;
        q.push(vv);
        for (auto &[a, b]: tab) s.insert({min(a, b), max(a, b)});
        debug(tab, vv);
        dist[vv] = 0;
        while (q.size()){
            int v = q.front();q.pop();
            for (auto x: G[v]){
                if (dist[x] == oo){
                    dist[x] = dist[v]+1;
                    debug(v, x);
                    s.erase({min(v, x), max(v, x)});
                    q.push(x);
                } 
            }
        }
        debug(s);
        if ((int)s.size()){
            for (auto &[a, b]: s){
                cnt[a]++;
                cnt[b]++;
            }
            bool ok = 0;
            auto now = *s.begin();
            for (auto v: valid){
                if (cnt[v] == (int)s.size()){
                    debug(v, dist[v]);
                    ret[dist[now.first]+dist[now.second]+1]+=C2(mx);
                    ok = 1;
                    break;
                }
            }
            T curr = {dist[now.first], dist[now.second]};
            if (curr.first > curr.second) swap(curr.first, curr.second);
            for (auto [a, b]: s){
                T tmp = {min(dist[a], dist[b]), max(dist[a], dist[b])};
                if (curr != tmp){
                    ok = 0;
                    break;
                }
            }   
            if (!ok){
                cout << "NIE\n";
                exit(0);
            }
        }
        for (auto x: valid){
            G[x].clear();
            dist[x] = oo;
            cnt[x] = 0;
        }
        valid.clear();
        s.clear();
    };

    function<void(int, int)>dfs = [&](int v, int pa){
        vis[v] = 1;
        pre[v] = low[v] = ++tt;
        int child = 0;
        for (auto x: g[v]){
            if (x == pa) continue;
            if (!vis[x]) {
                curr.emplace_back(v, x);
                dfs(x, v);
                low[v] = min(low[v], low[x]);
                child++;
                if ((v == 1 && child > 1) || low[x] >= pre[v]){
                    vector<T>tab;
                    while (1){
                        auto c = curr.back(); curr.pop_back();
                        tab.emplace_back(c);
                        if (c.first == v && c.second == x) break;
                    }
                    solve(tab);
                }
            } else {
                low[v] = min(low[v], pre[x]);
                if (pre[x] < pre[v]){
                    curr.emplace_back(v, x);
                }
            }
        }
    };
    dfs(1, 1);
    debug(ret);
    int pv = -1;
    for (int i = 1; i<=n; i++){
        if (ret[i] && pv != -1){
            cout << "NIE\n";
            return;
        }
        if (ret[i]) pv = i;
    }
    cout << "TAK\n";
    cout << pv << " " << ((ret[pv] * 2 * pv)%mod+mod)%mod << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}