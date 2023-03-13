#include <cstdio>
#include <iostream>
#include <algorithm>

char ciag[1000006];

int main(int argc, char* argv[])
{
	int n, m, start_x, start_y, cur_x, cur_y, result = 0, pom_x, pom_y;
	
	scanf("%d%d%d%d%s\n", &n, &m, &start_x, &start_y, ciag);
	cur_x = start_x; cur_y = start_y; pom_x = pom_y = 0;
	for (int i = 0; i < m; i++)
	{
		if (ciag[i] == 'D')
		{
			cur_y--;
			pom_y--;
		}
		if (ciag[i] == 'G')
		{
			cur_y++;
			pom_y++;
		}
		if (ciag[i] == 'L')
		{
			cur_x--;
			pom_x--;
		}
		if (ciag[i] == 'P')
		{
			cur_x++;
			pom_x++;
		}
		
		if (cur_x > n || cur_x < 1 || cur_y > n || cur_y < 1)
		{
			result++;
			if (cur_x > n) cur_x = n;
			if (cur_x < 1) cur_x = 1;
			if (cur_y > n) cur_y = n;
			if (cur_y < 1) cur_y = 1;
		}
	}
// 	printf("%d ", std::abs(pom_x) + std::abs(pom_y)); // heura
	printf("%d\n", std::abs(cur_x-start_x) + std::abs(cur_y-start_y) + result);
}