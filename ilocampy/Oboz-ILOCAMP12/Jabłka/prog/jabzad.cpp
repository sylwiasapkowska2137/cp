#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, m, a, b;
unsigned long long pref[N];

unsigned long long randomValue(unsigned long long x) {
    return (((53198751135ULL * x + 35819751ULL) * x + 1398517341341985ULL) * x + 8541674158651ULL) * x + 66659164917391333ULL;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        pref[i] = pref[i - 1] ^ randomValue(a);
    }
    while(m--) {
        scanf("%d %d", &a, &b);
        printf((pref[b] ^ pref[a - 1])? "NIE\n": "TAK\n");
    }
    return 0;
}