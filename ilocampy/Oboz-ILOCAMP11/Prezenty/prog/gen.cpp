#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
using namespace std;
int R(int a,int b)
{
return rand()%(b-a+1)+a;
}
int a,b,c,d,e,n;
main(int argc, char *argv[])
{
srand(time(0)*atoi(argv[1]));
int m=1000;
int S=100;
int P=100;
int q=1000;
printf("%d %d %d\n",m,S,P);
FOR(i,1,S)
	{
	printf("%d ",R(199,200));
	}
puts("");
FOR(i,1,P)
	{
	printf("%d ",R(199,200));
	}
puts("");
FOR(i,1,m)
	{
	printf("%d %d %d %d\n",R(1,P),R(1,S),R(1,1e4),R(1,1e4));
	}
printf("%d\n",q);
FOR(i,1,q)
	{
	printf("%d\n",R(1,2e4));
	}
}
