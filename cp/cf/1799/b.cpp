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
    for (int i = 1; i<=n; i++) cin >> a[i];
    if (n == 1) {
        cout << "0\n";
        return;
    }
    vector<T>ans;
    while (1){
        bool ok = 1;
        for (int i = 1; i<=n; i++){
            ok &= (a[i] == a[1]);
        }
        if (ok) break;
        int mx = -oo, mn = oo;
        for (int i = 1; i<=n; i++) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        int A = 1, B = 2;
        for (int i = 1; i<=n; i++){
            if (a[i] == mx){
                A = i;
                break;
            }
        }
        for (int i = 1; i<=n; i++){
            if (a[i] == mn){
                B = i;
                break;
            }
        }
        int nowy = (a[A] + a[B] - 1)/a[B];
        if (nowy == a[A]){
            cout << "-1\n";
            return;
        }
        ans.emplace_back(A, B);
        a[A] = nowy;
    }
    cout << (int)ans.size() << "\n";
    for (auto [a, b]: ans){
        cout << a << " " << b << "\n";
    }
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