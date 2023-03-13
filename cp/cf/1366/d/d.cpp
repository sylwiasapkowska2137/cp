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
const int mx = 1e7+7;
vector<int>p(mx);
vector<int>a, b;

void solve(){
    int n; cin >> n;
    if (p[n] == 0){
        a.emplace_back(-1);
        b.emplace_back(-1);
        return;
    }
    int prime = p[n];
    a.emplace_back(1);
    while (n % prime == 0){
        a.back() *= prime;
        n/=prime;
    }
    if (n == 1){
        a.back() = -1;
        b.emplace_back(-1);
    } else b.emplace_back(n);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i<mx; i++){
        if (p[i] == 0){
            for (int j = i*i; j<mx; j+=i){
                if (p[j] == 0){
                    p[j] = i;
                }
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--) solve();
    for (auto x: a) cout << x << " ";
    cout << "\n";
    for (auto x: b) cout << x << " ";
    cout << "\n";
    return 0;
}