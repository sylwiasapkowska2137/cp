#include <cstdio>
#include <iostream>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", b/c - (a-1) / c);
}