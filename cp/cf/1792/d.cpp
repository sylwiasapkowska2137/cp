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
    int n, m; cin >> n >> m;
    set<vector<int>>s;
    vector<vector<int>>p(n+1);
    for (int i = 1; i<=n; i++){
        vector<int>now(m+1);
        vector<int>pos(m+1);
        for (int j = 1; j<=m; j++){
            cin >> now[j];
            pos[now[j]] = j;
        }
        p[i] = now;
        vector<int>curr(m+1);
        for (int j = 1; j<=m; j++){
            curr[pos[j]] = j;
            s.insert(curr);
        }
    }
    for (int i = 1; i<=n; i++){
        vector<int>need(m+1);
        int ans = 0;
        for (int j = 1; j<=m; j++){
            need[p[i][j]] = j;
            if (s.find(need) == s.end()){
                break;
            }
            ans = j;
        }
        cout << ans << " ";
    }
    cout << "\n";
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