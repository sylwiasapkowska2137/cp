//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

void __print(int x){cerr << x;}
void __print(long long x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x){cerr << "\'" << x << "\'";}
void __print(string x){cerr << "\"" << x << "\"";}

template<typename T, typename V>
void __print(pair<T, V> x){
    cerr << "{";
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << "}";
}

template<typename T>
void __print(T t){
    int f = 0;
    cerr << "{";
    for (auto &i: t){
        cerr << (f++ ? ", ": "");
        __print(i);
    }
    cerr << "}";
}

void _print() {cerr << "]\n";}

template<typename T, typename... V>
void _print(T t, V... v){
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<T>>g(n+1);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    auto out = [&](){
        cout << "IMPOSSIBLE\n";
        exit(0);
    };
    for (int i = 1; i<=n; i++){
        if ((int)g[i].size()&1){
            out();
        }
    }
    vector<int>path;
    vector<bool>used(m+1);
    function<void(int)>dfs = [&](int v){
        while ((int)g[v].size()){
            auto [x, i] = g[v].back();
            g[v].pop_back();
            if (!used[i]){
                used[i] = 1;
                dfs(x);
            }
        }
        path.emplace_back(v);
    };
    dfs(1);
    debug(path, n);
    if (path.size() != m+1){
        out();
    }
    for (auto x: path) cout << x << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}