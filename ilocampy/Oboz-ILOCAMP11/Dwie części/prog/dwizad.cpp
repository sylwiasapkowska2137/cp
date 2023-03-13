#include <cstdio>
#include <iostream>

const int MAXN = 300006;

int t[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	
	int current = -1, count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		if (i == 0)
			current = t[i];
		
		count += (current == t[i]) ? 1 : -1;
		if (count == -1)
		{
			current = t[i];
			count = 1;
		}
	}
	
	count = 0;
	for (int i = 0; i < n; i++)
		count += (t[i] == current);
	
	if (count*2 <= n)
		puts("0");
	else
	{
		int allCount = count, result = 0;
		count = 0;
		
		for (int i = 0; i < n-1; i++)
		{
			count += (t[i] == current);
			if (count * 2 > i + 1 && (allCount - count) * 2 > n - i - 1)
				result++;
		}
		
		printf("%d\n", result);
	}
}