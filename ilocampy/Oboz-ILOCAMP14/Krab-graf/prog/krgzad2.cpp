#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>

#define PB push_back
#define SZ(x) (int)(x).size()
using namespace std;

int n, a, b;

bool T[1000005];
int Mn[1000005];
int Mx[1000005];

vector <int> Mid;
vector <int> Graph[1000005];

queue <int> Q;
bool Check();

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
    Mn[i] = n;
    if(SZ(Graph[i]) == 3)
    {
      Mid.PB(i);
    }
    else if(SZ(Graph[i]) == 1)
    {
      Mn[i] = 0;
      T[i] = true;
      Q.push(i);
    }
  }
  if(SZ(Mid) > 2) puts("NIE");
  else if(SZ(Mid) == 0) puts("TAK");
  else puts( Check() ? "TAK" : "NIE" );
}

bool Check()
{
  while(!Q.empty())
  {
    int v = Q.front();
    Q.pop();
    for(int i = 0; i < SZ(Graph[v]); i++)
    {
      int u = Graph[v][i];
      if(!T[u])
      {
        T[u] = true;
        Q.push(u);
      }
      Mn[u] = min(Mn[u], Mn[v] + 1);
      Mx[u] = max(Mx[u], Mn[v] + 1);
    }
  }
  return Mn[Mid[0]] == Mx[Mid[0]] && Mn[Mid[1]] == Mx[Mid[1]];
}