#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000005;
 
int n, a, b, ans;
int color[N];
bool vis[N];
pair<int, int> bestPair[N], secondBestPair[N];
vector<int> V[N];
 
void DFS(int w) {
    vis[w] = true;
   
    bestPair[w] = {0, color[w]};
    secondBestPair[w] = {-1e9, 0};
   
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            DFS(u);
            if (bestPair[w].second != bestPair[u].second) {
                ans = max(ans, bestPair[w].first + bestPair[u].first + 1);
            } else {
                ans = max(ans, max(bestPair[w].first + secondBestPair[u].first + 1,
                                   secondBestPair[w].first + bestPair[u].first + 1));
            }
            pair<int, int> tmp = bestPair[u];
            tmp.first++;
            if (tmp >= bestPair[w]) {
                swap(tmp, bestPair[w]);
            }
            if (tmp.second != bestPair[w].second) {
                secondBestPair[w] = max(secondBestPair[w], tmp);
            }
            tmp = secondBestPair[u];
            tmp.first++;
            if (tmp.second != bestPair[w].second) {
                secondBestPair[w] = max(secondBestPair[w], tmp);
            }
        }
    }
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }
   
    DFS(1);
    printf("%d\n", ans);
    return 0;
}
