//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    int n,m;
    int wyn = 1;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        int a;
        scanf("%d", &a);
        wyn = (LL)wyn*(a+1)%m;
    }
    wyn = (m+wyn-1)%m;
    printf("%d\n", wyn);
    return 0;
}
