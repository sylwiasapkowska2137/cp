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
int a, b;
 
int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest()
  {
  Test test;
  
  
test.addLine(8, 6);
test.addLine(1, 3);
test.addLine(1, 4);
test.addLine(2, 6);
test.addLine(5, 3);
test.addLine(3, 2);
test.addLine(7, 5);
test.addLine(8, 7);
test.addLine(1, 3);
test.addLine(1, 4);
test.addLine(1, 5);
test.addLine(6, 1);
test.addLine(6, 4);
test.addLine(6, 5);
  
  
  
  return test;
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
  
  
  

  

  
bool checktree(VPII V) {
// {a
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

  
  
  
  
  VPII generatetree(int n,int x, int minS)
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
      
      
      cout << n << " " << srednica(V1) << endl;
      
      while (srednica(V1) < minS)
          V1 = generatetree6(n);
      
      break;
      }
    }
  permutuj(V1);
  return V1;
  }
  
  
  
  
  Test losowy(int n, int m, int x, int minD, int maxD, int minS) {
    Test test;
    
    VPII v = generatetree(n, x, minS);
    
    test.addLine(n, m);
    
    for (int i=0; i<v.size(); i++)
        test.addLine(v[i].f, v[i].s);
    
    for (int i=0; i<m; i++) {
        int a = R(1, n);
        int d = R(minD, maxD);
        test.addLine(a, d);
    }
        
    
    return test;
}
  

int main(int argc, char *argv[]) 
  {
  Generator gen("pse");

  gen.beginGroup();
  gen.addTest(exampleTest());
  gen.endGroup();

  // 1
  gen.beginGroup();
  {
      Generator::setSeed(982751);
      
      gen.addTest(losowy(1, 1, 1, 0, 0, 0));
      gen.addTest(losowy(2, 4, 1, 0, 1, 0));
      gen.addTest(losowy(5, 10, 1, 0, 4, 0));
      gen.addTest(losowy(10, 20, 2, 0, 7, 0));
      gen.addTest(losowy(20, 30, 3, 0, 9, 0));
      gen.addTest(losowy(30, 40, 4, 0, 7, 0));
      gen.addTest(losowy(40, 50, 5, 0, 3, 0));
      gen.addTest(losowy(50, 60, 6, 0, 7, 0));
  }
  gen.endGroup();
  
  //2
  gen.beginGroup();
  {
      Generator::setSeed(191182751);

      gen.addTest(losowy(3, 10, 1, 0, 2, 0));
      gen.addTest(losowy(50, 200, 2, 0, 40, 0));
      gen.addTest(losowy(50, 300, 3, 0, 30, 0));
      gen.addTest(losowy(70, 400, 4, 0, 10, 0));
      gen.addTest(losowy(200, 500, 5, 1, 5, 0));
      gen.addTest(losowy(100, 600, 6, 0, 99, 70));
      gen.addTest(losowy(20000, 50000, 6, 1, 5, 10000));
      gen.addTest(losowy(50000, 50000, 6, 999, 9999, 25000));
      gen.addTest(losowy(50000, 50000, 6, 100, 10000, 30000));
  }
  gen.endGroup();

  //3
  gen.beginGroup();
  {
      Generator::setSeed(982755341);

      gen.addTest(losowy(1000, 2000, 3, 0, 49, 0));
      gen.addTest(losowy(1000, 2000, 6, 20, 99, 200));
      gen.addTest(losowy(1000, 2000, 5, 0, 10, 0));
      gen.addTest(losowy(1000, 2000, 6, 300, 549, 600));
      gen.addTest(losowy(1000, 2000, 6, 0, 999, 650));
      gen.addTest(losowy(200000, 500000, 6, 1, 5, 30000));
      gen.addTest(losowy(500000, 500000, 6, 9999, 99999, 65000));
      gen.addTest(losowy(500000, 500000, 6, 1000, 10000, 65000));
  }
  gen.endGroup();
  
  // 4
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      
      gen.addTest(losowy(100000, 500000, 3, 0, 10000, 0));
      gen.addTest(losowy(100000, 500000, 4, 0, 10, 1000));
      gen.addTest(losowy(100000, 500000, 5, 0, 100, 10000));
      gen.addTest(losowy(100000, 500000, 6, 0, 99, 35000));
      gen.addTest(losowy(200000, 500000, 6, 999, 9999, 0));
      gen.addTest(losowy(200000, 500000, 6, 9999, 99999, 30000));
      gen.addTest(losowy(500000, 500000, 6, 1000, 10000, 55000));
  }
  gen.endGroup();

  // 5
  gen.beginGroup();
  {
      Generator::setSeed(99755341);

      gen.addTest(losowy(100000, 500000, 6, 0, 10, 30000));
      gen.addTest(losowy(100000, 500000, 6, 0, 1000, 35000));
      gen.addTest(losowy(400000, 500000, 6, 0, 99999, 50000));
      gen.addTest(losowy(200000, 500000, 6, 1, 5, 30000));
      gen.addTest(losowy(500000, 500000, 6, 9999, 99999, 65000));
      gen.addTest(losowy(500000, 500000, 6, 1000, 10000, 65000));
      
      gen.addTest(losowy(300000, 500000, 3, 1, 10, 0));
      gen.addTest(losowy(300000, 500000, 2, 0, 100, 0));
      gen.addTest(losowy(300000, 500000, 4, 1, 4, 0));
      gen.addTest(losowy(400000, 500000, 4, 0, 10, 0));
      gen.addTest(losowy(400000, 500000, 5, 1, 4, 0));
      gen.addTest(losowy(500000, 500000, 5, 0, 10, 0));
  }
  gen.endGroup(); 
  
  // 6
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      
      gen.addTest(losowy(100000, 500000, 3, 1, 100, 0));
      gen.addTest(losowy(100000, 500000, 4, 1, 10, 1000));
      gen.addTest(losowy(100000, 500000, 5, 1, 5, 10000));
      gen.addTest(losowy(100000, 500000, 6, 1, 99, 35000));
      gen.addTest(losowy(300000, 500000, 6, 9999, 99999, 50000));
      gen.addTest(losowy(200000, 500000, 6, 9999, 99999, 0));
      gen.addTest(losowy(500000, 500000, 6, 1000, 10000, 60000));
  }
  gen.endGroup();
  
  // 7
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      
      gen.addTest(losowy(10, 500, 3, 1, 9, 0));
      gen.addTest(losowy(100, 500, 4, 1, 10, 0));
      gen.addTest(losowy(100, 500, 5, 1, 5, 0));
      gen.addTest(losowy(100, 500, 6, 1, 99, 50));
      gen.addTest(losowy(200, 500, 6, 50, 150, 150));
      gen.addTest(losowy(200, 500, 6, 30, 50, 150));
      gen.addTest(losowy(50, 500, 6, 5, 49, 40));
  }
  gen.endGroup();


  gen.generate();
  }
