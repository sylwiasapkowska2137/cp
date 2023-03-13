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
const int MXN=1e6+6;
int n;
map<int,int> M;
int ID;
int in[MXN];
int pom[MXN];
main()
{
scanf("%d",&n);
FOR(i,1,n)
	{
	scanf("%d",&in[i]);
	M[in[i]]=1;
	}

for(auto &it:M)
	it.s=++ID;
int res=0;

FOR(i,1,n)
	{
	int mx=0;
	FOR(j,i,n)
		{
		pom[in[j]]++;
		maxi(mx,pom[in[j]]);
		if(mx*2>j-i+1)maxi(res,j-i+1);
		}
	FOR(j,1,n)pom[j]=0;
	}
printf("%d\n",res);
}
