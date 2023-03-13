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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 11;
const int mod = 998244353;

struct Tree{
    vector<vector<T>>tab;
    vector<int>lazy;
    int size = 1;

    Tree(int n){
        while (size < n) size *= 2;
        tab.assign(2*size, vector<T>(K, {oo2, 0}));
        lazy.assign(2*size, 0);
    }

    void init(int x, int lx, int rx, int l, int r){
        if (lx > r || rx < l) return;
        if (lx == rx) {
            tab[x][0] = {0, 1};
            return;
        }
        int m = (lx+rx)/2;
        init(2*x, lx, m, l, r);
        init(2*x+1, m+1, rx, l, r);
        merge(x);
    }

    void merge(int x){
        int l = 0, r = 0;
        for (int i = 0; i<K; i++){
            if (tab[2*x][l].first == tab[2*x+1][r].first){
                tab[x][i] = {tab[2*x][l].first, tab[2*x][l].second + tab[2*x+1][r].second};
                l++;r++;
            } else if (tab[2*x][l].first < tab[2*x+1][r].first) tab[x][i] = tab[2*x][l++];
            else tab[x][i] = tab[2*x+1][r++];
        }
    }

    void add(int x, int b){
        lazy[x] += b;
        for (int i = 0; i<K; i++) {
            tab[x][i].first += b;
        }
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            add(x, v);
            return;
        }
        int m = (lx+rx)/2;
        add(2*x, lazy[x]);
        add(2*x+1, lazy[x]);
        lazy[x] = 0;
        update(2*x, lx, m, l, r, v);
        update(2*x+1, m+1, rx, l, r, v);
        merge(x);
    }
};

void solve(){
    int n, k; cin >> n >> k;
    vector a(2, vector<int>(n));
    for (int rep = 0; rep < 2; rep++){
        for (int i = 0; i < n; i++){
            cin >> a[rep][i];
        }
    }
    vector<vector<tuple<int, int, int>>>curr(2*n+2);
    auto add = [&](int aa, int b, int c, int d){
        if (aa <= b && c <= d){
            curr[aa].emplace_back(c, d, 1);
            curr[b+1].emplace_back(c, d, -1);
        }
    };
    auto add_rect = [&](pair<int, int>A, pair<int, int>B){
        int mn = min(A.first, A.second);
        int mx = max(A.first, A.second);
        int ymn = 1, ymx = 2*n;
        for (auto x: {B.first, B.second}){ // forbidden
            if (mn <= x && x <= mx) return;
            if (x <= mn) ymn = max(ymn, x+1);
            if (x >= mx) ymx = min(ymx, x-1);
        }
        add(ymn, mn, mx, ymx);
    };
    for (int i = 0; i < n; i++){
        int j = (i == 0 ? n-1 : i-1);
        add_rect({a[0][i], a[0][i]}, {a[1][i], a[0][j]});
        add_rect({a[1][i], a[1][i]}, {a[0][i], a[1][j]});
        add_rect({a[0][i], a[1][i]}, {a[0][j], a[1][j]});
    }
    Tree t(2*n+3);
    t.init(1, 0, t.size-1, 1, 2*n);
    vector<int>ans(K);
    for (int i = 1; i<=2*n; i++){
        for (auto [l, r, d]: curr[i]) t.update(1, 0, t.size-1, l, r, d);
        for (int j = 0; j<K; j++){
            if (t.tab[1][j].first <= k){
                ans[t.tab[1][j].first] += t.tab[1][j].second;
            }
        }
        t.update(1, 0, t.size-1, i, i, oo2);
    }
    ans[1] += ans[0];
    for (int i = 1; i<=k; i++) cout << ans[i] << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}