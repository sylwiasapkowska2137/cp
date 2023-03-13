#include <bits/stdc++.h>
using namespace std;

const int d=10;
int pier[2007];

int n, m, q, z;

int kraa[1000007];
int krab[1000007];
int krap[1000007];
int krak[1000007];
int krax[1000007];

int zapa[1000007];
int zapb[1000007];
int zapc[1000007];
int zapx[1000007];
int zapw[1000007];

map < pair <int,int> , int > mapa;

int czyzap[1000007];

int n1;
vector <int> edges[1100007];

vector <int> toroll[30];

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

vector <int> oj[1000007];
vector <int> roz[1000007];
vector <int> wiel[1000007];
vector <mac> gauss[1000007];

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

void read_input()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=q; i++)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			m++;
			scanf("%d%d%d", &kraa[m], &krab[m], &krax[m]);
			if (kraa[m]>krab[m])
				swap(kraa[m], krab[m]);
			mapa[{kraa[m], krab[m]}]=m;
			krap[m]=i;
		}
		if (typ==2)
		{
			int p1, p2;
			scanf("%d%d", &p1, &p2);
			if (p1>p2)
				swap(p1, p2);
			krak[mapa[{p1, p2}]]=i;
			mapa.erase({p1, p2});
		}
		if (typ==3)
		{
			z++;
			scanf("%d%d%d", &zapa[z], &zapb[z], &zapx[z]);
			zapc[z]=i;
			czyzap[i]=z;
		}
	}
}

void delete_edges()
{
	for (map < pair <int,int> , int >::iterator it=mapa.begin(); it!=mapa.end(); it++)
	{
		q++;
		krak[it->second]=q;
	}
}

void throw_one(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		edges[v].push_back(w);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	throw_one((v<<1), a, (a+b)>>1, graa, grab, w);
	throw_one((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

void throw_on_tree()
{
	n1=1;
	while(n1<q)
		n1<<=1;
	for (int i=1; i<=m; i++)
		throw_one(1, 1, n1, krap[i], krak[i], i);
}

void init2()
{
	for (int i=1; i<=n; i++)
	{
		oj[i].push_back(i);
		roz[i].push_back(0);
		gauss[i].push_back(mac());
		wiel[i].push_back(1);
	}
}

pair <int,int> fin(int v)
{
	int ret=0;
	while(oj[v].back()!=v)
	{
		ret^=roz[v].back();
		v=oj[v].back();
	}
	return {v, ret};
}

void add_edge(int v, int g)
{
	pair <int,int> p;
	int ret=krax[v];
	int a, b;
	
	p=fin(kraa[v]);
	a=p.first;
	ret^=p.second;
	
	p=fin(krab[v]);
	b=p.first;
	ret^=p.second;
	
	if (a==b)
	{
		oj[a].push_back(a);
		roz[a].push_back(0);
		int wez=wiel[a].back();
		wiel[a].push_back(wez);
		mac wez2=gauss[a].back();
		wez2.dodaj(ret);
		gauss[a].push_back(wez2);
		
		toroll[g].push_back(a);
	}
	else
	{
		oj[a].push_back(a);
		oj[b].push_back(a);
		
		roz[a].push_back(0);
		roz[b].push_back(ret);
		
		int wez=wiel[a].back()+wiel[b].back();
		
		wiel[b].push_back(0);
		wiel[a].push_back(wez);
		
		mac wez2=merge(gauss[a].back(), gauss[b].back());
		
		gauss[a].push_back(wez2);
		gauss[b].push_back(mac());
		
		toroll[g].push_back(a);
		toroll[g].push_back(b);
	}
}

void rollback(int v)
{
	oj[v].pop_back();
	roz[v].pop_back();
	gauss[v].pop_back();
	wiel[v].pop_back();
}

void query(int v)
{
	pair <int,int> p;
	int ret=zapx[v];
	int a, b;
	
	p=fin(zapa[v]);
	a=p.first;
	ret^=p.second;
	
	p=fin(zapb[v]);
	b=p.first;
	ret^=p.second;
	
	if (a!=b)
		return;
	if (gauss[a].back().czy_zaw(ret))
		zapw[v]=1;
}

void walk_on_tree(int v, int a, int b, int g)
{
	for (int i=0; i<edges[v].size(); i++)
		add_edge(edges[v][i], g);
	if (a==b)
	{
		if (czyzap[a])
			query(czyzap[a]);
	}
	else
	{
		walk_on_tree((v<<1), a, (a+b)>>1, g+1);
		walk_on_tree((v<<1)^1, (a+b+2)>>1, b, g+1);
	}
	while(!toroll[g].empty())
	{
		rollback(toroll[g].back());
		toroll[g].pop_back();
	}
}

void write_res()
{
	for (int i=1; i<=z; i++)
	{
		if (zapw[i])
			printf("TAK\n");
		else
			printf("NIE\n");
	}
}

int main()
{
	init();
	read_input();
	delete_edges();
	throw_on_tree();
	init2();
	walk_on_tree(1, 1, n1, 0);
	write_res();
	return 0;
}
