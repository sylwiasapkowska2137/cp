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

const int MAX = 10000;
vector<int>graf[MAX], parent;

void dfs(int v, int pa){
    parent[v] = pa;
    for (auto x: graf[v]){
        if (x!=pa){
            dfs(x, v);
        }
    }
}


void solve(){
    int n; cin >> n;   
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    vector<int>val(n+1);
    parent.assign(n+1, 0);
    for (int i = 1;i<=n;i++) cin >> val[i];
    dfs(1, 1);
    int q; cin >> q;
    while (q--){
        char t; cin >> t;
        if (t == 'Q'){
            int a, b; cin >> a >> b;
            dfs(a, a);
            int v = b;
            int ans = val[b];
            //debug(v);
            while (v != parent[a]){
                v = parent[v];
                ans = __gcd(ans, val[v]);
                //debug(v);
            }
            cout << ans << "\n";
        } else {
            int a, b, d; cin >> a >> b >> d;
            dfs(a, a);
            int v = b;
            val[b] += d;
            //debug(v);
            while (v != parent[a]){
                v = parent[v];
                val[v] += d;
                //debug(v);
            }
        }
    }

}

int main(){
    solve();
}