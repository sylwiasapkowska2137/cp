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
void __print(pair<T, V> t){
    cerr << "{";
    __print(t.first);
    cerr << ", ";
    __print(t.second);
    cerr << "}";
}

template<typename T>
void __print(T t){
    int f = 0;
    cerr << "{";
    for (auto i: t){
        cerr << (f++ ? ", ": "");
        __print(i);
    }
    cerr << "}";
}

void _print(){cerr << "]\n";}

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
    int n; cin >> n;
    vector<int>a(n);
    for (auto &x: a) cin >> x;
    debug(n, a);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}