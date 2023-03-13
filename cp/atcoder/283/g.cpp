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
const int oo = 1e18, oo2 = 1e9+7, K = 61;
const int mod = 998244353;

void solve(){
    int n; cin >> n;
    int L, R; cin >> L >> R;
    L--;R--;
    vector<int>base;
    auto insert = [&](int x){
        for (auto v: base)  x = min(x, x^v);
        for (auto &v: base) v = min(v, x^v);
        if (x) base.emplace_back(x);
    };
    for (int i = 1; i<=n; i++){
        int x; cin >> x;
        insert(x);
    }
    sort(base.begin(), base.end());
    debug(base);
    for (int i = L; i<=R; i++){
        int sl = 0;
        for (int j = 0; j<K; j++){
            if (i&(1LL<<j)){
                sl ^= base[j];
            }
        }   
        cout << sl << " ";
    }
    cout << "\n";
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