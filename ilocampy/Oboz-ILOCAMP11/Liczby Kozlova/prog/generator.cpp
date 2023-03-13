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
VI V={1, 13, 100, 1234567, 1000000000, 90967, 11319, 513, 11184, 375, 138167024, 424, 24528128, 29159607, 1043, 239412989, 416543150, 997143, 1168, 9777, 697611709, 831293191, 177, 191425575, 142779763, 3814502, 33096950, 3884785, 575209214, 63881, 57053771, 16973, 156221776, 2620340, 539, 4329180, 11595, 277268, 652494863, 844240558, 103244887, 628220597, 1403692, 922082415, 570889576, 4270983, 825196030, 220, 162620192, 56092, 284351294, 18445, 1958283, 117931104, 43767868, 590320058, 78513, 966027, 1185, 963135434, 1000000000, 999999999, 17, 1000000001};
VI grupy={3000, 4000000, 200000000, 1000000000};
	
Test genTest(int x) 
	{
  Test test;	
	test.addLine(V[x]);
	return test;
	}

	
//////////////////////////////////////////////
int main() 
	{
  Generator gen("koz");

  gen.beginGroup();
	  {
    gen.addTest(przykladowy());//kox0.in
  	}
  gen.endGroup();

	sort(ALL(V));
	int pom=0;
	REP(i,grupy.size())
		{
		gen.beginGroup();//kozix.in
			{
		  while(V[pom]<=grupy[i])
		  	{
		  	gen.addTest(genTest(pom));
		  	pom++;
		  	}
		  }
		gen.endGroup();
		}


	////////////////////////////////////////////////////////////////////////////
  // generowanie testow
  gen.generate();
	}
//////////////////////////
Test przykladowy()
	{
	Test test;
	test.addLine(10);
	return test;
	}

