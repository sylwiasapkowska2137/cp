#include <cstdio>
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int pier[n];
    int tab[2][n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[0][i]);
        pier[i] = tab[0][i];
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            tab[i%2][j] = tab[(i%2)^1][pier[j]];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[(k - 1)%2][i]);
    }
    return 0;
}


