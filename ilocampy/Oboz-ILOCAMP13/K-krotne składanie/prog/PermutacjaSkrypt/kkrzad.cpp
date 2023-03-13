//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1000006, MOD = 1000000007;

void polacz(int g, const vector<int> *tab);

int n,k;
int A[N];
bool odw[N];
vector<vector<int> > cykle[N];

vector<int> VC[N];

int C[N];
int DP[N];

int wyn[N];

int main()
{
    scanf("%d%d", &n, &k);

    for(int i = 1;i <= n;i++)
    {
        int nwd = __gcd(i,k);
        VC[i/nwd].push_back(nwd);
    }

    for(int i = 1;i <= n;i++)
        scanf("%d", &A[i]);
    
    for(int i = 1;i <= n;i++)
        if(!odw[i])
        {
            vector<int> cykl;
            int p = i, d = 0;
            while(!odw[p])
            {
                odw[p] = 1;
                cykl.push_back(p);
                p = A[p];
                d++;
            }
            cykle[d].push_back(cykl);
        }

    bool nie = false;
    for(int d = 1;d <= n;d++)
    {
        int m = cykle[d].size();
        int w = VC[d].size();
        for(int i = 0;i < VC[d].size();i++) C[i+1] = VC[d][i];
        C[w+1] = n+7;
        DP[0] = 1;

        for(int i = 1;i <= m;i++) DP[i] = 0;        

        for(int i = 1;C[i] <= m;i++)
        {
            for(int j = 0; j <= m-C[i];j++)
                if(DP[j])
                    DP[j+C[i]] = C[i];
            if(DP[m]) break; // Optymalizacja
        }
        if(!DP[m])
        {
            nie = true;
            break; // Optymalizacja
        }
        
        for(int i = m;i > 0;)
        {
            polacz(DP[i], &(cykle[d][i-DP[i]]));
            i -= DP[i];
        }
    }
    
    if(nie) printf("NIE\n");
    else
    {
        for(int i = 1;i <= n;i++)
            printf("%d ", wyn[i]);
        printf("\n");
    }
   

    return 0;
}

int kolejnosc[N];

void polacz(int g, const vector<int> *tab)
{
    int d = tab[0].size();
    for(int i = 0;i < d;i++)
        for(int j = 0;j < g;j++)
            kolejnosc[(LL)(i*k+j)%(d*g)] = tab[j][i];
    for(int i = 0;i < d*g-1;i++)
        wyn[kolejnosc[i]] = kolejnosc[i+1];
    wyn[kolejnosc[d*g-1]] = kolejnosc[0];
}

