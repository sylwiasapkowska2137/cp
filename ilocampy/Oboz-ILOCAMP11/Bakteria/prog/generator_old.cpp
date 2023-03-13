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
	sprintf(query, "./bak < %s.in > %s.out", filename, filename);
	
	system(query);
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

void losowe(const char *filename, int ziarno, int n)
{
	FILE *out = fopen(filename, "w");
	srand(ziarno);
	
	int z_a = n/2 + rand()%(n/2);
	fprintf(out, "%d %d %d", z_a, rand()%z_a+1, rand()%z_a+1);
	
	fclose(out);
}

int main(int argc, char *argv[])
{
	reczne("test/bak1.in", "10 1 1");
	answer("test/bak1");
	
	reczne("test/bak2.in", "30 12 19");
	answer("test/bak2");
	
	reczne("test/bak3.in", "100 12 1");
	answer("test/bak3");
	
	losowe("test/bak4.in", 3601, 5000);
	answer("test/bak4");
	
	losowe("test/bak5.in", 88889, 100000);
	answer("test/bak5");
	//
	losowe("test/bak6.in", 1111, 1000000000);
	answer("test/bak6");
	
	losowe("test/bak7.in", 132, 1000000000);
	answer("test/bak7");
	
	losowe("test/bak8.in", 232323, 1000000000);
	answer("test/bak8");
	
	losowe("test/bak9.in", 5555656, 1000000000);
	answer("test/bak9");
	
	losowe("test/bak10.in", 963963, 1000000000);
	answer("test/bak10");
	
	return 0;
}