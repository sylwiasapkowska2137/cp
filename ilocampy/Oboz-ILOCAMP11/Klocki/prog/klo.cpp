#include <cstdio>
#include <iostream>
#include <algorithm>

int t[400006];

int main()
{
	int n; long long int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		sum += t[i];
	}
	
	if (sum%n)
	{
		puts("NIE");
		return 0;
	}
	
	long long int result = 0, sr = sum / n;
	for (int i = 0; i < n; i++)
		if (t[i] > sr)
			result += t[i] - sr;
	
	printf("%lld\n", result);
}