#include <bits/stdc++.h>

using namespace std;

int R(int a, int b) { return rand() % (b - a + 1) + a; }

int main(int argc, char *argv[]) {
    srand(time(0) * atoi(argv[1]));

    int n = R(1, 1000);
    int k = R(1, n);
    printf("%d %d\n", n, k);
    int ones = R(0, n);
    for (int i = 1; i <= ones; i++) {
        printf("1");
    }
    for (int i = ones + 1; i <= n; i++) {
        printf("0");
    }

    return 0;
}