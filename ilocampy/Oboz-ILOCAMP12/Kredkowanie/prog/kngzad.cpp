#include<bits/stdc++.h>
#define int LL
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
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
int n,a,b,c,d,k,m,q,z;
const int MXN=2e5+5;
VI V[MXN];
int cc[MXN];
int skok[MXN];
int fat[MXN];
int jed[MXN];
int odl[MXN];
int colored;
void dfs(int x,int pop)
  {
  odl[x]=odl[pop]+1;
  REP(i,V[x].size())
    {
    int v=V[x][i].f;
    if(v==pop)continue;
    fat[v]=x;
    dfs(v,x);
    }
  }
int skacz(int x)
  { 
  if(cc[fat[x]]!=1)return x;
  if(skok[x]==x)
    return skok[x]=skacz(fat[x].f);
  return skok[x]=skacz(jeden[x]); 
  }
int krok(int x,int &v)
  {
  if(cc[fat[x].s]>1)
    {
    v/=cc[fat[x].s];
    return fat[x].f;
    }
  return jeden[x]=skacz(jeden[x]);
  }
void calc(int a,int b)
  {
  while(a!=b)
    {
    if(odl[a]<odl[b])swap(a,b);
    a=krok(a);
    }
  }
main()
{
ios_base::sync_with_stdio(0);
cin>>n>>m;
FOR(i,1,n-1)
  {
  cin>>a>>b;
  V[a].PB(b);
  V[b].PB(a);
  }
dfs(1,0);
FOR(i,1,n)skok[i]=i;

FOR(i,1,m)
  {
  cin>>a;
  calc(a,b);
  cout<<colored<<endl;
  }
}
