//Przemysław Jakub Kozłowski
// Heura
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

    int m = 1, j = 1;
    for(int i = 1;i <= n;i++)
    {
        while(j <= n && SUML[j]-SUML[i-1] < woz) j++;
        if(j > n) break;
        if(m < i) m = i;

        int za_duzo = SUML[j]-SUML[i-1]-woz;

        if(A[i] > za_duzo)
        {
            int wart = SUML[j]+SUML[i-1]+za_duzo;
            while(2*SUML[m] <= wart) m++;
            wyn = min(wyn, zciagnij(i, m, j)-(LL)za_duzo*(m-i));
        }

        if(A[j] > za_duzo)
        {
            int wart = SUML[j]+SUML[i-1]-za_duzo;
            while(2*SUML[m] <= wart) m++;
            wyn = min(wyn, zciagnij(i, m, j)-(LL)za_duzo*(j-m));
        }
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
