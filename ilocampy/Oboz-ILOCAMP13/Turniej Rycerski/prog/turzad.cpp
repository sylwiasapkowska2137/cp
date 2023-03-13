//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000006;

int n;
int tab[N][4];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &tab[i][1], &tab[i][2], &tab[i][3]);
    }

    int kandydat = 1;
    for (int i = 2; i <= n; i++) {
        int tury = 0;
        for (int j = 1; j <= 3; j++) {
            if (tab[kandydat][j] < tab[i][j]) {
                tury++;
            } else if (tab[kandydat][j] > tab[i][j]) {
                tury--;
            }
        }
        if (tury > 0) {
            kandydat = i;
        }
    }

    bool czyMistrz = true;
    for (int i = 1; i <= n; i++) {
        if (kandydat != i) {
            int tury = 0;
            for (int j = 1; j <= 3; j++) {
                if (tab[kandydat][j] < tab[i][j]) {
                    tury++;
                } else if (tab[kandydat][j] > tab[i][j]) {
                    tury--;
                }
            }
            if (tury >= 0) {
                czyMistrz = false;
                break;
            }
        }
    }

    if (czyMistrz) {
        printf("%d\n", kandydat);
    } else {
        printf("NIE\n");
    }

    return 0;
}
