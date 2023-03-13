#include <cstdio>
#include <iostream>
#include <algorithm>

int t[300006];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	std::sort(t, t+n);
	int l = 1;
	for (int i = 1; i < n; i++)
		if (t[i] != t[i-1])
			l++;
	printf("%d\n", (l == n) ? -1 : l+1);
}