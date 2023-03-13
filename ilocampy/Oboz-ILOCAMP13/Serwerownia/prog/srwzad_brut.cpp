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
#define MAXN 300000

using namespace std;

const int BASE = 1 << 20;
const int INF = 1000000000 + 7;

int n, n2, k, q, a, b, cnt, t;

int Prev[MAXN + MAXQ + 3];
int Cap[MAXN + MAXQ + 3];
PII Ope[MAXN + MAXQ + 3];

vector <int> Graph[MAXN + MAXQ + 3];

struct query
{
    int type, a, b;
    query(int _type = 0, int _a = 0, int _b = 0) : type(_type), a(_a), b(_b)
    {
    }
};

void DFS(int);
int Solve(int,int);

int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &Cap[i]);
    }
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        Graph[a].PB(b);
        Graph[b].PB(a);
    }
    DFS(1);
    for(int i = 1; i <= q; i++)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d %d", &a, &b);
            int r = Solve(b, a);
            if(r != -1) Cap[r] -= a;
            Ope[++cnt] = MP(a,r);
            printf("%d\n", r);
        }
        if(t == 2)
        {
            scanf("%d %d", &a, &b);
            n++;
            Graph[b].PB(n);
            Graph[n].PB(b);
            Prev[n] = b;
            Cap[n] = a;
            sort(ALL(Graph[b]));
        }
        if(t == 3)
        {
            scanf("%d", &a);
            Cap[Ope[a].ND] += Ope[a].ST;
            Ope[a].ST = 0;
        }
    }
}

void DFS(int v)
{
    sort(ALL(Graph[v]));
    for(int i = 0; i < SZ(Graph[v]); i++)
    {
        int u = Graph[v][i];
        if(u != Prev[v])
        {
            Prev[u] = v;
            DFS(u);
        }
    }
}

int Solve(int v, int val)
{
    int res = (Cap[v] >= val) ? v : -1;
    for(int i = 0; i < SZ(Graph[v]); i++)
    {
        if(res != -1) break;
        int u = Graph[v][i];
        if(u != Prev[v])
        {
            res = Solve(u, val);
        }
    }
    return res;
}