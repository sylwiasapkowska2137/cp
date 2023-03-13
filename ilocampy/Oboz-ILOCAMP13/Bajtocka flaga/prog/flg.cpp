#include <cstdio>
#include <iostream>

int t[2][500006];
int max[2][2] = {{0, 0}, {0, 0}};

int main()
{
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		t[i%2][a]++;
	}
	for (int p = 0; p < 2; p++)
		for (int i = 1; i <= n; i++)
		{
			if (t[p][i] >= t[p][max[p][0]])
			{
				max[p][1] = max[p][0];
				max[p][0] = i;
			}
			else if (t[p][i] > t[p][max[p][1]])
				max[p][1] = i;
		}
	if (max[0][0] != max[1][0])
		printf("%d\n", n - (t[0][max[0][0]] + t[1][max[1][0]]));
	else 
		printf("%d\n", n - (std::max(t[0][max[0][0]] + t[1][max[1][1]], t[0][max[0][1]] + t[1][max[1][0]])));
}