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
        // cerr << a << " " << b << "\n";
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
        for (auto v: valid){
            for (auto x: g[v]){
                if (numer[v] != numer[x]){
                    in[numer[x]]++;
                }
            }
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    int N = 2*n;
    SCC scc(N+2);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        b += n;
        if (a + n == b) scc.add(b, a);
        else scc.add(a, b);
    }
    string s; getline(cin, s);
    scc.scc();
    if (n == 1 || scc.curr == 1){
        cout << "No\n";
        return;
    } 
    cout << "Yes\n";
    vector<int>L, R;
    int r = 1;
    for (int i = n+1; i<=n+n; i++){
        if (scc.in[scc.numer[i]] == 0){
            r = scc.numer[i];
            break;
        }
    }
    debug(r);
    for (int i = n+1; i<=n+n; i++){
        if (scc.numer[i] == r){
            R.emplace_back(i-n);
        } else {
            L.emplace_back(i-n);
        }
    }
    cout << (int)L.size() << " " << (int)R.size() << "\n";
    for (auto x: L) cout << x << " ";
    cout << "\n";
    for (auto x: R) cout << x << " ";
    cout << "\n";
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