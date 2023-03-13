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
Test genTest(int n,int q,int k,int mxv=1e9,int mxpoc=-1,int minkon=1) 
	{
	if(mxpoc==-1)mxpoc=n;
  Test test;	
	test.addLine(n, q, k);
	VI V;
	REP(i,n)
		{
		V.PB(R(1, mxv));
		}
	test.addLine(V);
	REP(i,q)
		{
		int a=R(1, mxpoc);
		int b=R(max(a, minkon), n);
		test.addLine(a, b);
		}
	return test;
	}
	
//////////////////////////////////////////////
int main() 
	{
  Generator gen("tor");

  gen.beginGroup();
	  {
    Generator::setSeed(1);
    gen.addTest(przykladowy());//tor0.in
  	}
  gen.endGroup();


  gen.beginGroup();//tor1x.in
	  {
    Generator::setSeed(2);
    gen.addTest(genTest(5,5,10,15));

    Generator::setSeed(3);
    gen.addTest(genTest(7,8,10,15));
    
    Generator::setSeed(5);
    gen.addTest(genTest(7,8,10,15));
    
    Generator::setSeed(8);
    gen.addTest(genTest(10,10,50,70));
    
    Generator::setSeed(10);
    gen.addTest(genTest(20,15,100,300));
    
    Generator::setSeed(30);
    gen.addTest(genTest(20,20,30,17));
    }
  gen.endGroup();


  gen.beginGroup();//tor2x.in
	  {
    Generator::setSeed(13);
    gen.addTest(genTest(100,100,10000,20000));

    Generator::setSeed(32);
    gen.addTest(genTest(100,200,60,60));
    
    Generator::setSeed(443);
    gen.addTest(genTest(100,100,1e9,6.5e8));
    }
  gen.endGroup();


	 gen.beginGroup();//tor3x.in
	  {
    Generator::setSeed(1433);
    gen.addTest(genTest(2000,2000,1e9-100,1e9));

    Generator::setSeed(3253);
    gen.addTest(genTest(2000,1000,1e8,6e6));
    
    Generator::setSeed(443545);
    gen.addTest(genTest(2000,2000,1000,1200,100,1900));
    }
  gen.endGroup();


	gen.beginGroup();//tor4x.in
	  {
    Generator::setSeed(13453453);
    gen.addTest(genTest(10000,10000,1e8-32,1e9));

    Generator::setSeed(32352);
    gen.addTest(genTest(10000,10000,1e8,7e6));
    
    Generator::setSeed(4432235);
    gen.addTest(genTest(10000,10000,1e8,2e8,100,9400));
    }
  gen.endGroup();

	gen.beginGroup();//tor5x.in
	  {
    Generator::setSeed(3413453453);
    gen.addTest(genTest(100000,100000,1e8-424,1e8));
    
    Generator::setSeed(334432235);
    gen.addTest(genTest(100000,100000,1e9-344,1e9));
    }
  gen.endGroup();


	gen.beginGroup();//tor6x.in
	  {
    Generator::setSeed(787453);
    gen.addTest(genTest(300324,300000,1e8-44344,2e8));
    
    Generator::setSeed(70552235);
    gen.addTest(genTest(300000,300000,1e9-342434,1e9));
    }
  gen.endGroup();

	gen.beginGroup();//tor7x.in
	  {
    Generator::setSeed(43547453);
    gen.addTest(genTest(1e6-432,1e6-43,5e8,3e8));
    }
  gen.endGroup();

	gen.beginGroup();//tor8x.in
	  {
    Generator::setSeed(878647453);
    gen.addTest(genTest(1e6,1e6,1e9,6e8,1000,1e6-3443));
    }
  gen.endGroup();

	gen.beginGroup();//tor9x.in
	  {
    Generator::setSeed(64564424);
    gen.addTest(genTest(1e6,1e6,1e9,6e8));
    
    Generator::setSeed(99956424);
    gen.addTest(genTest(1e6,1e6,1e5,1e7,1000,1e6-3443));
    }
  gen.endGroup();
  
  gen.beginGroup();//tor10x.in
	  {
    Generator::setSeed(869444);
    gen.addTest(genTest(1e6,1e6,1e9,6e8));
    
    Generator::setSeed(5455444);
    gen.addTest(genTest(1e6-2,1e6-10,4e8,1e9));
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
	test.addLine(8, 4, 7);
	test.addLine(1, 3, 4, 8, 2, 6, 5, 4);
	test.addLine(2, 3);
	test.addLine(2, 4);
	test.addLine(6, 6);
	test.addLine(5, 8);
	return test;
	}

