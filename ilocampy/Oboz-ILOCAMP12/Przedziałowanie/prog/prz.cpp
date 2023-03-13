#include <cstdio>
#include <iostream>
#include <memory.h>

bool exist[1000006];

int main()
{
	int z, a, n, res;
	scanf("%d", &z);
	while(z--)
	{
		scanf("%d", &n);
		res = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			exist[a] = 1;
		}
		for (int i = 1; i <= 1000000; i++)
			if (exist[i] && !exist[i-1])
				res++;
		memset(exist, 0, sizeof(exist));
		printf("%d\n", res);
	}
}