/*
Maciej Hołubowicz
*/
//g++ -std=gnu++11 generator.cpp -o generator && ./generator
#include<bits/stdc++.h>
#include "generator.h"
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define VVI vector< VI >
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
 
int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}
VPII generatetree1(int n)
{
VPII ret;
FOR(i,2,n)
  {
  ret.PB(MP(i,R(1,i-1)));
  }
return ret;
}
VPII generatetree2(int n)
{
VPII ret;
FOR(i,2,n)
  {
  if(R(1,100)>=3)ret.PB(MP(i,R(max(1,i-7),i-1)));
  else ret.PB(MP(i,R(1,i-1)));
  }
return ret;
}
struct FI
  {
  int *t;
  FI(int n)
    {
    n++;
    t=new int[n+1];
    FOR(i,1,n)t[i]=i;
    }
  int find(int a)
    {
    return a==t[a]?a:t[a]=find(t[a]);
    }
  void unio(int a,int b)
    {
    t[find(a)]=find(b);
    }
  };
VPII generatetree3(int n)
{
FI X(n);
VPII ret;
while(ret.size()!=n-1)
  {
  a=R(1,n);
  b=R(1,n);
  if(X.find(a)!=X.find(b))
    {
    ret.PB(MP(a,b));
    X.unio(a,b);
    }
  }
return ret;
}
VPII generatetree4(int n,int T=0)//duże stopnie
  {
  if(T==0)T=R(3,10);
  VPII ret;
  FOR(i,2,n)
    {
    if(R(1,300)>=5)ret.PB(MP(i,R(1,min(i-1,T))));
    else ret.PB(MP(i,R(1,i-1)));
    }
  return ret;  
  }
VPII generatetree5(int n,int T=0)//bardzo duże stopnie
  {
  if(T==0)T=R(1,4);
  VPII ret;
  FOR(i,2,n)
    {
    if(R(1,300)>=2)ret.PB(MP(i,R(1,min(i-1,T))));
    else ret.PB(MP(i,R(1,i-1)));
    }
  return ret;  
  }
VPII generatetree6(int n)
  {
  VPII ret;
  FOR(i,2,n)
    {
    if(R(1,3000)>=2)ret.PB(MP(i,R(max(1,i-2),i-1)));
    else ret.PB(MP(i,R(1,i-1)));
    }
  return ret;
  }
void permutuj(VPII &V)
  {
  int n=V.size()+1;
  int t[n+1];
  FOR(i,1,n)t[i]=i;
  random_shuffle(t+2,t+n+1);
  REP(i,V.size())
    {
    V[i].f=t[V[i].f];
    V[i].s=t[V[i].s];
    if(R(1,3)==1)swap(V[i].f,V[i].s);
    }
  random_shuffle(ALL(V));
  }
VPII generatetree(int n,int x)
  {
  VPII V1;
    switch (x)
    {
    case 1:
      {
      V1=generatetree1(n);
      break;
      }
    case 2:
      {
      V1=generatetree2(n);
      break;
      }
    case 3:
      {
      V1=generatetree3(n);
      break;
      }
    case 4:
      {
      V1=generatetree4(n);
      break;
      }
    case 5:
      {
      V1=generatetree5(n);
      break;
      }
    case 6:
      {
      V1=generatetree6(n);
      break;
      }
    }
  permutuj(V1);
  return V1;
  }
bool checktree(VPII V)
{
int n=V.size()+1;
FI X(n);
REP(i,V.size())
  {
  a=V[i].f;
  b=V[i].s;
  if(a>n||b>n)return 0;
  if(a<1||b<1)return 0;
  if(X.find(a)==X.find(b))return 0;
  X.unio(a,b);
  }
return 1;
}

const int MXN = 1e6+6;
VI V[MXN];
int odl[MXN];
void dfs(int x,int pp)
  {
  for(auto it:V[x])
    {
    if(it == pp)continue;
    odl[it] = odl[x] + 1;
    dfs(it, x);
    }
  }
int srednica(VPII X)
  {
  int n = X.size() + 1;
  FOR(i,1,n)
    {
    V[i].clear();
    odl[i]=0;
    }
  for(auto it:X)
    {
    V[it.f].PB(it.s);
    V[it.s].PB(it.f);
    }
  odl[1]=0;
  dfs(1, 0);
  int mx=0;
  FOR(i,1,n)
    {
    if(odl[mx] < odl[i])
      {
      mx = i;
      }
    }
  odl[mx]=0;
  dfs(mx, 0);
  int r = 0;
  FOR(i,1,n)
    {
    maxi(r, odl[i]);
    }
  return r;
  }


void przygotujzapytania(VPII inn)
  {
  int n = inn.size() + 1;
  FOR(i,1,n)V[i].clear();
  REP(i,n)
    {
    V[inn[i].f].PB(inn[i].s);
    V[inn[i].s].PB(inn[i].f);
    }
  odl[1]=0;
  dfs(1, 0);
  
  }

Test dawaj(int n, bool k=0, VPII V = VPII())
  {
  if(V.size() == 0) 
    {
    int pluss=0;
    if(k==0)V = generatetree(n, R(1, 6));
    else
      while(1)
        {
        pluss+=1000;
        V = generatetree(n, R(6, 6));
        cerr<<n<<" "<<srednica(V) << endl;
        if(srednica(V) + pluss < n/7)
          {
          V = generatetree(n, R(1, 6));
          }
        else 
          {
          break;
          }
        }
    }
  int sred = srednica(V);
  int q = n + R(-10, 10);
  mini(q, 500000);
  maxi(q, 5);
 
 
  Test test;
  test.addLine(n, q);
  REP(i,V.size())
    {
    test.addLine(V[i].f, V[i].s);    
    }
  
  
  REP(i,q)
    {
    int a = R(1, n);
    if(R(1,10)<3) a = R(1, min(n, n/10 + 4));
    int b = R(1, n);
    test.addLine(a, b);
    }
  return test;
  }

Test exampleTest()
  {
  Test test;
  return test;
  }

int main(int argc, char *argv[]) 
  {
  Generator gen("kng");

  gen.beginGroup();
  gen.addTest(exampleTest());
  gen.endGroup();

  // 1
  gen.beginGroup();
  {
      Generator::setSeed(982751);
      REP(i,10)gen.addTest(dawaj(6));
      REP(i,10)gen.addTest(dawaj(10));
  }
  gen.endGroup();
  
  //2
  gen.beginGroup();
  {
      Generator::setSeed(191182751);
      REP(i,4)gen.addTest(dawaj(1003,1));
      REP(i,4)gen.addTest(dawaj(1133));
  }
  gen.endGroup();

  //3
  gen.beginGroup();
  {
      Generator::setSeed(982755341);
      REP(i,4)gen.addTest(dawaj(60000, 0));
      REP(i,2)gen.addTest(dawaj(80000, 1));
      REP(i,4)gen.addTest(dawaj(84340, 1));
  }
  gen.endGroup();
  
  // 4
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      REP(i,4)gen.addTest(dawaj(300000, 0));
      REP(i,2)gen.addTest(dawaj(240000, 1));
      REP(i,4)gen.addTest(dawaj(313440, 1));
  }
  gen.endGroup();

  // 5
  gen.beginGroup();
  {
      Generator::setSeed(99755341);
      REP(i,4)gen.addTest(dawaj(500000, 0, generatetree2(500000)));
      REP(i,2)gen.addTest(dawaj(500000, 1));
      REP(i,4)gen.addTest(dawaj(500000-R(1, 100), 1));
  }
  gen.endGroup(); 

  gen.generate();
  }


