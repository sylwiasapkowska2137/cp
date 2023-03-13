#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <memory.h>
#include <algorithm>

#define SHOW_RESULTS

const int MAXN = 300006;

int random(int a, int b)
{
	return rand()%(b-a+1) + a;
}

void answer(const char *filename)
{
	char query[666];
	sprintf(query, "./mon < %s.in > %s.out", filename, filename);
	
	system(query);
	
#ifdef SHOW_RESULTS
	sprintf(query, "./mon < %s.in", filename);
	system(query);
#endif
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

void generuj(const char *filename, int n, int ziarno, int tryb = 0)
{
	// 0 - random - ? 
	// 1 - takie same - -1
	// 2 - na przemian - 2
	// 3 - inna koncowka - 1
	// 4 - srodek x !x x - 2
	// 5 - kilka czesci - 0
	FILE *out = fopen(filename, "w");
	fprintf(out, "%d\n", n);
	srand(ziarno);
	
	if (tryb == 0)
	{
		for (int i = 0; i < n; i++)
			fprintf(out, "%d ", rand()%2);
	}
	if (tryb == 1)
	{
		int l = rand()%2;
		for (int i = 0; i < n; i++)
			fprintf(out, "%d ", l);
	}
	if (tryb == 2)
	{
		int l = rand()%2;
		for (int i = 0; i < n; i++)
			fprintf(out, "%d ", (i+l)%2);
	}
	if (tryb == 3)
	{
		int l = rand()%2;
		int place = rand()%3;
		for (int i = 0; i < n; i++)
			if ((i == 0 && place % 2 == 0) || (i == n-1 && place > 0)) 
				fprintf(out, "%d ", !l);
			else
				fprintf(out, "%d ", l);
	}
	if (tryb == 4)
	{
		int l = rand()%2;
		int place = random(1, n-2);
		for (int i = 0; i < n; i++)
				fprintf(out, "%d ", (i == place) ? !l : l);
	}
	if (tryb == 5)
	{
		bool change[n];
		memset(change, 0, sizeof(change));
		
		int changesCount = random(1, std::max(n/100, 2));
		
		while(changesCount--)
		{
			int place;
			do
			{
				place = random(2, n-3);
			} while(change[place-1] || change[place+1] || change[place-2] || change[place+2]);
			
			change[place] = true;
		}
		
		int cur = rand()%2;
		for (int i = 0; i < n; i++)
		{
			if (change[i])
				cur = !cur;
			
			fprintf(out, "%d ", cur);
		}
	}
	
	fprintf(out, "\n");
	fclose(out);
}

char query[666];

int main(int argc, char *argv[])
{
	reczne("test/mon1.in", "4\n1 0 0 1\n");
	reczne("test/mon2.in", "7\n1 0 1 0 1 0 1\n");
	reczne("test/mon3.in", "10\n1 1 1 1 1 1 1 1 1 1\n");
	reczne("test/mon4.in", "25\n1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0\n");
	generuj("test/mon5.in", 123, 1, 2);
	generuj("test/mon6.in", 456, 2, 3);
	generuj("test/mon7.in", 2500, 3, 0);
	generuj("test/mon8.in", 4000, 4, 1);
	generuj("test/mon9.in", 10000, 5, 5);
	generuj("test/mon10.in", 40000, 6, 4);
	generuj("test/mon11.in", 67333, 10, 3);
	generuj("test/mon12.in", 99567, 11, 1);
	generuj("test/mon13.in", 115000, 12, 4);
	generuj("test/mon14.in", 220000, 13, 2);
	generuj("test/mon15.in", 300000, 14, 5);
	generuj("test/mon16.in", 300000, 15, 0);
	
	for (int i = 1; i <= 16; i++)
	{
		sprintf(query, "test/mon%d", i);
		answer(query);
	}
}