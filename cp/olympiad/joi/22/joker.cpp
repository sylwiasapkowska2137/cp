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

const int oo = 1e9+7;

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
    void undo(int t){
        while ((int)st.size() > t){
            auto [a, b, sA, sB] = st.back();
            st.pop_back();
            rep[a] = a;rep[b] = b;
            sz[a] = sA;sz[b] = sB;
        }
    }
    void u(int a, int b){
        a = f(a); b = f(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        st.emplace_back(a, b, sz[a], sz[b]);
        sz[a] += sz[b];
        rep[b] = a;
    }
};

void solve(){
    int n, m, q; cin >> n >> m >> q;
    int N = 2*n+2;
    vector<pair<int, int>>edges;
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        edges.emplace_back(a, b);
    }
    vector<int>R(m, oo);
    UF dsu(N+2);
    auto merge = [&](int i){
        if (i == m) return true;
        auto [a, b] = edges[i];
        dsu.u(a, b+n);
        dsu.u(a+n, b);
        if (dsu.sameset(a, a+n)) return false;
        return true;
    };
   
    function<void(int, int, int, int)>rec = [&](int l, int r, int a, int b){
        //na przedziale [l, r] lewych końców odpowiedź należy do przedziału [a, b]
        if (l > r) return;
        if (a == b){
            for (int i = l; i <= r; i++) R[i] = a;
            return;
        }
        int mid = (l+r)/2;
        bool ok = 1;
        
        int t = (int)dsu.st.size();
        for (int i = l; i < mid; i++) ok &= merge(i); 
        if (ok && R[mid] == oo){
            for (int i = b; i >= mid; i--){ //odpowiedz in [a, b]
                ok &= merge(i);
                if (!ok){
                    R[mid] = i;
                    break;
                }
            }
            if (R[mid] == oo) R[mid] = mid;
        } else if (!ok) R[mid] = m;
        dsu.undo(t);
        // debug(l, r, mid, R[mid]);

        //left side
        ok = 1;
        for (int i = b; i>R[mid]; i--) ok &= merge(i);
        if (!ok) for (int i = l; i < mid; i++) R[i] = R[mid]; //is not bipartite
        else rec(l, mid-1, a, R[mid]); //check next
        dsu.undo(t);

        //right side
        ok = 1;
        for (int i = l; i<=mid; i++) ok &= merge(i);
        if (!ok) for (int i = mid+1; i<=r; i++) R[i] = m; 
        else rec(mid+1, r, R[mid], b);
        dsu.undo(t);
    };
    rec(0, m-1, 0, m);
    // debug(R);
    while (q--){
        int a, b; cin >> a >> b;
        --a;--b;
        cout << ((R[a] <= b) ? "NO\n" : "YES\n");
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}