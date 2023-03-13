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

// #define int long long
typedef pair<int, int> T;
const int oo = 1e9+1e7, K = 30;

struct Tree{
    vector<int>tab, lazy;
    int size = 1;

    Tree(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, oo);
        lazy.assign(2*size, 0);
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
        for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
    }

    void push(int x, int lx, int rx){
        if (lx == rx || !lazy[x]) return;
        tab[2*x] += lazy[x];
        tab[2*x+1] += lazy[x];
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }

    void update(int x, int lx, int rx, int l, int r){
        push(x, lx, rx);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tab[x]++;
            lazy[x]++;
            return;
        }
        int m = (lx+rx)/2;
        update(2*x, lx, m, l, r);
        update(2*x+1, m+1, rx, l, r);
        tab[x] = min(tab[2*x], tab[2*x+1]);
    }

    int find(int x, int lx, int rx, int v){
        if (lx == rx) return lx;
        int m = (lx+rx)/2;
        push(x, lx, rx);
        if (tab[2*x+1] <= v) return find(2*x+1, m+1, rx, v);
        return find(2*x, lx, m, v);
    }

    int query(int x, int lx, int rx, int pos){
        if (lx == rx) return tab[x];
        int m = (lx+rx)/2;
        push(x, lx, rx);
        if (pos <= m) return query(2*x, lx, m, pos);
        return query(2*x+1, m+1, rx, pos);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int>a(n+1);
    a[0] = -oo;
    for (int i = 1; i<=n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    Tree t(n+2, a);
    while (q--){
        string s; cin >> s;
        if (s[0] == 'p'){
            int k; cin >> k;
            if (!k) continue;
            int val = t.query(1, 0, t.size-1, k);
            // debug(val);
            int L = t.find(1, 0, t.size-1, val-1);
            int R = t.find(1, 0, t.size-1, val);
            // debug(L, R);
            if (L > 0) {
                t.update(1, 0, t.size-1, 1, L);
                // debug(1, L);
            }
            int left = k - L;
            if (left) {
                t.update(1, 0, t.size-1, R-left+1, R);
                // debug(R-left+1, R);
            }
        } else {
            int l, r; cin >> l >> r;
            cout << t.find(1, 0, t.size-1, r) - t.find(1, 0, t.size-1, l-1) << "\n";
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