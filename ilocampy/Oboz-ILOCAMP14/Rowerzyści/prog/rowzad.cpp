#include <bits/stdc++.h>
using namespace std;

int n;

long long tab1[100007];
long long tab2[100007];

int dos[100007];

long long mod=1000000007;
long long wyn=mod;
int wkol[100007];

int n1, n2;

vector < pair <long long,long long> > jed, dwa;
int szaf[17];
long long sil[17];

void check()
{
	long long dod=0;
	for (int i=n1+n2+1; i<=n; i++)
		dod=(dod+tab1[i]*tab2[dos[i]])%mod;
	jed.clear();
	dwa.clear();
	long long x, y;
	for (int h=sil[n1]; h; h--)
	{
		next_permutation(szaf+1, szaf+1+n1);
		x=dod;
		y=0;
		for (int i=1; i<=n1; i++)
		{
			x=(x+tab1[i]*tab2[dos[szaf[i]]])%mod;
			y=y*20+szaf[i];
		}
		jed.push_back({x, y});
	}
	for (int h=sil[n2]; h; h--)
	{
		next_permutation(szaf+1, szaf+1+n2);
		x=0;
		y=0;
		for (int i=1; i<=n2; i++)
		{
			x=(x+tab1[n1+i]*tab2[dos[n1+szaf[i]]])%mod;
			y=y*20+szaf[i]+n1;
		}
		dwa.push_back({x, y});
	}
	sort(jed.begin(), jed.end());
	sort(dwa.begin(), dwa.end());
	reverse(dwa.begin(), dwa.end());
	int g=0, gt;
	long long tu, tam;
	for (int i=0; i<jed.size(); i++)
	{
		tu=jed[i].first+dwa[g].first;
		if (tu>=mod)
			tu-=mod;
		while(1)
		{
			gt=g+1;
			if (gt==(int)dwa.size())
				gt=0;
			tam=jed[i].first+dwa[gt].first;
			if (tam>=mod)
				tam-=mod;
			if (tam<tu || (tam==tu && gt>g))
			{
				g=gt;
				tu=tam;
			}
			else
			{
				break;
			}
		}
		if (tu<wyn)
		{
			wyn=tu;
			x=jed[i].second;
			y=dwa[g].second;
			for (int j=n1; j>0; j--)
			{
				wkol[j]=dos[x%20];
				x/=20;
			}
			for (int j=n1+n2; j>n1; j--)
			{
				wkol[j]=dos[y%20];
				y/=20;
			}
			for (int j=n1+n2+1; j<=n; j++)
				wkol[j]=dos[j];
		}
	}
}

int main()
{
	srand(time(0));
	sil[0]=1;
	for (int i=1; i<=15; i++)
	{
		sil[i]=sil[i-1]*i;
		szaf[i]=i;
	}
	jed.reserve(400000);
	dwa.reserve(400000);
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab1[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab2[i]);
	n1=min(n/2, 9);
	n2=min((n+1)/2, 9);
	if (n<=14)
	{
		for (int i=0; i<(1<<(n+1)) && wyn; i+=2)
		{
			if (__builtin_popcount(i)!=n1)
				continue;
			int l1=0;
			int l2=n;
			for (int j=1; j<=n; j++)
			{
				if (i&(1<<j))
				{
					l1++;
					dos[l1]=j;
				}
				else
				{
					dos[l2]=j;
					l2--;
				}
			}
			check();
		}
	}
	else
	{
		while(wyn)
		{
			for (int i=1; i<=n; i++)
				dos[i]=i;
			random_shuffle(dos+1, dos+1+n);
			check();
		}
	}
	printf("%lld\n", wyn);
	for (int i=1; i<=n; i++)
		printf("%d ", wkol[i]);
	printf("\n");
    return 0;
}
