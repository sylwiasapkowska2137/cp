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
const int K = 20, mod = 1e9+7;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){ return a+rng()%(b-a+1);}

int mul(int a, int b){
    return (a*b)%mod;
}

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

int add2(int a, int b){
    a += b;
    if (a >= mod) a-=mod;
    return a;
}

int power(int a, int b){
    if (!b) return 1LL;
    int k = power(a, b/2);
    k = mul(k, k);
    if (b&1) k = mul(k, a);
    return k;
}

int inv(int a){
    return power(a, mod-2);
}

T inv(T a){
    return {inv(a.first), inv(a.second)};
}

T f(T a, T b){
    return {mul(a.first, b.first), mul(a.second, b.second)};
}

struct Tree{
    vector<T>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, {1, 1});
    }

    void update(int x, T v){
        x += size;
        tab[x] = v;
        while (x) {
            x /= 2;
            tab[x] = f(tab[2*x], tab[2*x+1]);
        }
    }

    T query(int l, int r){
        T ans = {1, 1};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = f(ans, tab[l+1]);
            if (r&1) ans = f(ans, tab[r-1]);
        }
        return ans;
    }
};

void solve(){
    int n; cin >> n;
    vector<vector<int>>g(n+1);
    for (int i = 2; i<=n; i++){
        int p; cin >> p;
        g[p].emplace_back(i);
    }
    vector<int>L(n+1), R(n+1), depth(n+1);
    vector jump(n+1, vector<int>(K));
    int tt = 0;
    function<void(int, int)>dfs = [&](int v, int pa){
        jump[v][0] = pa;
        for (int i = 1; i<K; i++) jump[v][i] = jump[jump[v][i-1]][i-1];
        L[v] = ++tt;
        for (auto x: g[v]){
            depth[x] = depth[v]+1;
            dfs(x, v);
        }
        R[v] = ++tt;
    };
    dfs(1, 1);
    vector<int>B1(n+1), B2(n+1);
    for (int i = 1; i<=n; i++) {
        B1[i] = p(1, mod-1);
        B2[i] = p(1, mod-1);
    }
    Tree hashes(2*n+3);
    int r = p(1, mod-1);
    //we ask [1, R[v]-1];
    auto change = [&](int v, int val){
        hashes.update(L[v], {add2(r, B1[val]), add2(r, B2[val])});
        hashes.update(R[v], {inv(r+B1[val]), inv(r+B2[val])});
    };
    auto below_lca = [&](int a, int b){
        bool f = 0;
        if (depth[a] > depth[b]) {
            f = 1;
            swap(a, b);
        }
        for (int i = K-1; i>=0; i--){
            if (depth[b] - (1<<i) >= depth[a]) {
                b = jump[b][i];
            }
        }
        assert(a != b);
        for (int i = K-1; i>=0; i--){
            if (jump[a][i] != jump[b][i]){
                a = jump[a][i];
                b = jump[b][i];
            }
        }
        if (f) swap(a, b);
        return T{a, b};
    };
    auto lca = [&](int a, int b){
        if (depth[a] > depth[b]) swap(a, b);
        for (int i = K-1; i>=0; i--){
            if (depth[b] - (1<<i) >= depth[a]) {
                b = jump[b][i];
            }
        }
        if (a == b) return a;
        for (int i = K-1; i>=0; i--){
            if (jump[a][i] != jump[b][i]){
                a = jump[a][i];
                b = jump[b][i];
            }
        }
        return jump[a][0];
    };
    auto hash_on_path = [&](int a, int b){
        //directed from a to b
        T h1 = hashes.query(1, R[a]-1);
        T h2 = hashes.query(1, R[b]-1);
        int l = lca(a, b);        
        if (l == a || l == b){
            T x = (l == 1 ? T{1, 1} : hashes.query(1, R[jump[l][0]]-1));
            if (l == a) return f(h2, inv(x));
            return f(h1, inv(x));
        } else {
            return f(f(h1, h2), f(inv(hashes.query(1, R[l]-1)), 
                (l != 1 ? inv(hashes.query(1, R[jump[l][0]]-1)) : T{1, 1})
            ));   
        }
    };
    
    int ans = 1;
    vector<int>rep(n+1), sz(n+1, 1), mn(n+1), mx(n+1);
    vector<vector<int>>tab(n+1);
    iota(rep.begin(), rep.end(), 0);
    for (int i = 1; i<=n; i++) {
        cin >> mn[i] >> mx[i];
        tab[i].emplace_back(i);
        ans = mul(ans, mx[i] - mn[i] + 1);
        change(i, i);
    }

    function<int(int)> f = [&](int a){return a == rep[a] ? a : rep[a] = f(rep[a]);};
    auto u  = [&](int a, int b){
        a = f(a); b = f(b);
        if (a == b) return false;
        ans = mul(ans, inv(mx[a] - mn[a] + 1));
        ans = mul(ans, inv(mx[b] - mn[b] + 1));
        if (sz[a] < sz[b]) swap(a, b);
        for (auto v: tab[b]){
            change(v, a);
            tab[a].emplace_back(v);
        }
        sz[a] += sz[b];
        mn[a] = max(mn[a], mn[b]);
        mx[a] = min(mx[a], mx[b]);
        if (mn[a] > mx[a]) ans = 0;
        else ans = mul(ans, mx[a] - mn[a] + 1);
        rep[b] = a;
        return true;
    };
    auto half = [&](int a, int b){        
        if (L[b] <= L[a] && R[b] >= R[a]){
            //a w poddrzewie b
            int h = (depth[a] - depth[b])/2;
            for (int i = K-1; i>=0; i--){
                if (h&(1<<i)){
                    a = jump[a][i];
                }
            }
            return a;
        }
        if (L[a] <= L[b] && R[a] >= R[b]){
            //b w poddrzewie a
            int h = (depth[b] - depth[a]+1)/2;
            for (int i = K-1; i>=0; i--){
                if (h&(1<<i)){
                    b = jump[b][i];
                }
            }
            return b;
        }
        
        T now = below_lca(a, b);
        int l = jump[now.first][0];
        debug(a, b, depth[a] + depth[b] - 2 * depth[l]);
        int d = (depth[a] + depth[b] - 2 * depth[l])/2;
        if (depth[a] - depth[l] >= d){
            for (int i = K-1; i>=0; i--){
                if (d&(1<<i)){
                    a = jump[a][i];
                }
            }
            return a;
        } else {
            d = (depth[a] + depth[b] - 2 * depth[l] + 1)/2;
            for (int i = K-1; i>=0; i--){
                if (d&(1<<i)){
                    b = jump[b][i];
                }
            }
            return b;
        }
    };
    auto binsearch = [&](int a, int b, int c, int d){
        //skocz o 2^k na sciezce????
        T prev = {-1, -1};
        while (1){
            int l1 = a, r1 = b, l2 = c, r2 = d;
            //znajdz polowe sciezki ;ooo
            while (1){
                int v1 = half(l1, r1);
                int v2 = half(l2, r2);
                debug(l1, r1, l2, r2, v1, v2, hash_on_path(l1, v1), hash_on_path(l2, v2));
                bool flag = 0;
                if (v1 == l1 || v1 == r1) flag = 1;
                if (hash_on_path(l1, v1) == hash_on_path(l2, v2)){
                    l1 = v1;
                    l2 = v2;
                } else {
                    r1 = v1;
                    r2 = v2;
                }
                if (flag) break;
            }
            debug(r1, r2);
            if (make_pair(r1,r2) == prev) break;
            prev = {r1, r2};
            if (r1 != r2 && !u(r1, r2)) break;
        }
    };
    debug(ans);
    int q; cin >> q;
    while (q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (ans == 0){
            cout << ans << "\n";
            continue;
        }
        debug(a, b, c, d);
        binsearch(a, b, c, d);
        cout << ans << "\n";
        // return;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}