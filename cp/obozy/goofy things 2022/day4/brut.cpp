#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int MAXN = 1e3+1;
const int di[] = {-1, -1, +1, +1};
const int dj[] = {-1, +1, -1, +1};

bool vis[MAXN][MAXN];

int c=1, tp[MAXN][MAXN], a[MAXN], n, d;

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = true;
    tp[x][y] = c;

    while (!q.empty()) {
        int i=q.front().first, j=q.front().second;
        q.pop();

        for (int k=0; k<4; ++k) {
            int ni=i+di[k], nj=j+dj[k];
            if ((ni >= 1 && ni <= n) && (nj >= 1 && nj <= n)) {
                if (abs(a[ni]-a[nj]) <= d && !vis[ni][nj]) {
                    tp[ni][nj] = c;
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>d;

    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i == j) continue;
            if (!vis[i][j] && abs(a[i]-a[j]) <= d) {
                bfs(i, j);
                ++c;
            }
        }
    }

    vector<pii> ans;
    for (int i=1; i<=n; ++i) {
        for (int j=i+1; j<=n; ++j) {
            if (tp[i][j] == tp[j][i] && tp[i][j] != 0) ans.push_back({i, j});
        }
    }
    sort(ans.begin(), ans.end());

    for (auto u : ans) {
        cout<<u.first<<" "<<u.second<<endl;
    }
}
