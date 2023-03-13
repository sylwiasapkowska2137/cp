#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
using namespace std;
int R(int a,int b)
{
return rand()%(b-a+1)+a;
}
int a,b,c,d,e,n;
main(int argc, char *argv[])
{
srand(time(0)*atoi(argv[1]));

int n = 370;
int m = 400;
int q = 1;

VPII edge;
set<PII> edgeS;
printf("%d %d %d\n",n, m, q);

  
FOR(i, 1, m)
  {
  if(i < n)
    {
    int a = R(1, i);
    int b = i+1;
    edge.PB(MP(a, b));
    edgeS.insert(MP(a, b));
    printf("%d %d\n", a, b);
    
    
    continue;
    }
  
  while(1)
    {
    int a = R(1, n);
    int b = R(1, n);
    if(a == b)continue;
    if(edgeS.count(MP(a,b)) || edgeS.count(MP(b,a)))continue;
    edge.PB(MP(a, b));
    edgeS.insert(MP(a, b));
    printf("%d %d\n", a, b);
    break;
    }
  }
  
FOR(i, 1, q)
  {
  int r = R(0, m-1);
  printf("%d %d %d %d\n", R(1, n), R(1, n), edge[r].f, edge[r].s);
  }
}
