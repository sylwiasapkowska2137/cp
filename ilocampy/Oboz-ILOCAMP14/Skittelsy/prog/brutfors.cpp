#include <bits/stdc++.h>

using namespace std;

int n;
bitset<10000005> cnt;

string slowo;

int main() {

    scanf("%d", &n);

    cin >> slowo;

    for (int i = 0; i < n; i++) {
        slowo[i] -= 48;
    }

    for (int k = 1; k <= n; k++) {
        int mask = 0;
        for (int i = 0; i < k; i++) {
            mask = 2 * mask + slowo[i];
        }
        cnt[mask] = 1;
        for (int i = k; i < n; i++) {
            mask = 2 * mask + slowo[i];
            mask %= (1 << k);
            cnt[mask] = 1;
        }
        for (int i = 0; i < (1 << k); i++) {
            if (cnt[i] == 0) {
                printf("%d\n", k);
                return 0;
            }
            cnt[i] = 0;
        }
    }

    return 0;
}