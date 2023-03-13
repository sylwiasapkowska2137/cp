#include <bits/stdc++.h>

using namespace std;

const int N = 200005, M = 1e9 + 7;

int n, m, k, a, b, c, erased, contradiction;
vector<pair<int, int> > V[N];
int vis[N];
bool pref[N], prefX[N], prefY[N];
bool prefArea[N];

void DFS(int w, int par, int parX, int parY, bool area, bool weightsSum) {
    if (vis[w]) {
        area ^= parY & (prefX[w] ^ parX);
        if ((weightsSum ^ pref[w]) != (area ^ prefArea[w])) contradiction = true;
        erased++;
        return;
    }
    pref[w] = weightsSum;
    vis[w] = true;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        int weight = V[w][i].second;
        if (u != par && vis[u] != 2) {
            int x, y;
            if (u > n) {
                x = parX;
                y = u - n;
            } else {
                x = u;
                y = parY;
            }
            x &= 1, y &= 1;
            long long newArea = area;
            if (parX != -1 && parY != -1) {
                newArea ^= y && (x ^ parX);
            }
            prefArea[w] = newArea;
            prefX[w] = x, prefY[w] = y;
            DFS(u, w, x, y, newArea, weightsSum ^ weight);
        }
    }

    vis[w] = 2;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= k; i++) {

        scanf("%d %d %d", &a, &b, &c);
        b += n;
        V[a].push_back({b, c});
        V[b].push_back({a, c});
    }

    for (int i = 1; i <= n + m; i++) {
        if (vis[i] == false) {
            int x = -1, y = -1;
            if (i > n) {
                y = i - n;
            } else {
                x = i;
            }
            DFS(i, -1, x, y, 0, 0);
        }
    }

    if (contradiction) {
        printf("0\n");
        return 0;
    }

    int ans = 1;
    for (int i = 1; i <= n + m - 1 - k + erased; i++) {
        ans += ans;
        if (ans >= M) ans -= M;
    }

    printf("%d\n", ans);

    return 0;
}