#include <cstdio>
#include <iostream>
#include <algorithm>

typedef unsigned long long int ull;
const ull P = 1000000007;

ull pref[1006], suf[1006];
int t[1006], r[1006];
ull powP[1006];

ull min_hash(int n, int p)
{
	std::sort(t, t+n);
	r[0] = p - t[n-1] + t[0];
	for (int i = 1; i < n; i++)
		r[i] = t[i] - t[i-1];
	
	pref[0] = r[0];
	suf[n-1] = r[n-1];
	for (int i = 1; i < n; i++)
		pref[i] = pref[i-1] * P + r[i];
	
	ull curPow = P;
	for (int i = n-2; i >= 0; i--)
	{
		suf[i] = r[i] * curPow + suf[i+1];
		curPow *= P;
	}
	
	ull result = pref[n-1];
	for (int i = 0; i < n-1; i++)
		result = std::min(result, suf[i+1] * powP[i+1] + pref[i]);
	return result;
}

ull hashe[1006];

int main()
{
	powP[0] = 1;
	for (int i = 1; i <= 1005; i++)
		powP[i] = powP[i-1] * P;
	
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &t[j]);
		hashe[i] = min_hash(m, p);
	}
	std::sort(hashe, hashe+n);
	int l = 1, result = 0;
	for (int i = 1; i < n; i++)
		if (hashe[i] != hashe[i-1])
		{
			result += l * (l-1);
			l = 1;
		}
		else
			l++;
	result += l * (l-1);
	printf("%d\n", result / 2);
}