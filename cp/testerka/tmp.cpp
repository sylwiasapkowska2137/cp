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
const int mod = 998244353;

struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    int query(int x){
        int ans = 0;
        x += size;
        while (x){
            ans += tab[x];
            x/=2;
        }
        return ans;
    }

    void update(int l, int r, int v){
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) tab[l+1] += v;
            if (r&1) tab[r-1] += v;
        }
    }
};

void move_a_bit(int &x, int &y){
    int m = max({x, -x, y, -y});
    int d = (oo2 + m-1)/m;
    x *= d;
    y *= d;
    x++;
}

void solve(){
    int n, X1, Y1, X2, Y2; cin >> n >> X1 >> Y1 >> X2 >> Y2;
    vector<T>p(n+1);
    if (X1 * Y2 == X2 * Y1) move_a_bit(X2, Y2);
    if (X1 * Y2 - X2 * Y1 < 0) {
        swap(X1, X2);
        swap(Y1, Y2);
    }
    vector<int>sx, sy;
    for (int i = 1; i<=n; i++){
        int a, b; cin >> a >> b;
        p[i].first = X1 * b - Y1 * a;
        p[i].second = Y2 * a - X2 * b;
        sx.emplace_back(p[i].first);
        sy.emplace_back(p[i].second);
    }
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());
    sx.erase(unique(sx.begin(), sx.end()), sx.end());
    sy.erase(unique(sy.begin(), sy.end()), sy.end());
    for (int i = 1; i<=n; i++) {
        p[i].first = lower_bound(sx.begin(), sx.end(), p[i].first) - sx.begin() + 1;
        p[i].second = lower_bound(sy.begin(), sy.end(), p[i].second) - sy.begin() + 1;
    }
    debug(p);
    vector<int>need(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> need[i];
        need[i] = min(need[i], i);
    }
    Tree t(n+2);
    vector<int>ans(n+1, oo);
    function<void(int, int, vector<int>)>rec = [&](int l, int r, vector<int>idx){
        if (l > r || idx.empty())  return;
        int m = (l+r)/2;
        debug(l, r, m, idx);
        vector<int>tab;
        for (int i = l; i<=m; i++) {
            if (ans[i] > l){
                tab.emplace_back(-i);
            }
        }
        for (auto i: idx) {
            tab.emplace_back(i);
        }
        sort(tab.begin(), tab.end(), [&](auto x, auto y){
            if (abs(x) == abs(y)) return x < y;
            return p[abs(x)].second == p[abs(y)].second ? p[abs(x)].first < p[abs(y)].first : p[abs(x)].second < p[abs(y)].second;
        });
        debug(tab);
        vector<int>L, R;
        for (auto id: tab){
            if (id < 0){
                // debug(-id, ans[-id]);
                // cerr << "zapalam " << -id << "\n"; 
                // debug(id, posa[-id], n);
                t.update(p[-id].first, n, +1);
            } else {
                // debug(id, posa[id], t.query(posa[id]));
                int c = t.query(p[id].first);
                // cerr << "sprawdzam ";
                // debug(id, c, need[id]);
                if (c >= need[id]){
                    if (id > m) t.update(p[id].first, n, +1);
                    L.emplace_back(id);
                    ans[id] = m;
                } else {
                    need[id] -= c;
                    R.emplace_back(id);
                }
            }
        }
        for (auto x: L){
            if (x > m) {
                t.update(p[x].first, n, -1);
            }
        }
        debug(L, R);
        for (int i = l; i<=m; i++) {
            t.update(p[i].first, n, -1);
        }
        
        rec(l, m-1, L);
        rec(m+1, r, R);
    };
    vector<int>all(n);
    iota(all.begin(), all.end(), 1);
    rec(1, n, all);
    for (int i = 1; i<=n; i++) cout << min(i, ans[i]) << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}