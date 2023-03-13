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

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int>pi(n);
    auto kmp = [&](int st){
        pi.assign(n, 0);
        pi[st] = st;
        for (int i = st+1; i<n; i++){
            int j = pi[i-1];
            while (j>st && s[i] != s[j]) j = pi[j-1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        for (int i = st; i<n; i++) pi[i] -= st;
    };
   
    int q; cin >> q;
    vector<vector<T>>que(n);
    for (int i = 0; i<q; i++){
        int l, r; cin >> l >> r;
        l--;r--;
        que[l].emplace_back(r, i);
    }
    vector<int>ans(q);
    for (int l = 0; l<n; l++){
        if (que[l].empty()) continue;
        kmp(l);
        for (auto [r, i]: que[l]){
            int len = r-l+1;
            int x = len - pi[r];
            if (len%x == 0) ans[i] = x;
            else ans[i] = len;
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