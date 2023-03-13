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
const int mx = 3e6+7;
int cnt[mx];
bitset<mx>dp;

void solve(){
    int n; cin >> n;
    vector<int>a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int last = a.back();
    a.pop_back();
    int sum  = accumulate(a.begin(), a.end(), 0);
    for (auto x: a) cnt[x]++;
    a.clear();
    for (int i = 0; i<mx; i++){
        int x = (cnt[i]-1)/2;
        cnt[i] -= 2*x;
        while (cnt[i]--) a.emplace_back(i);
        if (2*i < mx) cnt[2*i] += x;
    }
    dp[0] = 1;
    for (auto x: a) dp |= (dp<<x);
    int curr = 0;
    for (int i = 0; i <= sum/2; i++) if (dp[i]) curr = i;
    cout << last + curr << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}