#include <iostream>
#include <cstdio>
using namespace std;

const long long INF = 1000000000LL * 1000000000LL;
const int M = 3003;
int n, m;
long long dp[M][M];
long long t[M][M];

int main() {
    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            scanf("%lld", &t[i][j]);

    for (int i=0; i<=m; i++)
        dp[0][i] = -INF;

    for (int j=1; j<=m; j++) {
        long long sum = 0;
        for (int i=n+1; i>=1; i--) {
            sum += t[i][j];
            dp[i][j] = sum + max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i + 1][j - 1]));
        }
    }

    long long result = 0;

    for (int i=0; i<=n+1; i++)
        result = max(result, dp[i][m]);

    printf("%lld\n", result);

    return 0;
}