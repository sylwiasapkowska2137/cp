#define SHOW_ANSWER

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <assert.h>

typedef long long int lld;

const int MAXN = 1000006;

int t[MAXN];

lld random(lld a, lld b)
{
	lld r = (rand()%1000000000) * 1000000000LL + (rand()%1000000001);
	return r%(b-a+1) + a;
}

void answer(const char *filename)
{
	char query[666];
	sprintf(query, "./rza < %s.in > %s.out", filename, filename);
	
	system(query);
	
#ifdef SHOW_ANSWER
	sprintf(query, "printf \"%s:   \" && ./rza < %s.in", filename, filename);
	system(query);
#endif
}

void reczne(const char *filename, const char *test)
{
	FILE *out = fopen(filename, "w");
	fprintf(out, "%s", test);
	fclose(out);
}

void losowe(const char *filename, int n, int ziarno, lld min, lld max)
{
	srand(ziarno);
	
    FILE *out = fopen(filename, "w");
    fprintf(out, "%lld\n", random(min, max));
    fclose(out);
}

void reczneBin(const char *filename, const char *num)
{
	lld x = 0;
	for (int i = 0; num[i]; i++)
		x = (x << 1) + num[i] - '0';
	
	FILE *out = fopen(filename, "w");
    fprintf(out, "%lld\n", x);
    fclose(out);
}

// 50% // n <= 1 000 000
// 100$ // n <= 10^18

// 10^6
// 11110100001001000000

// 10^18
// 110111100000101101101011001110100111011001000000000000000001

int main(int argc, char *argv[])
{
	reczneBin("test/rza1a.in", "100110");
	reczneBin("test/rza1b.in", "111100");
	reczneBin("test/rza1c.in", "100000");
	
	reczneBin("test/rza2a.in", "1011011010110");
	reczneBin("test/rza2b.in", "1111111100");
	reczneBin("test/rza2c.in", "1010101010101");
	
	reczneBin("test/rza3a.in", "10011010111010101010");
	reczneBin("test/rza3b.in", "10011001100110011");
	reczneBin("test/rza3c.in", "1010101001011000000");
	
	reczneBin("test/rza4a.in", "10000001111101111011110101000011100000000000");
	reczneBin("test/rza4b.in", "11111111111111111111111111111111111111");
	reczneBin("test/rza4c.in", "10000000000000000000000000000000000000000000000000010");
	
	reczneBin("test/rza5a.in", "100010101010101010101010101010101010101010101010101010101100");
	reczneBin("test/rza5b.in", "100010101010101010101010101010101010101010101010101010101010");
	reczneBin("test/rza5c.in", "100010101010101010101010101010101010101010101010101010101011");
	
	reczneBin("test/rza6a.in", "110111100000101101101011001110100111011001000000000000000001");
	reczneBin("test/rza6b.in", "100101000000101001001010001010010101011001000000000000000001");
	reczneBin("test/rza6c.in", "100110110011001011011011010110110111010001101100101011001101");
	
	char query[666];
	for (int i = 1; i <= 6; i++)
		for (int j = 'a'; j <= 'c'; j++) {
			sprintf(query, "test/rza%d%c", i, j);
			answer(query);
		}
}



















