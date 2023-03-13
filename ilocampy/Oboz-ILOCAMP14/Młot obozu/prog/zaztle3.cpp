#include <bits/stdc++.h>
using namespace std;

int n, q;

map <int,int> mapa[200007];

int l;
int dp[507][1040];

void dfs(int v, int x)
{
	if (dp[v][x]==l)
		return;
	dp[v][x]=l;
	for (map <int,int>::iterator it=mapa[v].begin(); it!=mapa[v].end(); it++)
		dfs(it->first, x^(it->second));
}

int main()
{
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
			int p1, p2, p3;
			scanf("%d%d%d", &p1, &p2, &p3);
			l++;
			dfs(p1, 0);
			if (dp[p2][p3]==l)
				printf("TAK\n");
			else
				printf("NIE\n");
		}
	}
	return 0;
}
