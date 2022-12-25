//Sylwia Sapkowska
#include <bits/stdc++.h>
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
const int oo = 1e18, oo2 = 1e9+7, K = 11;
const int mod = 998244353;

struct Tree{
    vector<vector<int>>tab;
    vector<int>lazy;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, vector<int>(K, 0));
        for (int i = size; i<(int)tab.size(); i++) tab[i][1] = 1;
        for (int i = size-1; i>=1; i--) merge(i);
        lazy.assign(2*size, 0);
    }

    void calc(vector<int>&ans, int x, int lx, int rx, int l, int r){
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            for (int i = 0; i<K; i++){
                ans[max(i, 1LL)] += tab[x][i];
            }
            return;
        }
        int m = (lx+rx)/2;
        push(x, lx, rx);
        calc(ans, 2*x, lx, m, l, r);
        calc(ans, 2*x+1, m+1, rx, l, r);
        merge(x);
    }

    void push(int x, int lx, int rx){
        if (lx == rx || lazy[x] == 0) return;
        move(x);
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }

    void merge(int x){
        for (int i = 0; i<K; i++) tab[x][i] = tab[2*x][i] + tab[2*x+1][i];  
    }

    void move(int x){
        //move o lazy[x]
        if (!lazy[x]) return;
        // debug(x, lazy[x], tab[x]);
        if (lazy[x] > 0){
            //move right
            for (int i = K-1; i>=0; i--){
                if (i + lazy[x] < K) {
                    tab[x][i+lazy[x]] = tab[x][i];
                }
            }
            for (int i = 0; i<min(K, lazy[x]); i++){
                tab[x][i] = 0;
            }
        } else {
            for (int i = 0; i<K; i++){
                if (i + lazy[x] >= 0) {
                    tab[x][i+lazy[x]] = tab[x][i];
                }
            }
            for (int i = K-1; i>=max(0LL, K+lazy[x]); i--){
                tab[x][i] = 0;
            }
        }
        // debug(tab[x]);
        lazy[x] = 0;
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            lazy[x] += v;
            move(x);
            return;
        }
        int m = (lx+rx)/2;
        push(x, lx, rx);
        update(2*x, lx, m, l, r, v);
        update(2*x+1, m+1, rx, l, r, v);
        merge(x);
    }
};

struct sweep{
    int l, r, add;
    sweep(){}
    sweep(int _l, int _r, int _add){
        l = _l, r = _r, add = _add;
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
    vector<vector<sweep>>curr(2*n+2);
    auto add_rect = [&](vector<int>A, vector<int>B){
        int mn = *min_element(A.begin(), A.end());
        int mx = *max_element(A.begin(), A.end());
        int ymn = 1, ymx = 2*n;
        for (auto x: B){ // forbidden
            if (mn <= x && x <= mx) return;
            if (x < mn) ymn = max(ymn, x+1);
            if (x > mx) ymx = min(ymx, x-1);
        }
        if (ymn > ymx) return;
        curr[mn].emplace_back(ymn, ymx, 1);
        curr[mx+1].emplace_back(ymn, ymx, -1);
    };
    for (int i = 0; i < n; i++){
        int j = (i == 0 ? n-1 : i-1);
        add_rect({a[0][i]}, {a[1][i], a[0][j]});
        add_rect({a[1][i]}, {a[0][i], a[1][j]});
        add_rect({a[0][i], a[1][i]}, {a[0][j], a[1][j]});
    }
    Tree t(2*n+3);
    vector<int>ans(K);
    for (int i = 1; i<=2*n; i++){
        sort(curr[i].begin(), curr[i].end(), [](auto x, auto y){return x.add < y.add;});
        debug(i);
        for (auto [l, r, add]: curr[i]) {
            debug(l, r, add);
            t.update(1, 0, t.size-1, l, r, add);
        }
        t.calc(ans, 1, 0, t.size-1, i, 2*n);
    }
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