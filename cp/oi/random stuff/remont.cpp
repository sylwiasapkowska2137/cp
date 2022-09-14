#include <bits/stdc++.h>
using namespace std;

void __print(int x){cerr << x;}
void __print(long long x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x) {cerr << "\'" << x << "\'";}
void __print(string x){cerr << "\"" << x << "\"";}

template<typename T, typename V>
void __print(const pair<T, V>&x){
    cerr << "{";
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << "}";
}

template<typename T>
void __print(const T &x){
    int f = 0;
    cerr << "{";
    for (auto i: x) cerr << (f++?", ":" "), __print(i);
    cerr << "}";
}

void _print() {cerr << "]\n";}

template<typename T, typename... V>
void _print(T t, V... v){
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#define int long long  

void solve(){
    int n; cin >> n;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    int N = 2*n+2;
    vector<vector<int>>g(N), gt(N);
    for (int i = 1; i<n; i++){
        g[2*i+1].emplace_back(2*(i+1));
        g[2*(i+1)+1].emplace_back(2*i);
        gt[2*(i+1)].emplace_back(2*i+1);
        gt[2*i].emplace_back(2*(i+1)+1);
    }
    for (int i = 1; i<n; i++){
        for (int j = i+1; j<n; j++){
            if (a[i] == a[j] && a[i+1] == a[j+1]){
                g[2*i].emplace_back(2*j+1);
                g[2*j].emplace_back(2*i+1);
                gt[2*j+1].emplace_back(2*i);
                gt[2*i+1].emplace_back(2*j);
            }
        }
    }
    vector<bool>vis(N), numer(N);
    vector<int>post;

    function<void(int)>dfs = [&](int v){
        vis[v] = 1;
        for (auto x: g[v]){
            if (!vis[x]){
                dfs(x);
            }
        }
        post.emplace_back(v);
    };
    int nr = 0;

    function<void(int)>dfs2 = [&](int v){
        vis[v] = 1;
        numer[v] = nr;
        for (auto x: gt[v]){
            if (!vis[x]){
                dfs(x);
            }
        }
        post.emplace_back(v);
    };

    for (int i = 1; i<N; i++){
        if (!vis[i]){
            dfs(i);
        }
    }
    reverse(post.begin(), post.end());
    vis.assign(N, 0);
    for (auto x: post){
        if (!vis[x]){
            nr++;
            dfs2(x);
        }
    }
    for (int i = 1; i<N; i+=2){
        if (numer[i] == numer[i+1]){
            cout << "NIE\n";
            return;
        }
    }
    cout << "TAK\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}