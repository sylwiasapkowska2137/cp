// O(n) dp solution
#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000, N = 1000005;

int n;
int A[N], B[N];
int dp[N], dp_swap[N];

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp_swap[i] = INF;
    }
    dp[1] = 0;
    dp_swap[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            dp[i] = min(dp[i], dp[i - 1]);
            dp_swap[i] = min(dp_swap[i], dp_swap[i - 1] + 1);
        }
        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            dp[i] = min(dp[i], dp_swap[i - 1]);
            dp_swap[i] = min(dp_swap[i], dp[i - 1] + 1);
        }
    }

    int answer = min(dp[n], dp_swap[n]);

    if (answer >= INF) {
        printf("NIE\n");
    } else {
        printf("%d", answer);
    }

    return 0;
}
