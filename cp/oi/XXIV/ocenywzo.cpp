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
const int oo = 1e9+7;

struct Tree{
    vector<T>tab;
    vector<int>lazy;
    int size = 1;

    T f(T a, T b){
        if (a.first != b.first) return min(a, b);
        return T{a.first, a.second + b.second};
    }

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, {0, 1});
        lazy.assign(2*size, 0);
        for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        if (lx != rx) push(x);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r) {
            tab[x].first += v;
            lazy[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        update(2*x, lx, m, l, r, v);
        update(2*x+1, m+1, rx, l, r, v);
        tab[x] = f(tab[2*x], tab[2*x+1]);
    }

    T query(int x, int lx, int rx, int l, int r){
        if (lx != rx) push(x);
        if (lx > r || rx < l) return {oo, 0};
        if (lx >= l && rx <= r) return tab[x];
        int m = (lx+rx)/2;
        return f(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
    }

    void push(int x){
        tab[2*x].first += lazy[x];
        tab[2*x+1].first += lazy[x];
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    --q;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    a.emplace_back(n+1);
    n++;
    Tree t(n+2);    
    auto print = [&](){
        auto curr = t.query(1, 0, t.size-1, 1, n-1);
        debug(curr);
        if (curr.first) curr.second = 1;
        cout << curr.second << "\n";
    };

    vector<int>pos(n+1);
    for (int i = 1; i<=n; i++) pos[a[i]] = i;

    auto toggle = [&](int x, int coef){
        if (pos[x] < pos[x+1]) return;
        // if (pos[x+1] <= pos[x]-1) {
            debug(pos[x+1], pos[x]-1);
            t.update(1, 0, t.size-1, pos[x+1], pos[x]-1, coef);
        // }
    };
    for (int i = 1; i<n; i++){
        toggle(a[i], 1);
    }
    print();
    while (q--){
        int x, y; cin >> x >> y;
        
        int mn = min(a[x], a[y]);
        int mx = max(a[x], a[y]);
        if (mn > 1) toggle(mn-1, -1);
        toggle(mn, -1);
        toggle(mx, -1);
        if (mx - 1 != mn) toggle(mx-1, -1);
        swap(a[x], a[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
        if (mn > 1) toggle(mn-1, +1);
        toggle(mn, +1);
        toggle(mx, +1);
        if (mx - 1 != mn) toggle(mx-1, +1);
        print();
    }
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