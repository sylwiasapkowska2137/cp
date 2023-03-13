#include <bits/stdc++.h>
 
using namespace std;
const int N = 1000005;
 
int takenEdges;
vector<int> V[N];
bool vis[N];
int path[N];
int res;

void DFS(int w) {
    vis[w] = true;
    int longest = -1;
    for(int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if(!vis[u]) {
            DFS(u);
            if(path[u] + 1 > res) {
                takenEdges++;
                continue;
            }
            if(path[u] + longest + 2 > res) {
                takenEdges++;
                if(path[u] > longest) {
                    continue;
                }
                longest = path[u];
            } else {
                longest = max(longest, path[u]);
            }
        }
    }
    path[w] = longest + 1;
}
 
bool good(int n, int K) {
    for(int i = 0; i <= n; i++) {
        vis[i] = 0;
    }    
    takenEdges = 0;
    DFS(1);
    return takenEdges <= K;
}
 
int main() {
    int n, K;
    int a, b;
    scanf("%d %d", &n, &K);
   
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
   
    int poc = 0;
    int kon = n;
    int ret = n;
    while(poc <= kon) {
        int sr = (poc + kon) / 2;
        res = sr;
        if(good(n, K)) {
            ret = sr;
            kon = sr - 1;
        } else {
            poc = sr + 1;
        }
    }
    printf("%d\n", ret);
}
