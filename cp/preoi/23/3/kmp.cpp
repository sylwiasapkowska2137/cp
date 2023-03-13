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

// #define int long long
typedef pair<int, int> T;
const int mod = 1e9+7;

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int>pi(n);
    string s; cin >> s;
    for (int i = 1; i<n; i++){
        int j = pi[i-1];
        while (j && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    debug(pi);
    int curr = pi.back();
    vector<int>good;
    while (curr){
        good.emplace_back(n-curr);
        curr = pi[curr-1];
    }
    good.emplace_back(n);
    debug(good);
    vector<int>dp(k+1);
    dp[n] = 1;
    for (int i = n+1; i<=k; i++){
        for (auto x: good){
            add(dp[i], dp[i-x]);
        }
    }
    debug(dp);
    cout << dp[k] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}