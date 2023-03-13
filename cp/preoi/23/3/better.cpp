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
vector<vector<int>>g, gt;
vector<int>valid, post, numer, vis, in;
int curr = 0;

void init(int N){
    g.resize(N);
    gt.resize(N);
    vis.assign(N, 0);
    numer.assign(N, 0);
    in.assign(N, 0);
}

void clear(){
    curr = 0;
    for (auto v: valid){
        // g[v].clear();
        // gt[v].clear();
        numer[v] = 0;
        vis[v] = 0;
        in[v] = 0;
    }
    // valid.clear();
    post.clear();
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

void add_edge(int a, int b){
    g[a].emplace_back(b);
    gt[b].emplace_back(a);
    // valid.emplace_back(a);
    // valid.emplace_back(b);
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

int scc(){
    for (auto x: valid){
        if (!vis[x]){
            dfs(x);
        }
    }
    reverse(post.begin(), post.end());
    for (auto x: valid) vis[x] = 0;
    for (auto x: post){
        if (!vis[x]){
            curr++;
            dfs2(x);
        }
    }
    int ile = curr;
    // debug(post);
    for (auto v: post){
        for (auto x: g[v]){
            if (numer[v] != numer[x]){
                in[numer[x]]++;
                if (in[numer[x]] == 1) ile--;
            }
        }
    }
    return ile;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<T>edges;
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
    }
    int q; cin >> q;
    vector<int>que(q);
    vector<bool> deleted(m);
    for (int i = 0; i<q; i++){
        cin >> que[i];
        --que[i];
        deleted[que[i]] = 1;
    }
    for (int i = 0; i<m; i++) {
        if (!deleted[i]){
            que.emplace_back(i);
        }
    }
    reverse(que.begin(), que.end());
    // debug(que);
    vector<int>ans(m);
    init(n+1);
    for (int i = 1; i<=n; i++) valid.emplace_back(i);
    for (int i = 0; i<m; i++){
        ans[i] = scc();
        add_edge(edges[que[i]].first, edges[que[i]].second);
        clear();
    }   
    reverse(ans.begin(), ans.end());
    for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}