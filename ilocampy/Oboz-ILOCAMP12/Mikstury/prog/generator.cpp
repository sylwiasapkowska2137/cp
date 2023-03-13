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
Test notakijeden(int n,int k)
  {
  Test test;
  
  test.addLine(n, k);
  VI V;
  REP(i,n)V.PB(R(0, 10));
  REP(i,k)
    {
    VI V;
    REP(i,n+1)
      {
      V.PB(R(0, 10));
      }
    test.addLine(V);
    }
  
  return test;
  }

Test exampleTest()
  {
  Test test;
  test.addLine("3 3");
  test.addLine("1 2 3");
  test.addLine("1 0 0 1");
  test.addLine("0 1 0 2");
  test.addLine("0 0 6 1");
  return test;
  }

int main(int argc, char *argv[]) 
  {
  Generator gen("mik");

  gen.beginGroup();
  gen.addTest(exampleTest());
  gen.endGroup();

  // 1
  gen.beginGroup();
  {
      Generator::setSeed(982751);
      REP(i,10)gen.addTest(notakijeden(R(2,4), R(2,4)), 30);
  }
  gen.endGroup();
  

  gen.generate();
  }


