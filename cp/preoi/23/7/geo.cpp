//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using namespace __gnu_pbds;

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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, mod = 1e9+7;

struct P {
    int x, y;
    void read() { cin >> x >> y; }
    bool operator<(const P &he) const{ return tie(x, y) < tie(he.x, he.y);}
    bool operator==(const P &he) const { return tie(x, y) == tie(he.x, he.y);}
    P operator-(const P &he) const { return P{x - he.x, y - he.y};}
    P operator+(const P &he) const { return P{x + he.x, y + he.y};}
    int operator*(const P &he) const { return x * he.y - he.x * y;}
    int ilowek(const P &a, const P &b) const { return (a - *this) * (b - *this);}
};

bool po_prawej(P p){ return p.x > 0 || (p.x == 0 && p.y > 0);}

void add(int &a, int b){
    a += b;
    if (a >= mod) a-=mod;
}

void sub(int &a, int b){
    a -= b;
    if (a < 0) a+=mod;
}

int mul(int a, int b){
    return (a*b)%mod;
}

int add2(int a, int b){
    add(a, b);
    return a;
}

int sub2(int a, int b){
    sub(a, b);
    return a;
}

void __print(P x){
    cerr << "{" << x.x << ", " << x.y << "}";
}

struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    void update(int x, int v){
        x += size;
        add(tab[x], v);
        while (x){
            x/=2;
            tab[x] = add2(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) add(ans, tab[l+1]);
            if (r&1) add(ans, tab[r-1]);
        }
        return ans;
    }
    
    int sum(int L, int R){ ////?????????????????????????????????????????????
        if (L <= R) return query(L, R);
        //R < L;
        return add2(query(0, R), query(L, size-1));
    }
};

void solve(){
    int q; cin >> q;
    vector<P>p(q);
    vector<char>que(q);
    vector<P>scaler;
    for (int i = 0; i<q; i++){
        cin >> que[i];
        if (que[i] != 'S'){
            p[i].read();
            scaler.emplace_back(p[i]);
        }
    }
    sort(scaler.begin(), scaler.end());
    auto cmp = [](pair<P, int> a, pair<P, int> b){
        if (po_prawej(a.first) != po_prawej(b.first)) return po_prawej(a.first);
        int c = a.first * b.first;
        return (c == 0 ? a.second < b.second : c < 0);
    };
    int M = (int)scaler.size()+3;
    Tree X(M), Y(M);
    auto get = [&](P x){ return lower_bound(scaler.begin(), scaler.end(), x) - scaler.begin();};
    tree<pair<P, int>, null_type, decltype(cmp), rb_tree_tag, tree_order_statistics_node_update> s(cmp);
    int area = 0;
    for (int i = 0; i<q; i++){
        if (que[i] != 'S'){
            int coef = (que[i] == 'A' ? 1 : -1);
            int mid = get(p[i]);
            pair<P, int> curr = {p[i], i};
            if ((int)s.size()){
                P paralell_L = {-p[i].y, p[i].x};
                P paralell_R = {p[i].y, p[i].x};
                auto now = s.lower_bound({paralell_L, -oo});
                if (now == s.end()) now = s.begin();
                auto now2 = s.upper_bound({paralell_R, -oo});
                if (now2 != s.begin()) now2--;
                debug(p[i], now->first, now2->first);
                
                int L = s.order_of_key(*now);
                int R = s.order_of_key(*now2);
                // if (L == R) 
                debug(L, mid, R);
                debug(p[i].x, Y.sum(mid, R), p[i].y, X.sum(mid, R), Y.sum(L, mid), X.sum(L, mid));
                add(area, mul(coef, sub2(mul(p[i].y, X.sum(mid, R)), mul(p[i].x, Y.sum(mid, R)))));
                sub(area, mul(coef, sub2(mul(p[i].x, Y.sum(L, mid)), mul(p[i].y, X.sum(L, mid)))));
            }
            if (que[i] == 'A') s.insert(curr);
            else s.erase(s.lower_bound({p[i], 0}));
            X.update(mid, mul(coef, p[i].x));
            Y.update(mid, mul(coef, p[i].y));
        } else {
            cout << area << "\n";
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}