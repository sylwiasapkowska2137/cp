#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int a[N], b[N], c[N];
int n;

int comp(int x, int y) {
    int wins = 0, draws = 0, loses = 0;
    if (a[x] < a[y]) loses++;
    if (a[x] == a[y]) draws++;
    if (a[x] > a[y]) wins++;
    if (b[x] < b[y]) loses++;
    if (b[x] == b[y]) draws++;
    if (b[x] > b[y]) wins++;
    if (c[x] < c[y]) loses++;
    if (c[x] == c[y]) draws++;
    if (c[x] > c[y]) wins++;
    if (wins > loses) return -1;
    if (wins < loses) return 1;
    return 0;
}

int main() {
    long long X = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }
    for (int j = 1; j <= n; j++) {
        bool good = true;
        for (int i = 1; i <= n; i++) {
            X++;
            if (i != j && comp(j, i) >= 0) {
                good = false;
                break;
            }
        }
        if (good) {
            printf("%d\n", j);
            return 0;
        }
    }

    printf("%lld\n", X);

    printf("NIE\n");

    return 0;
}