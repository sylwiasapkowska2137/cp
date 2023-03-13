#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <memory.h>
#include <string.h>
#include <algorithm>
#include <assert.h>

//#define SHOW_RESULTS

const int MAXN = 300006;

int random(int a, int b)
{
	return rand()%(b-a+1) + a;
}

void answer(const char *filename)
{
	char query[666];
	sprintf(query, "./jed < %s.in > %s.out", filename, filename);
	
	system(query);
	
#ifdef SHOW_RESULTS
	sprintf(query, "./jed < %s.in", filename);
	system(query);
#endif
}

char query[666];

int main(int argc, char *argv[])
{
	for (int i = 1; i <= 10; i++)
	{
		sprintf(query, "jed%da", i);
		answer(query);
		sprintf(query, "jed%db", i);
		answer(query);
		sprintf(query, "jed%dc", i);
		answer(query);
		if (i <= 3 || i >= 8)
		{
			sprintf(query, "jed%dd", i);
			answer(query);
		}
	}
}