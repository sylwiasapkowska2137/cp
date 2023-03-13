#include <bits/stdc++.h>
using namespace std;

int n;
map <int, long long> mapa[35][35][35][35];

long long rek(int k, int mas, int ost, int dol, int gor)
{
	if (k==n+1)
		return 1;
	mas>>=(dol+1);
	mas<<=(dol+1);
	if (mapa[k][dol][gor][ost+1].count(mas))
		return mapa[k][dol][gor][ost+1][mas];
	long long ret=0;
	int ndol=dol;
	int ngor;
	for (int i=dol; i<=gor; i++)
	{
		if (i>dol && mas&(1<<(i-1)))
			ndol=i-1;
		ngor=gor+(i>ost);
		ret+=rek(k+1, (mas|(1<<i)), i, ndol, ngor);
	}
	mapa[k][dol][gor][ost+1][mas]=ret;
	return ret;
}

int main()
{
	scanf("%d", &n);
	printf("%lld\n", rek(1, 0, -1, 0, 0));
	return 0;
}
