//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#define R(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
const int N = 1999;

int n;

int main(int argv, char *argc[])
{
    srand(time(0)*atoi(argc[1]));
    n = N;

    printf("%d\n", n);

    for(int i = 1;i <= n;i++)
        printf("%c", R('a', 'z'));
    printf("\n");

    return 0;
}