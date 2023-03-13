//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e9+7;

struct T{
    int first, second, idx;
    bool vertical;
    T(int _f, int _s, int _i, int _v): first(_f), second(_s), idx(_i), vertical(_v) {}
    bool operator < (const T &y) const {return first * y.second == second * y.first ? (idx == y.idx ? vertical < y.vertical : idx < y.idx) : first * y.second < second * y.first;};
};

void __print(T a){
    cerr << "{" << a.first << ", " << a.second << "}, " << a.idx << ", " << a.vertical;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n+2, -oo), b(m+2, -oo);
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 1; i<=m; i++) cin >> b[i];
    multiset<T>s; 
    set<int>aliveA = {-oo, 1, oo}, aliveB = {-oo, 1, oo};
    for (int i = 1; i<n; i++) {
        aliveA.insert(i+1);
        s.insert({a[i+1]-a[i], 1LL, i+1, 0});
    }
    for (int i = 1; i<m; i++) {
        aliveB.insert(i+1);
        s.insert({b[i+1]-b[i], 1LL, i+1, 1});
    }
    // debug(s);
    pair<int, int> now = {n, m};
    int ans = 0;
    while (s.size()){
        auto it = *s.rbegin();
        if (!it.vertical){
            a.swap(b);
            aliveA.swap(aliveB);
        }
        //B
        auto it2 = aliveB.lower_bound(it.idx);
        auto R = *(++it2);
        --it2;
        auto L = *(--it2);
        if (L != -oo && R != oo) s.insert({b[R] - b[L], R-L, R, it.vertical});
        if (R != oo) s.erase(s.find({b[R] - b[it.idx], R-it.idx, R, it.vertical}));
        aliveB.erase(it.idx);
        //
        if (!it.vertical){
            a.swap(b);
            aliveA.swap(aliveB);
        }
        if (!it.vertical && now.first == it.idx){
            ans += b[now.second] * it.second;
            now.first -= it.second;
        } 
        if (it.vertical && now.second == it.idx) {
            ans += a[now.first] * it.second;
            now.second -= it.second;
        }
        // debug(it, now);
        s.erase(s.find(it));
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}