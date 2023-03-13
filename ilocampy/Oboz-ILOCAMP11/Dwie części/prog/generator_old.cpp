//#define SHOW_ANSWER

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <algorithm>
#include <memory.h>

const int MAXN = 1000006;

int random(int a, int b)
{
	return rand()%(b-a+1) + a;
}

void answer(const char *filename)
{
	char query[666];
	sprintf(query, "./dwizad < %s.in > %s.out", filename, filename);
	
	system(query);
	
#ifdef SHOW_ANSWER
	sprintf(query, "./dwizad < %s.in", filename);
	system(query);
#endif
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

// wszystkie takie same, wsrod nich M innych, K roznych wartosci, wszystko z przedzialu <MIN; MAX>
void generuj(const char *filename, int ziarno, int n, int m, int k, int min, int max)
{
	srand(ziarno);
	
	FILE *out = fopen(filename, "w");
	fprintf(out, "%d\n", n);
	
	int t[MAXN];
	memset(t, 0, sizeof(t));
	
	int a = random(min, max);
	for (int i = 0; i < n; i++)
		t[i] = a;
	
	int r[k];
	for (int i = 0; i < k; i++)
	{
		do
		{
			r[i] = random(min, max);
		} while(r[i] == a);
	}
	
	for (int i = 0; i < m; i++)
		t[i] = r[random(0, k-1)];
	
	std::random_shuffle(t, t+n);
	
	for (int i = 0; i < n; i++)
		fprintf(out, "%d ", t[i]);
	
	fprintf(out, "\n");
	fclose(out);
}

int main(int argc, char *argv[])
{
	reczne("test/dwi1a.in", "3\n-100 100 100\n");
	answer("test/dwi1a");
	reczne("test/dwi1b.in", "4\n100 100 100 100\n");
	answer("test/dwi1b");
	
	reczne("test/dwi2a.in", "10\n5 4 5 5 5 4 5 5 5 5\n");
	answer("test/dwi2a");
	reczne("test/dwi2b.in", "8\n5 5 4 5 4 5 4 4\n");
	answer("test/dwi2b");
	
	generuj("test/dwi3a.in", 1, 50, 20, 2, 100, 120);
	answer("test/dwi3a");
	generuj("test/dwi3b.in", 2, 100, 37, 1, -10, -5);
	answer("test/dwi3b");
	
	generuj("test/dwi4a.in", 1, 800, 100, 60, 1000, 1200);
	answer("test/dwi4a");
	generuj("test/dwi4b.in", 1, 1000, 505, 1, -1000000000, -100000000);
	answer("test/dwi4b");
	
	generuj("test/dwi5a.in", 10, 5000, 2300, 2, 999999999, 1000000000);
	answer("test/dwi5a");
	generuj("test/dwi5b.in", 3, 10000, 9000, 8000, 6000, 7000);
	answer("test/dwi5b");
	
	generuj("test/dwi6a.in", 11, 50000, 10000, 1, 0, 10);
	answer("test/dwi6a");
	generuj("test/dwi6b.in", 33, 75001, 37499, 1, -10, 0);
	answer("test/dwi6b");
	
	generuj("test/dwi7a.in", 123, 123321, 60000, 1, 10000000, 1000000000);
	answer("test/dwi7a");
	generuj("test/dwi7b.in", 123, 123321, 120000, 66066, 10000000, 1000000000);
	answer("test/dwi7b");
	
	generuj("test/dwi8.in", 1, 200001, 100000, 98000, -100000000, 100000000);
	answer("test/dwi8");
	
	generuj("test/dwi9.in", 1, 250000, 1, 1, 1, 2);
	answer("test/dwi9");
	
	generuj("test/dwi10a.in", 1, 300000, 149990, 1, -1000000000, -999999999);
	answer("test/dwi10a");
}