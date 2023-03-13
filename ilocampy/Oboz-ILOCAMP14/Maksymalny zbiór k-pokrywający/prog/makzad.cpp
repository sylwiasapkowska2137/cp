#include <bits/stdc++.h>
using namespace std;
 
int n, k;
 
vector < pair <int,long long> > graf[1000007];
 
pair <long long,int> dpt[1000007];
pair <long long,int> dpn[1000007];
 
long long bsa, bsb, bss;
 
pair <int,int> tak[1000007];
int bie[1000007];
 
pair <long long,int> dod(pair <long long,int> a, pair <long long,int> b)
{
	return {a.first+b.first, a.second+b.second};
}
 
pair <long long,int> por(pair <long long,int> a, pair <long long,int> b)
{
	if (a.first!=b.first)
		return max(a, b);
	return min(a, b);
}
 
void dfs(int v, int oj)
{
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i].first==oj)
			continue;
		dfs(graf[v][i].first, v);
	}
	dpt[v]={-bss, 1};
	dpn[v]={0, 0};
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i].first==oj)
			continue;
		int u=graf[v][i].first;
		long long w=graf[v][i].second;
		dpt[v]=dod(dpt[v], dod( por(dpt[u], dpn[u]) , {w, 0} ));
		dpn[v]=dod(dpn[v], por( dpn[u], dod(dpt[u], {w, 0}) ) );
	}
}
 
int lep(pair <long long,int> a, pair <long long,int> b)
{
	if (a.first!=b.first)
		return a>b;
	return a<b;
}
 
int gdz;
 
void odt(int v, int oj, int czy)
{
	gdz++;
	tak[v].second=v;
	tak[v].first=czy;
	if (czy)
	{
		for (int i=0; i<graf[v].size(); i++)
		{
			if (graf[v][i].first==oj)
				continue;
			int u=graf[v][i].first;
			long long w=graf[v][i].second;
		   
			if (lep(dpt[u], dpn[u]))
				odt(u, v, 1);
			else
				odt(u, v, 0);
		}
	}
	else
	{
		for (int i=0; i<graf[v].size(); i++)
		{
			if (graf[v][i].first==oj)
				continue;
			int u=graf[v][i].first;
			long long w=graf[v][i].second;
		   
			if (lep( dpn[u], dod(dpt[u], {w, 0}) ))
				odt(u, v, 0);
			else
				odt(u, v, 1);
		}
	}
}
 
int check()
{
	dfs(1, 0);
	return por(dpt[1], dpn[1]).second;
}
 
int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		long long p3;
		scanf("%d%d%lld", &p1, &p2, &p3);
		graf[p1].push_back({p2, p3});
		graf[p2].push_back({p1, p3});
		assert(p1!=p2);
	}
	bsa=0;
	bsb=(long long)n*10000000;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)/2;
		if (check()>k)
			bsa=bss+1;
		else
			bsb=bss;
	}
	bss=bsa;
	check();
	odt(1, 0, lep(dpt[1], dpn[1]));
	sort(tak+1, tak+1+n);
	reverse(tak+1, tak+1+n);
   
	long long wyn=0;
	for (int i=1; i<=k; i++)
		bie[tak[i].second]=1;
   
	for (int i=1; i<=n; i++)
		for (int j=0; j<graf[i].size(); j++)
			if (graf[i][j].first>i && (bie[i] || bie[graf[i][j].first]))
				wyn+=graf[i][j].second;
	printf("%lld\n", wyn);
	for (int i=1; i<=k; i++)
		printf("%d ", tak[i].second);
	printf("\n");
	return 0;
}
