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

struct Node {
    char l = 'z'+1, r = 'a'-1;
    bool f = 1;
};

struct tree{
    vector<Node>tab;
    int size = 1;

    tree(int n, string &s){
        while (size < n) size*=2;
        tab.resize(2*size+1);
        for (int i = 1; i<(int)s.size(); i++){
            tab[i+size].f = 1;
            tab[i+size].l = s[i];
            tab[i+size].r = s[i];
        }
        for (int i = size-1; i>=1; i--){
            tab[i] = merge(tab[2*i], tab[2*i+1]);
        }
    }

    Node query(int x, int lx, int rx, int l, int r){
        if (lx > r || rx < l) return tab[0];
        if (lx >= l && rx <= r) return tab[x];           
        int m = (lx+rx)/2;
        return merge(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
    }

    void update(int x, int lx, int rx, int pos, char c){
        if (lx == rx){
            tab[x].l = c;
            tab[x].r = c;
            return;
        }
        int m = (lx+rx)/2;
        if (pos <= m) update(2*x, lx, m, pos, c);
        else update(2*x+1, m+1, rx, pos, c);
        tab[x] = merge(tab[2*x], tab[2*x+1]);
    }

    Node merge(Node a, Node b){
        if (b.r < 'a') return a;
        if (a.r < 'a') return b;
        Node ret;
        ret.l = a.l;
        ret.r = b.r;
        ret.f = (a.f && b.f && a.r <= b.l);
        return ret;
    }
};

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = "$"+s;
    tree t(n+2, s);
    int q; cin >> q;
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int pos; char c; cin >> pos >> c;
            t.update(1, 0, t.size-1, pos, c);
        } else {
            int l, r; cin >> l >> r;
            bool f = t.query(1, 0, t.size-1, l, r).f;
            if (f) cout << "Yes\n";
            else cout << "No\n";
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