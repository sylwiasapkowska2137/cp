#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 5 * 100 * 1000 + 7;

int n;
int Pom[3];
int A[MAXN];
int B[MAXN];
int C[MAXN];

vector <int> Res;

bool Solve(int);

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &Pom[0], &Pom[1], &Pom[2]);
        sort(Pom, Pom + 3);
        A[i] = Pom[2];
        B[i] = Pom[1];
        C[i] = Pom[0];
    }
    for(int i = 1; i <= n; i++)
    {
        if(Solve(i))
        {
            Res.push_back(i);
        }
    }
    printf("%d\n", (int)Res.size());
    for(int i = 0; i < Res.size(); i++)
    {
        printf("%d ", Res[i]);
    }
}

bool Solve(int x)
{
    int amm = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i != x)
        {
            //WW_
            if(A[x] > B[i] && B[x] > C[i])
            {
                amm++;
            }
            //WDD
            else if( (A[x] > A[i] && B[x] == B[i] && C[x] == C[i]) || (A[x] > C[i] && B[x] == A[i] && C[x] == B[i]) )
            {
                amm++;                
            }
        }
    }
    return (amm == n - 1);
}