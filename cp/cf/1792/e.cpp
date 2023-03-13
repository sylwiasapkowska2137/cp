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

vector<T> rozloz(int x){
    vector<T>p;
    for (int d = 2; d * d <= x; d++){
        if (x%d == 0){
            int cnt = 0;
            while (x%d == 0){
                x/=d;
                cnt++;
            }
            p.emplace_back(d, cnt);
        }
    }
    if (x > 1) p.emplace_back(x, 1);
    return p;
}

void solve(){
    int n, m1, m2; cin >> n >> m1 >> m2;
    auto A = rozloz(m1);
    auto B = rozloz(m2);
    vector<T>C, D;
    merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
    if ((int)C.size()){
        D.emplace_back(C[0]);
        for (int i = 1; i<(int)C.size(); i++){
            if (C[i].first == D.back().first){
                D.back().second += C[i].second;
            } else {
                D.emplace_back(C[i]);
            }
        }
    }
    vector<int>what;
    function<void(int, int)>gen = [&](int pos, int x){
        what.emplace_back(x);
        int p = 1;
        if (pos + 1 <= (int)D.size()){
            for (int i = 0; i<=D[pos].second; i++){
                gen(pos+1, x*p);
                p *= D[pos].first;
            }
        }
    };
    gen(0, 1);
    sort(what.begin(), what.end());
    what.erase(unique(what.begin(), what.end()), what.end());
    int s = (int)what.size();
    vector<int>dp(s+1);
    auto get = [&](int x){
        return (int)(lower_bound(what.begin(), what.end(), x) - what.begin());
    };
    int ans = 0, ret = 0;
    for (int i = 0; i<s; i++){
        int x = what[i];
        if (x <= n){
            dp[i] = x;
        } else {
            for (auto [d, cnt]: D){
                if (x%d == 0){
                    dp[i] = max(dp[i], dp[get(x/d)]);
                }
            }
        }
        if (dp[i] != oo && x/dp[i] <= n){
            ans++;
            ret ^= (x/dp[i]);
        } else {
            dp[i] = oo;
        }
    }
    cout << ans << " " << ret << "\n";
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