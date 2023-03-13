//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const int N = 1000006;

int n;
pair<int,int> tab[N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &tab[i].FI, &tab[i].SE);
    }

    sort(tab + 1, tab + n + 1);

    bool wynik = true;
    int nastepnyTost = 1;
    for (int i = 1; i <= n; i++) {
        nastepnyTost += tab[i].SE;
        if (nastepnyTost > tab[i].FI) {
            wynik = false;
            break;
        }
    }

    if (wynik) {
        printf("TAK\n");
    } else {
        printf("NIE\n");
    }

    return 0;
}
