#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define PII pair <int, int>
const int mxn = 3e5 + 10;
const int SQRT = 550;

int n, m;
int t[mxn];
map <int, int> ID;
vector < pair <PII, int> > zap;

void wczytaj()
{
	scanf("%d%d", &n, &m);
	int curr = 0;
	ID[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
		if(ID.find(t[i]) == ID.end())
			ID[t[i]] = ++curr;
		
		t[i] = ID[t[i]];
	}
	
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		zap.push_back({{a, b}, i});
	}
}

bool cmp( pair < PII, int > A, pair < PII, int > B)
{
	auto a = A.fi;
	auto b = B.fi;
	
	if(a.fi / SQRT == b.fi / SQRT)
		return a.se < b.se;
	return a.fi < b.fi;
}

int wyn = 0;

int ile[mxn], odp[mxn];

void dodaj(int id)
{
	//printf("dodaje %d\n", id);
	if(t[id] == 0)
		return;
	
	ile[t[id]]++;
	//printf(" += %d\n", ile[t[id]] % 2);
	wyn += ile[t[id]] % 2;
}

void usun(int id)
{
	//printf("usuwam %d\n", id);
	if(t[id] == 0)
		return;
	
	//printf(" -= %d\n", ile[t[id]] % 2);
	wyn -= ile[t[id]] % 2;
	ile[t[id]]--;
}

int main()
{
	wczytaj();
	sort(zap.begin(), zap.end(), cmp);
	
	
	int pocz = 1, kon = 0;
	for(auto p : zap)
	{
		int a = p.fi.fi, b = p.fi.se, id = p.se;
		
		//printf("przedzial [%d %d]\n", a, b);
		
		while(kon < b)
		{
			kon++;
			dodaj(kon);
		}
		
		while(pocz > a)
		{
			pocz--;
			dodaj(pocz);
		}
		
		while(kon > b)
		{
			usun(kon);
			kon--;
		}
		
		while(pocz < a)
		{
			usun(pocz);
			pocz++;
		}
		odp[id] = wyn;
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", odp[i]);
}