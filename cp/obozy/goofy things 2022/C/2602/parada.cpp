#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct E{
    int a, b, c; 
    E(){}
    E(int _a, int _b, int _c){
        a = _a, b = _b, c = _c;
    }
};
int n;
const int MAX = 1e6+7, K = 21, INF = 1e9+7;
vector<int>rep, sz, graf[MAX], pre, sub, order;
int up[MAX][K];
map<int, int>mapa;
int cnt, czas;

int Find(int a){
    if (a == rep[a]) return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b, int c){
    int A = Find(a);
    int B = Find(b);
    if (A == B) return;
    cnt++;
    graf[cnt].push_back(A);
    //graf[A].push_back(cnt);
    graf[cnt].push_back(B);
    //graf[B].push_back(cnt);
    rep[B] = cnt;
    rep[A] = cnt;
    mapa[cnt] = c;
}

void dfs(int v, int pa){
    sub[v] = 1;
    pre[v] = czas++;
    up[v][0] = pa;
    order.push_back(v);
    for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
    for (auto x: graf[v]){
        if (x!=pa){
            dfs(x, v);
            sub[v] += sub[x];
        }
    }
}
 
struct segtree{
    vector<pair<int, int>>tab;
    vector<int> lazy;
    int size = 1;
 
    segtree(int N){
        while (size < N) size*=2;
        tab.assign(2*size+1, {INF, 1});
        for (int i = 0; i<(int)order.size(); i++){
            if (order[i] <= n) tab[i+size] = {0, 1};
            else tab[i+size] = {INF, 1};
        }
        for (int i = size-1; i>=1; i--){
            tab[i] = combine(tab[2*i], tab[2*i+1]);
        }
        lazy.assign(2*size+1, 0);
    }
 
    void push(int x, int lx, int rx){
        if (lx == rx) return;
        tab[2*x].first += lazy[x];
        tab[2*x+1].first += lazy[x];
        lazy[2*x] += lazy[x];
        lazy[2*x+1] += lazy[x];
        lazy[x] = 0;
    }
 
    pair<int, int> combine(pair<int, int>a, pair<int, int>b){
        if (a.first == b.first) return {a.first, a.second+b.second};
        if (a.first < b.first) return a;
        return b;
    }
 
    void update(int x, int lx, int rx, int l, int r, int val){
        push(x, lx, rx);
        if (lx > r || rx < l) return;
        if (lx >= l && rx <= r){
           
            tab[x].first+=val;
            lazy[x]+=val;
            //debug(x, lx, rx, val, tab[x]);
            return;
        }
        int m = (lx+rx)/2;
        
        update(2*x, lx, m, l, r, val);
        update(2*x+1, m+1, rx, l, r, val);
        tab[x] = combine(tab[2*x], tab[2*x+1]);
    }
 
    pair<int, int> query(int x, int lx, int rx, int l, int r){
        push(x, lx, rx);
        if (lx > r || rx < l) return {INF, 1};
        if (lx >= l && rx <= r) return tab[x];
        int m = (lx+rx)/2;
        return combine(query(2*x, lx, m, l, r),query(2*x+1, m+1, rx, l, r));
    }
};
 

int jump(int v, int k){
    for (int i = K-1; i>=0; i--){
        if (mapa.find(up[v][i]) != mapa.end() && mapa[up[v][i]] <= k){
            v = up[v][i];
        }
    }
    return v;
}

void solve(){
    int q, x; cin >> n >> q >> x;
    cnt = n;
    vector<E>edges;
    for (int i = 1; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b){return a.c < b.c;});
    rep.resize(2*n+1);
    sz.assign(2*n+1, 1);
    iota(rep.begin(), rep.end(), 0);
    for (auto [a, b, c]:edges){
        //debug(a, b, c);
        Union(a, b, c);
    }
    /*
    for (int v = 1; v<=cnt; v++){
        for (auto x: graf[v]){
            if (x > v) {
                cerr << v << " " << x << "\n";
            }
        }
    }
    debug(mapa);
    */
    pre.assign(cnt+1, 0);
    sub.assign(cnt+1, 0);
    dfs(cnt, cnt);
    /*
    debug(pre);
    debug(sub);
    */
    //debug(order);
    
    set<pair<long long, pair<int, int>>>s;
    segtree seg(cnt+1);
    //debug(seg.tab);
    while (q--){
        int d, k, v; cin >> d >> v >> k;
        while (!s.empty() && s.begin()->first < d){
            seg.update(1, 0, seg.size-1, s.begin()->second.first, s.begin()->second.second, -1);
            s.erase(s.begin());
        }
        int w = jump(v, k);
        //debug(w);
        pair<int, int>curr = seg.query(1, 0, seg.size-1, pre[w], pre[w]+sub[w]-1);
        //debug(w, curr);
        if (!curr.first)cout << curr.second << "\n";
        else cout << "0\n";
        seg.update(1, 0, seg.size-1, pre[w], pre[w]+sub[w]-1, 1); 
        s.insert({(long long)d+x-1,{pre[w], pre[w]+sub[w]-1}});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
