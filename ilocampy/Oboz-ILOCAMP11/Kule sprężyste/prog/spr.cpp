#include <cstdio>
#include <iostream>
#include <queue>

char s[1000006];

int main(int argc, char* argv[])
{
	long long int res = 0; int n;
	std::queue<int> q;
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L' && q.empty())
			continue;
		if (s[i] == 'P')
			q.push(i);
		if (s[i] == 'L')
		{
			res += q.size();
			s[q.front()] = 'L'; q.pop();
			s[i] = 'P'; q.push(i);
		}
	}
	printf("%lld\n%s\n", res, s);
}
