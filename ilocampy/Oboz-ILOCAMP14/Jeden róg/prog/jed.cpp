#include <iostream>
#include <cstdio>
using namespace std;

int n, x, odp;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &x);
			if(x==1) odp=max(odp, (n-i)*(n-j));
		}
	}
	printf("%d", odp);
	return 0;
}