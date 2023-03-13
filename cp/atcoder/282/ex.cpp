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
vector<int>a, b, pref;

void rec(int l, int r){
    int m = t.query(l, r).second;
    int sum = 0;
    if (m-l+1 >= r-m+1){
        //right part shorter
        for (int i = m; i<=r; i++){
            sum += b[i];
            int L = l, R = m, ptr = m+1;
            while (R >= L){
                int mid = (L+R)/2;
                if (pref[mid-1] >= sum + a[m] + pref[m-1] - S){
                    ptr = mid;
                    R = mid-1;
                } else L = mid+1;
            }
            ans += (m-ptr+1);
        }
    } else {
        for (int i = m; i>=l; i--){
            sum += b[i];
            int L = m, R = r, ptr = m-1;
            while (R >= L){
                int mid = (L+R)/2;
                if (pref[mid] <= pref[m] - sum - a[m] + S){
                    ptr = mid;
                    L = mid+1;
                } else {
                    R = mid-1;
                }
            }
            ans += (ptr-m+1);
        }
    }
    if (l <= m-1) rec(l, m-1);
    if (m+1 <= r) rec(m+1, r);
}

void solve(){
    cin >> n >> S;
    a.resize(n+1);
    b.resize(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=n; i++) cin >> b[i];
    pref.emplace_back(0);
    for (int i = 1; i<=n; i++) pref.emplace_back(pref.back() + b[i]);
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