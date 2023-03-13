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
int n,a,b,c,d,k,m,q,z;
const int MXN=1e5+5;
int MAGIC=100;
PII przedzialy[MXN];
VPII dodac;
LL sumx[MXN];//sumy po tej tablicy x
LL x[MXN];
unsigned LL sumseg[MXN];
void aktualizuj()
  {
  while(dodac.size())
    {
    x[dodac.back().f]=dodac.back().s;    
    dodac.pop_back();
    }  
  FOR(i,1,n)
    {
    sumx[i]=sumx[i-1]+x[i];
    }
  FOR(i,1,n)
    {
    LL val=sumx[przedzialy[i].s]-sumx[przedzialy[i].f-1];
    sumseg[i]=sumseg[i-1]+val;
    }
  }
unsigned LL ans[MXN];
bool co[MXN];
unsigned LL odans[MXN];
struct aaa
{
int co,gdzie,ile;
} y;
 
vector<aaa> V[MXN];
void zapytanie(int poc,int kon,int co,int gdzie,int ile)//ile razy w [poc,kon] jest co i pod ans[gdzie]+=wynik*ile;
  {
  y.co=co;
  y.gdzie=gdzie;
  y.ile=-ile;
  V[poc-1].PB(y);
  y.ile*=-1;
  V[kon].PB(y);
  }
 
namespace tree
  {
  const int BASE=(1<<17);
  int t[BASE*2];
  void insert(int a,int co)
    {
    a+=BASE;
    while(a)
      {
      t[a]+=co;
      a/=2;
      }
    }
  int query(int a,int b)
    {
    int ret=0;
    a+=BASE-1;
    b+=BASE+1;
    while(a/2!=b/2)
      {
      if(a%2==0)ret+=t[a+1];
      if(b%2==1)ret+=t[b-1];
      a/=2;
      b/=2;
      }
    return ret;
    }
  }
  
  
int main()
{
scanf("%d",&n);
FOR(i,1,n)
  {
  scanf("%d",&a);
  dodac.PB(MP(i,a));
  }
FOR(i,1,n)
  {
  scanf("%d%d",&przedzialy[i].f,&przedzialy[i].s);
  }
aktualizuj();
scanf("%d",&q);
FOR(i,1,q)
  {
  scanf("%d%d%d",&a,&b,&c);
  if((int)dodac.size()>MAGIC)aktualizuj();
  if(a==1)
    {
    co[i]=1;
    REP(i,(int)dodac.size())
      {
      if(dodac[i].f==b)
        {
        dodac[i].s=c;
        c=0;
        break;
        }
      }
    if(c!=0)dodac.PB(MP(b,c));
    }
  if(a==2)
    {
    ans[i]=sumseg[c]-sumseg[b-1];
    REP(j,(int)dodac.size())
      {
      zapytanie(b,c,dodac[j].f,i,dodac[j].s-x[dodac[j].f]);
      }
    }
  }
FOR(i,1,n)
  {
  tree::insert(przedzialy[i].f,1);
  tree::insert(przedzialy[i].s+1,-1);
  REP(j,(int)V[i].size())
    {
    int a=tree::query(1,V[i][j].co);
//    cout<<i<<" "<<j<<" "<<a<<" "<<V[i][j].ile<<" "<<V[i][j].gdzie<<endl;
    if(V[i][j].ile<0)odans[V[i][j].gdzie]+=((LL)-V[i][j].ile)*a;
    else ans[V[i][j].gdzie]+=(LL)V[i][j].ile*a;
    }
  }
FOR(i,1,q)if(co[i]==0)printf("%llu\n",ans[i]-odans[i]);
 
} 
