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
const int oo2 = 1e9+7;

struct SCC{
    vector<vector<int>>g, gt;
    vector<int>post, valid, vis, numer, in;
    int curr = 0;

    SCC(int N){
        g.resize(N);
        gt.resize(N);
        vis.assign(N, 0);
        numer.assign(N, 0);
        in.assign(N, 0);
    }

    void clear(){
        for (auto x: valid){
            vis[x] = 0;
            numer[x] = 0;
            g[x].clear();
            in[x] = 0;
            gt[x].clear();
        }
        post.clear();
        valid.clear();
    }

    void dfs(int v){
        vis[v] = 1;
        for (auto x: g[v]){
            if (!vis[x]){
                dfs(x);
            }
        }
        post.emplace_back(v);
    }

    void add(int a, int b){
        g[a].emplace_back(b);
        gt[b].emplace_back(a);
        valid.emplace_back(a);
        valid.emplace_back(b);
    }

    void dfs2(int v){
        vis[v] = 1;
        numer[v] = curr;
        for (auto x: gt[v]){
            if (!vis[x]){
                dfs2(x);
            }
        }
    }

    void scc(){
        curr = 0;
        for (auto x: valid){
            if (!vis[x]){
                dfs(x);
            }
        }
        reverse(post.begin(), post.end());
        for (auto v: post) vis[v] = 0;
        for (auto v: post){
            if (!vis[v]){
                curr++;
                dfs2(v);
            }
        }
        // debug(numer);
    }

    int check(){
        for (auto v: post){
            for (auto x: g[v]){
                if (numer[v] != numer[x]){
                    in[numer[x]]++;
                }
            }
            vis[v] = 0;
        }
        for (auto v: post){
            if (!in[numer[v]]){
                dfs(v);
                break;
            }
        }
        int cnt = 0;
        for (auto x: vis) if (x) cnt++;
        return cnt;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>>edges;
    for (int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    SCC scc(n+1);
    int L = 0, R = oo2, ans = oo2;
    auto check = [&](int mid){
        scc.clear();
        for (auto [a, b, c]: edges){
            if (c <= mid){
                scc.add(a, b);
                scc.add(b, a);
            } else {
                scc.add(a, b);
            }
        }
        scc.scc(); 
        return (scc.check() == n);
    };
    while (R >= L){
        int mid = (L+R)/2;
        if (check(mid)){
            ans = mid;
            R = mid-1;
        } else {
            L = mid+1;
        }
    }
    if (ans == oo2) cout << "-1\n";
    else cout << ans << "\n";
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