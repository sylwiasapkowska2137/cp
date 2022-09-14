#include <bits/stdc++.h>
using namespace std;

const int MAX = 1007;
vector<int> graf[MAX], match;
vector<bool>vis;

bool dfs(int v){
    vis[v] = 1;

    for (auto x: graf[v]){
        if (match[x] == -1){
            match[x] = v;
            match[v] = x;
            return 1;
        }
    }

    for (auto x: graf[v]){
        if (!vis[match[x]] && dfs(match[x])){
            match[x] = v;
            match[v] = x;
            return 1;
        }
    }
    return 0;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i<k; i++){
        int a, b; cin >> a >> b;
        b+=n;
        graf[a].push_back(b);
        //graf[b].push_back(a);
    }
    match.assign(n+m+1, -1);
    while (1){
        vis.assign(n+m+1, 0);
        bool any = 0;
        for (int i = 1; i<=n+m; i++){
            if (match[i] == -1 && dfs(i)) any = 1;
        }
        if (!any) break;
    }
    for (int i = 1; i<=n+m; i++) cerr << match[i] << " ";
    cerr << "\n";
    vector<pair<int, int>>ans;
    for (int i = 1; i<=n; i++){
        if (match[i] == -1) continue;
        //cout << i << " " << match[i]-n << "\n";
        ans.emplace_back(i, match[i]-n);
    }
    cout << ans.size() << "\n";
    for (auto x: ans) cout << x.first << " " << x.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}