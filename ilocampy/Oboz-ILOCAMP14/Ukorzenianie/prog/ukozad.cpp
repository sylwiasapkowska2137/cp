#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define QI queue <int>
#define VI vector <int>
#define PII pair <int,int>
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define SYNC ios_base::sync_with_stdio(0)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

using namespace std;

const int INF = 1e9+7;

int n, k, res = INF, good, a, b;

bool Dir[200000]; // 1 - jak na poczarku 0 - przeciwnie
bool Vis[200000];
bool Good[200000];
int Num[200000];
int Amm[200000][2];
PII Route[200000];

vector <int> Graph[200000];

void Prepare(int);
void DFS(int);

int main()
{
  scanf("%d %d", &n, &k);
  for(int i = 1; i < n; i++)
  {
    scanf("%d %d %d", &a, &b, &Num[i]);
    Route[i] = MP(a,b);
    Graph[a].PB(i);
    Graph[b].PB(i);
  }
  Prepare(1);
  for(int i = 1; i <= n; i++)
    Vis[i] = false;
  for(int i = 1; i <= k; i++)
  {
    Good[i] = ((LL)Amm[i][0] * Amm[i][1] == 0);
    good += Good[i];
  }
  DFS(1);
  printf("%d", res);
}

void Prepare(int v)
{
  Vis[v] = true;
  for(int i = 0; i < SZ(Graph[v]); i++)
  {
    int x = Graph[v][i];
    int u = Route[x].ST == v ? Route[x].ND : Route[x].ST;
    if(!Vis[u])
    {
      Dir[x] = (Route[x].ST == v);
      Amm[Num[x]][Dir[x]]++;
      Prepare(u);
    }
  }
}

void DFS(int v)
{
  if(good == k)
    res = min(res, v);
    Vis[v] = true;
  for(int i = 0; i < SZ(Graph[v]); i++)
  {
    int x = Graph[v][i];
    int u = Route[x].ST == v ? Route[x].ND : Route[x].ST;
    if(!Vis[u])
    {
      bool d = Route[x].ST == v ? 0 : 1;
      if(d != Dir[x])
      {
        Amm[Num[x]][Dir[x]]--;
        Amm[Num[x]][d]++;
        LL w = (LL)Amm[Num[x]][0] * Amm[Num[x]][1];
        if( (Good[Num[x]] && w == 0) || (!Good[Num[x]] && w != 0))
          DFS(u);
        if(Good[Num[x]] && w != 0)
        {
          Good[Num[x]] = false;
          good--;
          DFS(u);
          Good[Num[x]] = true;
          good++;
        }
        if(!Good[Num[x]] && w == 0)
        {
          Good[Num[x]] = true;
          good++;
          DFS(u);
          Good[Num[x]] = false;
          good--;
        }
        Amm[Num[x]][Dir[x]]++;
        Amm[Num[x]][d]--;
      }
      else
        DFS(u);
    }
  }
}

