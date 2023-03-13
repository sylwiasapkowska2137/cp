#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
#define PB push_back
#define PII pair<int,int>
#define MP make_pair
#define ST first
#define ND second
#define MAXQ 500000
#define MAXN 1000000 + 7

using namespace std;

typedef long long LL;

const LL INF = 100000000000000000LL;

int n, t, h;

LL res, c, k;

LL L[MAXN];
LL P[MAXN];

vector <PII> V;

int main()
{
    scanf("%d %d %lld", &n, &k, &c);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &t, &h);
        h -= h % c;
        V.PB(MP(t,h));
    }
    V.PB(MP(0, INF - INF % c));
    sort(ALL(V));
    if(V.back().ST != k)
    {
        V.PB(MP(k, INF - INF % c));
    }
    L[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        L[i] = max(L[i - 1], (LL)V[i].ST - (V[i].ND / c));
    }
    P[n + 1] = INF;
//    P[n] = V[n - 1].ST - (V[n - 1].ND / c);
    for(int i = n; i >= 1; i--)
    {
        P[i] = min(P[i + 1], V[i].ST + (LL)(V[i].ND / c));
    }

    for(int i = 1; i <= n - 1; i++)
    {
        LL len = P[i + 1] - L[i];
        res = max(res, (len / 2) * c);
    }
    for(int i = 0; i < SZ(V); i++)
    {
        if(V[i].ND == 0 && i % 2 == 0)
        {
            res = -1;
        }
    }
    if(res == -1)
    {
        puts("NIE");
        return 0;
    }
    printf("%lld\n", res);
}