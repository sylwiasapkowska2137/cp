#include <bits/stdc++.h>

using namespace std;

const int N = 500005, INF = 1000 * 1000 * 1000;

int n, m;
int from, to, a, b;
int dist[2 * N];
bool vis[2 * N];
priority_queue<pair<int, int> > Q;
vector<pair<int, int> > V[2 * N];

void dijkstra(int v) {
    for (int i = 1; i <= 2 * n; i++) {
        vis[i] = false;
        dist[i] = INF;
    }

    dist[v] = 0;
    Q.push(make_pair(0, v));

    while (!Q.empty()) {
        int w = Q.top().second;
        Q.pop();
        if (vis[w]) {
            continue;
        }
        for (int i = 0; i < V[w].size(); i++) {
            int u = V[w][i].first;
            int weight = V[w][i].second;
            if (dist[u] > dist[w] + weight) {
                dist[u] = dist[w] + weight;
                Q.push(make_pair(-dist[u], u));
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
        V[a].push_back(make_pair(b, 0));
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        a += n, b += n;
        V[a].push_back(make_pair(b, 0));
    }

    for (int i = 1; i <= n; i++) {
        V[i].push_back(make_pair(i + n, 1));
        V[i + n].push_back(make_pair(i, 1));
    }

    dijkstra(from);

    if (dist[to] >= INF) {
        printf("NIE\n");
    } else {
        printf("%d\n", dist[to]);
    }

    return 0;
}