//Mateusz Puczel
#include <bits/stdc++.h>

using namespace std;

const int N = 3000005;

bool vis[N];
long long dist[N];
int rep[N];
int n, m, a, b, k;
vector<pair<int, int> >V[N];

int find(int w) {
    return rep[w] == w? w: rep[w] = find(rep[w]);
}

void Union(int a, int b) {
    rep[find(a)] = find(b);
}

void DFS(int w) {
    vis[w] = true;
    for(int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        int edge = V[w][i].second;
        if(!vis[u]) {
            dist[u] = dist[w] + edge * ((u > w) * 2 - 1);
            DFS(u);
        }
    }    
}

int main() {
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n + 1; i++) {
        rep[i] = i;
    }
    int components = n + 1;
    
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &k);
        b++;
        V[a].push_back({b, k});
        V[b].push_back({a, k});
        if(find(a) != find(b)) {
            Union(a, b);
            components--;
        }
        if(components == 1) {
            printf("%d\n", i);
            break;
        }
    }
    
    if(components != 1) {
        printf("-1\n");
        return 0;
    }
    
    DFS(1);
 
    for(int i = 1; i <= n; i++) {
        printf("%lld ", dist[i + 1] - dist[i]);
    }
    
    return 0;
} 
