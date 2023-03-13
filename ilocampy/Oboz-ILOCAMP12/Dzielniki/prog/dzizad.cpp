//Przemysław Jakub Kozłowski
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
typedef long double LD;
const int N = 100005, logN = 30, W = 1300000;
const int MOD = 1000000007;
const LL LINF = 1000000000000000018;

char ERA[W];
vector<int> P;

void eratostenes(int n)
{
    for(int i = 2;i*i <= n;i++)
        if(!ERA[i])
            for(int j = i*i;j <= n;j += i)
                ERA[j] = 1;
    for(int i = 2;i <= n;i++)
        if(!ERA[i])
            P.push_back(i);
}

inline int pot(int a, int k, int mod)
{
    int ret = 1;
    while(k)
    {
        if(k%2) ret = (LL)ret*a%mod;
        a = (LL)a*a%mod;
        k /= 2;
    }
    return ret;
}

inline bool porownaj(LD a, LD b, LD c, LD d) // a^b < c^d
{
    return b*log(a) < d*log(c);
}

int x,y;
LL xdo[N]; // xdo[i] to x^i
int wyk[N]; // wyk[i] reprezentuje P[i]^(x^wyk[i] - 1), czyli x^wyk[i]-1 to wykladnik liczby P[i]
int wdp[logN]; // wdp[i] - pierwsze k takie, że wyk[k] <= i

int main()
{
    eratostenes(W);

    scanf("%d%d", &x, &y);

    xdo[0] = 1;
    for(int i = 1;LINF/x > xdo[i-1];i++)
        xdo[i] = xdo[i-1]*x;

    for(int i = 1;i <= y;i++)
    {
        int r = wdp[0], ri = 0;
        for(int j = 1;wdp[j-1] != 0;j++)
        {
            int q = wdp[j];
            if(q != r && porownaj(P[q], (xdo[wyk[q]+1]-1)-(xdo[wyk[q]]-1), P[r], (xdo[wyk[r]+1]-1)-(xdo[wyk[r]]-1)))
            {
                r = q;
                ri = j;
            }
        }

        wyk[r]++;
        wdp[ri]++;
    }

    int wyn = 1;
    for(int i = 0;i < y;i++)
        wyn = (LL)wyn*pot(P[i], xdo[wyk[i]]-1, MOD)%MOD;

    printf("%d\n", wyn);

    return 0;
}
