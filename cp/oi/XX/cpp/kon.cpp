#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << "\'" << x << "\'";}
void __print(string x) {cerr << "\"" << x << "\"";}

template<typename T, typename V>
void __print(pair<T, V> x){
    cerr << "{";
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << "}";
}

template<typename T>
void __print(T v){
    int f = 0;
    cerr << "{";
    for (auto &i: v){
        cerr << (f++ ? ", " : "");
        __print(i);
    }
    cerr << "}";
}

void _print(){cerr << "]\n";}
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
const int oo = 1e18;

struct Tree{
    vector<int>tab;
    int size = 1;

    void init(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    void update(int x){
        x += size;
        tab[x]++;
        while (x){
            x/=2;
            tab[x] = tab[2*x] + tab[2*x+1];
        }
    }

    int query(int l, int r){
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans += tab[l+1];
            if (r&1) ans += tab[r-1];
        }
        return ans;
    }
} tsum;

struct Lazy{
    vector<int>tab, lazy;
    int size = 1;

    void init(int n, int32_t *a){
        while (size < n+2) size*=2;
        tab.assign(2*size, 0);
        lazy.assign(2*size, 0);
        for (int i = 0; i<n; i++){
            tab[i+size] = a[i];
        }
        for (int i = size-1; i>=1; i--){
            tab[i] = max(tab[2*i], tab[2*i+1]);
        }
    }

    void update(int x, int lx, int rx, int l, int r, int val){
        push(x, lx, rx);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
            tab[x] += val;
            lazy[x] += val;
            return;
        }
        int m = (lx+rx)/2;
        update(2*x, lx, m, l, r, val);
        update(2*x+1, m+1, rx, l, r, val);
        tab[x] = max(tab[2*x], tab[2*x+1]);
    }

    void push(int x, int lx, int rx){
        if (lx == rx || lazy[x] == 0) return;
        tab[2*x] += lazy[x];
        tab[2*x+1] += lazy[x];
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }

    int find(int x, int lx, int rx){
        if (lx == rx) return lx;
        push(x, lx, rx);
        int m = (lx+rx)/2;
        if (tab[2*x] >= tab[2*x+1]) return find(2*x, lx, m);
        return find(2*x+1, m+1, rx);
    }
} tmax;

#undef int
int K;

void fix(){
    while (tmax.tab[1] >= K){
        int i = tmax.find(1, 0, tmax.size-1);
        tmax.update(1, 0, tmax.size-1, i, i, -oo);
        tsum.update(i);
    }
}


void inicjuj(int n, int k, int *D){
    tsum.init(n+1);
    tmax.init(n, D);
    K = k;
    fix();
}

void podlej(int a, int b){
    tmax.update(1, 0, tmax.size-1, a, b, 1);
    fix();
}

int dojrzale(int l, int r){
    return tsum.query(l, r);
}