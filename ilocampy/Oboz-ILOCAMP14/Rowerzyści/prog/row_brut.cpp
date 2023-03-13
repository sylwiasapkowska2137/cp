#include <bits/stdc++.h>
using namespace std;

int n;

long long tab1[100007];
long long tab2[100007];

int dos[100007];

long long mod=1000000007;
long long wyn=mod;
int wkol[100007];

long long x=0;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab1[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab2[i]);
	for (int i=1; i<=n; i++)
		dos[i]=i;
	for (int h=1; wyn; h++)
	{
		x=0;
		for (int i=1; i<=n; i++)
			x=(x+tab1[i]*tab2[dos[i]])%mod;
		if (x<wyn)
		{
			wyn=x;
			for (int i=1; i<=n; i++)
				wkol[i]=dos[i];
		}
		if (!next_permutation(dos+1, dos+1+n))
			break;
	}
	printf("%lld\n", wyn);
	for (int i=1; i<=n; i++)
		printf("%d ", wkol[i]);
	printf("\n");
    return 0;
}
