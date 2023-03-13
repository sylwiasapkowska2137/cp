//Przemysław Jakub Kozłowski
// Złożoność: O(q*n)
// 12 ILOCAMP
// 2016-01-21
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1000006;
const LL LINF = 1000000000000000018LL;

int n;
int A[N];
int SUML[N], SUMR[N];
LL KOSL[N], KOSR[N];

void preprocesing()
{
    /*for(int i = 1;i <= n;i++)
        cerr << A[i] << " ";
    cerr << endl;*/
    for(int i = 1;i <= n;i++)
    {
        SUML[i] = SUML[i-1]+A[i];
        KOSL[i] = KOSL[i-1]+SUML[i-1];
    }
    for(int i = n;i >= 1;i--)
    {
        SUMR[i] = SUMR[i+1]+A[i];
        KOSR[i] = KOSR[i+1]+SUMR[i+1];
    }
}

inline LL zciagnij(int i, int m, int j)
{
    return KOSL[m]-KOSL[i-1]-(LL)SUML[i-1]*(m-i+1)+
           KOSR[m]-KOSR[j+1]-(LL)SUMR[j+1]*(j-m+1);
}

inline LL oblicz(int woz)
{
    LL wyn = LINF;

    int d = 0;
    for(int m = 1;m <= n;m++)
    {
        while(d >= 0 && SUML[min(n, m+d)]-SUML[max(0, m-d-1)] >= woz) d--;
        while(d <= n && SUML[min(n, m+d)]-SUML[max(0, m-d-1)] < woz) d++;
        if(d > n) break;
        int l = max(1, m-d), p = min(n, m+d);

        LL za_duzo = SUML[p]-SUML[l-1]-woz;
        LL twyn = zciagnij(l, m, p)-za_duzo*d;
        wyn = min(wyn, twyn);
    }

    if(wyn == LINF) wyn = -1;
    return wyn;
}

int main()
{
    int m, rw;
    scanf("%d%d", &m, &rw);
    int last = 0;
    for(int i = 1;i <= m;i++)
    {
        int odl, dlug;
        scanf("%d%d", &odl, &dlug);
        assert(last <= odl);
        A[i] = odl-last;
        last = odl+dlug;
    }
    A[m+1] = rw-last;
    n = m+1;

    preprocesing();

    int q;
    scanf("%d", &q);
    for(int i = 1;i <= q;i++)
    {
        int woz;
        scanf("%d", &woz);
        printf("%lld\n", oblicz(woz));
    }
    return 0;
}
