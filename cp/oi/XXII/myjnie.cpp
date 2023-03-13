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
const int oo = 1e9+7;
typedef tuple<int, int, int> F;
typedef bitset<12> bb;

void add(bb &a, bb b){
    int x = (int)(a.to_ulong());
    int y = (int)(b.to_ulong());
    x += y;
    a = bb(x);
}

void solve(){
    int n, m; cin >> n >> m;
    vector<F>a;
    vector<int>s = {-oo};
    vector<vector<int>>pos(n);
    for (int i = 0; i<m; i++){
        int l, r, c; cin >> l >> r >> c;
        --l;--r;
        a.emplace_back(l, r, c);
        s.emplace_back(c);
        for (int k = l; k <= r; k++){
            pos[k].emplace_back(c);
        }
    }
    for (int i = 0; i<n; i++){
        sort(pos[i].begin(), pos[i].end());
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int M = (int)s.size();
    vector ile(n, vector<vector<vector<bb>>>(n, vector<vector<bb>>(n, vector<bb>(M, 0))));
    for (int i = 0; i<m; i++){
        auto [l, r, c] = a[i];
        int id = lower_bound(s.begin(), s.end(), c) - s.begin();
        for (int L = 0; L <= l; L++){
            for (int R = r; R < n; R++){
                for (int k = l; k <= r; k++){
                    add(ile[L][R][k][id], 1);
                }
            }
        }
    }
    for (int L = 0; L < n; L++){
        for (int R = L; R < n; R++){
            for (int k = L; k <= R; k++){
                for (int i = M-2; i>=1; i--){
                    add(ile[L][R][k][i], ile[L][R][k][i+1]);
                    // debug(L, R, k, s[i], ile[L][R][k][i]);
                }
            }
        }
    }
    // return;
    vector dp(n, vector<vector<pair<int, int16_t>>>(n, vector<pair<int, int16_t>>(M)));
    for (int len = 1; len <= n; len++){
        for (int l = 0, r = len-1; r < n; l++, r++){
            for (int16_t i = M-1; i >= 1; i--){
                dp[l][r][i] = {0, i};
                for (int k = l; k <= r; k++){
                    dp[l][r][i] = max(dp[l][r][i], 
                        make_pair((int)(ile[l][r][k][i].to_ulong()) * s[i] + (k ? dp[l][k-1][i].first : 0) + (k + 1 < n ? dp[k+1][r][i].first : 0), i)
                    );
                }
                if (i+1 < M) dp[l][r][i] = max(dp[l][r][i], dp[l][r][i+1]);
            }
        }
    }
    cout << dp[0][n-1][1].first << "\n";
    vector<int16_t>ans(n);
    function<void(int16_t, int16_t, int16_t)>rec = [&](int16_t l, int16_t r, int16_t mn){
        // debug(l, r, s[dp[l][r][mn].second], dp[l][r][mn]);
        int16_t i = dp[l][r][mn].second;
        int16_t split = -1;
        for (int k = l; k <= r; k++){
            int x = (int)(ile[l][r][k][i].to_ulong()) * s[i] + (k ? dp[l][k-1][i].first : 0) + (k + 1 < n ? dp[k+1][r][i].first : 0);
            if (dp[l][r][i].first == x){
                split = k;
                break;
            }
        }
        assert(split != -1);
        // debug(split);
        ans[split] = i;
        if (l <= split-1) rec(l, split-1, dp[l][split-1][i].second);
        if (split + 1 < n && split + 1 <= r) rec(split+1, r, dp[split+1][r][i].second);
    };
    rec(0, n-1, 1);
    for (int i = 0; i<n; i++) cout << s[ans[i]] << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}