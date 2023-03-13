#include <vector>
#include <cstdio>
#include <iostream>

#define PB push_back
#define SZ(x) (int)(x).size()

using namespace std;

int n, cnt, x;

bool Sito[1000005];
int T[1000005];
int Last[1000005];
long long Res[1000005];

vector <int> Index[1000005];

void Factor(int, int);
void Solve(vector<int>);
void Update(int, int, long long);

int main()
{
  for(int i = 2; i <= 1000; i++)
  {
    if(!Sito[i])
    {
      Last[i] = i;
      for(int j = i * i; j <= 1000000; j += i)
      {
        Sito[j] = 1;
        Last[j] = i;
      }
    }
  }
  for(int i = 2; i <= 1000000; i++)
  {
    if(!Sito[i])
    {
      Last[i] = i;
    }
  }
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &T[i]);
    Factor(i, T[i]);
  }
  for(int i = 2; i <= 1000000; i++)
  {
    if(!Sito[i])
    {
      Solve(Index[i]);
    }
  }
  for(int i = 1; i <= n; i++)
  {
    printf("%lld ", Res[i]);
  }
  printf("\n");
}

void Factor(int ind, int x)
{
  while(x != 1)
  {
    int div = Last[x];
    Index[div].PB(ind);
    while(x % div == 0)
    {
      x /= div;
    }
  }
}

void Solve(vector <int> V)
{
  V.PB(-1);
  int pocz = 0, kon = 0;
  long long sum = 0;
  while(kon != SZ(V))
  {
    if(V[kon] + 1 == V[kon + 1])
    {
      sum += T[V[kon++]];
    }
    else
    {
      Update(V[pocz], V[kon], sum + T[V[kon]]);
      pocz = ++kon;
      sum = 0;
    }
  }
}

void Update(int a, int b, long long sum)
{
  for(int i = a; i <= b; i++)
  {
    Res[i] = max(Res[i], sum);
  }
}