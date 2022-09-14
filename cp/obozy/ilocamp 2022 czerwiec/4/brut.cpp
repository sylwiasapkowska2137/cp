//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define int long long
const int oo = 1e18, K = 30;
int n, m, t, s, l;
 
int count(vector<pair<int, int>> &x){
        int p = 0;
        int ans = 0;
        for (int i = 0; i<(int)x.size(); i++){
                ans += (x[i].first-p)/s;
                p = x[i].second;
        }
        ans += (t-p)/s;
        return ans;
}
 
bool check(vector<pair<int, int>>&a){
        int m = (int)a.size();
        for (int i = 1; i<m; i++){
                if (a[i].first < a[i-1].second){
                        return 0;
                }
        }
        return 1;
}
 
void solve(){
    cin >> n >> m >> t >> s >> l;
    vector<pair<int,int>>a;
    for (int i = 0; i<m; i++){
        int x; cin >> x;
        a.emplace_back(x, x+l);
    }
    sort(a.begin(), a.end());

    if (n == 1){
        if (check(a)) cout << count(a) << "\n";
        else cout << "NIE\n";
    } else {
        int ans = -oo;
        for (int mask = 0; mask<(1LL<<m); mask++){
            vector<pair<int, int>>aa, bb;
            for (int i = 0; i<m; i++){
                if (mask&(1<<i)) aa.emplace_back(a[i]);
                else bb.emplace_back(a[i]);
            }
            if (check(aa) && check(bb)) ans = max(ans, count(aa)+count(bb));
        }
        if (ans < 0) cout << "NIE\n";
        else cout << ans << "\n";
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) solve();
    
    return 0;
}