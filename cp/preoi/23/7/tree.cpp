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
const int mod = 1e9+7;


int mul(int a, int b){
    return (a*b)%mod;
}

int power(int a, int b){
    if (!b) return 1LL;
    int k = power(a, b/2);
    k = mul(k, k);
    if (b&1) k = mul(k, a);
    return k;
}

int inv(int a){
    return power(a, mod-2);
}

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

void sub(int &a, int b){
    a -= b;
    if (a < 0) a+=mod;
}


int add2(int a, int b){
    add(a, b);
    return a;
}

int sub2(int a, int b){
    sub(a, b);
    return a;
}

struct Tree{
    vector<int>tab;
    int size = 1;

    void init(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    void clear(){
        tab.assign(2*size, 0);
    }

    void update(int x, int v){
        x += size;
        add(tab[x], v);
        while (x){
            x/=2;
            tab[x] = add2(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) add(ans, tab[l+1]);
            if (r&1) add(ans, tab[r-1]);
        }
        return ans;
    }
};

const int I = (mod+1)/2;
const int mx = 5e5+7;
int a[mx];
vector<int>g[mx];
vector<int>s;
int ans, n;
Tree t, occ;

int get(int x){
    return lower_bound(s.begin(), s.end(), x) - s.begin();
}
int tmp_sum, start;

void dfs(int v, int pa){
    if (start <= v) add(ans, tmp_sum);
    for (auto x: g[v]){
        if (x != pa){
            int k = get(a[x]);
            int mniejsze = occ.query(1, k);
            int sum = t.query(k+1, n);
            t.update(k, a[x]);
            occ.update(k, 1);
            add(tmp_sum, mul(mniejsze+1, a[x]));
            add(tmp_sum, sum);
            dfs(x, v);
            occ.update(k, -1);
            sub(tmp_sum, mul(mniejsze+1, a[x]));
            sub(tmp_sum, sum);
            t.update(k, -a[x]);
        }
    }
}

void solve(){
    cin >> n;
    s.emplace_back(0);
    int S = 0;
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        s.emplace_back(a[i]);
        add(S, a[i]);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i = 1; i<n; i++){
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    t.init(n+2);
    occ.init(n+2);
    for (int i = 1; i<=n; i++){
        t.clear();
        occ.clear();
        tmp_sum = 0;
        start = i;
        t.update(get(a[i]), a[i]);
        occ.update(get(a[i]), 1);
        tmp_sum = a[i];
        dfs(i, i);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}