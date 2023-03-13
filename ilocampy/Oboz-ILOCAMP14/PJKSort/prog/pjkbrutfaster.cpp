#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, m, pos;
int tab[N];

int calcAns() {
    int lastZero = 0;
    int totalOnes = 0;
    for (int i = 1; i <= n; i++) {
        if (tab[i] == 0) {
            lastZero = i;
        } else {
            totalOnes++;
        }
    }

    int ones = 0;
    int ans = 0;
    for (int i = 1; i <= lastZero; i++) {
        if (tab[i] == 1) {
            ones++;
            ans = max(ans, n - totalOnes - i + 2 * ones - 1);
        }
    }

    return ans;
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    printf("%d\n", calcAns());
    while (m--) {
        int pos;
        scanf("%d", &pos);
        tab[pos] ^= 1;
        printf("%d\n", calcAns());
    }

    return 0;
}