#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <memory.h>
#include <string.h>
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
	sprintf(query, "./rob < %s.in > %s.out", filename, filename);
	
	system(query);
	
#ifdef SHOW_RESULTS
	sprintf(query, "./rob < %s.in", filename);
	system(query);
#endif
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

std::vector<std::string> fibWords;

void prepareFibo()
{
	if (fibWords.empty())
	{
		fibWords.push_back("a");
		fibWords.push_back("b");
		for (int i = 3; i <= 26; i++)
		{
			std::string s = fibWords[fibWords.size()-1] + fibWords[fibWords.size()-2];
			fibWords.push_back(s);
		}
	}
}

void generuj(const char *filename, int n, int k, int m, int min, int max, int ziarno, bool odwroc)
{
	srand(ziarno);
	FILE *out = fopen(filename, "w");
	
	if (odwroc)
		k = n-k-1;
	
	int t[n];
	memset(t, 0, sizeof(t));
	fprintf(out, "%d %d %d\n", n, k, m);
	
	for (int i = 0; i < n; i++)
		t[(odwroc) ? n-i-1 : i] = random(min, max);
	
	for (int i = 0; i < n; i++)
		fprintf(out, "%d ", t[i]);
	fprintf(out, "\n");
	
	fclose(out);
}

char query[666];

int main(int argc, char *argv[])
{
	reczne("test/rob1.in", "4 2 2\n1 5 1 5\n");
	reczne("test/rob2.in", "5 0 0\n100 9 8 7 6\n");
	
	generuj("test/rob3.in", 25, 10, 7, 1, 50, 2, 0);
	generuj("test/rob4.in", 25, 10, 7, 1, 50, 2, 1);
	
	generuj("test/rob5a.in", 1300, 123, 150, 1, 400, 3, 0);
	generuj("test/rob5b.in", 1300, 123, 150, 1, 400, 3, 1);
	
	generuj("test/rob6a.in", 5000, 1, 1000, 1, 700, 4, 1);
	generuj("test/rob6b.in", 5000, 1, 1000, 1, 700, 4, 0);
	
	generuj("test/rob9.in", 50000, 20, 30, 1, 800, 5, 0);
	generuj("test/rob10.in", 50000, 20, 30, 1, 800, 5, 1);
	
	generuj("test/rob11a.in", 87654, 87652, 87653, 1, 2, 6, 0);
	generuj("test/rob11b.in", 87654, 87652, 87653, 1, 2, 6, 1);
	
	generuj("test/rob12a.in", 127654, 87652, 87653, 500, 976, 7, 1);
	generuj("test/rob12b.in", 127654, 87652, 87653, 500, 976, 7, 0);
	
	generuj("test/rob13.in", 230876, 111111, 100000, 678, 1000, 8, 0);
	
	generuj("test/rob14.in", 230876, 230875, 100000, 678, 1000, 9, 0);
	
	generuj("test/rob15.in", 300000, 280000, 250000, 800, 1000, 10, 0);
	
	for (int i = 1; i <= 15; i++)
	{
		if (i == 5 || i == 6 || i == 11 || i == 12)
		{
			sprintf(query, "test/rob%da", i);
			answer(query);
			sprintf(query, "test/rob%db", i);
			answer(query);
		}
		else
		{
			sprintf(query, "test/rob%d", i);
			answer(query);
		}
	}
}