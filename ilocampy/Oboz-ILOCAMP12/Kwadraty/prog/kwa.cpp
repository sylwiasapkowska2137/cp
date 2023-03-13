#include <cstdio>
#include <iostream>

int dp[2][4];
int t[4];

int main()
{
	int n, cur = 0, prev = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		prev = cur;
		cur = !cur;
		for (int j = 0; j < 4; j++)
			scanf("%d", &t[j]);
		dp[cur][t[0]-1] = dp[prev][t[1]-1] + 1;
		dp[cur][t[1]-1] = dp[prev][t[0]-1] + 1;
		dp[cur][t[2]-1] = dp[prev][t[3]-1] + 2;
		dp[cur][t[3]-1] = dp[prev][t[2]-1];
	}
	printf("%d\n", std::min(std::min(dp[cur][0], dp[cur][1]), std::min(dp[cur][2], dp[cur][3])));
}