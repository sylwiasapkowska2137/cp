#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x, last = 0;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x == 1 && last == 0) {
            ans++;
        }
        if (x == 1) {
            ans++;
        }
        last = x;
    }
    
    if (ans > 0) ans--;
    printf("%d\n", ans);

    return 0;
}