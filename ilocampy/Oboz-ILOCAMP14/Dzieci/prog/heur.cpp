#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, x;
    scanf("%d %d", &n, &m);

    int best = 1;
    int val = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x / m >= val) {
            best = i;
            val = x / m;
        }
    }

    printf("%d\n", best);

    return 0;
}