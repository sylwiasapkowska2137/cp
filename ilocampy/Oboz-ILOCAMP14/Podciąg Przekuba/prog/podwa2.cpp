#include <bits/stdc++.h>
using namespace std;

int k;
int n, m;

int tabn[2007];
int tabm[2007];

vector <int> wyn;
vector <int> aktu;

int juz;
int jesz[2007];

void czys()
{
	juz=0;
	for (int i=1; i<=k; i++)
		jesz[i]=0;
}

void dorz(int v)
{
	if (jesz[v])
		return;
	juz++;
	jesz[v]=1;
	if (juz==k)
	{
		czys();
		aktu.push_back(v);
	}
}

void jebaj()
{
	int l1=0;
	int l2=0;
	czys();
	aktu.clear();
	for (int i=1; i<=n+m; i++)
	{
		if ((rand()%(n-l1+m-l2))<n-l1)
		{
			l1++;
			dorz(tabn[l1]);
		}
		else
		{
			l2++;
			dorz(tabm[l2]);
		}
	}
	for (int i=1; i<=k; i++)
		dorz(i);
	if (aktu.size()<wyn.size())
		wyn=aktu;
}

int main()
{
	srand(time(0));
	scanf("%d", &k);
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tabn[i]);
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
		scanf("%d", &tabm[i]);
	for (int i=1; i<=max(n, m)+1; i++)
		wyn.push_back(1);
	for (int h=1; h*(n+m+k+200)<=100000000; h++)
		jebaj();
	printf("%d\n", (int)wyn.size());
	for (int i=0; i<wyn.size(); i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}
