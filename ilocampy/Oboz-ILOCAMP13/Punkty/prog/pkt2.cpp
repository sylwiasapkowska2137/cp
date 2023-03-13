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
#define VL vector<LL>
#define LL long long
#define MP make_pair
#define LD long double
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
LD best = 0;
VPII B;
LD odl(PII a, PII b)
  {
  return (LD)sqrt((LD)(a.f - b.f) * (a.f - b.f) + (LD)(a.s - b.s) * (a.s - b.s));  
  }
void result(VPII V)
  {
  LD x = 0;
  FOR(i, 0, (int)V.size()-2)
    {
    x+=odl(V[i], V[i+1]);
    }
  if(x > best)
    {
    best = x;
    B = V;
    }
  }
int main()
{
int n, m;
cin>>n>>m;
set<PII> S;

for(auto it:{0,n-1})
  for(auto jt:{0,m-1})
    FOR(i, max(0, it), min(n, it+1))
      FOR(j, max(0, jt), min(m, jt+1))
        {
        S.insert(MP(i, j));
        }


VPII V;
for(auto it:S)V.PB(it);

for(int i = 0; i < (1<<V.size()); i++)
  {
  VPII X;
  if(__builtin_popcount(i) == 4)
    {
    REP(j, (int)V.size())
      {
      if(i & (1<<j))
        {
        X.PB(V[j]);
        }
      }
    }
  else continue;
  sort(ALL(X));
  do
    {
    result(X);
    }
  while(next_permutation(ALL(X)));
  }
cerr<<best<<endl;
for(auto it:B)
  {
  cout<<it.f<<" "<<it.s<<endl;
  }
}
