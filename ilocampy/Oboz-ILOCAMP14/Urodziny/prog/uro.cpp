#include <algorithm>
#include <iostream>
using namespace std;
int n,a,b,t[505],sum,w[50004],wyn;
int main()
{
	wyn=10000000;
	scanf("%d",&n);
	w[0]=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		t[i]=abs(a-b);
		sum+=t[i];
		for(int j=sum;j>=0;j--)
		{
			if (w[j]==1)
				w[j+t[i]]=1;
		}
	}
	for(int i=0;i<sum;i++)
		if (w[i]==1)
			wyn=min(wyn,abs(sum-i-i));
	printf("%d\n",wyn);
// 	system("pause");

}
