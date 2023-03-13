#include <cstdio>
#include <iostream>
#include <algorithm>
#include <assert.h>

int main()
{
	int n, a, b, res; long long int A, B;
	scanf("%d%lld%lld", &n, &A, &B);
	//assert(n >= 1 && n <= 500000 && A >= 1 && B >= 1 && A <= 1000000000 && B <= 1000000000);
	
	res = std::abs(A-B);
	while(n--)
	{
		scanf("%d%d", &a, &b);
		//assert(a >= 1 && a <= 1000 && b >= 1 && b <= 1000);
		
		A += a; B += b;
		res = std::min((long long int)res, std::abs(A-B));
	}
	printf("%d\n", res);
}