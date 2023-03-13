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
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct UF{
    vector<int>rep, sz;
    vector<tuple<int, int, int, int>> st;
    int s;
 
    UF(int n){
        s = n;
        rep.assign(s, 0);
        iota(rep.begin(), rep.end(), 0);
        sz.assign(s, 1);
    }
    int f(int a){return a == rep[a] ? a : f(rep[a]);}
    bool sameset(int a, int b){return f(a) == f(b);}
    void undo(){
        while (st.size()){
            auto [a, b, sA, sB] = st.back();
            st.pop_back();
            rep[a] = a;rep[b] = b;
            sz[a] = sA;sz[b] = sB;
        }
    }
    bool u(int a, int b){
        a = f(a); b = f(b);
        if (a == b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        st.emplace_back(a, b, sz[a], sz[b]);
        sz[a] += sz[b];
        rep[b] = a;
        return 1;
    }
};

struct e{
    int a, b, c;
    e(){}
    e(int _a, int _b, int _c){a = _a, b = _b, c = _c;}
};

void solve(){
    int n, m; cin >> n >> m;
    vector<e>edges;
    for (int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b){return a.c < b.c;});
    UF dsu(n+1);
    vector<int>L(m, -oo), R(m, oo), used;
    //maksymalnie O(n) krawędzi, zanim nie spróbujemy połączyć czegoś, co już jest w jednej spójnej(;pppp)
    for (int i = 0; i<m; i++){
        auto [a, b, c] = edges[i];
        if (dsu.u(a, b)) {
            used.emplace_back(i);
            continue;
        }
        int what = -1;
        dsu.undo();
        for (int j = (int)used.size()-1; j>=0; j--){
            dsu.u(edges[used[j]].a, edges[used[j]].b);
            if (dsu.sameset(a, b)){
                what = used[j];
                used.erase(used.begin()+j);
                break;
            }
        }
        dsu.undo();
        assert(what != -1);
        used.emplace_back(i);
        int cc = (edges[i].c + edges[what].c + 1)/2;
        L[i] = R[what] = cc;
        // debug(what, i, used);
        for (auto j: used) dsu.u(edges[j].a, edges[j].b);
    } 
    //                      b      a = cnt of bigger than L
    // [-oo, Li) ---> 0     0      0
    // [Li, wi)  ---> wi-x (+wi)   -1
    // [wi, Ri)  ---> x-wi (-2wi)  1 (+2 in pref)
    // [Ri, +oo) ---> 0    (+wi)   0 (-1 in pref)
    vector<pair<int, pair<int, int>>>pref;
    for (int i = 0; i<m; i++){
        auto [a, b, c] = edges[i];
        pref.emplace_back(L[i], T{-1, c});
        pref.emplace_back(c, T{2, -2*c});
        pref.emplace_back(R[i], T{-1, c});
        // debug(a, b, c, L[i], R[i]);
    }
    sort(pref.begin(), pref.end());
    int ptr = 0, a = 0, b = 0;
    int q; cin >> q;
    while (q--){
        int x; cin >> x; 
        while (ptr < (int)pref.size() && pref[ptr].first <= x){
            a += pref[ptr].second.first;
            b += pref[ptr].second.second;
            ptr++;
        }
        cout << a * x + b << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}