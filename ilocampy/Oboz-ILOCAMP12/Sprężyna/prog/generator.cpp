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
	sprintf(query, "./spr < %s.in > %s.out", filename, filename);
	
	system(query);
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

void losowe(const char *filename, int ziarno, int n, int zakr)
{
	FILE *out = fopen(filename, "w");
	srand(ziarno);
	
	fprintf(out, "%d\n", n);
	for(int i=0; i<n; i++)
	{
	  int left = rand()%(zakr-3)+4;
	  int pom=0;
	  if(left % 2 == 1)
	    pom=1;
	  int right = rand()%(left-pom);
	  fprintf(out, "%d %d\n", left, right);
	}
	fclose(out);
}

int main(int argc, char *argv[])
{
	reczne("test/spr1.in", "6\n5 2\n8 8\n8 5\n10 9\n9 2\n3 3");
	answer("test/spr1");
	
	losowe("test/spr2.in", 123, 100, 100);
	answer("test/spr2");
	
	losowe("test/spr3.in", 998, 1000, 1000);
	answer("test/spr3");
	
	losowe("test/spr4.in", 9102, 5000, 5000);
	answer("test/spr4");
	
	losowe("test/spr5.in", 2323, 10000, 10000);
	answer("test/spr5");
	//
	losowe("test/spr6.in", 2929, 50000, 50000);
	answer("test/spr6");
	
	losowe("test/spr7.in", 8765, 150000, 1000000);
	answer("test/spr7");
	
	losowe("test/spr8.in", 556655, 300000, 1000000000);
	answer("test/spr8");
	
	losowe("test/spr9.in", 5555656, 278010, 1000000000);
	answer("test/spr9");
	
	losowe("test/spr10.in", 8877, 290900, 1000000000);
	answer("test/spr10");
	
	return 0;
}