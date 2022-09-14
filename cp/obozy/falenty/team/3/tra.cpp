#include <bits/stdc++.h>

using namespace std;

const int N = 501;
const int INF = 1e9;

vector<int> G[N], GT[N];
bool e[N][N];
int d[N];

void bfs(vector<int> *G) {
    for (int i=0; i<N; ++i) d[i]=1e9;
    d[1]=0;
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int v=q.front(); q.pop();
        for (auto u : G[v]) {
            if (d[u] > d[v]+1) {
                d[u]=d[v]+1;
                q.push(u);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; cin>>n>>m;
    for (int i=1; i<=m; ++i) {
        int a, b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        e[a][b]=e[b][a]=true;
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (!e[i][j]) {
                GT[i].push_back(j);
                GT[j].push_back(i);
            }
        }
    }

    if (e[1][n]) bfs(GT);
    else bfs(G);

    if (d[n] == INF) cout<<-1<<"\n";
    else cout<<d[n]<<"\n";
}