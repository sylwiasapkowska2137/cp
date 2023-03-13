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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
typedef long double ld;

struct P{
    int x, y;
    P(){}
    P(int _x, int _y): x(_x), y(_y){}
    void read(){cin >> x >> y;}
    bool operator < (const P &he) const { return tie(x, y) < tie(he.x, he.y);}
    P operator -(const P &he) const { return P{x-he.x, y-he.y};}
    int operator*(const P &he) const { return x * he.y - y * he.x;}
    int ilo(const P &A, const P &B) const{ return (A-*this) * (B-*this);}
};

ld dist(P A, P B){
    return sqrtl((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); 
}

void convex_hull(vector<P>&p){
    vector<P>hull;
    sort(p.begin(), p.end());
    for (int rep = 0; rep < 2; rep++){
        int S = (int)hull.size();
        for (auto C: p){
            while ((int)hull.size() >= S+2){
                auto B = hull.end()[-2];
                auto A = hull.end()[-1];
                if (A.ilo(B, C) <= 0){
                    break;
                }
                hull.pop_back();
            }
            hull.emplace_back(C);
        }
        hull.pop_back();
        reverse(p.begin(), p.end());
    }
    p.swap(hull);
}


int sgn(const int& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(int a, int b, int c, int d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool intersect(const P &a, const P& b, const P& c, const P& d) {
    if (c.ilo(a, d) == 0 && c.ilo(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.ilo(b, c)) != sgn(a.ilo(b, d)) &&
           sgn(c.ilo(d, a)) != sgn(c.ilo(d, b));
}

void solve(){
    int n; cin >> n;
    vector<P>p(n);
    for (int i = 0; i<n; i++) p[i].read();
    P A, B; A.read(); B.read();
    bool any = 0;
    for (int i = 0; i<n; i++){
        if (intersect(A, B, p[i], p[(i == n-1 ? 0 : i+1)])){
            any = 1;
            break;
        }
    }
    cout << setprecision(15) << fixed;
    if (!any){
        cout << dist(A, B) << "\n";
        return;
    }
    p.emplace_back(A);
    p.emplace_back(B);
    convex_hull(p);
    // for (auto [x, y]: p){
    //     debug(x, y);
    // }
    ld a = 0, b = 0;
    int idxa = 0, idxb = 0;
    for (int i = 0; i<(int)p.size(); i++){
        if (p[i].x == A.x && p[i].y == A.y) idxa = i;
        if (p[i].x == B.x && p[i].y == B.y) idxb = i;
    }
    auto nxt = [&](int i){ return (i == (int)p.size()-1 ? 0 : i+1);};
    for (int i = idxa; i != idxb; i = nxt(i)) a += dist(p[i], p[nxt(i)]);
    for (int i = idxb; i != idxa; i = nxt(i)) b += dist(p[i], p[nxt(i)]);
    cout << min(a, b) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cerr << fixed << setprecision(4);
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}