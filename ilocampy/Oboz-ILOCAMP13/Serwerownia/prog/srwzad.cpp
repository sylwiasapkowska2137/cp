#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
#define PB push_back
#define MAXQ 500000
#define MAXN 300000

using namespace std;

const int BASE = 1 << 20;
const int INF = 1000000000 + 7;

int n, n2, k, q, a, b, cnt, t;

int In[MAXN + MAXQ + 3];
int Out[MAXN + MAXQ + 3];
int Num[MAXN + MAXQ + 3];
int RealNum[MAXN + MAXQ + 3];
int Cap[MAXN + MAXQ + 3];
int Tree[2 * BASE + 3];

vector <int> Graph[MAXN + MAXQ + 3];

struct query
{
    int type, a, b;
    query(int _type = 0, int _a = 0, int _b = 0) : type(_type), a(_a), b(_b)
    {
    }
};
vector <query> Queries;
query* Ope[MAXQ + 3];

void Numerate(int);
void Add(int,int);
int Solve(query*);

int main()
{
    scanf("%d %d", &n, &q);
    n2 = n;
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
    for(int i = 1; i <= q; i++)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d %d", &a, &b);
        }
        if(t == 2)
        {
            scanf("%d %d", &a, &b);
            n++;
            Graph[b].PB(n);
            Graph[n].PB(b);
        }
        if(t == 3)
        {
            scanf("%d", &a);
            b = 0;
        }
        Queries.push_back(query(t,a,b));
        
    }
    Numerate(1);
    for(int i = 1; i <= n; i++)
    {
        Tree[Num[i] + BASE - 1] = Cap[i];
    }
    for(int i = BASE - 1; i > 0; i--)
    {
        Tree[i] = max(Tree[i * 2], Tree[i * 2 + 1]);
    }
    cnt = 0;
    for(int i = 0; i < q; i++)
    {
        if(Queries[i].type == 1)
        {
            Queries[i].b = Solve(&Queries[i]);
            if(Queries[i].b != -1)
            {
                Add(Num[Queries[i].b], -Queries[i].a);
            }
            printf("%d\n", Queries[i].b);
            Ope[++cnt] = &(Queries[i]);
        }
        if(Queries[i].type == 2)
        {
            Add(Num[++n2], Queries[i].a); 
        }
        if(Queries[i].type == 3)
        {
            Add(Num[Ope[Queries[i].a]->b], Ope[Queries[i].a]->a);
            Ope[Queries[i].a]->a = 0;
        }
    }
}

void Numerate(int v)
{
    sort(ALL(Graph[v]));
    Num[v] = In[v] = ++cnt;
    RealNum[cnt] = v;
    for(int i = 0; i < SZ(Graph[v]); i++)
    {
        int u = Graph[v][i];
        if(Num[u] == 0)
        {
            Numerate(u);
        }
    }
    Out[v] = cnt;
}

void Add(int x, int val)
{
    if(val == 0) return;
    x += BASE - 1;
    Tree[x] += val;
    while(x /= 2)
    {
        Tree[x] = max(Tree[x * 2], Tree[x * 2 + 1]);   
    }
}

int Solve(query* q)
{
    int x = In[q->b] + BASE - 1;
    int val = q->a;
    while(x != 0 && Tree[x] < val)
    {
        if(x % 2 && x != 1) x++;
        x /= 2;
    }
    if(x == 0) return -1;
    while(x < BASE)
    {
        x *= 2;
        x += (Tree[x] < val);
    }
    x = x - BASE + 1;
    return (In[q->b] <= x && x <= Out[q->b]) ? RealNum[x] : -1;
}