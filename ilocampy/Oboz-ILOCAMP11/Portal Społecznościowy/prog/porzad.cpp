//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const int N = 1003, F = 1000006;

int n,m;
char A[N][N];
char B[N][N];
int  Z[N][N];
int  P[N][N];

inline int merge(int a, int b) {return (B[a][b] ? a : b);}
inline bool check(int kan, int a, int b) {return a > Z[kan][b];}

pair<int,int> prz[F];

int main()
{
    scanf("%d", &n);

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
        {
            scanf(" %c", &A[i][j]);
            A[i][j] -= '0';
        }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            B[i][j] = ((A[j][i]&&(!A[i][j])) || i == j);

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            Z[i][j] = (B[i][j] ? Z[i][j-1] : j);

    for(int i = 1;i <= n;i++)
    {
        P[i][i] = i;
        for(int j = i+1;j <= n;j++)
            P[i][j] = merge(P[i][j-1], j);
    }

    scanf("%d", &m);
    for(int zap = 1;zap <= m;zap++)
    {
        int l;
        scanf("%d", &l);

        for(int i = 1;i <= l;i++)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            prz[i] = MP(a,b);
        }

        int kandydat = P[prz[1].FI][prz[1].SE];
        for(int i = 2;i <= l;i++)
            kandydat = merge(kandydat, P[prz[i].FI][prz[i].SE]);

        bool exists = true;
        for(int i = 1;i <= l;i++)
            if(!check(kandydat, prz[i].FI, prz[i].SE))
            {
                exists = false;
                break;
            }

        printf("%d\n", (exists ? kandydat : -1));
    }

    return 0;
}
