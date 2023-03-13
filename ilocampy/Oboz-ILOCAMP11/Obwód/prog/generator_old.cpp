#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <memory.h>
#include <algorithm>

const int MAX=1000000000;

int random(int a, int b)
{
	return rand()%(b-a+1) + a;
}

void answer(const char *filename)
{
	char query[666];
	sprintf(query, "./obw < %s.in > %s.out", filename, filename);
	
	system(query);
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

void losowe(const char *filename, int ziarno, int zakr)
{
	FILE *out = fopen(filename, "w");
	srand(ziarno);
	fprintf(out, "%d", rand()%zakr+1);
	fclose(out);
}

int main(int argc, char *argv[])
{	
// 	a - duzo dzielnikow
// 	b - liczba pierwsza
// 	c - liczba losowa
//      d - kwadrat/przypadek brzegowy
	
	reczne("test/obw1a.in", "100000");
	answer("test/obw1a");
	reczne("test/obw1b.in", "125863");
	answer("test/obw1b");
	losowe("test/obw1c.in", 87574, 100000);
	answer("test/obw1c");
	reczne("test/obw1d.in", "1");
	answer("test/obw1d");
	
	reczne("test/obw2a.in", "890000");
	answer("test/obw2a");
	reczne("test/obw2b.in", "744127");
	answer("test/obw2b");
	losowe("test/obw2c.in", 7848574, 1000000);
	answer("test/obw2c");
	reczne("test/obw2d.in", "100");
	answer("test/obw2d");
	
	reczne("test/obw3a.in", "524288");
	answer("test/obw3a");
	reczne("test/obw3b.in", "684433");
	answer("test/obw3b");
	losowe("test/obw3c.in", 9685731, 1000000);
	answer("test/obw3c");
	reczne("test/obw3d.in", "10000");
	answer("test/obw3d");
	
	reczne("test/obw4a.in", "602000");
	answer("test/obw4a");
	reczne("test/obw4b.in", "949523");
	answer("test/obw4b");
	losowe("test/obw4c.in", 1119967, 1000000);
	answer("test/obw4c");
	reczne("test/obw4d.in", "942841");
	answer("test/obw4d");
	
	reczne("test/obw5a.in", "999956100");
	answer("test/obw5a");
	reczne("test/obw5b.in", "999989191");
	answer("test/obw5b");
	losowe("test/obw5c.in", 12, MAX);
	answer("test/obw5c");
	reczne("test/obw5d.in", "1000000000");
	answer("test/obw5d");
	
	reczne("test/obw6a.in", "999908448");
	answer("test/obw6a");
	reczne("test/obw6b.in", "999991151");
	answer("test/obw6b");
	losowe("test/obw6c.in", 369, MAX);
	answer("test/obw6c");
	reczne("test/obw6d.in", "2");
	answer("test/obw6d");
	
	reczne("test/obw7a.in", "999966240");
	answer("test/obw7a");
	reczne("test/obw7b.in", "999994379");
	answer("test/obw7b");
	losowe("test/obw7c.in", 6984584, MAX);
	answer("test/obw7c");
	reczne("test/obw7d.in", "961000000");
	answer("test/obw7d");
	
	reczne("test/obw8a.in", "999969300");
	answer("test/obw8a");
	reczne("test/obw8b.in", "999995419");
	answer("test/obw8b");
	losowe("test/obw8c.in", 7538568, MAX);
	answer("test/obw8c");
	reczne("test/obw8d.in", "999999999");
	answer("test/obw8d");
	
	reczne("test/obw9a.in", "999949860");
	answer("test/obw9a");
	reczne("test/obw9b.in", "999998261");
	answer("test/obw9b");
	losowe("test/obw9c.in", 554666, MAX);
	answer("test/obw9c");
	reczne("test/obw9d.in", "101010101");
	answer("test/obw9d");
	
	reczne("test/obw10a.in", "999999000");
	answer("test/obw10a");
	reczne("test/obw10b.in", "999999929");
	answer("test/obw10b");
	losowe("test/obw10c.in", 332211, MAX);
	answer("test/obw10c");
	reczne("test/obw10d.in", "7");
	answer("test/obw10d");
	
	return 0;
}