//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    int n;
    scanf("%d", &n);
    LL wyn = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        wyn += a;
    }
    printf("%lld\n", wyn);
    return 0;
}
