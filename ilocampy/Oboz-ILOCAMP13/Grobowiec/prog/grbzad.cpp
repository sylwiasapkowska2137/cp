#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

#define ST first
#define ND second
#define MP make_pair
#define SZ(x) (int)(x).size()
#define PII pair<int,int>
#define PB push_back
#define MAXK 32 + 3
#define MAXN 100000 + 3

using namespace std;

typedef long long LL;

const long long INF = 100000000000000000LL + 7;

int n, m, k, a, b, c;

LL res = INF;

int On[MAXN];
int Off[MAXN];
LL Dis[2][MAXN][MAXK];

vector <PII> Graph[MAXN];

struct state
{
    int taken, room, open;
    state(int a = 0, int b = 0, int c = 0) : taken(a), room(b), open(c)
    {
    }
    LL giveDis()
    {
        return Dis[taken][room][open];
    }
    void setDis(int val)
    {
        Dis[taken][room][open] = val;
    }
    void pressButton()
    {
        open |= 1 << On[room];
        open &= ((1 << k) - 1) - (1 << Off[room]);
    }
    void print()
    {
        cout << "t: " << taken << " r: " << room << " o: " << open <<  " dis: " << giveDis() << endl;
    }
};
queue <state> Q;
queue <state> Temp;

void Solve(int);

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &On[i]);
        On[i]--;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &Off[i]);
        Off[i]--;
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        c--;
        Graph[a].PB(MP(b,c));
        Graph[b].PB(MP(a,c));
    }
    Solve(1);
    for(int i = 0; i < (1 << k); i++)
    {
        cout << Dis[1][1][i] << endl;
        res = min(res, Dis[1][1][i]);
    }
    if(res == INF)
    {
        puts("NIE");
        return 0;
    }
    printf("%lld\n", res);
}

void Solve(int x)
{
    for(int i = 0; i <= 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int l = 0; l < (1 << k); l++)
            {
                Dis[i][j][l] = INF;
            }
        }
    }
    Temp.push(state(0,1,0));
    Temp.front().setDis(0);
    while(!Temp.empty())
    {
        while(!Temp.empty())
        {
            Q.push(Temp.front());
            state pressed = Temp.front();
            pressed.pressButton();
            if(pressed.giveDis() == INF)
            {
                pressed.setDis(Temp.front().giveDis());
                Q.push(pressed);
            }
            Temp.pop();
        }
        while(!Q.empty())
        {
            state v = Q.front();
            Q.pop();
            for(int i = 0; i < SZ(Graph[v.room]); i++)
            {
                PII w = Graph[v.room][i];
                if( (v.open & (1 << w.ND)) != 0)
                {
                    state u = v;
                    u.room = w.ST;
                    u.taken |= (u.room == n) ? 1 : 0; 
                    if(u.giveDis() == INF)
                    {
                        u.setDis(v.giveDis() + 1);
                        Temp.push(u);
                    }
                }
            }
        }
    }
}