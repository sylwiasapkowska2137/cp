//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1000006, MOD = 1000000007;

bool next(vector<int> &V, int m)
{
    for(int i = V.size()-1;i >= 0;i--)
        if(V[i] != m)
        {
            V[i]++;
            for(int j = i+1;j < V.size();j++)
                V[j] = 1;
            return true;
        }
    return false;
}

vector<int> obl(const vector<int> &V)
{
    vector<int> ret(V.size());
    ret[0] = -1;
    for(int i = 1;i < V.size();i++)
    {
        int p = i-1;
        while(p != -1 && V[p] >= V[i]) p = ret[p];
        ret[i] = p;
    }
    for(int i = 0;i < ret.size();i++)
        ret[i] = (ret[i] == -1 ? 0 : V[ret[i]]);
    return ret;
}

int n,m;
vector<int> B;

int main()
{
    scanf("%d%d", &n, &m);
    B.resize(n);
    for(int i = 1;i <= n;i++)
        scanf("%d", &B[i-1]);

    int wyn = 0;

    vector<int> A(n, 1);
    do
    {
        vector<int> C = obl(A);
        if(C == B) wyn++;
    }
    while(next(A, m));

    printf("%d\n", wyn);

    return 0;
}
