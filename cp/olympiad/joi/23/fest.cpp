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
int n, mod;
int ans = 0;

void backtrack(vector<bool>tab, int open, int close){
    if ((int)tab.size() == n){
        stack<int>s;
        int b = 0;
        for (int i = 0; i<n; i++){
            if (tab[i] == false) cerr << "(";
            else cerr << ")";
        }
        cerr << "\n";
        bool better = 0;
        int zachlan = 0;
        vector<int>dp(n);
        for (int i = 0; i<n; i++){
            if (tab[i] == false){
                s.push(i);
                b++;
            } else {
                int b2 = 0;
                int cnt = 0;
                dp[i] = max(dp[i-1], (s.top() > 0 ? dp[s.top()-1] : 0LL)+1);
                b--;
                if (!b) zachlan++;
                s.pop();
            }
        }
        debug(dp, zachlan);
        if (better) {
            cerr << "a\n";
            ans++;
        }
        if (ans >= mod) ans-=mod;
        return;
    }
    if (open > close) {
        tab.emplace_back(1);
        backtrack(tab, open, close+1);
        tab.pop_back();
    }
    if (open < n/2){
        tab.emplace_back(0);
        backtrack(tab, open+1, close);
    }
}

void solve(){
    cin >> n >> mod;
    n*=2;
    backtrack({}, 0, 0);
    cout << ans << "\n";
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