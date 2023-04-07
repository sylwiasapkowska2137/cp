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
const int oo = 1e18, oo2 = 1e9+7, K = 18;

struct Q{
    int a, b, x, y;
    void read(){
        cin >> a >> b >> x >> y;
    }
};

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < (int)s.size(); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
    void clear(){s.assign((int)s.size(), 0);}
};

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>>g(n+1);
    vector<T>edges = {{0, 0}};
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        edges.emplace_back(a, b);
    }
    vector<T>checkpoints(m);
    for (auto &[id, v]: checkpoints) cin >> id >> v;
    sort(checkpoints.begin(), checkpoints.end(), [](auto x, auto y){return x.second < y.second;});
    vector<Q>que(q);
    for (int i = 0; i<q; i++) que[i].read();
    vector<int>depth(n+1), pre(n+1), post(n+1);
    vector up(n+1, vector<int>(K));
    int tt = 0;
    function<void(int, int)>dfs = [&](int v, int pa){
        up[v][0] = pa;
        pre[v] = ++tt;
        for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
        for (auto x: g[v]){
            if (x == pa) continue;
            depth[x] = depth[v]+1;
            dfs(x, v);
        }
        post[v] = ++tt;
    };
    dfs(1, 1);
    auto lca = [&](int a, int b){
        if (depth[a] > depth[b]) swap(a, b);
        for (int i = K-1; i>=0; i--){
            if (depth[b] - (1<<i) >= depth[a]){
                b = up[b][i];
            }
        }
        if (a == b) return a;
        for (int i = K-1; i>=0; i--){
            if (up[a][i] != up[b][i]){
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };
    vector<int>ans(q, -1);
    vector<int>L(q, 0), R(q, m-1);
    FT t(2*n+2);
    debug(checkpoints);
    auto add = [&](int i, int v){
        auto [a, b] = edges[checkpoints[i].first];
        if (depth[a] < depth[b]) swap(a, b);
        //a jest nizej
        debug(a, v);
        t.update(pre[a], v);
        t.update(post[a], -v);
    };
    auto sum = [&](int a, int b){
        int l = lca(a, b);
        // debug(a, b, t.query(0, post[a]-1), t.query(0, post[b]-1));
        return t.query(post[a]) + t.query(post[b]) - 2 * t.query(post[l]);
    };
    while (1){
        bool any = 0;
        t.clear();
        vector<vector<int>> event(m+1);
        for (int i = 0; i<q; i++){
            if (L[i] <= R[i]){
                debug(i, L[i], R[i], (L[i]+R[i])/2);
                event[(L[i]+R[i])/2].emplace_back(i);
                any = 1;
            }
        }
        if (!any) break;
        int ptr = -1;
        for (int i = 0; i<=m; i++){
            if (event[i].empty()) continue;
            while (ptr + 1 <= i){
                ptr++;
                debug(ptr);
                add(ptr, checkpoints[ptr].second);
            }
            for (auto id: event[i]){
                // debug(i, id, sum(que[id].a, que[id].b), que[id].y);
                if (sum(que[id].a, que[id].b) <= que[id].y){
                    ans[id] = i;
                    L[id] = i+1;
                } else {
                    R[id] = i-1;
                }
            }
        }
    }
    debug(ans);
    t.clear();
    vector<vector<int>> event(m+1);
    for (int i = 0; i<q; i++){
        if (ans[i] == -1) continue;
        event[ans[i]].emplace_back(i);
    }
    int ptr = -1;
    for (int i = 0; i<=m; i++){
        if (event[i].empty()) continue;
        while (ptr + 1 <= i){
            ptr++;
            debug(ptr);
            add(ptr, 1);
        }
        for (auto id: event[i]){
            // debug(i, id, sum(que[id].a, que[id].b), que[id].y);
            ans[id] = sum(que[id].a, que[id].b);
        }
    }
    debug(ans);
    t.clear();
    for (int i = 0; i<m; i++) add(i, 1);
    for (int i = 0; i<q; i++) {
        if (ans[i] == -1) ans[i] = 0;
        int now = que[i].x - (sum(que[i].a, que[i].b) - ans[i]);
        if (now < 0) now = -1;
        cout << now << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}