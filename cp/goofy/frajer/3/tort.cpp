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
    vector<T>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, {oo, oo});
    }
    
    T merge(T a, T b){
        T ret = {oo, oo};
        if (a.first < b.first) swap(a, b);
        if (a.first == b.first){
            ret = {a.first, a.first};
        } else {
            ret = {b.first, min(b.second, a.first)};
        }
        return ret;
    }

    void update(int x, int v){
        x += size;
        tab[x] = merge(tab[x], T{v, oo});
        while (x){
            x/=2;
            tab[x] = merge(tab[2*x], tab[2*x+1]);
        }
    }

    T query(int l, int r){
        T ans = {oo, oo};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = merge(ans, tab[l+1]);
            if (r&1) ans = merge(ans, tab[r-1]);
        }
        return ans;
    }
};

void solve(){
    int n, q, k; cin >> n >> q >> k;
    vector<int>a(n+1);
    Tree t(n+2);
    vector<int>pref(n+1);
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        pref[i] = pref[i-1];
        if (a[i] > k/2){
            t.update(i, a[i]);
            pref[i]++;
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        int ans = pref[r]-pref[l-1];
        T curr = t.query(l, r);
        debug(l, r, curr);
        if (curr.first < k) ans--;
        cout << ans << "\n"; 
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