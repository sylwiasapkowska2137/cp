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

// #define int long long
typedef pair<int, int> T;
const int oo = 1e9+7, K = 30;
const int mod = 998244353;

struct Tree{
    struct Node{
        bool x[2][2] = {{1, 0}, {0, 1}};
        int left[2] = {oo, oo};
        int right[2] = {oo, oo};
    };
    vector<Node>tab;
    int size = 1;

    Tree(int n, vector<T>&a){
        while (size < n) size*=2;
        tab.resize(2*size);
        for (int i = 1; i<(int)a.size(); i++){
            tab[i+size].left[0] = a[i].first;
            tab[i+size].left[1] = a[i].second;
            tab[i+size].right[0] = a[i].first;
            tab[i+size].right[1] = a[i].second;
        }
        for (int i = size-1; i>=1; i--){
            tab[i] = merge(tab[2*i], tab[2*i+1]);
        }
    }

    void update(int x, T curr){
        x += size;
        tab[x].left[0] = curr.first;
        tab[x].left[1] = curr.second;
        tab[x].right[0] = curr.first;
        tab[x].right[1] = curr.second;
        while (x){
            x/=2;
            tab[x] = merge(tab[2*x], tab[2*x+1]);
        }
    }

    Node merge(Node &xx, Node &yy){
        if (xx.left[0] == oo) return yy;
        if (yy.left[0] == oo) return xx;
        Node res;
        res.left[0] = xx.left[0]; 
        res.left[1] = xx.left[1]; 
        res.right[0] = yy.right[0];
        res.right[1] = yy.right[1];
        memset(res.x, 0, sizeof(res.x));
        for (int x = 0; x < 2; x++){
            for (int y = 0; y < 2; y++){
                for (int a = 0; a < 2; a++){
                    for (int b = 0; b < 2; b++){
                        if (xx.x[x][y] && yy.x[a][b] && xx.right[y] <= yy.left[a]){
                            res.x[x][b] = 1;
                        }
                    }
                }
            }
        }
        return res;
    }

    void d(Node curr){
        cerr << "-------\n";
        for (int a = 0; a < 2; a++){
            for (int b = 0; b < 2; b++){
                cerr << curr.x[a][b] << " ";
            }
        }
        cerr << "\n";
        // debug(curr.left, curr.right);
    }

    Node query(int x, int lx, int rx, int l, int r){
        if (lx > r || rx < l) return tab[0];
        if (lx >= l && rx <= r) return tab[x];
        int m = (lx+rx)/2;
        Node a = query(2*x, lx, m, l, r);
        Node b = query(2*x+1, m+1, rx, l, r);
        return merge(a, b);
    }
    
    bool query(int l, int r){
        bool ans = 0;
        for (int x = 0; x < 2; x++){
            for (int y = 0; y < 2; y++){
                ans |= tab[1].x[x][y];
            }
        }
        return ans;
    }
};

void solve(){
    int n; cin >> n;
    vector<T>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i].first >> a[i].second;
    Tree t(n+3, a);
    int q; cin >> q;
    while (q--){
        int x, y; cin >> x >> y;
        T X = a[x];
        T Y = a[y];
        a[y].swap(a[x]);
        t.update(y, X);
        t.update(x, Y);
        cout << (t.query(1, n) ? "TAK\n" : "NIE\n");
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}