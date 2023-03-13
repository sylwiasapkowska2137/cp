#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, k, ones;
bool vis[2][N];
int dist[2][N];
queue<pair<int, int> > Q;
char tab[N];
int cnt[N];
set<int> notVis[2][2];

void BFS() {
    for (int i = 0; i <= n; i++) {
        dist[0][i] = dist[1][i] = n + 3;
        if (i != ones) {
            notVis[i % 2][0].insert(i);
        }
        notVis[i % 2][1].insert(i);
    }
    dist[0][ones] = 0;
    vis[0][ones] = true;
    Q.push({0, ones});
    while (!Q.empty()) {
        int d = Q.front().first;
        int w = Q.front().second;
        Q.pop();

        int maxOnesTaken = min(k, w);
        int minOnesTaken = max(0, k - (n - w));
        int from = w + k - 2 * maxOnesTaken;
        int to = w + k - 2 * minOnesTaken;

        set<int> &S = notVis[from % 2][1 - d];
        while (true) {
            auto it = S.lower_bound(from);
            if (it == S.end()) {
                break;
            }
            int u = *it;
            if (u <= to) {
                if (!vis[1 - d][u]) {
                    S.erase(u);
                    vis[1 - d][u] = true;
                    dist[1 - d][u] = dist[d][w] + 1;
                    Q.push({1 - d, u});
                }
            } else {
                break;
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &k);

    ones = 0;
    scanf("%s", &tab[1]);
    for (int i = 1; i <= n; i++) {
        if (tab[i] == '1') ones++;
    }

    BFS();

    for (int i = 0; i <= n; i++) {
        cnt[dist[0][i]] = i;
        cnt[dist[1][i]] = i;
    }

    for (int i = 2; i <= n; i++) {
        cnt[i] = max(cnt[i], cnt[i - 2]);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", cnt[i]);
    }

    return 0;
}