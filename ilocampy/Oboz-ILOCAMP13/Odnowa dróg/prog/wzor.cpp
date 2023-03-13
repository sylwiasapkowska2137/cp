//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const int N = 103, INF = 1000000009;

int n,m;
char ORG[N][N];
int tab[N][N];

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            tab[i][j] = INF;
    for(int i = 1;i <= n;i++)
        tab[i][i] = 0;

    for(int i = 1;i <= m;i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        ORG[a][b] = ORG[b][a] = 1;
        tab[a][b] = tab[b][a] = 1;
    }

    // Floyd-Warshall
    for(int k = 1;k <= n;k++)
        for(int u = 1;u <= n;u++)
            for(int v = 1;v <= n;v++)
                tab[u][v] = min(tab[u][v], tab[u][k]+tab[k][v]);

    pair<int,int> wynp = MP(INF, 0);
    for(int i = 1;i <= n;i++)
    {
        int twyn = 0;
        for(int l = 1;l <= n;l++) twyn = max(twyn, tab[i][l]);
        if(twyn < wynp.FI) wynp = MP(twyn, i);
    }

    pair<int,pair<int,int> > wynn = MP(INF, MP(0,0));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(ORG[i][j])
            {
                int twyn = 0;
                for(int l = 1;l <= n;l++) twyn = max(twyn, min(tab[i][l], tab[j][l]));
                if(twyn < wynn.FI) wynn = MP(twyn, MP(i,j));
            }

    if(2*wynp.FI <= 2*wynn.FI+1)
    {
        printf("%d\n", 2*wynp.FI);
        int v = wynp.SE;
        for(int i = 1;i <= n;i++)
            if(i != v)
            {
                int x = 0;
                for(int j = 1;j <= n;j++)
                    if(ORG[i][j] && tab[v][j]+1 == tab[v][i])
                    {
                        x = j;
                        break;
                    }
                printf("%d %d\n", i, x);
            }
    }
    else
    {
        printf("%d\n", 2*wynn.FI+1);
        int u = wynn.SE.FI, v = wynn.SE.SE;
        printf("%d %d\n", u, v);
        for(int i = 1;i <= n;i++)
            if(i != u && i != v)
            {
                int x = 0;
                for(int j = 1;j <= n;j++)
                    if(ORG[i][j] && min(tab[u][j], tab[v][j])+1 == min(tab[u][i], tab[v][i]))
                    {
                        x = j;
                        break;
                    }
                printf("%d %d\n", i, x);
            }
    }

    return 0;
}
