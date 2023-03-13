#include <cstdio>
#include <iostream>
#include <algorithm>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ant = (std::max(std::max(a, b), c) + std::min(std::min(a, b), c)) / 2;
	ant = std::max(ant, 0);
	printf("%d\n", std::max(std::max(std::abs(ant-a), std::abs(ant-b)), std::abs(ant-c)));

}
