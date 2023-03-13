#include <bits/stdc++.h>
using namespace std;
#define M 5050

int tot;
int n[2];
int a[2][M];
int nxt[2][M][M];
int mp[2][2][1<<20];

void input() {
    cin >> tot;
    memset(mp, -1, sizeof mp);
    for (int r = 0; r < 2; r++) {
        cin >> n[r];
        for (int i = 0; i < n[r]; i++) {
            cin >> a[r][i];
            a[r][i]--;
            if (mp[1][r][a[r][i]] == -1) {
                mp[1][r][a[r][i]] = i;
                ///printf("%d %d %d; %d\n", 1, r, a[r][i], i);
            }
        }
    }
    if (tot == 1) {
        int m = max(n[0], n[1]) + 1;
        cout << m << endl;
        for (int i = 1; i <= m; i++) {
            cout << 1 << " \n"[i == m];
        }
        exit(0);
    }
    for (int i = 0; i < tot; i++) if (mp[1][0][i] == -1 && mp[1][1][i] == -1) {
        cout << 1 << endl;
        cout << i + 1 << endl;
        exit(0);
    }
    for (int r = 0; r < 2; r++) {
        for (int t = 0; t < tot; t++) {
            int last = n[r];
            for (int i = n[r] - 1; i >= 0; i--) {
                nxt[r][i][t] = last;
                if (a[r][i] == t) {
                    last = i;
                }
                //printf("nxt[%d][%d][%d] = %d\n", r, i, t, nxt[r][i][t]);
            }
        }
    }
    //cout << "pass" << endl;
}

int len, bf;
int p[33];

void print() {
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        cout << p[i] + 1 << " \n"[i == len - 1];
    }
    exit(0);
}

void dfs(int d, int cur) {
    if (d == len) {
        //if (len == 3) if (cur != 26) return;
        //printf("d = %d, len = %d; cur = %d\n", d, len, cur);
        //for (int i = 0; i < len; i++) printf("%d ", p[i]); puts("");
        int c = cur / tot;
        bool res = 0;
        for (int r = 0; r < 2; r++) {
            mp[bf][r][cur] = -1;
            if (mp[!bf][r][c] >= 0) {
                int i = mp[!bf][r][c];
                if (nxt[r][i][p[d-1]] < n[r]) {
                    mp[bf][r][cur] = nxt[r][i][p[d-1]];
                    res = 1;
                }
            }
            //printf("mp[%d][%d][%d] = %d\n", len, r, cur, mp[bf][r][cur]);
        }
        if (!res) {
            print();
        }
        return;
    }
    for (int i = 0; i < tot; i++) {
        p[d] = i;
        dfs(d + 1, cur * tot + i);
    }
}

int main() {
    input();
    for (len = 2; len <= 33; len++) {
        bf = len & 1;
        dfs(0, 0);
    }
    return 0;
}
