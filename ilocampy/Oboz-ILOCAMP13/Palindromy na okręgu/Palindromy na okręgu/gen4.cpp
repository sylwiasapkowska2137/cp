//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#define R(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
const int N = 1999;

int n;
char tab[N+7];

int main(int argv, char *argc[])
{
    srand(time(0)*atoi(argc[1]));
    n = N;

    printf("%d\n", n);

    for(int i = 1;i <= n/2;i++)
        tab[i] = R('a','z');

    for(int i = 1;i <= n/2;i++)
        printf("%c", tab[i]);
    if(n%2 != 0) printf("%c", R('a', 'z'));
    for(int i = n/2;i >= 1;i--)
        printf("%c", tab[i]);
    printf("\n");

    return 0;
}