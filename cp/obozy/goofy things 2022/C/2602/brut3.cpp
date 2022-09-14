#include <bits/stdc++.h>
using namespace std;

 
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
 

const int MAX = 5e5+7;
vector<pair<int, int>>graf[MAX];
vector<int>czas, curr;
int ans, x;

void dfs(int v, int pa, int d, int k){
    if (czas[v] < d){
        czas[v] = d+x-1;
        ans++;
        curr.push_back(v);
    } 
    czas[v] = d+x-1;
    for (auto [x, c]: graf[v]){
        if (x!=pa && c <= k){
            dfs(x, v, d, k);
        }
    }
}

void solve(){
    int n, q; cin >> n >> q >> x;
    for (int i = 1; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }   
    czas.assign(n+1, 0); 
    while (q--){
        int d, k, v; cin >> d >> v >> k;
        ans = 0;
        curr.clear();
        dfs(v, v, d, k);
        cout << ans << "\n";
        //debug(curr);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}