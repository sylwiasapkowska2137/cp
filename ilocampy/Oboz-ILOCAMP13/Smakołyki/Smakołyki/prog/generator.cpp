#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <memory.h>
#include <algorithm>

int t[1000010];

int random(int a, int b)
{
	return rand()%(b-a+1) + a;
}

void answer(const char *filename)
{
	char query[666];
	sprintf(query, "./sma < %s.in > %s.out", filename, filename);
	
	system(query);
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

void losowe(const char *filename, int ziarno, int n, int m)
{
	FILE *out = fopen(filename, "w");
	
	srand(ziarno);
	fprintf(out, "%d %d\n", n, m);
	while(n--)
	  fprintf(out, "%d ", rand()%m+1);
	fclose(out);
}

void powtorzenia(const char *filename, int ziarno, int n, int m)
{
	FILE *out = fopen(filename, "w");
	
	srand(ziarno);
	fprintf(out, "%d %d\n", n, m);
	for(int i=0; i<n; i++)
	{
	  if(rand()%3 == 0)
	  {
	    int powt = rand()%8+1;
	    int val = rand()%m+1;
	    while(i<n && powt--)
	    {
	      fprintf(out, "%d ", val);
	      i++;
	    }
	    i--;
	  }
	  else
	    fprintf(out, "%d ", rand()%m+1);
	}
	fclose(out);
}

void rozne(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");
	
	srand(ziarno);
	fprintf(out, "%d %d\n", n, n);
	for(int i = 0 ; i<n; i++)
	  t[i]=i+1;
	std::random_shuffle(t, t+n);
	for(int i = 0 ; i<n; i++)
	  fprintf(out, "%d ", t[i]);
	fclose(out);
}

void rozne2(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");
	
	srand(ziarno);
	fprintf(out, "%d %d\n", n, n-5);
	for(int i = 0 ; i<n; i++)
	  t[i]=i+1;
	for(int i=0; i<5; i++)
	  t[n-5+i]=rand()%(n-5)+1;
	std::random_shuffle(t, t+n);
	for(int i = 0 ; i<n; i++)
	  fprintf(out, "%d ", t[i]);
	fclose(out);
}

int main(int argc, char *argv[])
{
	reczne("test/sma1a.in", "5 5\n1 2 3 4 5\n");
	answer("test/sma1a");
	reczne("test/sma1b.in", "3 1\n1 1 1\n");
	answer("test/sma1b");
	
	losowe("test/sma2a.in", 2345123, 20, 5);
	answer("test/sma2a");
	reczne("test/sma2b.in", "6 2\n1 2 2 1 1 2\n");
	answer("test/sma2b");
	
	losowe("test/sma3a.in", 562, 5000, 4000);
	answer("test/sma3a");
	reczne("test/sma3b.in", "7 4\n1 2 3 4 3 2 1\n");
	answer("test/sma3b");
	
	losowe("test/sma4a.in", 2385, 5000, 500);
	answer("test/sma4a");
	rozne("test/sma4b.in", 7598, 5000);
	answer("test/sma4b");
	
	losowe("test/sma5a.in", 753956, 100000, 40000);
	answer("test/sma5a");
	powtorzenia("test/sma5b.in", 1235843, 100000, 9876);
	answer("test/sma5b");
	
	losowe("test/sma6a.in", 258364, 100000, 21000);
	answer("test/sma6a");
	rozne("test/sma6b.in", 15896, 100000);
	answer("test/sma6b");
	
	losowe("test/sma7a.in", 147854, 200000, 65000);
	answer("test/sma7a");
	powtorzenia("test/sma7b.in", 35974, 200000, 98200);
	answer("test/sma7b");
	
	rozne2("test/sma8.in", 35, 1000000);
	answer("test/sma8");
	
	losowe("test/sma9.in", 948, 1000000, 1000000);
	answer("test/sma9");
	
	rozne2("test/sma10.in", 55964, 1000000);
	answer("test/sma10");
	
	return 0;
}