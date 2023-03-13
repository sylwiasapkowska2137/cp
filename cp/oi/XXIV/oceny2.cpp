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

struct TreeMax{
    vector<int>tab;
    int size = 1;

    TreeMax(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, -oo);
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
        for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
    }

    void update(int x, int v){
        x += size;
        tab[x] = v;
        while (x){
            x/=2;
            tab[x] = max(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = -oo;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[l-1]);
        }
        return ans;
    }
};

struct TreeMin{
    vector<int>tab;
    int size = 1;

    TreeMin(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, oo);
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
        for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
    }

    void update(int x, int v){
        x += size;
        tab[x] = v;
        while (x){
            x/=2;
            tab[x] = min(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = oo;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = min(ans, tab[l+1]);
            if (r&1) ans = min(ans, tab[l-1]);
        }
        return ans;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    --q;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];

    TreeMax tmax(n+2, a);
    TreeMin tmin(n+2, a);

    auto print = [&](){
        debug(a);
        
    };
    print();
    while (q--){
        int x, y; cin >> x >> y;
        swap(a[x], a[y]);
        tmax.update(y, a[y]);
        tmax.update(x, a[x]);
        tmin.update(y, a[y]);
        tmin.update(x, a[x]);
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