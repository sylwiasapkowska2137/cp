#include <cstdio>
#include <iostream>
#include <cmath>
#include <assert.h>

typedef long long int lld;

int main()
{
	int a, b;
	long long int A, B, c;
	int z;
	scanf("%d", &z);
	//assert(z <= 100000);
	while(z--)
	{
		scanf("%d%d%lld", &a, &b, &c);
		//assert(a <= 1000000 && b <= 1000000 && c <= 1000000000000000000LL && a >= 1 && b >= 1 && c >= 1);
		
		if ((lld)a * b >= c)
		{
			A = a;
			B = b;
		}
		else if ((lld)std::max(a, b) * std::max(a, b) >= c)
		{
			A = std::max(a, b);
			B = c/A;
			if (A*B < c) B++;
		}
		else
		{
			A = sqrt(c);
			B = A;
			if (A*A < c) A++;
			if (A*B < c) B++;
		}
		printf("%lld\n", B-b + A-a);
	}
}