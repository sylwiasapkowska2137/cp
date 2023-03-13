#include<bits/stdc++.h>
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
using namespace std;
int n,q,k,a,b;
const int MXN=1e6+6;
int biggerkdiv2[MXN];
int cntbigger(int a,int b)
	{
	return biggerkdiv2[b]-biggerkdiv2[a-1];
	}
const int BASE=1<<20;
struct TREE
	{	
	int t[BASE*2];
	TREE(int v=1e9+1)
		{
		REP(i,2*BASE)t[i]=v;
		}
	void insert(int x,int v)
		{
		x+=BASE;
		t[x]=v;
		x/=2;
		while(x)
			{
			t[x]=min(t[x*2], t[x*2+1]);
			x/=2;
			}		
		}
	int query(int x,int y)
		{
		x+=BASE-1;
		y+=BASE+1;
		int ret=1e9+1;
		while(x/2!=y/2)
			{
			if(x%2==0)mini(ret, t[x+1]);
			if(y%2==1)mini(ret, t[y-1]);
			x/=2;
			y/=2;
			}
		return ret;
		}
	} bigger,lower(0);
main()
{
scanf("%d%d%d",&n,&q,&k);
FOR(i,1,n)
	{
	scanf("%d",&a);
	biggerkdiv2[i]=(a>k/2)+biggerkdiv2[i-1];
	if(a>k/2)
		bigger.insert(i,a);
	else
		lower.insert(i,-a);
	}
FOR(i,1,q)
	{
	scanf("%d%d",&a,&b);
	int res=cntbigger(a,b)-1;
	if(res==-1)
		{
		puts("0");
		continue;
		}
	if(bigger.query(a, b) + (-lower.query(a, b)) > k) 
		res++;
	printf("%d\n",res);
	}
}
