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
 
void solve(){
        int n, k; cin >> n >> k;
        vector<vector<int>>g(n+1);
        vector<int>t(n+1);
        vector<vector<int>>d(k+1);
        for (int i = 1; i<=n; i++) {
                cin >> t[i];
                d[t[i]].emplace_back(i);
        }
        for (int i = 1; i<n; i++){
                int a, b; cin >> a >> b;
                g[a].emplace_back(b);
                g[b].emplace_back(a);
        }
        int l = 0, idx = -1;
        for (int i = 1; i<=n; i++){
                if ((int)g[i].size() == 1){
                        l++;
                        if (idx == -1) idx = i;
                }
        }
        // if (l == 2){
        //      vector<int>a;
        //      function<void(int, int)>dfs = [&](int v, int pa){
        //              a.emplace_back(v);
        //              for (auto x: g[v]){
        //                      if (x == pa) continue;
        //                      dfs(x, v);
        //              }
        //      };
 
        //      dfs(idx, idx);
        //      //debug(a);
        //      for (auto &x: a) x = t[x];
        //      debug(a);
        //      vector<int>last(k+1, -1);
        //      for (int i = 0; i<n; i++) last[a[i]] = i;
        //      int l = 0, r = 0, m = last[a[0]];
        //      map<int, int>cnt;
        //      int ans = oo;
        //      while (l < n){
        //              cnt.clear();
        //              cnt[a[r]]++;
        //              while (r < m){
        //                      r++;
        //                      m = max(m, last[a[r]]);
        //                      cnt[a[r]]++;
        //              }
        //              debug(l, r, cnt.size());
        //              ans = min(ans, (int)cnt.size()-1);
        //              l = r+1;
        //              m = l;
        //      }
        //      cout << ans << "\n";
        //      return;
        // }
        int ans = oo;
        for (int typ = 1; typ<=k; typ++){
                vector<int>color = t;
                int curr = 0;
                while (1){
                        int cnt = 0;
                        vector<int>sub(n+1, 0);
 
                        function<void(int, int)>dfs = [&](int v, int pa){
                                if (color[v] == typ) sub[v]++;
                                for (auto x: g[v]){
                                        if (x == pa) continue;
                                        dfs(x, v);
                                        sub[v]+=sub[x];
                                }
                        };
 
                        dfs(d[typ][0], d[typ][0]);
                        vector<int>change;
                        for (int i = 1; i<=n; i++){
                                if (sub[i]){
                                        cnt++;
                                        if (color[i] != typ){
                                                change.emplace_back(t[i]);
                                        }
                                }
                        }
                        if (cnt == sub[d[typ][0]]) {
                                //debug(typ);
                                break;
                        }
                        sort(change.begin(), change.end());
                        change.erase(unique(change.begin(), change.end()), change.end());
                        //debug(sub, change);
                        curr += (int)change.size();
                        for (auto c: change){
                                for (auto v: d[c]){
                                        color[v] = typ;
                                }
                        }
                }
                //debug(curr);
                ans = min(ans, curr);
        }
        cout << ans << "\n";
       
}
 
int32_t main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
 
        int t = 1;
        while (t--) solve();
       
        return 0;
}