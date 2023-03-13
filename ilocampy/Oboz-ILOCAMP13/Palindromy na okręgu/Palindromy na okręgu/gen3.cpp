//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#define R(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
const int N = 1573;

int n;

int main(int argv, char *argc[])
{
    srand(time(0)*atoi(argc[1]));
    n = N;

    printf("%d\n", n);

    for(int i = 1;i <= n;i++)
    {
        int tmp = R(1,3);
        if(tmp == 1)
            printf("a");
        else if(tmp == 2)
            printf("z");
        else
            printf("%c", R('a', 'z'));
    }
    printf("\n");

    return 0;
}