#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, k, ones;
bool vis[2][N];
int dist[2][N];
queue<pair<int, int> > Q;
char tab[N];
int cnt[N];

void BFS() {
    for (int i = 0; i <= n; i++) {
        dist[0][i] = dist[1][i] = n + 3;
    }
    dist[0][ones] = 0;
    vis[0][ones] = true;
    Q.push({0, ones});
    while (!Q.empty()) {
        int d = Q.front().first;
        int w = Q.front().second;
//         cerr << d << " " << w << " " << dist[d][w] << endl;
        Q.pop();
        for (int i = min(k, w); i >= 0; i--) {
            int zeros = k - i;
            if (zeros > n - w) {
                break;
            }
            int u = w - i + zeros;
            if (!vis[1 - d][u]) {
                vis[1 - d][u] = true;
                dist[1 - d][u] = dist[d][w] + 1;
                Q.push({1 - d, u});
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