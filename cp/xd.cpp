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

struct chash{
    const uint64_t C = (long long)(4e18 * acos(0)) | 71;
    long long operator()(long long x) const {return __builtin_bswap64(x*C);}
};

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
gp_hash_table<int, int, chash>cnt;

struct Fenwick{
    vector<int>s;
    Fenwick(int n): s(n) {}
    void update(int x, int delta){
        for (;x < (int)s.size(); x|=(x+1)){
            s[x] += delta;
        }
    }
    int query(int x){ //query [0, pos)
        int ans = 0;
        for (;x; x&=(x-1)){
            ans += s[x-1];
        }
        return ans;
    }
};


void solve(){
    int n; cin >> n;
    vector<int>a(n);
    for (auto &x: a) cin >> x;
    debug(n, a, (string)"gowno");
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}