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

// #define int long long
typedef pair<int, int> T;
const int oo = 1e9+7, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
    int n, p, q, x, y; cin >> n >> p >> q >> x >> y;
    int s = 0;
    string t; cin >> t;
    t = "$"+t;
    vector<int>mn(n+1, oo);
    for (int i = 1; i<=n; i++){
        if (t[i] == '+') s++;
        else s--;
        mn[i] = min(mn[i-1], s);
    }
    vector<int>pref(n+2, oo), sum(n+1);
    s = 0;
    for (int i = n; i>=1; i--) {
        if (t[i] == '+') s++;
        else s--;
        sum[i] = s;
    }
    s = 0;
    for (int i = 1; i<=n; i++){
        if (t[i] == '+') s++;
        else s--;
        pref[i] = s;
    }
    vector<int>suf(n+2, oo);
    for (int i = n; i>=1; i--){
        suf[i] = min(suf[i+1], pref[i]);
    }
    int change = (q-p-s)/2;
    debug(change);
    int ans = oo;
    for (int i = 1; i<=n; i++){
        // if (i != n) continue;
        int curr = p + (i == n ? mn[n] : min(sum[n-i+1] + mn[n-i], suf[n-i+1] - pref[n-i]));
        int ck = y*(i == n ? 0 : i);
        int currch = change;
        if (curr < 0) {
            curr = -curr;
            ck += ((curr+1)/2)*x;
            currch -= (curr+1)/2;
        }
        debug(curr, ck, currch);
        ck += x*abs(currch);
        ans = min(ans, ck);
    }
    cout << ans << "\n";
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