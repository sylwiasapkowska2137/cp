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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct TreeMin{
    vector<T>tab;
    int size = 1;

    void init(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, {oo, oo});
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = {a[i], i};
        for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
    }

    T query(int l, int r){
        T ans = {oo, oo};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = min(ans, tab[l+1]);
            if (r&1) ans = min(ans, tab[r-1]);
        }
        return ans;
    }
} t;

int n, S, ans;
vector<int>a, b, sum;

void rec(int l, int r){
    int m = (l+r)/2;
    debug(l, r, m);
    vector<int>pref, suf;
    int p = m, q = m;
    for (int i = m; i<=r; i++) pref.emplace_back(pref.empty() ? a[i] : min(pref.back(), a[i]));
    for (int i = m; i>=l; i--) suf.emplace_back(suf.empty() ? a[i] : min(suf.back(), a[i]));
    reverse(suf.begin(), suf.end());
    pref.emplace_back(oo); suf.emplace_back(oo);
    debug(pref, suf);
    int ppref = (int)pref.size()-1, psuf = (int)suf.size()-1;
    int mn = a[m];
    while (p >= l && q <= r){
        if (pref[ppref-1] <= suf[psuf-1]){
            ppref--;
            mn = pref[ppref];
            p--;
            debug(p, q);
            //policzyc ile o poczatku w p
            int L = p, R = q, ptr = p-1;
            while (R >= L){
                int mm = (L+R)/2;
                if (mn + sum[mm] - sum[p-1] <= S){
                    ptr = mm;
                    L = mm+1;
                } else {
                    R = mm-1;
                }
            }
            debug(ptr, ptr-p+1);
            ans += (ptr - p + 1);
        } else {
            psuf++;
            mn = suf[psuf];
            q++;
            //policzyc ile o koncu w q
            debug(p, q);
            int L = p, R = q, ptr = q+1;
            while (R >= L){
                int mm = (L+R)/2;
                if (mn + sum[q] - sum[mm-1] <= S){
                    ptr = mm;
                    R = mm-1;
                } else {
                    L = mm+1;
                }
            }  
            debug(ptr, q-ptr+1);
            ans += (q - ptr + 1);
        }
    }
    return;
    if (l <= m-1) rec(l, m-1);
    if (m+1 <= r) rec(m+1, r);
}

void solve(){
    cin >> n >> S;
    a.resize(n+1);
    b.resize(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=n; i++) cin >> b[i];
    sum.emplace_back(0);
    for (int i = 1; i<=n; i++) sum.emplace_back(sum.back() + b[i]);
    t.init(n+2, a);
    rec(1, n);
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}