#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(bool x) {cerr << x;}
void __print(char x) {cerr << "\'" << x << "\'";}
void __print(string x) {cerr << "\"" << x << "\"";}

template<typename T, typename V>
void _print(pair<T, V>&x){
    cerr << "{"; __print(x.first);
    cerr << ", "; __print(x.second);
    cerr << "}";
}
template<typename T>
void __print(T& x){
    int f = 0;
    cerr << "{";
    for (auto &i: x){
        cerr << (f++ ? ", " : "");
        __print(i);
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

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...) 
#endif

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n; cin >> n;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    debug(n, a);
    debug(p(1, 2137));
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}