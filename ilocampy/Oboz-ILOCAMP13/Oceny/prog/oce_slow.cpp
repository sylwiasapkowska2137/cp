#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, INF = 1e9;
int dp[N], dp_swap[N];
int A[N], B[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 1; i < n; i++) {
        dp_swap[i] = INF;
    }
    dp_swap[0] = 1;
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
            dp_swap[i] = dp_swap[i - 1] + 1;
        }
        if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
            dp_swap[i] = min(dp_swap[i], dp[i - 1] + 1);
        }
        int best = INF;
        for (int j = i; j >= 0; j--) {
            if (j == 0) {
                best = 0;
                continue;
            }
            if (A[j - 1] <  B[j] && B[j - 1] < A[j]) {
                best = min(best, dp_swap[j - 1]);
            }
            if (A[j - 1] >= A[j] || B[j - 1] >= B[j]) {
                break;
            }
        }
        dp[i] = best;
    }
    int answer = min(dp[n - 1], dp_swap[n - 1]);
    if (answer >= INF) {
        printf("NIE\n");
    } else {
        printf("%d\n", answer);
    }
}