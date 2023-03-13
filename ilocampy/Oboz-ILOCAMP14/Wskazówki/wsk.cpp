#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define PB push_back
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()

typedef long long LL;
typedef long double LD;
typedef unsigned int UD;
typedef unsigned long long int ULL;

using namespace std;

ULL P = 1e9+7, powP = 1;

int ilosc, wskazowki, p, ile, res, d;
int T[1000000];

vector <int> V[10000];
priority_queue <ULL> Q;

void HASZUJ(int);

int main()
{
	scanf("%d %d %d", &ilosc, &wskazowki, &p);
	for(int i = 1; i < wskazowki; i++)
		powP *= P;
	for(int i = 1; i <= ilosc; i++)
	{
		for(int j = 1; j <= wskazowki; j++)
			scanf("%d", &T[j]);
		sort(T+1,T+wskazowki+1);
		T[wskazowki+1] = T[1] + p;
		for(int j = 1; j <= wskazowki; j++)
			V[i].PB(abs(T[j]-T[j+1]));
		for(int j = 0; j < wskazowki; j++)
			V[i].PB(V[i][j]);
		HASZUJ(i);
	}
	while(!Q.empty())
	{
		ULL pom = Q.top();
		ile = 0;
		while(!Q.empty() && Q.top() == pom)
		{
			ile++;
			Q.pop();
		}
		res += (ile*(ile-1))/2;
	}
	printf("%d\n", res);
}

void HASZUJ(int i)
{
	ULL wyn = 0;
	ULL hasz = 0;
	for(int j = 0; j < wskazowki; j++)
	{
		hasz *= P;
		hasz += V[i][j];
	}
	wyn = hasz;
	for(int j = wskazowki; j < SZ(V[i]); j++)
	{
		hasz -= powP * V[i][j-wskazowki];
		hasz *= P;
		hasz += V[i][j];
		wyn ^= hasz;
	}
	Q.push(wyn);
}

