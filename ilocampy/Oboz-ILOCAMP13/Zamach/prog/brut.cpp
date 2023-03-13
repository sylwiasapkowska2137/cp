//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1003, MOD = 1000000007;

int obl(int n, int *A, int k)
{
    if (k > n) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    if (n == 1) {
        return A[0];
    }

    int wyn = obl(n - 1, A + 1, k);
    for (int i = 1; i <= A[0]; i++) {
        int ile = 0;
        for (int j = 1; j < n; j++) {
            if (A[j] < i) {
                break;
            }
            A[j]--;
            ile++;
        }

        wyn = (wyn + obl(n - 1, A + 1, k - 1)) % MOD;
//         cerr << "I: " << i << " " << wyn << endl;

        for (int j = 1; j <= ile; j++) {
            A[j]++;
        }
    }

//     cerr << "KOBL -- N: " << n << " K: " << k << " WYN: " << wyn << endl;
//     cerr << "A: ";
//     for (int i = 0; i < n; i++) {
//         cerr << A[i] << " ";
//     }
//     cerr << endl;
    return wyn;
}

int main()
{
    int n,k;
    scanf("%d%d", &n, &k);
    int A[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("%d\n", obl(n, A, k));

    return 0;
}
