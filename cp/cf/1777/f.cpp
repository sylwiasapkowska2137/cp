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
const int oo2 = 1e9+7, K = 30;

struct Tree{
    vector<T>tab;
    int size = 1;

    Tree(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, {-oo2, -oo2});
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = {a[i], i};
        for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
    }

    T query(int l, int r){
        T ans = {-oo2, -oo2};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }
};


struct trie{
    vector<array<int, 2>>tab;
    vector<int>valid;

    trie(){
        tab.push_back({-1, -1});
    }

    void add(int x){
        int v = 0;
        valid.emplace_back(x);
        for (int i = K; i>=0; i--){
            int b = (int)((x>>i)&1);
            if (tab[v][b] == -1){
                tab[v][b] = (int)tab.size();
                tab.push_back({-1, -1});
            }
            v = tab[v][b];
        }
    }

    int find_mx(int x){
        int v = 0, ans = 0;
        for (int i = K; i>=0; i--){
            int b = (((x>>i)&1)^1);
            if (tab[v][b] == -1) b^=1;
            ans += b*(1<<i);
            v = tab[v][b];
        }
        debug(x, ans);
        return (ans^x);
    }
};

void solve(){
    int n; cin >> n;
    vector<int>a(n+1), pref(n+1);
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] ^ a[i];
    }
    Tree t(n+2, a);
    vector<trie>curr;
    int ans = 0;
    debug(pref);
    function<void(int, int, int)>rec = [&](int l, int r, int x){
        curr.resize(x+1);
        if (l - r == 1) {
            curr[x].add(pref[l-1]);
            return;
        }
        int tmp = x;
        T now = t.query(l, r);
        int mx = now.second;
        int L = ++x; rec(l, mx-1, L);
        int R = ++x; rec(mx+1, r, R);
        debug(l, r, curr[L].valid, curr[R].valid);
        //lewe trie musi zawierac pref l-1, ..., mx-1
        //prawe trie musi zawierac pref mx, ..., r
        if (mx - l >= r - mx){ //right part shorter
            int cxor = 0;
            for (int k = mx; k<=r; k++){
                cxor ^= a[k];
                ans = max(ans, curr[L].find_mx(pref[mx]^cxor));
            }
            for (auto v: curr[R].valid){
                curr[L].add(v);
            }
            swap(curr[tmp], curr[L]);
        } else { //left part shorter
            int cxor = a[mx];
            for (int k = mx; k >= l; k--){
                cxor ^= a[k];
                ans = max(ans, curr[R].find_mx(pref[mx]^cxor));
            }
            for (auto v: curr[L].valid){
                curr[R].add(v);
            }
            swap(curr[tmp], curr[R]);
        }
    };
    rec(1, n, 1);    
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}