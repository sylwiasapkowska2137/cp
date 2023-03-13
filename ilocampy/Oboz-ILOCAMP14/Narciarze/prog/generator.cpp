#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <memory.h>
#include <algorithm>

void answer(const char *filename)
{
	char query[666];
	sprintf(query, "./nar < %s.in > %s.out", filename, filename);
	
	system(query);
}

void takieSame(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");
	srand(ziarno);
	
	int val = rand()%n + 1;
	
	fprintf(out, "%d\n", n);
	for(int i=0; i<n; i++)
	  fprintf(out, "%d ", val);
	fclose(out);
}

void rozne(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");
	srand(ziarno);
	
	fprintf(out, "%d\n", n);
	for(int i=0; i<n; i++)
	  fprintf(out, "%d ", rand()%n + 1);
	fclose(out);
}

void losowe(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");
	srand(ziarno);
	
	int licznik = 0;
	fprintf(out, "%d\n", n);
	while(licznik < n)
	{
	   int powtorzenia = rand() % (n-licznik) + 1;
	   int val = rand()%n + 1;
	   while( licznik < n && powtorzenia)
	   {
	     fprintf(out, "%d ", val);
	     licznik++;
	     powtorzenia--;
	   }
	}
	
	fclose(out);
}

int main(int argc, char *argv[])
{
	losowe("test/nar1a.in", 12, 10);
	answer("test/nar1a");
	rozne("test/nar1b.in", 90, 10);
	answer("test/nar1b");
	takieSame("test/nar1c.in", 31, 10);
	answer("test/nar1c");
	
	losowe("test/nar2a.in", 154, 1000);
	answer("test/nar2a");
	rozne("test/nar2b.in", 111, 1000);
	answer("test/nar2b");
	takieSame("test/nar2c.in", 2213, 1000);
	answer("test/nar2c");
	
	losowe("test/nar3a.in", 544, 10000);
	answer("test/nar3a");
	rozne("test/nar3b.in", 1678, 10000);
	answer("test/nar3b");
	takieSame("test/nar3c.in", 9898, 10000);
	answer("test/nar3c");
	
	losowe("test/nar4a.in", 2901, 300000);
	answer("test/nar4a");
	rozne("test/nar4b.in", 6565, 300000);
	answer("test/nar4b");
	takieSame("test/nar4c.in", 85642, 300000);
	answer("test/nar4c");
	
	losowe("test/nar5a.in", 8001, 1000000);
	answer("test/nar5a");
	rozne("test/nar5b.in", 45465, 1000000);
	answer("test/nar5b");
	takieSame("test/nar5c.in", 68687, 1000000);
	answer("test/nar5c");
	
	losowe("test/nar6a.in", 23254, 1000000);
	answer("test/nar6a");
	rozne("test/nar6b.in", 7464, 1000000);
	answer("test/nar6b");
	takieSame("test/nar6c.in", 42642, 1000000);
	answer("test/nar6c");
	
	return 0;
}