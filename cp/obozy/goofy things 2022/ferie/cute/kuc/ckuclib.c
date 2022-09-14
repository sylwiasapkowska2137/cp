#include "ckuclib.h"
#include <stdio.h>

bool initialized = 0;
int n, e;
int data[3][1000 * 1000 + 1];
void initialize()
{
    scanf("%d", &n);
    scanf("%d", &e);
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &data[i][j]);
    initialized = 1;
}

int dajn()
{
    if (!initialized)
        initialize();
    return n;
}

int daje()
{
    if (!initialized)
        initialize();
    return e;
}

int jedno(int k)
{
    if (!initialized)
        initialize();
    return data[0][k];
}

int dwa(int k)
{
    if (!initialized)
        initialize();
    return data[1][k];
}

int polowa(int k)
{
    if (!initialized)
        initialize();
    return data[2][k];
}

void odpowiedz(int wynik)
{
    if (!initialized)
        initialize();
    printf("%d\n", wynik);
}
