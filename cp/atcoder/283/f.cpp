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

struct TreeMin{
    vector<int>tab;
    int size = 1;

    TreeMin(int n){
        while (size < n) size*=2;
        tab.assign(2*size, oo);
    }

    void update(int x, int v){
        x += size;
        tab[x] = min(tab[x], v);
        while (x){
            x/=2;
            tab[x] = min(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = oo;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = min(ans, tab[l+1]);
            if (r&1) ans = min(ans, tab[r-1]);
        }
        return ans;
    }

    void clear(){
        tab.assign(2*size, oo);
    }
};

void solve(){
    int n; cin >> n;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<T>p;
    for (int i = 1; i<=n; i++){
        p.emplace_back(i, a[i]);
    }
    sort(p.begin(), p.end(), [](auto x, auto y){ return x.second < y.second;});
    TreeMin t(n+2);
    vector<int>ans(n+1, oo);
    for (auto [x, y]: p){
        int c = t.query(1, x);
        if (c < oo2) ans[x] = min(ans[x], x + y + c);
        t.update(x, - y - x);
    }
    debug(ans);
    t.clear();
    for (auto [x, y]: p){
        // debug(t.query(x, n));
        int c = t.query(x, n);
        if (c < oo2) {
            ans[x] = min(ans[x], y - x + c);
        }
        t.update(x, x - y);
    }
    t.clear();
    reverse(p.begin(), p.end());
    debug(ans);
    for (auto [x, y]: p){
        int c = t.query(x, n);
        if (c < oo2) ans[x] = min(ans[x], - x - y + c);
        t.update(x, x + y);
    }
    debug(ans);
    t.clear();
    for (auto [x , y]: p){
        int c = t.query(1, x);
        debug(c);
        if (c < oo2) ans[x] = min(ans[x], x - y + c);
        t.update(x, y-x);
    }
    for (int i = 1; i<=n; i++) cout << ans[i] << " ";
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