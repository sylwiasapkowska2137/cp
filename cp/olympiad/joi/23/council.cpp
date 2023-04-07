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
const int oo = 1e18, oo2 = 1e9+7, K = 3;

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(m+1);
    vector<int>mask(n+1);
    for (int i = 1; i<=n; i++){
        for (int j = m-1; j>=0; j--){
            int k; cin >> k;
            if (k == 1){
                mask[i] += (1<<j);
                a[j]++;
            }
        }
    }
    vector dp((1<<K)+2, vector<T>(2, {oo, oo}));
    auto f = [&](vector<T>a, vector<T>b){
        vector<T>now;
        merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(now));
        now.pop_back();
        now.pop_back();
        return now;
    };
    vector ret((1<<K)+2, oo);
    {
        // debug(mask);
        for (int i = 1; i<=n; i++){
            dp[mask[i]][0] = {0, mask[i]};
        }
        for (int i = 0; i<K; i++){
            for (int mask = 0; mask < (1<<K); mask++){
                if (mask&(1<<i)){
                    if (dp[mask][0].second&(1<<i)) dp[mask][0].first++;
                    if (dp[mask][1].second&(1<<i)) dp[mask][1].first++;
                    dp[mask] = f(dp[mask], dp[mask^(1<<i)]);
                } 
            }
        }
        for (int mask = 0; mask<(1<<K); mask++){
            // debug(mask, dp[mask]);
            for (int rep2 = 0; rep2 < 2; rep2++){
                if (dp[mask][rep2].second != mask){
                    ret[mask] = min(ret[mask], dp[mask][rep2].first);
                }
            }
        }
    }
    // return;
    {
        debug(mask);
        dp.assign((1<<K)+2, vector<T>(2, {oo, oo}));
        for (int i = 1; i<=n; i++){
            dp[mask[i]][0] = {0, mask[i]};
        }
        for (int i = 0; i<K; i++){
            for (int mask = (1<<K)-1; mask >= 0; mask--){
                if (!(mask&(1<<i))){
                    auto curr = dp[mask^(1<<i)];
                    curr[0].first--;
                    curr[1].first--;
                    dp[mask] = f(dp[mask], curr);
                } else {
                    if (dp[mask][0].second&(1<<i)) dp[mask][0].first++;
                    if (dp[mask][1].second&(1<<i)) dp[mask][1].first++;
                }
            }
        }
        for (int mask = 0; mask<(1<<K); mask++){
            debug(mask, dp[mask]);
            for (int rep2 = 0; rep2 < 2; rep2++){
                if (dp[mask][rep2].second != mask){
                    ret[mask] = min(ret[mask], dp[mask][rep2].first);
                }
            }
        }
    }
    for (int mask = 0; mask<(1<<K); mask++){
        debug(mask, ret[mask]);
    }
    for (int i = 1; i<=n; i++){
        int nmask = 0, all = 0;
        for (int j = 0; j<m; j++){
            int curr = a[j];
            if (mask[i]&(1<<j)){
                curr--;
            }
            debug(j, curr);
            if (curr > n/2) all++;
            if (curr == n/2) nmask += (1<<j);
        }
        debug(all, nmask);
        cout << all+__builtin_popcount(nmask)-ret[nmask] << "\n";
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