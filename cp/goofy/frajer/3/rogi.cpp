//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("popcnt")
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
const int mx = 2001;

void solve(){
    int n; cin >> n;
    vector<bitset<mx>>tab(n);
    vector a(n+1, vector<bool>(n+1));
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            int x; cin >> x;
            a[i][j] = (bool)(x);
            if (a[i][j]) tab[i].set(j);
        }
        reverse(a[i].begin(), a[i].end());
    }
    bitset<mx>now;
    int ans = 0;
    vector<vector<int>>lst(n+1, vector<int>(n+1, -1));
    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){
            now = tab[i] & tab[j];
            if (now.count() == 0) continue;
            lst[i][j] = n-now._Find_first();
        }
    }
    for (int i = 0; i<n; i++){
        tab[i].reset();
        for (int j = 0; j<n; j++){
            if (a[i][j]){
                tab[i].set(j);
            }
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){
            if (lst[i][j] == -1) continue;
            now = tab[i] & tab[j];
            ans = max(ans, (lst[i][j]-(int)now._Find_first()+1)*(j-i+1));
        }
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