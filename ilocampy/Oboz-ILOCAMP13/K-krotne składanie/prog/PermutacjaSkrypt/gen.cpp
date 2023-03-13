//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sys/time.h>
using namespace std;

int R(int a, int b) {return a+rand()%(b-a+1);}

int main()
{
    timeval czas;
    gettimeofday(&czas, 0);
    srand(czas.tv_sec*1000+czas.tv_usec%1000);

    int n = R(1, 100000);
    int k = R(1, n);
    printf("%d %d\n", n, k);
    
    vector<int> tab(n+1);
    
    for(int i = 1;i <= n;i++)  tab[i] = i;
    random_shuffle(tab.begin()+1, tab.begin()+n+1);
    
    for(int i = 1;i <= n;i++)
        printf("%d ", tab[i]);
    printf("\n");

    return 0;
}

