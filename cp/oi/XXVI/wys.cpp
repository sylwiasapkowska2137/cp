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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
int n;

#define m (lx+rx)/2
struct Tree{
    vector<T>tab;
    vector<int>lazy;
    int size = 1;

    T f(T a, T b){
        return T{max(a.first, b.first), max(a.second, b.second)};
    }

    Tree(vector<int>&a){
        while (size <= n) size*=2;
        tab.assign(2*size, {-oo, -oo});
        lazy.assign(2*size, 0);
        for (int i = 0; i<(int)a.size(); i++) tab[i+size] = {a[i] + i, a[i]};
        for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        if (lx != rx) push(x);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tab[x].first += v;
            tab[x].second += v;
            lazy[x] += v;
            return;
        }
        update(2*x, lx, m, l, r, v);
        update(2*x+1, m+1, rx, l, r, v);
        tab[x] = f(tab[2*x], tab[2*x+1]);
    }

    void push(int x){
        if (lazy[x] == 0) return;
        for (int k: {2*x, 2*x+1}){
            tab[k].first += lazy[x];
            tab[k].second += lazy[x];
            lazy[k] += lazy[x];
        }
        lazy[x] = 0;
    }

    int lower_bound(int x, int lx, int rx, int v){ //ostatni indeks ≥v
        if (lx == rx) return lx;
        push(x);
        if (tab[2*x+1].second >= v) return lower_bound(2*x+1, m+1, rx, v);
        return lower_bound(2*x, lx, m, v);
    }

    int query(int x, int lx, int rx){
        if (lx == rx) return lx;
        push(x);
        if (tab[2*x+1].first == tab[1].first) return query(2*x+1, m+1, rx);
        return query(2*x, lx, m);
    }

    int val(int x, int lx, int rx, int pos){
        if (lx == rx) return tab[x].second;
        push(x);
        if (pos <= m) return val(2*x, lx, m, pos);
        else return val(2*x+1, m+1, rx, pos);
    }

    int solve(int x, int lx, int rx, int mx = -oo){
        if (lx == rx) return lx;
        push(x);
        if (val(2*x+1, m+1, rx, m+1)+n >= max(mx, tab[2*x].first)){
            return solve(2*x+1, m+1, rx, max(mx, tab[2*x].first));
        }
        return solve(2*x, lx, m, mx);
    }
};
#undef m

void solve(){
    int q; cin >> n >> q;
    vector<int>a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    a.emplace_back(oo);
    sort(a.rbegin(), a.rend());
    debug(a);
    a[0] = -oo;
    Tree t(a);
    while (q--){
        char c; cin >> c;
        if (c == 'Z'){
            cout << t.solve(1, 0, t.size-1) << "\n";
        } else if (c == 'B'){
            int x, delta; cin >> x >> delta;
            int pos = t.lower_bound(1, 0, t.size-1, x);
            if (pos >= 1) t.update(1, 0, t.size-1, 1, pos, delta);
        } else {
            int x, delta; cin >> x >> delta;
            int pos = t.lower_bound(1, 0, t.size-1, x+1)+1;
            if (pos <= n) t.update(1, 0, t.size-1, pos, n, -delta);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}