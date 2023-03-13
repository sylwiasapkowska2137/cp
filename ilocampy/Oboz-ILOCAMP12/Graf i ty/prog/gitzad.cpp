#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, m, a, b;
int sum[N];

int NWD(int a, int b) {
    return b? NWD(b, a % b) : a;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 2; i <= n; i++) {
        if (sum[i] == 0) {
            for (int j = i; j <= n; j += i) {
                int tmp = j;
                while (tmp % i == 0) {
                    sum[j] += i;
                    tmp /= i;
                }
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", sum[a] + sum[b] - 2 * sum[NWD(a, b)]);
    }
    
    return 0;
}