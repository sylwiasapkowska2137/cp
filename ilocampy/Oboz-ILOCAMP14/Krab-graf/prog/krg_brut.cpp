#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>

#define PB push_back
#define MP make_pair
#define SZ(x) (int)(x).size()

using namespace std;

int n, a, b;

bool T[500005];
int Dis[500005];
int Ile[500005];
vector <int> Mid;
vector <int> Graph[500005];
vector <pair<int,int> > V;

queue <int> Q;
bool Solve();
bool Check(int);

int main()
{
  scanf("%d", &n);
  for(int i = 1; i < n; i++)
  {
    scanf("%d %d", &a, &b);
    Graph[a].PB(b);
    Graph[b].PB(a);
    V.PB(MP(a,b));
  }
  puts( Solve() ? "TAK" : "NIE" );
}

bool Solve()
{
  int ile = 0;
  for(int i = 1; i <= n; i++)
  {
    if(SZ(Graph[i]) >= 3) ile++;
  }
  if(ile > 2)
  {
    return false;
  }
  for(int i = 0; i < SZ(V); i++)
  {
    for(int j = 1; j <= n; j++)
    {
      T[j] = false;
      Dis[j] = 0;
    }
    pair <int,int> p = V[i];
    T[p.first] = T[p.second] = true;
    if(Check(p.first) && Check(p.second)) return true;
  }
  return false;
}


bool Check(int x)
{
  int mn = n, mx = 0;
  Q.push(x);
  while(!Q.empty())
  {
    int v = Q.front();
    Q.pop();
    if(v != x && SZ(Graph[v]) > 2)
    {
      mn = -1;
    }
    if(SZ(Graph[v]) == 1)
    {
      mn = min(mn, Dis[v]);
      mx = max(mx, Dis[v]);
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
  return mx == mn;
}
