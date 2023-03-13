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

struct frac{
    int a, b;
    frac(int _a = 0, int _b = 1){
        a = _a, b = _b;
        if (b < 0) { a = -a, b = -b;}
    }
    bool operator <(const frac&he) const{ return a * he.b < b * he.a;}
    bool operator <=(const frac&he) const{ return a * he.b <= b * he.a;}
    void out(){
        assert(a * b >= 0);
        if (b < 0){ a = -a; b = -b;}
        int g = __gcd(a, b);
        a/=g; b/=g;
        cout << a << "/" << b << "\n";
    }
};

void __print(frac x){
    cerr << "{" << x.a << ", " << x.b << "}";
}

struct Line{
    int a, b;
    Line(int _a = 0, int _b = 0){ a = _a, b = _b;}
    int f(int x){return a*x + b;}
    frac inter(const Line&he){
        if (he.a == a) return frac{oo2, 1};
        // debug(*this, he);
        return frac{he.b - b, a - he.a};
    }
};

void __print(Line x){
    cerr << "y = " << x.a << "x + " << x.b;
}

void solve(){
    int n; cin >> n;
    vector<Line>tab;
    for (int i = 0; i<n; i++){
        int a, b; cin >> b >> a;
        tab.emplace_back(a, b);
    }
    frac mn = {0, 1}, mx = {oo2-7, 1};
    multiset<frac>L, R;
    set<T>bad;
    auto print = [&](){
        debug(bad, L, R);
        if ((int)bad.size()){
            cout << "NIE\n";
            return;
        }
        frac left = mn;
        frac right = mx;
        if ((int)L.size() && left < *L.rbegin()) left = *L.rbegin();
        if ((int)R.size() && *R.begin() < right) right = *R.begin(); 
        debug(left, right);
        if (left <= right){
            if (left.a != 0) left.out();
            else right.out();
        } else {
            cout << "NIE\n";
        }
    };
    vector<int>ord(n);
    for (int i = 0; i<n; i++) {
        cin >> ord[i];
        --ord[i];
    }
    auto insert = [&](int idxa, int idxb){ //wyznaczyc przedzial, gdzie prev < curr
        if (idxa < 0 || idxb < 0 || idxa >= n || idxb >= n) return;
        auto &prev = tab[idxa];
        auto &curr = tab[idxb];
        if (prev.a == curr.a){
            if (prev.b > curr.b){
                bad.insert(T{idxa, idxb});
            } else {
                //zawsze dziala
            }
            return;
        }
        frac now = prev.inter(curr);
        debug(idxa, idxb, now);
        if (prev.a < curr.a){
            //curr jest bardziej nachylone
            L.insert(now);
        } else {
            R.insert(now);
        }
        // debug(now);
    };
    
    auto remove = [&](int idxa, int idxb){
        if (idxa < 0 || idxb < 0 || idxa >= n || idxb >= n) return;
        debug(idxa, idxb, "remove");
        auto &prev = tab[idxa];
        auto &curr = tab[idxb];
        if (prev.a == curr.a){
            if (prev.b > curr.b){
                bad.erase(T{idxa, idxb});
            } else {
                //zawsze dziala
            }
            return;
        }
        frac now = prev.inter(curr);
        if (prev.a < curr.a){
            //curr jest bardziej nachylone
            L.erase(L.find(now));
        } else {
            R.erase(R.find(now));
        }
        // debug(now);
    };
    
    for (int i = 1; i<n; i++) insert(ord[i-1], ord[i]);
    print();
    int q; cin >> q;
    while (q--){
        int a, b; cin >> a >> b;
        --a;--b;
        debug(a, b, ord);
        if (abs(b-a) == 1){
            if (min(a, b)) remove(ord[min(a, b)-1], ord[min(a, b)]);
            if (max(a, b) + 1 < n) remove(ord[max(a, b)], ord[max(a, b)+1]);
            remove(ord[min(a, b)], ord[max(a, b)]);
        } else {
            if (a) remove(ord[a-1], ord[a]);
            if (a + 1 < n) remove(ord[a], ord[a+1]);
            if (b) remove(ord[b-1], ord[b]);
            if (b + 1 < n) remove(ord[b], ord[b+1]);
        }
        swap(ord[a], ord[b]);
        debug(ord);
        if (abs(b-a) == 1){
            if (min(a, b)) insert(ord[min(a, b)-1], ord[min(a, b)]);
            if (max(a, b) + 1 < n) insert(ord[max(a, b)], ord[max(a, b)+1]);
            insert(ord[min(a, b)], ord[max(a, b)]);
        } else {
            if (a) insert(ord[a-1], ord[a]);
            if (a + 1 < n) insert(ord[a], ord[a+1]);
            if (b) insert(ord[b-1], ord[b]);
            if (b + 1 < n) insert(ord[b], ord[b+1]);
        }
        print();
        // return;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}