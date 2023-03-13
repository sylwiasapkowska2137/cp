/* Program oceniajacy do zadania Konewka
 *
 * Czyta ze standardowego wejscia kolejno (wierszami):
 * 1) dwie liczby calkowite N, K,
 * 2) N liczb calkowitych oznaczajacych poczatkowe wysokosci drzew,
 * 3) liczbe naturalna q.
 *
 * Nastepnie czyta q wierszy, w ktorych znajduja sie instrukcje postaci:
 *
 * "p a b" (reprezentujaca wykonanie funkcji "podlej(a,b)")
 * "d a b" (reprezentujaca wykonanie funkcji "dojrzale(a,b)")
 *
 * Program wywoluje odpowiednie funkcje ocenianej biblioteki i wypisuje
 * wyniki funkcji "dojrzale" na standardowe wyjscie */

#include <bits/stdc++.h>
#include "koninc.h"
using namespace std;

const int MAXN = 300000;

int main()
{
    int D[MAXN];
    int num_calls, i;
    int n, k;
    cin >> n >> k;
    for (i = 0; i < n; ++i)
        cin >> D[i];

    inicjuj(n,k, D);

    cin >> num_calls;
    for (i = 1; i <= num_calls; i++)
    {
        char call;
        int a, b;
        cin >> call >> a >> b;
        if (call == 'p')
            podlej(a, b);
        else
            cout << dojrzale(a, b) << "\n";
    }
    return 0;
}
