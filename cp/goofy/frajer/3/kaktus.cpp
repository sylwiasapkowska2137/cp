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

const int sz = (1<<19);
int tab[2*sz];

void update(int x, int v){
    x += sz;
    tab[x] = max(tab[x], v);
    while (x){
        x/=2;
        tab[x] = max(tab[2*x], tab[2*x+1]);
    }
}

int query(int l, int r){
    int ans = 0;
    for (l += sz-1, r += sz+1; r-l>1; l/=2, r/=2){
        if (!(l&1)) ans = max(ans, tab[l+1]);
        if (r&1) ans = max(ans, tab[r-1]);
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int>a(n), s;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
        s.emplace_back(a[i]);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (auto &x: a) x = lower_bound(s.begin(), s.end(), x)-s.begin()+1;
    auto calc = [&](){
        vector<int>dp(n);
        for (int i = 0; i<n; i++){
            dp[i] = query(0, a[i]-1) + 1;
            update(a[i], dp[i]);
        }
        return dp;
    };
    auto pref = calc();
    reverse(a.begin(), a.end());
    memset(tab, 0, sizeof(tab));
    auto suf = calc();
    reverse(suf.begin(), suf.end());
    int ans = 1;
    debug(pref);
    debug(suf);
    for (int i = 0; i<n; i++){
        ans = max(ans, pref[i] + suf[i] - 1);
    }
    cout << n-ans << "\n";
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