#include "ckuclib.h"

int main()
{
    int n = dajn();
    int e = daje();
    int odp = 0;
    while (n > 1) {
        odp += polowa(n);
        n /= 2;
    }
    odp += jedno(n);
    odpowiedz(odp);
}