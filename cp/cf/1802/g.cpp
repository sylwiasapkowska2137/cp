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
const int oo = 1e18, oo2 = 1e9+7, K = 20;
const int mod = 1e9+7;
const int B1 = 2137, B2 = 2139;

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

struct Tree{
    vector<T>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, {0, 0});
    }

    T f(T a, T b){
        return {add2(a.first, b.first), add2(a.second, b.second)};
    }

    void update(int x, T v){
        // debug(x, v);
        x += size;
        tab[x] = v;
        while (x) {
            x /= 2;
            tab[x] = f(tab[2*x], tab[2*x+1]);
        }
    }

    T query(int l, int r){
        T ans = {0, 0};
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
    vector<T>range(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> range[i].first >> range[i].second;
    }
    int q; cin >> q;
    vector<int>L(n+1), R(n+1), depth(n+1), drev(n+1);
    vector<vector<int>>jump(n+1, vector<int>(K));
    int tt = 0;
    function<void(int, int)>dfs = [&](int v, int pa){
        jump[v][0] = pa;
        for (int i = 1; i<K; i++) jump[v][i] = jump[jump[v][i-1]][i-1];
        L[v] = ++tt;
        for (auto x: g[v]){
            depth[x] = depth[v]+1;
            drev[x] = drev[v] - 1;
            dfs(x, v);
        }
        R[v] = ++tt;
    };
    drev[1] = n;
    dfs(1, 1);
    debug(L);
    debug(R);
    vector<int>p1(n+1, 1), p2(n+1, 1);
    for (int i = 1; i<=n; i++){
        p1[i] = mul(p1[i-1], B1);
        p2[i] = mul(p2[i-1], B2);
    }
    Tree up(2*n+2), down(2*n+2);
    //we ask [1, R[v]-1];

    auto change = [&](int v, int val){
        //increasing up--->down
        debug(v, val, depth[v], drev[v]);
        down.update(L[v], {mul(p1[depth[v]], val), mul(p2[depth[v]], val)});
        down.update(R[v], {mul(mul(p1[depth[v]], val), mod-1), mul(mul(p2[depth[v]], val), mod-1)});
        //down--->up
        up.update(L[v], {mul(p1[drev[v]], val), mul(p2[drev[v]], val)});
        up.update(R[v], {mul(mul(p1[drev[v]], val), mod-1), mul(mul(p2[drev[v]], val), mod-1)});
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
    auto hash_on_path = [&](int a, int b){
        //directed from a to b
        if (depth[a] >= depth[b]){
            if (L[a] >= L[b] && R[a] <= R[b]){
                //a jest w poddrzewie b
                T h = up.query(L[b], R[a]-1);
                debug(a, b, L[b], R[a]-1, h);
                mul(h.first, inv(p1[drev[a]]));
                mul(h.second, inv(p2[drev[a]]));
                return h;
            } 
        } else {
            if (L[a] <= L[b] && R[a] >= R[b]){
                //b jest w poddrzewie a
                T h = down.query(L[a], R[b]-1);
                mul(h.first, inv(p1[depth[b]]));
                mul(h.second, inv(p2[depth[b]]));
                return h;
            } 
        }
        T below = below_lca(a, b);
        T h1 = up.query(L[below.first], R[a]-1);
        mul(h1.first, inv(p1[drev[a]]));
        mul(h1.second, inv(p2[drev[a]]));
        T h2 = down.query(L[jump[b][0]], R[b]-1);
        mul(h2.first, inv(p1[depth[b]]));
        mul(h2.second, inv(p2[depth[b]]));
        add(h1.first, h2.first);
        add(h1.second, h2.second);
        return h1;
    };
    
    int ans = 1;
    vector<int>rep(n+1), sz(n+1, 1), mn(n+1), mx(n+1);
    vector<vector<int>>tab(n+1);
    
    iota(rep.begin(), rep.end(), 0);
    for (int i = 1; i<(int)range.size(); i++) {
        tab[i].emplace_back(i);
        mn[i] = range[i].first;
        mx[i] = range[i].second;
        ans = mul(ans, range[i].second - range[i].first + 1);
    }

    function<int(int)> f = [&](int a){return a == rep[a] ? a : rep[a] = f(rep[a]);};

    auto u  = [&](int a, int b){
        a = f(a); b = f(b);
        if (a == b) return false;
        ans = mul(ans, inv(power(mx[a] - mn[a] + 1, sz[a])));
        ans = mul(ans, inv(power(mx[b] - mn[b] + 1, sz[b])));
        if (sz[a] < sz[b]) swap(a, b);
        debug(a, b, tab[a], tab[b]);
        for (auto v: tab[b]){
            change(v, a);
            tab[a].emplace_back(v);
        }
        sz[a] += sz[b];
        mn[a] = max(mn[a], mn[b]);
        mx[a] = min(mx[a], mx[b]);
        if (mn[a] > mn[b]) ans = 0;
        else ans = mul(ans, power(mx[a] - mn[a] + 1, sz[a]));
        rep[b] = a;
        return true;
    };
    for (int i = 1; i<=n; i++){
        change(i, i);
    }
    
    auto half = [&](int a, int b){
        if (depth[a] < depth[b]) swap(a, b);
        if (L[b] <= L[a] && R[b] >= R[a]){
            //a w poddrzewie b
            int h = (depth[b] - depth[a])/2;
            for (int i = K-1; i>=0; i--){
                if (h&(1<<i)){
                    a = jump[a][i];
                }
            }
            return a;
        }
        T now = below_lca(a, b);
        int lca = jump[now.first][0];
        int d = (depth[a] + depth[b] - 2 * depth[lca])/2;
        if (depth[a] - depth[lca] >= depth[b] - depth[now.second]){
            for (int i = K-1; i>=0; i--){
                if (d&(1<<i)){
                    b = jump[b][i];
                }
            }
            return b;
        } else {
            for (int i = K-1; i>=0; i--){
                if (d&(1<<i)){
                    a = jump[a][i];
                }
            }
            return a;
        }
    };

    auto binsearch = [&](int a, int b, int c, int d){
        //skocz o 2^k na sciezce????
        while (hash_on_path(a, b) != hash_on_path(c, d)){
            debug(hash_on_path(a, b), hash_on_path(c, d));
            int l1 = a, r1 = b, l2 = c, r2 = d;
            //find first pos where hashes differ
            //znajdz polowe sciezki ;ooo
            while (l1 != r1){
                int v1 = half(l1, r1);
                int v2 = half(l2, r2);
                if (hash_on_path(l1, v1) == hash_on_path(l2, v2)){
                    l1 = v1;
                    l2 = v2;
                } else {
                    r1 = v1;
                    r2 = v2;
                }
            }
            debug(r1, r2);
            u(r1, r2);
            debug(hash_on_path(a, b), hash_on_path(c, d));
            break;
        }
    };
    debug(ans);
    while (q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (ans == 0){
            cout << ans << "\n";
            continue;
        }
        debug(a, b, c, d);
        binsearch(a, b, c, d);
        cout << ans << "\n";
        return;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}