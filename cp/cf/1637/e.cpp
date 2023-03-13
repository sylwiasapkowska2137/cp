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

void solve(){
    int n, m; cin >> n >> m;
    vector<T>bad;
    unordered_map<int, int>cnt;
    for (int i = 1; i<=n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        bad.emplace_back(x, y);
        bad.emplace_back(y, x);
    }
    stable_sort(bad.begin(), bad.end());
    vector<vector<int>>what(n+1);  
    vector<int>valid;
    for (auto &[x, ile]: cnt) what[ile].emplace_back(x);
    for (int i = 1; i<=n; i++){
        if (!what[i].empty()){
            valid.emplace_back(i);
            stable_sort(what[i].rbegin(), what[i].rend());
        }
    }
    long long ans = 0;
    for (auto &cntx: valid){
        for (auto &cnty: valid){
            if (cntx < cnty) break;
            for (auto x: what[cntx]){
                for (auto y: what[cnty]){
                    if (x == y) continue;
                    if (!binary_search(bad.begin(), bad.end(), T{x, y})){
                        ans = max(ans, (long long)(cntx+cnty)*(x+y));
                        break;
                    }
                }
            }
        }
    }
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