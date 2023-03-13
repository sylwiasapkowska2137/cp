//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <atcoder/math>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using namespace atcoder;

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
const int oo = 1e18, oo2 = 1e9, K = 30;

int power(int a, int b, int m){
    if (!b) return 1LL;
    int k = power(a, b/2, m);
    k = (k*k)%m;
    if (b&1) k = (k*a)%m;
    return k;
}

void solve(){
    vector<int>now = {4, 9, 5, 7, 11, 13, 17, 19, 23};
    // vector<int>now = {2, 3};
    vector<int>a;
    int k = 1;
    for (auto x: now){
        int l = k+1;
        for (int i = 0; i<x; i++){
            a.emplace_back((i == x-1 ? k : l));
            l++;
        }
        k = l-1;
    }
    int m = (int)a.size();
    cout << m << "\n";
    for (auto x: a) cout << x << " ";
    cout << endl;
    vector<int>b(m+1);
    for (int i = 1; i<=m; i++) cin >> b[i];
    k = 1;
    vector<int>A;
    for (auto x: now){
        debug(b[k], a[k-1]);
        A.emplace_back((b[k]-a[k-1]+1+x)%x);
        k += x;
    }
    cout << crt(A, now).first << "\n";
    cout.flush();
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