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
Test stupidtest(int n,int w) 
	{
  Test test;	
	test.addLine(n);
	VI V;
	FOR(i,1,n)
		{
		V.PB(R(1,w));
		}
	test.addLine(V);
	return test;
	}
Test type1Test(int n,int w,int x,int ill)
	{
  Test test;	
	test.addLine(n);
	VI V;
	FOR(i,1,n)
		{
		V.PB(R(1,w));
		}
	FOR(i,1,x)
		{
		int ter=R(1,w);
		REP(j,ill)
			{
			V[R(0,n-1)]=ter;
			}
		}
	test.addLine(V);
	return test;
	}
Test type2Test(int n,int w,int x,LD ges)
	{
  Test test;	
	test.addLine(n);
	VI V;
	FOR(i,1,n)
		{
		V.PB(R(1,w));
		}
	FOR(i,1,x)
		{
		int val=R(1,w);
		int a=R(0,n-1);
		int b=R(a,min(a+(R(0,100)<1?1000000:20000),n-1));
		int ile=(b-a+1)*ges;
		REP(j,ile)
			{
			V[R(a,b)]=val;
			}
		}
	test.addLine(V);
	return test;
	}
//////////////////////////////////////////////
int main() 
	{
  Generator gen("bel");

  gen.beginGroup();
	  {
    Generator::setSeed(1);
    gen.addTest(przykladowy());//bel0.in
  	}
  gen.endGroup();


  gen.beginGroup();//bel1x.in
	  {
	  Generator::setSeed(2);
	  gen.addTest(stupidtest(10,100),10);
	  
	  Generator::setSeed(3);
	  gen.addTest(stupidtest(10,4),10);
	  
	  Generator::setSeed(4);
	  gen.addTest(stupidtest(80,5),10);

		Generator::setSeed(6);
	  gen.addTest(stupidtest(84,100),10);
	
		Generator::setSeed(7);
	  REP(i,3)gen.addTest(type1Test(90,10,9,8),10);

		Generator::setSeed(8);
   	REP(i,6)gen.addTest(type2Test(R(80,100),100,10,9),10);
    }
   gen.endGroup();
   
   gen.beginGroup();//bel2x.in
	  {
	  Generator::setSeed(20);
	  gen.addTest(stupidtest(2000,1e9),20);
	  
	  Generator::setSeed(31);
	  gen.addTest(stupidtest(1000,10),20);
	  
	  Generator::setSeed(333);
	  gen.addTest(stupidtest(1000,3),20);

		Generator::setSeed(132);
	  REP(i,3)gen.addTest(type1Test(R(900,2000),1e9,8,16),20);

		Generator::setSeed(234);
   	REP(i,6)
   		{
   		int x=R(800,1500);
   		gen.addTest(type2Test(x,100,10,R(7,11)/10.0),20);
    	}
    }
  gen.endGroup();
   
  gen.beginGroup();//bel3x.in
	  {
	  Generator::setSeed(24230);
	  gen.addTest(stupidtest(20000,1e9),20);
	  
	  Generator::setSeed(3453451);
	  gen.addTest(stupidtest(30000,10),20);
	  
	  Generator::setSeed(33524253);
	  gen.addTest(stupidtest(30000,3),20);

		Generator::setSeed(1453454532);
	  REP(i,3)gen.addTest(type1Test(30000,1e9,100,200),20);

		Generator::setSeed(1323432);
	  REP(i,3)gen.addTest(type1Test(30000,1e9,100,1000),20);

		Generator::setSeed(2343244);
   	REP(i,6)gen.addTest(type2Test(30000,1e9,1000,R(3,11)/10.0),20);
    }
  gen.endGroup();

	gen.beginGroup();//bel4x.in
	  {
	  Generator::setSeed(22224230);
	  gen.addTest(stupidtest(200000,1e9),20);
	  
	  Generator::setSeed(111453451);
	  gen.addTest(stupidtest(200000,10),20);
	  
	  Generator::setSeed(463534253);
	  gen.addTest(stupidtest(200000,3),20);

		Generator::setSeed(555553532);
	  REP(i,3)gen.addTest(type1Test(200000-R(1,100),1e9,1000,400),20);

		Generator::setSeed(144423432);
	  REP(i,3)gen.addTest(type1Test(200000,1e9,100,1000),20);

		Generator::setSeed(242342344);
   	REP(i,4)gen.addTest(type2Test(220000,1e9,1000,R(2,14)/10.0),20);
    }
  gen.endGroup();
  
	gen.beginGroup();//bel5x.in
	  {
	  Generator::setSeed(772222230);
	  gen.addTest(stupidtest(500000,1e9),30);
	  
	  Generator::setSeed(1222230);
	  gen.addTest(stupidtest(500000,1e9),30);
	  
	  Generator::setSeed(887451);
	  gen.addTest(stupidtest(500000,10),30);
	  
	  Generator::setSeed(2334253);
	  gen.addTest(stupidtest(500000,4),30);

		Generator::setSeed(654656532);
	  REP(i,3)gen.addTest(type1Test(500000-R(1,100),1e9,4000,600),30);

		Generator::setSeed(545552);
	  REP(i,3)gen.addTest(type1Test(500000,1e9,800,5000),30);

		Generator::setSeed(53455);
   	REP(i,3)
   		{
   		int x=R(800,4000);
   		gen.addTest(type2Test(500000,1e9,x,R(4,14)/10.0),30);
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
	test.addLine(7);
	test.addLine(2, 4, 3, 4, 4, 2, 3);
	return test;
	}

