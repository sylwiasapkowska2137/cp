#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << "\'" << x << "\'";}
void __print(const char *x) {cerr << "\'" << x << "\'";}
void __print(const string &x) {cerr << "\"" << x << "\"";}
void __print(bool x) {cerr << (x?"true":"false");}

template<typename V, typename T>
void __print(const pair<V, T> &x){
    cerr << "{";
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << "}";
}

template<typename T>
void __print(const T &t){
    int f = 0;
    cerr << "{";
    for (auto &i: t){
        cerr << (f++?", ": ""), __print(i);
    }
    cerr << "}";
}

void _print(){cerr << "]\n";}

template<typename T, typename... V>
void _print(T t, V... v){
    __print(t);
    if (sizeof...(v)){
        cerr << ", ";
    }
    _print(v...);
}

#define int long long
#define debug(x...) cerr << "[" << #x << "] = [", _print(x);

void solve(){
    int n; cin >> n;
    int ans = 0;
    vector<vector<int>>graf(n+1);
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    vector<int>sub(n+1), dp(n+1);

    function<void(int, int)>dfs = [&](int v, int pa){
        sub[v] = 1;
        for (auto x: graf[v]){
            if (x!=pa){
                dfs(x, v);
                sub[v] += sub[x];
                dp[v] += dp[x];
            }
        }
        dp[v] += sub[v];
    };
    
    function<void(int, int)>reroot = [&](int v, int pa){
        ans = max(ans, dp[v]);
        for (auto x: graf[v]){
            if (x!=pa){
                int dpv = dp[v], dpx = dp[x], subv = sub[v], subx = sub[x];
                sub[v] = n-sub[x];
                sub[x] = n;
                dp[v] -= dpx+subx;
                dp[x] += dp[v]+sub[v];
                reroot(x, v);
                dp[v] = dpv, dp[x] = dpx, sub[v] = subv, sub[x] = subx;
            }
        }
    };

    dfs(1, -1);
    reroot(1, -1);
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}