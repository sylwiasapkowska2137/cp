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
const int oo = 1e18, oo2 = 1e9+7, K = 15;
const int mod = 998244353;

void solve(){
    int n; cin >> n;
    vector<T>ans;
    vector<vector<int>>st(n+1, vector<int>(K));
    for (int j = 0; (1<<j) <= n; j++){
        for (int i = 1; i+(1<<j)-1 <= n; i++){
            ans.emplace_back(i, i+(1<<j)-1);
            st[i][j] = ans.size();
        }
    }
    cout << (int)ans.size() << "\n";
    for (auto [a, b]:ans){
        cout << a << " " << b << "\n";
    }
    cout.flush();
    int q; cin >> q;
    while (q--){
        int l, r; cin >> l >> r;
        int k = r-l+1;
        int i = log2(k);
        cout << st[l][i] << " " << st[r-(1<<i)+1][i] << "\n";
        cout.flush();
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