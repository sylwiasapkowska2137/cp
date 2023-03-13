#include "generator.h"
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
Test przykladowy();
int R(int a,int b)
	{
	return Generator::random()%(b-a+1)+a;
	}
	
Test genTest(int m,int S,int P,int q,int mxf,int flo,bool pom=0) 
	{
  Test test;	
  if(pom==1)(mini(m,S*P));	
  test.addLine(m,S,P);
  
  VI V;
  REP(i,S)
  	{
  	V.PB(R(1,mxf));
  	}
  test.addLine(V);
  V.clear();
  REP(i,P)
  	{
  	V.PB(R(1,mxf));
  	}
  test.addLine(V);

	set<PII> SS;
	REP(i,m)
		{
		int a=R(1,P);
		int b=R(1,S);
		if(pom==1)
			{
			if(SS.count(MP(a,b))){i--;continue;}
			SS.insert(MP(a,b));
			}
		int X=R(1,flo);
		int C=R(1,1e4);
		test.addLine(a,b,X,C);		
		}
	test.addLine(q);
	REP(i,q)
		{
		int x=R(1,200);
		if(x==1)
				test.addLine(R(1,1e9));
		else 
			test.addLine(R(1,min(S,P)*mxf+1));
		}
	return test;
	}
Test reczny()
	{
	Test test;
	test.addLine(4, 4, 5);
	test.addLine(3, 4, 4, 3);
	test.addLine(4, 4, 3, 3, 4); 
	test.addLine(1, 1, 3, 3);
	test.addLine(5, 4, 3, 5);
	test.addLine(2, 4, 4, 10);
	test.addLine(5, 1, 3, 2);
	test.addLine(5);
	test.addLine(6);
	test.addLine(3);
	test.addLine(1);
	test.addLine(9);
	test.addLine(5);
	return test;
	}
	
//////////////////////////////////////////////
int main() 
	{
  Generator gen("bud");

  gen.beginGroup();
	  {
    gen.addTest(przykladowy());//bud0.in
  	}
  gen.endGroup();

	
	gen.beginGroup();
	  {
	  Generator::setSeed(41);
    REP(i,10)
    	{
    	gen.addTest(genTest(4,4,5,4,3,5,1),20);//bud1x.in
  		}
  	gen.addTest(reczny(),20);
  	}
  gen.endGroup();


	gen.beginGroup();
	  {
	  Generator::setSeed(44);
    REP(i,10)gen.addTest(genTest(100,30,32,20,30,30),30);//bud2x.in
  	}
  gen.endGroup();

	gen.beginGroup();
	  {
	  Generator::setSeed(45);
    REP(i,10)
    	{
    	int fff=R(1,1e4);
    	gen.addTest(genTest(1000,100,R(80,100),1000,200,fff),50);//bud3x.in
  		}
  	}
  gen.endGroup();

	////////////////////////////////////////////////////////////////////////////
  // generowanie testow
  gen.generate();
	}
//////////////////////////
Test przykladowy()
	{
	Test test;
	test.addLine(3, 3, 2);
	test.addLine(2, 2, 1);
	test.addLine(2, 3);
	test.addLine(1, 2, 1, 2);
	test.addLine(1, 3, 2, 4);
	test.addLine(2, 3, 1, 1);
	test.addLine(2);
	test.addLine(1);
	test.addLine(2);
	return test;
	}

