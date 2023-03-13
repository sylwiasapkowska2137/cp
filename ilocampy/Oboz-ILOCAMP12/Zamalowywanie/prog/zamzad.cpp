//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 303;

int n,m;
int A[N][N];

LL t1_[N][N];LL (*t1)[N] = t1_;
LL t2_[N][N];LL (*t2)[N] = t2_;
LL wyn;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d", &A[i][j]);

    for(int p = n;p >= 1;p--)
    {
        for(int i = 1;i <= m;i++)
        {
            LL ten_poziom = 0;
            for(int j = i;j <= m;j++)
            {
                if(A[p][j] > 0)
                    ten_poziom += A[p][j];
                wyn = max(wyn, t1[i][j]+ten_poziom);
            }
        }

        for(int i = 1;i <= m;i++)
        {
            LL ten_poziom = 0;
            for(int j = i;j <= m;j++)
            {
                ten_poziom += A[p][j];
                t2[i][j] = ten_poziom+t1[i][j];
            }
        }

        for(int dlg = m;dlg >= 1;dlg--)
            for(int i = 1;i <= m-dlg+1;i++)
            {
                int a = i, b = i+dlg-1;
                if(a > 1)
                    t2[a][b] = max(t2[a][b], t2[a-1][b]);
                if(b < m)
                    t2[a][b] = max(t2[a][b], t2[a][b+1]);
            }

        swap(t1, t2);
    }

    printf("%lld\n", wyn);

    return 0;
}
