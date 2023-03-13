#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m, rp, cp, rj, cj;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d %d %d", &n, &m, &rp, &cp, &rj, &cj);
        printf((abs(cj - cp) + abs(rj - rp)) % 2 == 1 ? "TAK\n" : "NIE\n");
    }

    return 0;
}