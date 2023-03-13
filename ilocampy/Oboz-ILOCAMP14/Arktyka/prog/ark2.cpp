#include <bits/stdc++.h>
using namespace std;

int n, m;
int l;

char wcz[1007];

int suma[1007][1007];

int d;

int wyn;

inline int zap(int a, int b, int d)
{
    return suma[a][b]-suma[a][b-d]-suma[a-d][b]+suma[a-d][b-d];
}

int main()
{
    scanf("%d%d%d", &n, &m, &l);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", wcz+1);
        for (int j=1; j<=m; j++)
            suma[i][j]=suma[i-1][j]+suma[i][j-1]-suma[i-1][j-1]+(wcz[j]=='#');
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            d=1;
            while(d<=i && d<=j)
            {
                int b=zap(i, j, d);
                if (b>l)
                    break;
                if (b==l)
                    wyn++;
                d++;
            }
        }
    }
    printf("%d\n", wyn);
    return 0;
}
