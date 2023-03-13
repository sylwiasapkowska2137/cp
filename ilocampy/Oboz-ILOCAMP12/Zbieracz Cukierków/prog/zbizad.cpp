#include<bits/stdc++.h>
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
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
using namespace std;
int n,a,b,c,k;

LL inf = 1e18;
const int MXN=(5e5)+5;
bool active[MXN];
VPII V[MXN];
int findsize(int x,int pp)
  {
  if(!active[x])return 0;
  int res=1;
  for(auto it:V[x])
    {
    if(it.f == pp)continue;
    res+=findsize(it.f, x);
    }
  return res;
  }

int dfscentroid(int x,int pp,int siz)
  {
  if(!active[x])return 0;
  int mx = 0;
  int s = 1;
  for(auto it:V[x])
    {
    if(it.f == pp)continue;
    int r = dfscentroid(it.f, x, siz);
    s+=r;
    maxi(mx, r);
    }
  maxi(mx, siz-s);
  if(mx*2 <= siz)throw x;
  return s;
  }
int findcentroid(int x)
  {
  int siz = findsize(x, 0);
  try 
    {
    dfscentroid(x, 0, siz);
    }
  catch(int cen)
    {
    return cen;
    }
  puts("OOOO");
  throw "nie znaleziono centroida :O";
  }
void dfs(int x,int pp, int dis, LL cost, VL &result)
  {
  if(!active[x])return;
  while(result.size() < dis+1)
    result.PB(-inf);
  maxi(result[dis], cost);    
  for(auto it:V[x])
    {
    if(it.f == pp)continue;
    dfs(it.f, x, dis+1, cost+it.s, result);
    }
  }

LL result;
void go(int x)
  {
  if(!active[x])return;
  x = findcentroid(x);
//  cerr<<"centroid: "<<x<<endl;
  active[x] = 0;
  
  VL best;
  best.PB(0);
  for(auto it:V[x])
    {
    VL r;
    dfs(it.f, 0, 1, it.s, r);
    REP(i,r.size())
      {
      if(k-i>best.size()-1)continue;
      maxi(result, r[i] + best[k-i]);
     // cerr<<r[i]<<" ";
      }//cerr<<" a"<<endl;
    if(best.size()<r.size())swap(r,best);
    REP(i,r.size())
      {
      if(i)
        maxi(best[i], max(r[i], best[i-1])); //zmiana tej linijki i będzie długość dokłądnie k
      }
    }
  for(auto it:V[x])
    go(it.f);
  }

main()
{
scanf("%d%d",&n,&k);
FOR(i,1,n)active[i]=1;
REP(i,n-1)
  {
  scanf("%d%d%d",&a,&b,&c);
  V[a].PB(MP(b,c));
  V[b].PB(MP(a,c));
  }
go(1);
printf("%lld\n",result);
}
