#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>

#define PB push_back
#define SZ(x) (int)(x).size()

using namespace std;

int n, a, b;

bool T[500005];
int Dis[500005];
int Ile[500005];
vector <int> Mid;
vector <int> Graph[500005];

queue <int> Q;
bool Check(int,bool);
bool IsConnected(int,int)

int main()
{
  scanf("%d", &n);
  for(int i = 1; i < n; i++)
  {
    scanf("%d %d", &a, &b);
    Graph[a].PB(b);
    Graph[b].PB(a);
  }
  for(int i = 1; i <= n; i++)
  {
    if(SZ(Graph[i]) >= 3)
    {
      Mid.PB(i);
    }
  }
  if(SZ(Mid) == 0) puts("TAK");
  else if(SZ(Mid) == 1)
  {
    T[Mid[0]] = true;
    puts( Check2(Mid[0], 0) ? "TAK" : "NIE" );
  }
  else if(SZ(Mid) == 2 && IsConnected(Mid[0], Mid[1]))
  {
    T[Mid[0]] = T[Mid[1]] = true;
    puts( Check(Mid[0], 1) && Check(Mid[1], 1) ? "TAK" : "NIE" );
   }
  else puts("NIE");
}

bool IsConnected(int a, int b)
{
  for(int i = 0; i < SZ(Graph[a]); i++)
  {
    int u = Graph[a][i];
    if(u == b) return true;
  }
  return false;
}

bool Check(int x, bool type)
{
  int mn = n, mx = 0;
  Q.push(x);
  while(!Q.empty())
  {
    int v = Q.front();
    Q.pop();
    if(SZ(Graph[v]) == 1)
    {
      mn = min(mn, Dis[v]);
      mx = max(mx, Dis[v]);
      Ile[Dis[v]]++;
    }
    for(int i = 0; i < SZ(Graph[v]); i++)
    {
      int u = Graph[v][i];
      if(!T[u])
      {
        T[u] = true;
        Dis[u] = Dis[v] + 1;
        Q.push(u);
      }
    }
  }
  if(type) return mx == mn;
  else return (Ile[mx] >= liscie - 1 || Ile[mn] >= liscie - 1);
}