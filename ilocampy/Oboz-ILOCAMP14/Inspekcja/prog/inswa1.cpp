#include <bits/stdc++.h>
using namespace std;

int n, q;

multiset <long long> zbi[500007];
multiset <long long>::iterator it;
long long tab[500007];
long long aktu[500007];

long long suma;
long long wyn;

map < pair <int,int> , long long > mapa;

long long licz(long long d, long long k)
{
	if (d&1)
		return licz(d-1, k-1);
	return d/2;
}

void popraw(int v)
{
	wyn-=aktu[v];
	it=zbi[v].end();
	it--;
	aktu[v]=licz(tab[v], (*it));
	wyn+=aktu[v];
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		long long p3;
		scanf("%d%d%lld", &p1, &p2, &p3);
		if (p1>p2)
			swap(p1, p2);
		zbi[p1].insert(p3);
		zbi[p2].insert(p3);
		suma+=p3;
		tab[p1]+=p3;
		tab[p2]+=p3;
		mapa[{p1, p2}]=p3;
	}
	for (int i=1; i<=n; i++)
		popraw(i);
	printf("%lld\n", suma-wyn);
	scanf("%d", &q);
	while(q--)
	{
		int p1, p2;
		long long p3;
		scanf("%d%d", &p1, &p2);
		if (p1>p2)
			swap(p1, p2);
		p3=mapa[{p1, p2}];
		tab[p1]-=p3;
		tab[p2]-=p3;
		suma-=p3;
		zbi[p1].erase(zbi[p1].find(p3));
		zbi[p2].erase(zbi[p2].find(p3));
		scanf("%lld", &p3);
		mapa[{p1, p2}]=p3;
		tab[p1]+=p3;
		tab[p2]+=p3;
		suma+=p3;
		zbi[p1].insert(p3);
		zbi[p2].insert(p3);
		popraw(p1);
		popraw(p2);
		printf("%lld\n", suma-wyn);
	}
	return 0;
}
