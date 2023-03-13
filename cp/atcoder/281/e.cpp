//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    ordered_set L, R;

    int sum = 0;
    for (int i = 1; i<=m; i++){
        L.insert({a[i], i});
        sum += a[i];
    }
    while (L.size() > k){
        auto it = L.rbegin();
        sum -= it->first;
        R.insert(*it);
        L.erase(it);
    }
    for (int i = 1; i<=n-m+1; i++){
        cout << sum << " ";
        //remove {a[i], i}
        auto it = L.find({a[i], i});
        if (it != L.end()){
            sum -= it->first;
            sum += a[i+m];
            L.erase(it);
            L.insert({a[i+m], i+m});
        } else {
            R.erase(R.find({a[i], i}));
            R.insert({a[i+m], i+m});
        }
        if (L.empty() || R.empty()) continue;
        auto it2 = R.begin();
        auto it3 = L.rbegin();
        if (it2->first <= it3->first){
            auto a = *it2;
            auto b = *it3;
            L.erase(it3);
            sum -= it3->first;
            sum += it2->first;
            R.erase(it2);
            L.insert(a);
            R.insert(b);
        }
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