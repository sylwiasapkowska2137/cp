//Sylwia Sapkowska
//bombbbbbel sort
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

const int oo = 1e9+7;
typedef pair<int, int> T;

struct TreeSum{
    vector<int>tab, lazy;
    int size = 1;

    TreeSum(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
        lazy.assign(2*size, 0); 
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        if (lx != rx) push(x);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tab[x] += v;
            lazy[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        update(2*x, lx, m, l, r, v);
        update(2*x+1, m+1, rx, l, r, v);
        tab[x] = max(tab[2*x], tab[2*x+1]);
    }

    void push(int x){
        tab[2*x] += lazy[x];
        tab[2*x+1] += lazy[x];
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }

    int query(int x, int lx, int rx, int l, int r){
        if (lx != rx) push(x);
        if (lx > r || rx < l) return -oo;
        if (lx >= l && rx <= r) return tab[x];
        int m = (lx+rx)/2;
        return max(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
    }
};

vector<int> countScans(vector<int>a, vector<int>x, vector<int>v){
    int n = (int)a.size();
    int q = (int)x.size();
    vector<pair<int, int>>s;
    s.emplace_back(-oo, -oo);
    for (int i = 0; i<n; i++) s.emplace_back(a[i], i);
    for (int i = 0; i<q; i++) s.emplace_back(v[i], x[i]);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    // debug(s);
    int mx = (int)s.size()-1;
    TreeSum t(mx+3);
    auto get = [&](pair<int, int>now) -> int {
        return lower_bound(s.begin(), s.end(), now) - s.begin();
    };
    for (int i = 0; i < n; i++){
        auto curr = get(T{a[i], i});
        t.update(1, 0, t.size-1, curr, mx, -1);
        t.update(1, 0, t.size-1, curr, curr, i+1);
    }
    //ans = max(i-(less or equal to ai))
    // t.d();
    vector<int>ans;
    for (int i = 0; i<q; i++){
        auto nxt = get(T{v[i], x[i]});
        auto curr = get(T{a[x[i]], x[i]});
        a[x[i]] = v[i];
        t.update(1, 0, t.size-1, curr, curr, -(x[i]+1));
        t.update(1, 0, t.size-1, curr, mx, 1);
        t.update(1, 0, t.size-1, nxt, nxt, x[i]+1);
        t.update(1, 0, t.size-1, nxt, mx, -1);
        // t.d();
        ans.emplace_back(t.query(1, 0, t.size-1, 1, mx));
    }
    return ans;
}

/*
void solve(){
    int n, q; cin >> n >> q;
    vector<int>a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    vector<int>x(q), v(q);
    for (int i = 0; i < q; i++) cin >> x[i] >> v[i];
    debug(countScans(a, x, v));
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
*/
