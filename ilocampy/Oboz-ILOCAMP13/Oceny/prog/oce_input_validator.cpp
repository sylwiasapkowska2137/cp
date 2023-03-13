#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 1, MAX_N = 500000, MAX_VALUE = 1e9, MIN_VALUE = -MAX_VALUE;

int main() {
    int n;
    scanf("%d", &n);
    assert(MIN_N <= n && n <= MAX_N);
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        scanf("%d" ,&x);
        assert(MIN_VALUE <= x && x <= MAX_VALUE);
    }
    return 0;
}