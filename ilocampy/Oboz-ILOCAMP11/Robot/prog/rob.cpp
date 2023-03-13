#include <cstdio>
#include <iostream>

const int MAXN = 300000;

int sum[MAXN+6];

int main()
{
	int n, start, k;
	scanf("%d%d%d", &n, &start, &k);
	
	start++;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	
	int result = 0;
	for (int i = std::max(1, start-k); i < n && i <= start+k; i++)
	{
		if (i >= start)
		{
			if ((i - start) * 2 < k)
				result = std::max(result, sum[i] - sum[std::max(0, start - (k - (i-start)*2))]);
			else
				result = std::max(result, sum[i] - sum[start-1]);
		}
		else
		{
			if ((start - i) * 2 < k)
				result = std::max(result, sum[std::min(n, start + (k - (start-i)*2))] - sum[i-1]);
			else
				result = std::max(result, sum[start] - sum[i-1]);
		}
	}
	
	printf("%d\n", result);
}