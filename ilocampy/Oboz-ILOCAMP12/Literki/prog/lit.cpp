#include <cstdio>
#include <iostream>

char s[1000006];
int l[26][2];

int main()
{
	int n;
	scanf("%d%s", &n, s);
	
	for (int i = 0; i < 26; i++) l[i][0] = l[i][1] = -1;
	for (int i = 0; i < n; i++)
	{
		if (l[s[i]-'a'][0] == -1)
			l[s[i]-'a'][0] = i;
		l[s[i]-'a'][1] = i;
	}
	int res = 2000000000;
	for (int i = 0; i < 26; i++)
		if (l[i][0] != -1)
			res = std::min(res, l[i][0] + n - 1 - l[i][1]);
	printf("%d\n", res);
}