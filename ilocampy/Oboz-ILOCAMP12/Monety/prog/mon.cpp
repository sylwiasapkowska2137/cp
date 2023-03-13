#include <cstdio>
#include <iostream>

int main()
{
	int n;
	scanf("%d", &n);
	
	int result, maxChange;
	result = 0;
	maxChange = -1;
	
	int prev, cur, next;
	prev = cur = next = -1;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &next);
		if (i > 0)
			if (next == cur)
				result++;
			
		if (i > 1)
		{
			// !x (x) !x
			if (prev == next && next != cur)
				maxChange = 2;
			
			// x (x) !x lub !x (x) x
			if (prev != next && (cur == next || cur == prev))
				maxChange = std::max(maxChange, 0);
		}
		
		// (x) !x .. lub .. !x (x)
		if (i == 1 || i == n-1)
			if (next != cur)
				maxChange = std::max(maxChange, 1);
			
		prev = cur;
		cur = next;
	}
	
	printf("%d\n", result + maxChange);
}