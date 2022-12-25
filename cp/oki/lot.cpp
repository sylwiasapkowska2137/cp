#include <bits/stdc++.h>
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


void solve(){
    int n; cin >> n;
    vector<pair<int, int>>deg(n);
    for (int i = 0; i<n; i++) {
        cin >> deg[i].first;;
        deg[i].second = i+1;
    }
    vector vis(n+1, vector<int>(n+1));
    for (int i = 1; i<=n; i++){
        sort(deg.rbegin(), deg.rend());
        while ((int)deg.size() && !deg.back().first) deg.pop_back();
        if (deg.empty()) break;
        int curr = deg[0].second;
        for (auto &[x, v]:deg){
            if (!deg[0].first) break;
            if (v == curr) continue;
            if (vis[v][curr]) continue;
            x--;
            deg[0].first--;
            vis[v][curr] = vis[curr][v] = 1;
            cout << curr << " " << v << "\n";
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}