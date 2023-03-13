#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	int k = atoi(argv[3]);
	
	srand(time(NULL) * n * m);
	
	printf("%d\n", n);
	long long int sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		int a = rand()%m + 1;
		sum += a;
		printf("%d ", a);
	}
	if (k && sum % n == 0)
		printf("%d\n", n);
	else if (k)
		printf("%lld\n", n - sum%n);
	else
		printf("%d\n", rand()%m + 1);
}