#include <bits/stdc++.h>

using namespace std;

const int MIN_T = 1, MAX_T = 500000;
const int MIN_N = 3, MAX_N = 1000 * 1000 * 1000;

bool tooClose(int rp, int cp, int rj, int cj) {
    return abs(rp - rj) + abs(cp - cj) < 2;
}

int main() {
    int t;
    scanf("%d", &t);
    assert(MIN_T <= t && t <= MAX_T);
    while (t--) {
        int n, m, rp, cp, rj, cj;
        scanf("%d %d %d %d %d %d", &n, &m, &rp, &cp, &rj, &cj);
        assert(MIN_N <= min(n, m) && max(n, m) <= MAX_N);
        assert(1 <= min(rp, rj) && max(rp, rj) <= n);
        assert(1 <= min(cp, cj) && max(cp, cj) <= m);
        assert(!tooClose(rp, cp, rj, cj));
    }
}
