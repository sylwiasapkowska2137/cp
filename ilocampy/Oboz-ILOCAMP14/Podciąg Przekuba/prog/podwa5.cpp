#include <stdio.h>
#include <string.h>

const int MAXK = 5010, MAXM = 5010, MAXN = 5010;
int k, m, n;
int a[MAXM], b[MAXN];
int x[MAXK], y[MAXK];
int last[MAXM];
int prex[MAXM][MAXN], prey[MAXM][MAXN];
int ans[MAXM], len;

void init()
{
    scanf("%d", &k);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
}

void findfirst(int x0, int y0)
{
    for (int i = 1; i <= k; ++i) x[i] = m + 1, y[i] = n + 1;
    for (int i = m; i > x0; --i) x[a[i]] = i;
    for (int i = n; i > y0; --i) y[b[i]] = i;
}

void answer(int last, int x, int y)
{
    len = 0;
    ans[len++] = last;
    while (x && y) {
        if (x <= m) ans[len++] = a[x];
        else        ans[len++] = b[y];
        int x0 = x, y0 = y;
        x = prex[x0][y0];
        y = prey[x0][y0];
    }
    printf("%d\n", len);
    for (int i = len - 1; i >= 0; --i) printf("%d ", ans[i]);
    puts("");
}

void solve()
{
    memset(last, -1, sizeof(last));
    last[0] = 0;
    for (;;) {
        for (int i = m + 1; i >= 0; --i) {
            if (last[i] < 0) continue;
            findfirst(i, last[i]);
            for (int j = 1; j <= k; ++j) {
                if (x[j] > m && y[j] > n) {
                    answer(j, i, last[i]);
                    return;
                }
                if (y[j] > last[x[j]]) {
                    last[x[j]] = y[j];
                    prex[x[j]][y[j]] = i;
                    prey[x[j]][y[j]] = last[i];
                }
            }
            last[i] = -1;
        }
    }
}

int main()
{
    init();
    solve();
}
