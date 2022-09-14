#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int MAXN = 1e5+1;

int n, q, col[MAXN], dist[MAXN], ans[MAXN], tin[MAXN], tout[MAXN], l, t=0;
vector<int> G[MAXN];
set<pii> s[MAXN];
vector<vector<int>> up;

// fajne zadania dzisiaj, +10 social credits

void preorder(int v, int p) {
    tin[v] = t++;
    if (p != v) dist[v] = dist[p]+1;
    s[col[v]].insert({t-1, v});
    up[v][0] = p;
    for (int i=1; i<=l; ++i) up[v][i] = up[up[v][i-1]][i-1];
    for (auto u : G[v]) {
        if (u == p) continue;
        preorder(u, v);
    }
    tout[v] = t++;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i=l; i>=0; --i) {
        if (!isAncestor(up[u][i], v)) u=up[u][i];
    }
    return up[u][0];
}

int d(int v, int u) {
    return dist[v]+dist[u]-2*dist[lca(u, v)];
}

pii findN(int v, int c) {
    auto p = s[c].find({tin[v], v});
    int left=(v == s[c].begin()->second ? s[c].rbegin()->second : (--p)->second);
    if (p->second != v) ++p;
    assert(p->second == v);
    int right=(v == s[c].rbegin()->second ? s[c].begin()->second : (++p)->second);
    return {left, right};
}

void removeVertex(int v) {
    int vc=col[v], tmp=2*ans[vc];
    assert(!s[vc].empty());
    auto [left, right] = findN(v, vc);
    tmp += d(left, right)-(d(left, v)+d(v, right));
    s[vc].erase({tin[v], v});
    ans[vc] = tmp/2;
}

void addVertex(int v, int c) {
    int tmp=2*ans[c];
    s[c].insert({tin[v], v});
    auto [left, right] = findN(v, c);
    tmp += d(left, v)+d(v, right)-d(left, right);
    ans[c] = tmp/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    l=ceil(log2(n));
    up.assign(n+1, vector<int>(l+1, 1));

    for (int i=1; i<=n-1; ++i) {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i=1; i<=n; ++i) cin>>col[i];

    preorder(1, 1);
    for (int i=1; i<MAXN; ++i) {
        if (s[i].size() <= 1) continue;
        int last=s[i].begin()->second, tmp=0;

        for (auto u : s[i]) {
            if (u.second == last) continue;
            tmp += d(u.second, last);
            last = u.second;
        }
        tmp += d(s[i].begin()->second, s[i].rbegin()->second);
        ans[i] = tmp/2;
    }
    cin>>q;

    for (int i=1; i<=q; ++i) {
        char c;
        cin>>c;

        if (c == 'Q') {
            int a;
            cin>>a;
            if (s[a].empty()) cout<<-1<<"\n";
            else cout<<ans[a]<<"\n";
        } else {
            int a, b;
            cin>>a>>b;
            removeVertex(a);
            addVertex(a, b);
            col[a] = b;
        }
    }
}
