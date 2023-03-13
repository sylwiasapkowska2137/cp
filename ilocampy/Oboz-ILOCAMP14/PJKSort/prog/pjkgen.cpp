#include <bits/stdc++.h>

using namespace std;

int R(int a, int b) { return rand() % (b - a + 1) + a; }

int main(int argc, char *argv[]) {
    srand(time(0) * atoi(argv[1]));
    int n = R(1, 5);
    int m = R(0, 0);
    printf("%d %d\n", n, m);

    for (int i = 1; i <= n; i++) {
        printf("%d ", R(0, 1));
    }

    while (m--) {
        printf("%d\n", R(1, n));
    }

    return 0;
}