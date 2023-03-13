#include <cstdio>
#include <iostream>

using namespace std;

int n, pocz = 1;

int T[1000005];
int Amm[1000005];
int Ile[1000005];
long long Res[1000005];
int Last[1000005];
long long Pref[1000005];
bool Sito[1000005];

void Factor(int, int);
void Update(int, int);

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
    if(!Sito[i]) Last[i] = i;
    Ile[0] += (!Sito[i]);
  }
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &T[i]);
    Pref[i] = Pref[i - 1] + T[i];
  }
  T[n + 1] = 1;
  for(int i = 1; i <= n + 1; i++)
  {
    Factor(T[i], 1);
    if(Ile[i - pocz + 1] == 0 || i == n)
    {
      Update(pocz, i - 1);
      while(Ile[i - pocz + 1] == 0)
      {
        Factor(T[pocz++], -1);
      }
    }
  }
  for(int i = 1; i <= n; i++)
  {
    printf("%d ", Res[i]);
  }
  printf("\n");
}

void Factor(int x, int val)
{
  while(x != 1)
  {
    int div = Last[x];
    while(x % div == 0)
    {
      x /= div;
    }
    Ile[Amm[div]]--;
    Amm[div] += val;
    Ile[Amm[div]]++;
  }
}

void Update(int a, int b)
{
  long long sum = Pref[b] - Pref[a - 1];
  for(int i = a; i <= b; i++)
  {
    Res[i] = max(Res[i], sum);
  }
}