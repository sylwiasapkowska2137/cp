#include <cstdio>
#include <iostream>
#include <algorithm>

int t[1006][1006];
int r[1006];

int minLex(int x, int m)
{
	int i = 0, j = 1, k = 1, p = 1, a, b;
	while(j + k <= (m << 1))
	{
		a = t[x][(i + k - 1) % m];
		b = t[x][(j + k - 1) % m];
		if (a > b)
		{
			i = j++;
			k = p = 1;
		}
		else if (a < b)
		{
			j += k;
			k = 1;
			p = j - i;
		}
		else if (a == b && k != p)
			k++;
		else
		{
			j += p;
			k = 1;
		}
	}
	return i;
}

int M;
bool compare(int a, int b)
{
	int i = 0;
	while(i < M && t[a][i] == t[b][i]) i++;
	return t[a][i] < t[b][i];
}

bool equal(int a, int b)
{
	int i = 0;
	while(i < M && t[a][i] == t[b][i]) i++;
	return i == M;
}

int main()
{
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	M = m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &r[j]);
		std::sort(r, r+m);
		t[i][0] = p - r[m-1] + r[0];
		for (int j = 1; j < m; j++)
			t[i][j] = r[j] - r[j-1];
		for (int j = 0; j < m; j++)
			r[j] = t[i][j];
		
		int minLexR = minLex(i, m), cur = 0;
		for (int j = minLexR; j < m; j++)
			t[i][cur++] = r[j];
		for (int j = 0; j < minLexR; j++)
			t[i][cur++] = r[j];
	}
	
	int result = 0;
	for (int i = 0; i < n; i++)
		r[i] = i;
	std::sort(r, r+n, compare);
	
	int l = 1;
	for (int i = 1; i < n; i++)
		if (equal(r[i], r[i-1]))
			l++;
		else
		{
			result += l * (l-1);
			l = 1;
		}
	result += l * (l-1);
	printf("%d\n", result/2);
	
}