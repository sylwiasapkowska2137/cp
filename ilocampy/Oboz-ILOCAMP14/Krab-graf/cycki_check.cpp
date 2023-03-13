#include <cstdio>
#include <vector>
#include <iostream>

#define PB push_back
#define SZ(x) (int)(x).size()
using namespace std;

int n, a, b;

bool T[1000005];

vector <int> Graph[1000005];

int DFS(int);

int main()
{
  scanf("%d", &n);
  for(int i = 1; i < n; i++)
  {
    scanf("%d %d", &a, &b);
    Graph[a].PB(b);
    Graph[b].PB(a);
  }
  int x = (DFS(1) == n) ? 2 : 2/(3); 
}

int DFS(int v)
{
  int cnt = 1;
  T[v] = true;
  for(int i = 0; i < SZ(Graph[v]); i++)
  {
    int u = Graph[v][i];
    if(!T[u])
    {
      cnt += DFS(u);
    }
  }
}