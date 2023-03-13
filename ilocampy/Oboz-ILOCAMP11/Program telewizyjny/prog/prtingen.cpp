#include "oi.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

const std::string ID = "prt";
oi::Random RG;
oi::Scanner in(stdin, oi::PL);

int randInt (int a, int b)
{
  return RG.rand() % (b - a + 1) + a;
}

// -----------------------------------------------------------------------------

const int maxN = 100000;
const int maxK = 100000;
const int maxT = 1000000;
const int maxA = 1000000;

int I;
int N;
int K;
int P[maxN + 1][3];

void print()
{
  char tmp[100] = {0};
  FILE *fin = 0;

  sprintf(tmp, "%s%d.in", ID.c_str(), I);
  fin = fopen(tmp, "w");

  fprintf(fin, "%d %d\n", N, K);
  for (int i = 1; i <= N; ++i)
  {
    fprintf(fin, "%d %d %d\n", P[i][0], P[i][1], P[i][2]);
  }

  fclose(fin);
}

void generate(int seed, int _I, int _N, int _K, int _maxT, int _maxD, int _maxA)
{
  RG.setSeed(seed);

  I = _I;
  N = _N;
  K = _K;
  memset(P, 0, sizeof(P));

  for (int i = 1; i <= N; ++i)
  {
    int length = randInt(2, _maxD);
    int begin = randInt(1, _maxT - length + 1);
    int end = begin + length - 1;
    int attractivity = randInt(1, _maxA);
    P[i][0] = begin;
    P[i][1] = end;
    P[i][2] = attractivity;
  }

  print();
}

int main()
{
  generate(101, 1, 10, 4, 20, 5, 20);
  generate(2131, 2, 20, 5, 50, 10, 100);
  generate(2293, 3, 20, 5, 50, 10, 100);
  generate(2437, 4, 1000, 100, 500, 10, 1000);
  generate(2621, 5, 1000, 100, 500, 10, 500);
  generate(2749, 6, 100000, 10000, 1000000, 100, 1000000);
  generate(2909, 7, 100000, 10000, 1000000, 100, 1000000);
  generate(3083, 8, 100000, 100000, 1000000, 100, 1000000);
  generate(3433, 9, 100000, 100000, 1000000, 100, 1000000);
  return 0;
}












