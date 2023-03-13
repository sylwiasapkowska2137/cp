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
  if(R(1,30)>=4)ret.PB(MP(i,R(max(1,i-7),i-1)));
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
    if(R(1,30)>=5)ret.PB(MP(i,R(1,min(i-1,T))));
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
    if(R(1,30)>=2)ret.PB(MP(i,R(1,min(i-1,T))));
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
Test dawaj(int n,int minw, int maxw, double part, VPII V = VPII())
  {
  if(V.size() == 0) V = generatetree(n, R(1, 5));
  
  int sred = srednica(V);
  int K;
  if(part < 0) 
    if(R(1, 5) == 1)K = R(1, n);
    else K = R(1, sred);
  else
    K = R(sred / part - 3, sred / part + 5);
 
  maxi(K, 2);
  mini(K, n-1);
  
  Test test;
  test.addLine(n, K);
  REP(i,V.size())
    {
    test.addLine(V[i].f, V[i].s, R(minw, maxw));    
    }
  return test;
  }

Test exampleTest()
  {
  Test test;
  test.addLine(7, 2);
  test.addLine(1, 2, -1);
  test.addLine(1, 3, 4);
  test.addLine(2, 5, 1);
  test.addLine(2, 6, 1);
  test.addLine(2, 7, 3);
  test.addLine(4, 3, 2);
  return test;
  }

int main(int argc, char *argv[]) 
  {
  Generator gen("zbi");

  gen.beginGroup();
  gen.addTest(exampleTest());
  gen.endGroup();

  // 1
  gen.beginGroup();
  {
      Generator::setSeed(982751);
      REP(i,4)gen.addTest(dawaj(6, -10, 30, -1));
      REP(i,6)gen.addTest(dawaj(10, 0, 30, 2));
  }
  gen.endGroup();
  
  //2
  gen.beginGroup();
  {
      Generator::setSeed(191182751);
      REP(i,4)gen.addTest(dawaj(1003, -1e6, 2e6, -1));
      gen.addTest(dawaj(1003, -1e6, 1e6, -1));
      REP(i,4)gen.addTest(dawaj(1133, 0, 30, 1.2));
  }
  gen.endGroup();

  //3
  gen.beginGroup();
  {
      Generator::setSeed(982755341);
      REP(i,2)gen.addTest(dawaj(20000, -1e9, 1e9, -1));
      REP(i,2)gen.addTest(dawaj(20000, 0, 1e9, 10));
      REP(i,4)gen.addTest(dawaj(34340, -1e8, 1e9, 1+1/R(1,6)));
  }
  gen.endGroup();
  
  // 4
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      REP(i,4)gen.addTest(dawaj(200000, -5e8, 1e9, -1, generatetree2(200000)));
      REP(i,2)gen.addTest(dawaj(200000, 0, 1e9, 2));
      REP(i,4)gen.addTest(dawaj(313440, -1e8, 1e9, -1));
  }
  gen.endGroup();

  // 5
  gen.beginGroup();
  {
      Generator::setSeed(99755341);
      REP(i,4)gen.addTest(dawaj(500000, -5e8, 1e9, -1, generatetree2(500000)));
      REP(i,2)gen.addTest(dawaj(500000, 0, 1e9, 1.5));
      REP(i,4)gen.addTest(dawaj(500000-R(1, 100), -1e8, 1e9, -1));
  }
  gen.endGroup(); 

  gen.generate();
  }

Test tiny2() {
    Test test;

    test.addLine(15);
    test.addLine(2, 1);
    test.addLine(3, 2);
    test.addLine(4, 3);
    test.addLine(5, 3);
    test.addLine(6, 3);
    test.addLine(7, 4);
    test.addLine(8, 4);
    test.addLine(9, 4);
    test.addLine(10, 5);
    test.addLine(11, 5);
    test.addLine(12, 6);
    test.addLine(13, 6);
    test.addLine(14, 6);
    test.addLine(15, 6);

    return test;
}


