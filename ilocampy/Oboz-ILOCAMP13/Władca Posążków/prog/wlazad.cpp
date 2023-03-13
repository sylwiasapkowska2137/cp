//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const int N = 1000006;
typedef long long LL;

int n,k,d;
LL g;
int S[N];
LL A[N];
pair<int, LL> row[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &S[i]);
    }

    d = __gcd(n, k);

    for (int i = 1; i <= d; i++) {
        row[i] = MP(i, 0);
        for (int j = (i + k - 1)%n + 1; j != i; j = (j + k - 1) % n + 1) {
            int poprzednia = (j - k - 1 + n) % n + 1;
            row[j].FI = row[poprzednia].FI;
            row[j].SE = row[poprzednia].SE + (S[(poprzednia + 1 - 1) % n + 1] - S[poprzednia]);
        }
    }

    g = 0;
    for (int i = 1; i <= k; i++) {
        g += row[i].SE;
    }

    A[1] = (S[1] - g) / (k/d);

    for (int i = d + 1; i <= n; i++) {
        A[i] = A[row[i].FI] + row[i].SE;
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld", A[i]);
        if (i != n) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}