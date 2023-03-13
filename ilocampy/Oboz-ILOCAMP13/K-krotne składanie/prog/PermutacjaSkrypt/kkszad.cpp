//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> perm_zloz(vector<int> per, int k)
{
    int n = per.size()-1;
    vector<int> ret(n+1);
    vector<char> odw(n+1);

    for(int i = 1;i <= n;i++)
        if(!odw[i])
        {
            vector<int> cykl;
            int w = i;
            while(!odw[w])
            {
                odw[w] = 1;
                cykl.push_back(w);
                w = per[w];
            }
            int D = cykl.size();
            for(int j = 0;j < D;j++)
                ret[cykl[j]] = cykl[(j+k)%D];
        }
   return ret;
}

int n,k;

int main()
{
    scanf("%d%d", &n, &k);

    vector<int> A(n+1);
    for(int i = 1;i <= n;i++)
        scanf("%d", &A[i]);
    vector<int> wyn = perm_zloz(A, k);
    for(int i = 1;i <= n;i++)
        printf("%d ", wyn[i]);
    printf("\n");

    return 0;
}

