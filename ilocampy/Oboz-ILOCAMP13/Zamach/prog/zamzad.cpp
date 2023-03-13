//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1003, MOD = 1000000007;

int odwmod[N];

int pot(int a, int k, int mod)
{
    int wyn = 1;
    while(k) {
        if (k%2) {
            wyn = (LL)wyn * a % mod;
        }
        k /= 2;
        a = (LL)a * a % mod;
    }
    return wyn;
}

int prostakat(int n, int m, int k)
{
    if (n < k || m < k) {
        return 0;
    }
    int wyn = 1;
    for (int i = n - k + 1; i <= n; i++) {
        wyn = (LL)wyn * i % MOD;
    }
    for (int i = m - k + 1; i <= m; i++) {
        wyn = (LL)wyn * i % MOD;
    }
    for(int i = 1; i <= k; i++) {
        wyn = (LL)wyn * odwmod[i] % MOD;
    }
    return wyn;
}

vector<int> scal(const vector<int> &A, const vector<int> &B)
{
    vector<int> C(A.size() + B.size() - 1);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] = (C[i + j] + (LL)A[i] * B[j]) % MOD;
        }
    }
    return C;
}

vector<int> removeRows(const vector<int> &A, int count)
{
    vector<int> W = A;
    for (int r = 1; r <= count; r++) {
        for (int i = 1; i < W.size(); i++) {
            W[i] = (W[i] - (LL)W[i - 1] * ((W.size() - 1) - (i - 1))) % MOD;
            if (W[i] < 0) {
                W[i] += MOD;
            }
        }
    }
    return W;
}

vector<int> insertRows(const vector<int> &A, int count)
{
//     cerr << "Insert Rows: ";
//     for (int i = 0; i < A.size(); i++) {
//         cerr << A[i] << " ";
//     }
//     cerr << endl;

    vector<int> W;
    if (count < A.size()) {
        W = A;
        for (int r = 1; r <= count; r++) {
            for (int i = W.size() - 1; i >= 1; i--) {
                W[i] = (W[i] + (LL)W[i - 1] * ((W.size() - 1) - (i - 1))) % MOD;
            }
        }
    } else {
        W.resize(A.size());
        for (int i = 0; i < A.size(); i++) {
            int maxK = min((int)A.size() - 1 - i, count);
//             for (int j = 0; j <= maxK; j++) {
//                 W[i + j] = (W[i + j] + (LL)A[i] * prostakat(count, A.size() - 1 - i, j)) % MOD;
//             }

            int Pn = A.size() - 1 - i;
            int Pm = count;
            int Pk = 0;
            int currentProstakat = 1;
            for (; Pk <= maxK; Pk++) {
                if (Pk >= 1) {
                    currentProstakat = (LL)currentProstakat * (Pn - Pk + 1) % MOD;
                    currentProstakat = (LL)currentProstakat * (Pm - Pk + 1) % MOD;
                    currentProstakat = (LL)currentProstakat * odwmod[Pk] % MOD;
                }
                W[i + Pk] = (W[i + Pk] + (LL)A[i] * currentProstakat) % MOD;
            }
        }
    }

//     cerr << "Insert Rows Koniec: ";
//     for (int i = 0; i < W.size(); i++) {
//         cerr << W[i] << " ";
//     }
//     cerr << endl;
    return W;
}

// vector<int> merge(const vector<int> &L, const vector<int> &P, int w)
// {
//     if (L.size() > P.size()) {
//         return merge(P, L, w);
//     }
//     // Zachodzi L.size() <= P.size().
//     if (L.size() * L.size() > P.size()) {
//         vector<int> scalone = scal(L, P);
//         scalone.push_back(0);  // Dodanie kolumny zerowej.
//         return insertRows(scalone, w);
//     } else {
//
//     }
// }

vector<int> oblD(int n, int *A);
vector<int> obl(int n, int *A)
{
//     vector<int> tmp(A, A + n);
//     cerr << "START OBL: " << n << " :: ";
//     for (int i = 0; i < n; i++) {
//         cerr << tmp[i] << " ";
//     }
//     cerr << endl;
    vector<int> wyn = oblD(n, A);
//     cerr << "KONIEC OBL: " << n << " :: ";
//     for (int i = 0; i < n; i++) {
//         cerr << tmp[i] << " ";
//     }
//     cerr << " :: ";
//     for (int i = 0; i < wyn.size(); i++) {
//         cerr << wyn[i] << " ";
//     }
//     cerr << endl;
    return wyn;
}

vector<int> oblD(int n, int *A)
{
    if (n == 0) {
        vector<int> W(1);
        W[0] = 1;
        return W;
    }

    int minpoz = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[minpoz]) {
            minpoz = i;
        }
    }
    int minw = A[minpoz];
//     cerr << "Minpoz: " << minpoz << " minw: " << minw << endl;

    int X = minpoz;
    int Y = n - minpoz -1;

    if (X > Y) {
//         cerr << "ODWROC" << endl;
        swap(X, Y);
        reverse(A, A + n);
        minpoz = n - 1 - minpoz;
    }

    if ((LL)X * X * Y > (LL)Y * min(Y, minw)) {
//         cerr << "PIERWSZY" << endl;
        for (int i = 0; i < n; i++) {
            A[i] -= minw;
        }
        vector<int> wynL = obl(X, A);
        vector<int> wynP = obl(Y, A + minpoz + 1);
        vector<int> scalone = scal(wynL, wynP);
        scalone.push_back(0);  // Dodanie kolumny zerowej.
        return insertRows(scalone, minw);
    } else {
        for (int i = 0; i < X; i++) {
            A[i] -= minw;
        }
        vector<int> wynL = obl(X, A);
        vector<int> wynP = obl(Y, A + minpoz + 1);

//         cerr << "A w drugim" << endl;
//         for (int i = 0; i <= X; i++) {
//             int sposoby1 = wynL[i];
//             for (int j = 0; j <= X - i; j++) {
//                 int sposoby2 = prostakat(X - i, minw, j);
//                 for (int l = 0; l <= Y; l++) {
//                     int sposoby3;
//
//                 }
//             }
//         }
        vector<int> wynOST(X + Y + 1 + 1);
        for (int j = 0; j <= X + 1; j++) {
            if (j > 0) {
                wynP = removeRows(wynP, 1);
            }
            for (int i = 0; i <= min(X, X + 1 - j); i++) {
//                 cerr << "J: " << j << " I: " << i << endl;
                int sposoby1 = wynL[i];
                int sposoby2 = prostakat(X + 1 - i, minw, j);  // TODO Można przyśpieszyć.
//                 cerr << "X: " << X << " Minw: " << minw << endl;
                for (int l = 0; l <= Y; l++) {
//                     cerr << "L: " << l << endl;
                    int sposoby3 = wynP[l];
//                     cerr << "S1: " << sposoby1 << " S2: " << sposoby2 << " S3: " << sposoby3 << endl;
                    wynOST[j + i + l] = (wynOST[j + i + l] + (LL)sposoby1 * sposoby2 % MOD * sposoby3) % MOD;
                }
            }
        }

//         cerr << "B w drugim" << endl;
        return wynOST;
    }
}

int main()
{
    int n,k;
    scanf("%d%d", &n, &k);

    int silnia = 1;
    for (int i = 1; i <= n; i++) {
        silnia = (LL)silnia * i % MOD;
    }
    odwmod[n] = pot(silnia, MOD - 2, MOD);
    for (int i = n - 1; i >= 1; i--) {
        odwmod[i] = (LL)odwmod[i + 1] * (i + 1) % MOD;
    }
    silnia = 1;
    for (int i = 1; i <= n; i++) {
        odwmod[i] = (LL)odwmod[i] * silnia % MOD;
        silnia = (LL)silnia * i % MOD;
    }

    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    vector<int> wyn = obl(n, (&A[1]));
    printf("%d\n", wyn[k]);
    return 0;
}
