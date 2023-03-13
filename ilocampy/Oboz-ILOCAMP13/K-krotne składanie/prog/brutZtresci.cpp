#include <cstdio>
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int permutacja[n];
    int tab[k][n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &permutacja[i]);
        tab[0][i] = permutacja[i];
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            tab[i][j] = tab[i - 1][permutacja[j]];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[k - 1][i]);
    }
    return 0;
}


