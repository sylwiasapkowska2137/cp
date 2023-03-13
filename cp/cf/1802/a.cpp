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
    vector<int>a(n+1);
    vector<int>curr(n+1);
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        curr[abs(a[i])]++;
    }
    vector<int>mn;
    int cnt = 0;
    for (int i = 1; i<=n; i++){
        if (curr[i] == 2){
            cnt++;
            mn.emplace_back(cnt);
            cnt--;
            mn.emplace_back(cnt);
        }
    }
    for (int i = 1; i<=n; i++){
        if (curr[i] == 1){
            cnt++;
            mn.emplace_back(cnt);
        }
    }
    vector<int>mx;
    cnt = 0;
    for (int i = 1; i<=n; i++){
        if (curr[i] > 0){
            cnt++;
            mx.emplace_back(cnt);
        }
    }
    for (int i = 1; i<=n; i++){
        if (curr[i] == 2){
            cnt--;
            mx.emplace_back(cnt);
        }
    }
    for (auto x: mx){
        cout << x << " ";
    }
    cout << "\n";
    for (auto x: mn) {
        cout << x << " ";
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