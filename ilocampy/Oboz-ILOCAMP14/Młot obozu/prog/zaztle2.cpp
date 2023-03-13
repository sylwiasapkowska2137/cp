#include <bits/stdc++.h>
using namespace std;

const int d=10;
int pier[2007];

struct mac
{
	int tab[d];
	mac()
	{
		for (int i=0; i<d; i++)
			tab[i]=0;
	}
	void dodaj(int v)
	{
		for (int i=0; i<d; i++)
			if (v&(1<<i))
				v^=tab[i];
		if (!v)
			return;
		for (int i=0; i<d; i++)
			if (tab[i]&(1<<pier[v]) || i==pier[v])
				tab[i]^=v;
	}
	int czy_zaw(int v)
	{
		for (int i=0; i<d; i++)
			if (v&(1<<i))
				v^=tab[i];
		return (!v);
	}
	void wypisz()
	{
		for (int i=0; i<d; i++)
		{
			for (int j=0; j<d; j++)
				printf("%d", (tab[i]&(1<<j))>0);
			printf("\n");
		}
		printf("\n");
	}
};

mac merge(mac a, mac b)
{
	mac ret=a;
	for (int i=0; i<d; i++)
		if (b.tab[i])
			ret.dodaj(b.tab[i]);
	return ret;
}

void init()
{
	for (int i=0; i<(1<<d); i++)
	{
		pier[i]=-1;
		int v=(-i&i);
		while(v)
		{
			v>>=1;
			pier[i]++;
		}
	}
}

int n, q;

map <int,int> mapa[200007];

int ost[200007];
int doj[200007];
int l;

mac ter;

void dfs(int v, int x)
{
	if (ost[v]==l)
	{
		ter.dodaj(doj[v]^x);
		return;
	}
	ost[v]=l;
	doj[v]=x;
	for (map <int,int>::iterator it=mapa[v].begin(); it!=mapa[v].end(); it++)
		dfs(it->first, x^(it->second));
}

int main()
{
	init();
	scanf("%d%d", &n, &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int p1, p2, p3;
			scanf("%d%d%d", &p1, &p2, &p3);
			mapa[p1][p2]=p3;
			mapa[p2][p1]=p3;
		}
		if (typ==2)
		{
			int p1, p2;
			scanf("%d%d", &p1, &p2);
			mapa[p2].erase(p1);
			mapa[p1].erase(p2);
		}
		if (typ==3)
		{
			l++;
			ter=mac();
			int p1, p2, p3;
			scanf("%d%d%d", &p1, &p2, &p3);
			dfs(p1, p3);
			if (ost[p2]==l && ter.czy_zaw(doj[p2]))
				printf("TAK\n");
			else
				printf("NIE\n");
		}
	}
	return 0;
}
