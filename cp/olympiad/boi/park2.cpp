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
typedef long double ld;

struct circle{
    int x, y, r;
    circle(int _x = 0, int _y = 0, int _r = 0){ x = _x, y = _y, r = _r;}
    ld dist(circle &he){ return sqrtl(ld((he.x - x) * (he.x - x) + (he.y - y) * (he.y - y))) - (ld)he.r - (ld)r;}
    void read(){cin >> x >> y >> r;}
};

struct DSU{
    vector<int>rep, sz;

    DSU(int n){
        rep.resize(n);
        iota(rep.begin(), rep.end(), 0);
        sz.assign(n, 1);
    }

    int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}
    bool sameset(int a, int b){ return f(a) == f(b);}

    bool u(int a, int b){
        a = f(a); b = f(b);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        rep[b] = a;
        return 1;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    int w, h; cin >> w >> h;
    vector<circle>circ(n+1);
    for (int i = 1; i<=n; i++) circ[i].read();
    cerr << fixed << setprecision(3);
    vector<tuple<ld, int, int>>ord;
    for (int i = 1; i<=n; i++){
        for (int j = i+1; j<=n; j++){
            ord.emplace_back(circ[i].dist(circ[j]), i, j);
        }
        //sciany:
        ord.emplace_back((ld)(circ[i].x - circ[i].r), i, n+1); //lewa 
        ord.emplace_back((ld)(circ[i].y - circ[i].r), i, n+2); //dolna
        ord.emplace_back((ld)(w - circ[i].x - circ[i].r), i, n+3); //prawa
        ord.emplace_back((ld)(h - circ[i].y - circ[i].r), i, n+4); //gorna
    }    
    for (auto [d, i, j]: ord){
        debug(d, i, j);
    }
    DSU dsu(n+5);
    sort(ord.begin(), ord.end());
    
    vector<tuple<int, int, int>>que;
    for (int i = 1; i<=m; i++){
        int r, e; cin >> r >> e;
        e += n;
        que.emplace_back(r, e, i);
    }
    sort(que.begin(), que.end());
    int ptr = 0;
    vector<string>ans(m+1);
    auto check = [&](int a, int b){
        if (a == b) return 1;
        if (a > b) swap(a, b);
        //a < b, c < d
        int c = -1, d = -1;
        for (int j = n+1; j<=n+4; j++) {
            if (j == a || j == b) continue;
            if (c == -1) c = j;
            else d = j;
        }
        debug(a, b, c, d);
        if (b - a == 2){
            //naprzemianlegle
            if (dsu.sameset(c, d) || dsu.sameset(a, b) ||
                (a == n+1 && (dsu.sameset(a, c) || dsu.sameset(b, d))) || 
                (a == n+2 && (dsu.sameset(a, d) || dsu.sameset(b, c)))) return 0;
        } else {
            //sasiadujace
            int between = (b == n+4 ? (a == n + 1 ? a : b) : b);
            debug(between);
            for (int j = n+1; j<=n+4; j++){
                if (j != between && dsu.sameset(between, j)) {
                    return 0;
                }
            }
        }
        return 1;
    };
    for (int i = 0; i<m; i++){
        auto [r, e, idx] = que[i];
        while (ptr < (int)ord.size() && (ld)2 * r > get<0>(ord[ptr])){
            auto [d, a, b] = ord[ptr];
            debug(a, b);
            dsu.u(a, b);
            ptr++;
        }
        debug(r, e);
        for (int j = n+1; j<=n+4; j++){
            if (check(e, j)) {
                ans[idx] += (char)(j-n + '0');
            }
        }
    }
    for (int i = 1; i<=m; i++) cout << ans[i] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}