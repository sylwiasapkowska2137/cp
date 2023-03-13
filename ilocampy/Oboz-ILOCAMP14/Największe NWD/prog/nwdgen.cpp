//Zadanie NWD, generator testow
#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;
int R(int a, int b){return rand()%(b-a+1)+a;}
int RW(int a, int d, int b){int e = d/a+1; if(d%a == 0)e--; int c = b/a; return a * (rand() % (c-e+1) + e);}
void generateOut(const char *testName)
{
	char buf[666];
	sprintf(buf, "./nwd < %sin > %sout",testName, testName);
	system(buf);
}
void GeneratePrint(const char *filename, const char *test)
{
    FILE *file;
    if(filename[0] != 0)
    {
	file = fopen(filename, "r");
	if(file) {fclose(file);return;}
	file = fopen(filename, "w");
	fprintf(stderr, "Generowanie: %s\n", filename);
    }
    else file = stdout;

    fprintf(file, "%s", test);

    if(filename[0] != 0) fclose(file);
    char filename2[50];
    sprintf(filename2, "%s", filename);
    int l = strlen(filename2);
    filename2[l - 1] = filename2[l - 2] = 0;
    generateOut(filename2);
}
void GenerateRandom(const char *filename, int seed, int n, int k, int Amin, int Amax)
{
    if(k > n || n > 1000000 || Amin > Amax || Amax > 1000000)
    {
      fprintf(stderr, "Blad argumentow\n");
      return;
    }
    FILE *file;
    if(filename[0] != 0)
    {
	file = fopen(filename, "r");
	if(file) {fclose(file);return;}
	file = fopen(filename, "w");
	fprintf(stderr, "Generowanie: %s\n", filename);
    }
    else file = stdout;
    srand(seed);
    
    fprintf(file, "%d %d\n", n, k);
    for(int i=1; i<=n; i++)
      fprintf(file, "%d ", R(Amin, Amax));
    
    if(filename[0] != 0)
      fclose(file);
    char filename2[50];
    sprintf(filename2, "%s", filename);
    int l = strlen(filename2);
    filename2[l - 1] = filename2[l - 2] = 0;
    generateOut(filename2);
}


void GenerateRandom2(const char *filename, int seed, int n, int k, int ans, int Amin, int Amax)
{
  if(k >= n || n > 1000000 || Amin > Amax || Amax > 1000000)
    {
      fprintf(stderr, "Blad argumentow\n");
      return;
    }
    FILE *file;
    if(filename[0] != 0)
    {
	file = fopen(filename, "r");
	if(file) {fclose(file);return;}
	file = fopen(filename, "w");
	fprintf(stderr, "Generowanie: %s\n", filename);
    }
    else file = stdout;
    srand(seed);
    
    fprintf(file, "%d %d\n", n, k);
    int tab[n+5];
    for(int i=1; i<=k+1; i++)
      tab[i] = RW(ans, Amin, Amax);
    for(int i=k+2; i<=n; i++)
      tab[i] = R(Amin, Amax);
    random_shuffle(tab+1, tab+1+n);
    for(int i=1; i<=n; i++)
      fprintf(file, "%d ", tab[i]);
    if(filename[0] != 0)
      fclose(file);
    char filename2[50];
    sprintf(filename2, "%s", filename);
    int l = strlen(filename2);
    filename2[l - 1] = filename2[l - 2] = 0;
    generateOut(filename2);
}

int main()
{
  GeneratePrint("test/nwd1a.in", "10 4\n5 3 7 8 6 9 4 2 4 6");
  GenerateRandom("test/nwd1b.in", 102, 15, 2, 1, 20);
  GenerateRandom2("test/nwd1c.in", 103, 15, 5, 4 , 1, 20);
  GeneratePrint("test/nwd1d.in", "1 1\n1");
  GenerateRandom2("test/nwd2a.in", 201, 500, 30, 54, 10, 1000);
  GenerateRandom("test/nwd2b.in", 202, 500, 14, 100, 1000);
  GenerateRandom2("test/nwd2c.in", 203, 500, 200, 33, 20, 2000);
  
  GenerateRandom2("test/nwd3a.in", 301, 1000, 50, 82, 1, 2000);
  GenerateRandom("test/nwd3b.in", 302, 1000, 13, 1, 2000);
  GenerateRandom2("test/nwd3c.in", 303, 1000, 300, 132, 50, 2000);
  
  GenerateRandom2("test/nwd4a.in", 401, 20000, 100, 637, 10, 100000);
  GenerateRandom("test/nwd4b.in", 402, 20000, 40, 1, 100000);
  GenerateRandom2("test/nwd4c.in", 403, 20000, 5000, 4314, 100, 100000);
  
  GenerateRandom2("test/nwd5a.in", 501, 100000, 143,  1029, 1, 500000);
  GenerateRandom("test/nwd5b.in", 502, 100000, 55, 1, 500000);
  GenerateRandom2("test/nwd5c.in", 503, 100000, 13311, 113214, 1, 500000);
  
  GenerateRandom2("test/nwd6a.in", 601, 100000, 214, 37, 1, 500000);
  GenerateRandom("test/nwd6b.in", 602, 100000, 41, 1, 500000);
  GenerateRandom2("test/nwd6c.in", 603, 100000, 30000, 97, 1, 500000);
  
  GenerateRandom2("test/nwd7a.in", 701, 100000, 3124,  135, 1, 500000);
  GenerateRandom("test/nwd7b.in", 702, 100000, 516, 1, 500000);
  GenerateRandom2("test/nwd7c.in", 703, 100000, 1947, 9362, 1, 500000);
  
  GenerateRandom2("test/nwd8a.in", 801, 100000, 1000, 4156, 250000, 500000);
  GenerateRandom("test/nwd8b.in", 802, 100000, 100, 1, 1000000);
  GenerateRandom2("test/nwd8c.in", 803, 100000, 15000, 10315, 250000, 500000);
  GenerateRandom2("test/nwd8d.in", 804, 100000, 80000, 7133, 250000, 500000);
  
  GenerateRandom2("test/nwd9a.in", 901, 1000000, 10000, 157, 750000, 1000000);
  GenerateRandom("test/nwd9b.in", 902, 1000000, 13510, 1, 1000000);
  GenerateRandom2("test/nwd9c.in", 903, 1000000, 245281, 19511, 750000, 1000000);
  GenerateRandom2("test/nwd9d.in", 904, 1000000, 813571, 183941, 750000, 1000000);
  
  GenerateRandom2("test/nwd10a.in", 1001, 1000000, 31511, 134, 950000, 1000000);
  GenerateRandom("test/nwd10b.in", 1002, 1000000, 2,  1, 1000000);
  GenerateRandom2("test/nwd10c.in", 1003, 1000000, 300000, 9317, 950000, 1000000);
  GenerateRandom2("test/nwd10d.in", 1004, 1000000, 900000, 33, 970000, 1000000);
  GenerateRandom("test/nwd10e.in", 1005, 1000000, 1000000, 999999, 1000000);
  return 0;  
}
