#include <bits/stdc++.h>

using namespace std;

const int N = 500005, K = 50;

int n, from, to, m, a, b;
bool vis[K][2 * N];
vector<int> V[2 * N];
queue<pair<int, int> > Q;

void dijkstra(int v) {
    vis[0][v] = true;
    Q.push({0, v});
    while (!Q.empty()) {
        int w = Q.front().second;
        int steps = Q.front().first;
        Q.pop();
        for (int i = 0; i < V[w].size(); i++) {
            int u = V[w][i];
            if (!vis[steps][u]) {
                vis[steps][u] = true;
                Q.push({steps, u});
            }
        }
        if (steps + 1 < K)  {
            if (w <= n) {
                if (!vis[steps + 1][w + n]) {
                    vis[steps + 1][w + n] = true;
                    Q.push({steps + 1, w + n});
                }
            } else {
                if (!vis[steps + 1][w - n]) {
                    vis[steps + 1][w - n] = true;
                    Q.push({steps + 1, w - n});
                }
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &n, &from, &to);
    to += n;

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        a += n, b += n;
        V[a].push_back(b);
    }

    dijkstra(from);

    for (int i = 0; i < K; i++) {
        if (vis[i][to]) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("NIE\n");

    return 0;
}