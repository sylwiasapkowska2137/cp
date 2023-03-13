//do własnego testowania
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
int X=1e9;
int n=1e3;
int m=1;
int k=R(1,X);
printf("%d %d %d\n",n,m,k);
FOR(i,1,n)printf("%d ",R(1,min(X*2,(int)1e9)));puts("");
FOR(i,1,m)printf("%d %d\n",R(1,b),b=R(1,n));
}
