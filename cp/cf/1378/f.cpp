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
    int mx = -oo, k = -1; 
    for (int ck = 1; ck <= n; ck++){
        int curr = n - ck - (n + ck - 1)/ck;
        if (mx <= curr){
            mx = curr;
            k = ck;
        }
    }
    debug(k);
    vector<bool>bad(n+1), on(n+1);
    for (int i = k; i <= n; i+=k)  bad[i] = 1;
    int moves = 0;
    while (1){
        if (moves == 10000) {
            cout << "0\n";
            cout.flush();
            exit(0);
        }
        moves++;
        vector<int>now;
        for (int i = 1; i<=n; i++){
            if (!bad[i] && !on[i]){
                now.emplace_back(i);
                if ((int)now.size() == k) {
                    break;
                }
            }
        }
        if ((int)now.size() < k) {
            cout << "0\n";
            cout.flush();
            exit(0);
        }
        cout << k << " ";
        for (auto x: now) {
            cout << x << " ";
            on[x] = 1;
        }
        cout << "\n"; cout.flush();
        int x; cin >> x;
        for (int i = x, ck = k; ck>0; i = (i == n ? 1 : i+1), ck--){
            on[i] = 0;
            debug(i);
        }
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