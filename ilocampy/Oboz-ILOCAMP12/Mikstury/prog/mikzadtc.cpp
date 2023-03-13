#include<bits/stdc++.h>
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
int n, m;

const int MXN = 11;
LD eps = 1e-10;

LD c[MXN], b[MXN], A[MXN][MXN];
LD Ab[MXN][MXN+1];

LD calc(int use)
  {
  int mm = 0;
  VI mapping;
  REP(j,m)
    if(use&(1<<j))
      {
      mapping.PB(j);
      REP(i,n)Ab[i][mm]=A[i][j]; ++mm;
      }
  REP(i,n)Ab[i][mm]=b[i]; ++mm;
  int r = 0, c = 0;
  while(r<n && c < mm-1)
    {
    int maxr=r;
    FOR(i,r+1,n-1)
      if(abs(Ab[i][c]) > abs(Ab[maxr][c])) maxr = i;
    if(abs(Ab[maxr][c]) < eps)
      {
      c++;
      continue;
      throw 1;//?
      }
    FOR(j,c,mm-1)swap(Ab[r][j], Ab[maxr][j]);
    LD div = Ab[r][c];
    FOR(j,c,mm)Ab[r][j]/=div;
    
    FOR(i, r+1,n-1)
      FORD(j, mm-1, c)
        {
        Ab[i][j]-=Ab[i][c]*Ab[r][j];
        }
    ++r;++c;
    }
  if(c!=mm-1)throw 2;  else FOR(i,r,n-1) if(abs(Ab[i][mm-1])>eps)throw 3;
  
  --r;--c;
  while(r>0 && c>0)
    {
    REP(i, r)
      {
      LD times = Ab[i][c];
      FORD(j, mm-1, i)
        {
        Ab[i][j]=Ab[i][j]*Ab[r][c] - times * Ab[r][j];
        }
      }
    --r;
    --c;
    }
  REP(i,mm-1)if(Ab[i][mm-1]<eps)throw 4;
    
  LD ret=0;
  REP(i,mm-1)ret+=::c[mapping[i]]*Ab[i][mm-1];
  return ret;
  }

class Mixture
{
public:
double mix(vector<int> mix, vector<string> have)
  {
  n = mix.size();
  REP(i,n)b[i]=mix[i];
  m=have.size();
  REP(i, m)
    {
    istringstream sin(have[i]);
    REP(j, n)
      {
      sin>>A[j][i];
      }
    sin>>c[i];
    }
//  vector<VI> splitv<int>(have);REP(i,m)REP(j,n)A[j][i]=tmp[i][j];REP(i,m)c[i]=tmp[i][n];
  
  LD ret=1e18;
  FOR(i,1,(1<<m)-1)
    {
    try
      {
      ret=min(ret, calc(i));
      }
    catch(int e) {}
    }
  return ret>1e17?-1:ret;
  }
};
