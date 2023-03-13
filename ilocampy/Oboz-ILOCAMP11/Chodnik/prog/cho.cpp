#include <cstdio>
#include <iostream>

int main()
{
	int n, a;
	scanf("%d", &n);
	long long int s = ((long long int)n*n+n)/2;
	while(--n)
	{
		scanf("%d", &a);
		s -= a;
	}
	printf("%lld\n", s);
}