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
const int oo = 1e9, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

#define lc 2*x
#define rc 2*x+1
#define mid (lx+rx)/2
#define NO cout << "NIE\n";\
            exit(0);


struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, -oo);
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
        for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
    }

    int query(int l, int r){
        int ans = -oo;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }
};

void solve(){
    int n, s, m; cin >> n >> s >> m;
    int size = 1;
    while (size <= n) size*=2;
    int cnt = 2*size+1;
    int sz = 2*size+m+3;
    
    vector<vector<T>>g(sz);
    vector<vector<int>>idx(m+1);
    vector<int>a(sz, oo), b = {0}, in(sz);
    vector<T>tab, known;
    for (int i = 1; i<size; i++){
        g[i].emplace_back(2*i, 0);
        g[i].emplace_back(2*i+1, 0);
    }

    for (int i = 0; i<s; i++){
        int id, val; cin >> id >> val;
        a[id+size] = val;
        known.emplace_back(id, val);
    }
    function<void(int, int, int, int, int, int)>update = [&](int x, int lx, int rx, int l, int r, int from){
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            g[from].emplace_back(x, 1);
            return;
        }
        update(lc, lx, mid, l, r, from);
        update(rc, mid+1, rx, l, r, from);
    };

    for (int i = 0; i<m; i++){
        int l, r, k; cin >> l >> r >> k;
        tab.emplace_back(l, r);
        int prev = l;
        while (k--){
            int x; cin >> x;
            idx[i].emplace_back(x);
            g[x+size].emplace_back(cnt, 0);
            if (x - 1 >= prev) {
                update(1, 0, size-1, prev, x-1, cnt);
            }
            prev = x+1;
        }
        if (prev <= r) update(1, 0, size-1, prev, r, cnt);
        cnt++;
    }
    for (int i = 1; i<(int)g.size(); i++){
        for (auto [j, c]: g[i]){
            in[j]++;
        }
    }
    // return;
    debug(size);
    debug(in);
    queue<int>q;
    for (int i = 1; i<(int)g.size(); i++){
        if (!in[i]) {    
            q.push(i);
        }
    }
    if (q.empty()) {
        NO
    }
    while (q.size()){
        int v = q.front();q.pop();
        for (auto [x, c]: g[v]){
            a[x] = min(a[x], a[v]-c);
            
            debug(x, a[x]);
            in[x]--;
            if (!in[x]) {
                q.push(x);
            }
        }
    }
    int mx = *min_element(a.begin(), a.end());
    debug(mx);
    if (mx <= 0) {
        NO
    }
    for (int i = size+1; i<=size+n; i++) {
        b.emplace_back(a[i]);   
    }
    debug(b);
    for (auto [id, val]:known){
        if (b[id] != val){
            NO
        }
    }
    Tree t(n+2, b);
    debug(b);
    for (int i = 0; i<m; i++){
        auto [l, r] = tab[i];
        int prev = l;
        int mn = oo;
        for (auto id: idx[i]){
            mn = min(mn, b[id]);
        }
        for (auto id: idx[i]){
            if (id-1 >= prev){
                if (t.query(prev, id-1) >= mn){
                    NO
                }
            }
            prev = id+1;
        }
        if (prev <= r){
            if (t.query(prev, r) >= mn){
                NO
            }
        }
    }
    cout << "TAK\n";
    for (int i = 1; i<=n; i++) cout << b[i] << " ";
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