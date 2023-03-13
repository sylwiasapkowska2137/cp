//Przemysław Jakub Kozłowski
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
typedef long long LL;
const int N = 102;
const LL INF = 1000000000000000018LL;

int n, nnn;
int wiox, wioy;
vector<pair<int,int> > V[2*(N+1)*(N+1)];

LL odl[2*(N+1)*(N+1)];

struct cmp
{
    bool operator()(const pair<int, LL> &A, const pair<int, LL> &B) const {return A.SE > B.SE;}
};

void dijkstra(int x)
{
    priority_queue<pair<int, LL>, vector<pair<int, LL> >, cmp> K;

    for(int i = 1;i <= 2*nnn;i++)
        odl[i] = INF;

    odl[x] = 0;
    K.push(MP(x, 0));

    while(!K.empty())
    {
        pair<int,LL> k = K.top();
        K.pop();

        if(k.SE != odl[k.FI]) continue;

        for(int j = 0;j < V[k.FI].size();j++)
            if(k.SE+V[k.FI][j].SE < odl[V[k.FI][j].FI])
            {
                odl[V[k.FI][j].FI] = k.SE+V[k.FI][j].SE;
                K.push(MP(V[k.FI][j].FI, odl[V[k.FI][j].FI]));
            }
    }
}

int main()
{
    scanf("%d", &n);
    nnn = (n+1)*(n+1);
    scanf("%d%d", &wiox, &wioy);
    for(int i = 1;i <= n+1;i++)
        for(int j = 1;j <= n;j++)
        {
            int a = (i-1)*(n+1)+j;
            int b = (i-1)*(n+1)+(j+1);
            int c;
            scanf("%d", &c);
            if(j == wiox && i <= wioy) // Nad wioską
            {
                V[a].push_back(MP(nnn+b, c));
                V[b].push_back(MP(nnn+a, c));
                V[nnn+a].push_back(MP(b, c));
                V[nnn+b].push_back(MP(a, c));
            }
            else
            {
                V[a].push_back(MP(b,c));
                V[b].push_back(MP(a,c));
                V[nnn+a].push_back(MP(nnn+b,c));
                V[nnn+b].push_back(MP(nnn+a,c));
            }
        }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n+1;j++)
        {
            int a = (i-1)*(n+1)+j;
            int b = i*(n+1)+j;
            int c;
            scanf("%d", &c);
            V[a].push_back(MP(b,c));
            V[b].push_back(MP(a,c));
            V[nnn+a].push_back(MP(nnn+b,c));
            V[nnn+b].push_back(MP(nnn+a,c));
        }

    LL wyn = INF;
    for(int i = 1;i <= wioy;i++)
    {
        int a = (i-1)*(n+1)+wiox;
        dijkstra(a);
        wyn = min(wyn, odl[nnn+a]);
    }

    printf("%lld\n", wyn);

    return 0;
}
