#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, k;
int tab[N];

int main() {

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    sort(tab + 1, tab + 1 + n);

    int ans = 0;
    int low = 1;
    int val = -1;
    long long cost = 0;
    for (int i = 1; i <= n; i++) {
        cost += (long long)(tab[i] - tab[i - 1]) * (i - low);
        while (cost > k) {
            cost -= tab[i] - tab[low];
            low++;
        }
        if (i - low + 1 > ans || (i - low + 1 == ans && val > tab[i])) {
            ans = i - low + 1;
            val = tab[i];
        }
    }

    printf("%d %d\n", ans, val);

    return 0;
}