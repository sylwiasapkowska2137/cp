//https://www.codechef.com/viewsolution/5420879
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<vector>
#include<map>
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define ff first
#define ss second
#define ll long long
#define pii pair< int, int >
#define MEM(p, v) memset(p, v, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define S system("pause")
#define INF int(1e9)
#define MAX_5 int(1e5+5)
#define MAX_6 int(1e6+6)
#define ll long long
using namespace std;
ll a[MAX_5],v[MAX_5],b[MAX_5],R[MAX_5],L[MAX_5],tree[MAX_6],d,i,m,ans,k,l,j,q,x,n,ma,mi,MaxVal=100000,z,y,Q,ans1,ans2,ans3;
string s;
ll h[350][MAX_5];
void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
ll read(int idx){
	ll sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int main()
{
 
		  cin>>n;
		  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		  for(int i=1;i<=n;i++)b[i]+=b[i-1]+a[i];
		  for(int i=1;i<=n;i++)scanf("%lld%lld",&L[i],&R[i]);
		  for(int i=1;i<=n;i++)update(i,a[i]);
		  
		  d=319;//cout<<d<<endl;
		  
          for(i=1;i<=n;i++)
          {
          	h[i/d][L[i]]++;
          	h[i/d][R[i]+1]--;
          }
          for(i=0;i<=n/d;i++)
            for(j=1;j<=n;j++)h[i][j]+=h[i][j-1];
          
          
          for(i=1;i<=n;i++)
          {
          	k=0;
          	for(;i<=n;i++)
          	{
			    k+=read(R[i])-read(L[i]-1);
          		if((i+1)/d!=i/d)break;
			}
          	
          	v[i/d]=(k);
          }
     //     for(i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
          
          cin>>Q;
          
		  for(int i=1;i<=Q;i++)
		  {
		  	ans=0;
		  	cin>>z>>x>>y;
		  	if(z==1)
		  	{
		  		update(x,y-a[x]);
		  		
		  		for(int i=0;i<=n/d;i++)		  		
		  		   v[i]=v[i]+(y-a[x])*h[i][x];
		  		a[x]=y;
		  	}else
		  	{
		  		if(x/d==y/d)
		  		{
		  			for(int j=x;j<=y;j++)ans+=read(R[j])-read(L[j]-1);
		  			printf("%lld\n",ans);
		  			continue;
		  		}
		  		for(int j=x;j<=n;j++)
		  		{
		  			ans+=read(R[j])-read(L[j]-1);
		  			if((j+1)/d!=j/d)break;
		  		}
		  		for(int j=y;j>=1;j--)
		  		{
		  	//		cout<<j<<"=";
		  			ans+=read(R[j])-read(L[j]-1);
		  			if((j-1)/d!=j/d)break;
		  		}
		  	//	cout<<endl;
		  		for(int j=x/d+1;j<y/d;j++)ans+=v[j];
		  	//	cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
		  		printf("%lld\n",ans);
		  	}
		  }
}  
