//brut O(q * n log n)
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
int n,q,k,a,b;
const int MXN=1e6+6;
int in[MXN];
main()
{
scanf("%d%d%d",&n,&q,&k);
FOR(i,1,n)
	{
	scanf("%d",&in[i]);
	}
FOR(i,1,q)
	{
	scanf("%d%d",&a,&b);
	VI V;
	FOR(j,a,b)V.PB(in[j]);
	V.PB(0);
	V.PB(0);
	sort(ALL(V));
	int r=0;
	while(V.back()+V[V.size()-2]>k)V.pop_back(),r++;
	printf("%d\n",r);
	}

}
