//Rozwiązanie brutalne, O(z * n)
#include <bits/stdc++.h>

using namespace std;

const int N = 10000005;

int t, n, k;
bool removed[N];

int main() {

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        if (k == 1) {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            removed[i] = false;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (removed[i] == false) {
                ans++;
                if ((long long)i * k <= n) {
                    removed[i * k] = true;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}