#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;

vector<int> G[N], vals, idx;
int n, m, a[N], ans[N];
bool vis[N];

void dfs(int v) {
    vis[v]=true;
    vals.push_back(a[v]);
    idx.push_back(v);

    for (auto u : G[v]) {
        if (vis[u]) continue;
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for (int i=1; i<=m; ++i) {
        int a, b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=n; ++i) {
        if (!vis[i]) {
            vals.clear(), idx.clear();
            dfs(i);

            sort(idx.begin(), idx.end());
            sort(vals.begin(), vals.end(), greater<int>());

            int sz=idx.size();
            assert(vals.size() == idx.size());
            for (int i=0; i<sz; ++i) ans[idx[i]]=vals[i];
        }
    }

    for (int i=1; i<=n; ++i) cout<<ans[i]<<" ";
    cout<<"\n";
}