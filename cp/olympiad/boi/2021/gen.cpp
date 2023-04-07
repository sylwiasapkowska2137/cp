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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 5);
    int k = p(1, 3);
    vector<tuple<char, int, int>>que;
    for (int i = 2; i<=n; i++){
        que.emplace_back('S', p(1, i-1), i);
    }
    for (int i = 1; i<=k; i++){
        if (p(0, 1)) que.emplace_back('Q', p(1, n), p(1, n));
        else que.emplace_back('C', p(1, n), -1);
    }
    cout << n << " " << k << "\n";
    shuffle(que.begin(), que.end(), rng);
    for (auto [c, a, b]: que){
    
        cout << c << " " << a;
        if (b != -1) cout << " " << b << "\n";
        else cout << "\n";
    }
}

void solve2(){
    int n = p(2, 5);
    int d = p(1, n-1);
    int tt = p(1, 10);
    cout << n << " " << d << " " << tt << "\n";
    for (int i = 1; i<=n; i++) cout << p(1, 10) << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve2();

    return 0;
}