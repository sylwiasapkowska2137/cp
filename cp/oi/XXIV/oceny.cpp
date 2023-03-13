//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
const int oo = 1e9+7;

void __print(int x) { 
    if (x == oo) cerr << "x"; 
    else if (x == -oo) cerr << "-x";
    else cerr << x;
}
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

typedef pair<int, int> T;
struct TreeMax{
    vector<int>tab;
    int size = 1;

    TreeMax(int n, vector<int>a = vector<int>()){
        while (size < n) size*=2;
        tab.assign(2*size, -oo);
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
        for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
    }

    void print(){
        for (int i = size; i<2*size; i++) {
            __print(tab[i]);
            cerr << ", ";
        }
        cerr << "\n";
    }

    void update(int x, int v){
        x += size;
        tab[x] = v;
        while (x){
            x/=2;
            tab[x] = max(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = -oo;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }

    int find(int x, int lx, int rx, int v){
        if (lx == rx) return lx;
        int m = (lx+rx)/2;
        if (tab[2*x] > v) return find(2*x, lx, m, v);
        return find(2*x+1, m+1, rx, v);
    }  
};

struct TreeMin{
    vector<int>tab;
    int size = 1;

    TreeMin(int n, vector<int>a = vector<int>()){
        while (size < n) size*=2;
        tab.assign(2*size, oo);
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
        for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
    }

    void print(){
        for (int i = size; i<2*size; i++) {
            __print(tab[i]);
            cerr << ", ";
        }
        cerr << "\n";
    }

    void update(int x, int v){
        x += size;
        tab[x] = v;
        while (x){
            x/=2;
            tab[x] = min(tab[2*x], tab[2*x+1]);
        }
    }

    int query(int l, int r){
        int ans = oo;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = min(ans, tab[l+1]);
            if (r&1) ans = min(ans, tab[r-1]);
        }
        return ans;
    }

    int find(int x, int lx, int rx, int v){
        if (lx == rx) return lx;
        int m = (lx+rx)/2;
        if (tab[2*x+1] < v) return find(2*x+1, m+1, rx, v);
        return find(2*x, lx, m, v);
    }    
};

struct TreeAns{
    vector<T>tab;
    vector<int>lazy;
    int size = 1;

    T f(T a, T b){
        if (a.first != b.first) return min(a, b);
        return T{a.first, a.second + b.second};
    }

    TreeAns(int n){
        while (size < n) size*=2;
        tab.assign(2*size, {0, 1});
        lazy.assign(2*size, 0);
        for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
    }

    void push(int x){
        tab[2*x].first += lazy[x];
        tab[2*x+1].first += lazy[x];
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }

    void update(int x, int lx, int rx, int l, int r, int add){
        if (lx != rx) push(x);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tab[x].first += add;
            lazy[x] += add;
            return;
        }
        int m = (lx+rx)/2;
        update(2*x, lx, m, l, r, add);
        update(2*x+1, m+1, rx, l, r, add);
        tab[x] = f(tab[2*x], tab[2*x+1]);
    }

    T query(int x, int lx, int rx, int l, int r){
        if (lx != rx) push(x);
        if (lx > r || rx < l) return T{oo, 0};
        if (lx >= l && rx <= r) return tab[x];
        int m = (lx+rx)/2;
        return f(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
    }
};

void solve(){
    int n, q; cin >> n >> q;
    --q;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    TreeMax tmax(n+2, a);
    TreeMin tmin(n+2, a);
    TreeAns tans(n+2);
    TreeMax left(n+2);
    TreeMin right(n+2);
    auto add_seg = [&](int l, int r){
        if (l >= r) return;
        debug(l, r);
        if (left.query(0, l) < r){ //wszystkie przedzialy zaczynajace sie wczesniej (≤) niz l koncza sie wczesniej niz r
            debug(l, r);
            left.update(l, r);
            right.update(r, l);
            if (l <= r-1) tans.update(1, 0, tans.size-1, l, r-1, +1);
        } 
    };
    auto first_to_right = [&](int i){
        if (i == n) return;
        int x = tmin.find(1, 0, tmin.size-1, a[i]);
        if (x == oo || x < 1) return;
        // debug(a[i], i, x);
        add_seg(i, x);
    };
    auto first_to_left = [&](int i){
        if (i == 1) return;
        int x = tmax.find(1, 0, tmax.size-1, a[i]); //[x, i]
        if (x == -oo || x > n) return;
        // debug(i, a[i], x);
        add_seg(x, i);
    };
    auto remove_seg = [&](int l){
        // debug(l, r);
        // if (l >= r) return;
        // if (left.query(l, l) == r) {
        int r = left.query(l, l);
        debug(l, r);
        if (r == -oo) return;
        debug("r", l, r);
        if (l <= r-1) tans.update(1, 0, tans.size-1, l, r-1, -1);
        left.update(l, -oo);
        right.update(r, oo);
        first_to_right(l);
        first_to_left(r);
        // }
    };
    for (int i = 1; i<n; i++){
        first_to_right(i);
        first_to_left(i);
    }
    auto print = [&](){
        T curr = tans.query(1, 0, tans.size-1, 1, n);
        if (curr.first) curr.second = 1;
        cout << curr.second << "\n";
    };
    auto fix = [&](int l, int r){
        first_to_left(l);
        first_to_left(r);
        first_to_right(l);
        first_to_right(r);
    };
    print();
    // left.print();
    // right.print();
    while (q--){
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        
        //am i dumb???
        remove_seg(l, L[l]);
        remove_seg(r, L[r]);
        remove_seg(R[l], l);
        remove_seg(R[r], r);
        swap(a[l], a[r]);
        tmin.update(l, a[l]);
        tmin.update(r, a[r]);
        tmax.update(l, a[l]);
        tmax.update(r, a[r]);
        remove_seg(l);
        remove_seg(r);
        first_to_left(l);
        first_to_left(r);
        first_to_right(r);
        first_to_right(l);
        add_seg(l, L[l]);
        add_seg(r, L[r]);
        add_seg(R[l], l);
        add_seg(R[r], r);
        add_seg(l, left.query(l, l));
        add_seg(r, left.query(r, r));
        print();
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

