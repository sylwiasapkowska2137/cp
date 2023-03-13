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
	int a = rand()%m + 1; int b = std::min(a + rand()%(2*m) + m/2, 1000000000);
	
	printf("%d %d %d\n", n, a, b);
	while(n--)
	{
		printf("%d %d\n", rand()%k + 1, rand()%k + 1);
	}
}