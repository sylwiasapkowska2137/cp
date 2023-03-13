#include <bits/stdc++.h>
using namespace std;

void jebnij()
{
	printf("KURWA\n");
	assert(0);
}

int n, q;

map < pair <int,int> , int> mapa;

int main()
{
	scanf("%d%d", &n, &q);
	while(q--)
	{
		int p1, p2, p3;
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			scanf("%d%d%d", &p1, &p2, &p3);
			if (p2<p1)
				swap(p1, p2);
			if (p1<1)
				jebnij();
			if (p2>n)
				jebnij();
			if (p3<0)
				jebnij();
			if (p3>=1024)
				jebnij();
			if (mapa[{p1, p2}])
				jebnij();
			mapa[{p1, p2}]++;
			continue;
		}
		if (typ==2)
		{
			scanf("%d%d", &p1, &p2);
			if (p2<p1)
				swap(p1, p2);
			if (p1<1)
				jebnij();
			if (p2>n)
				jebnij();
			if (!mapa[{p1, p2}])
				jebnij();
			mapa[{p1, p2}]--;
			continue;
		}
		if (typ==3)
		{
			scanf("%d%d%d", &p1, &p2, &p3);
			if (p2<p1)
				swap(p1, p2);
			if (p1<1)
				jebnij();
			if (p2>n)
				jebnij();
			if (p3<0)
				jebnij();
			if (p3>=1024)
				jebnij();
			continue;
		}
		jebnij();
	}
	int p1;
	if (scanf("%d", &p1)==1)
		jebnij();
	return 0;
}
