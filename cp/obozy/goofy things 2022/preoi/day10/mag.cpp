#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAX = 1e5+7;
vector<int>rep, tab[MAX], w[MAX];
LL ans;

int Find(int a){
    if (a == rep[a]) return a;
    return rep[a] = Find(rep[a]);
}

bool Union(int a, int b, int c){
    a = Find(a);
    b = Find(b);
    if (a == b) return 0;
    if ((int)tab[a].size() < (int)tab[b].size()) swap(a, b);
    ans += c;
    tab[a].insert(tab[a].end(), tab[b].begin(), tab[b].end());
    w[a].push_back(c);
    w[a].insert(w[a].end(), w[b].begin(), w[b].end());
    rep[b] = a;
    return 1;
}

void init(int n){
    rep.resize(n+1);
    iota(rep.begin(), rep.end(), 0);
    for (int i = 1; i<=n; i++) tab[i].push_back(i);
}

struct E{
    int a, b, c;
    E(int _a = 0, int _b = 0, int _c = 0){
        a = _a, b = _b, c = _c;
    }
};

struct segtree{
    vector<int>tab;
    int size = 1;

    segtree(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size+1, 0);
        for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
        for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
    }

    int query(int l, int r){
        l = l+size-1;
        r = r+size+1;
        int ans = 0;
        while (r-l>1){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
            l/=2;r/=2;
        }
        return ans;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<E>edges;
    map<pair<int, int>, int>edge;
    for (int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        if (a > b) swap(a, b);
        edges.emplace_back(a, b, c);
        edge[{a, b}] = c;
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b){return a.c < b.c;});
    init(n);
    set<pair<int, int>>used;
    for (auto [a, b, c]:edges) if (Union(a, b, c)) used.insert({a, b});
    //cerr << ans << "\n";
    int x = 1;
    for (int v = 2; v<=n; v++) if ((int)tab[v].size() == n) x = v;
    vector<int>pos(n+1);
    for (int i = 0; i<(int)tab[x].size(); i++) {
        pos[tab[x][i]] = i;
    }
    segtree seg(n+1, w[x]);
    int q; cin >> q;
    while (q--){
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        if (used.find({a, b}) != used.end()){
            cout << ans << "\n";
            continue;
        }
        int l = pos[a], r = pos[b];
        if (l > r) swap(l, r);
        cout << ans-seg.query(l, r-1)+edge[{a, b}]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}