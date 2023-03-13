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
const int oo2 = 1e9+7;
const int sz = (1<<20);
int tab[2*sz+3];

void update(int x, int v){
    x += sz;
    tab[x] = v;
    while (x){
        x/=2;
        tab[x] = min(tab[2*x], tab[2*x+1]);
    }
}

int find(int x, int lx, int rx, int v){
    if (lx == rx) return lx;
    int m = (lx+rx)/2;
    if (tab[2*x] < v) return find(2*x, lx, m, v);
    return find(2*x+1, m+1, rx, v);
}

void solve(){
    int n; cin >> n;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    int q; cin >> q;
    vector<vector<T>>que(n+1);
    vector<int>ans(q);
    for (int i = 0; i<q; i++){
        int l, r; cin >> l >> r;
        que[r].emplace_back(l, i);
    }  
    for (int r = 1; r<=n; r++){
        update(a[r], r);
        for (auto [l, i]: que[r]){
            ans[i] = find(1, 0, sz-1, l); 
        }
    }
    for (int i = 0; i<q; i++) cout << ans[i] << "\n";
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