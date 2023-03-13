#include <cstdio>
#include <iostream>

using namespace std;

int n, x, tests;
long long k;

bool Sito[1000005];
int Last[1000005];
int Count[1000005];
int Test[1000005];

int Solve(long long);

int main()
{
  for(int i = 2; i <= 1000; i++)
  {
    if(!Sito[i])
    {
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
  }
  scanf("%d", &tests);
  while(tests--)
  {
    bool duba = false;
    scanf("%d %lld", &n, &k);
    for(int i = 1; i <= n; i++)
    {
      scanf("%d", &x);
      if(x == 0) duba = true;
      else
      {
        while(x != 1)
        {
          if(Test[Last[x]] != tests)
          {
            Test[Last[x]] = tests;
            Count[Last[x]] = 0;
          }
          Count[Last[x]]++;
          x /= Last[x];
        }
      }
    }
    printf("%d\n", duba ? 0 : Solve(k));
  }
}

int Solve(long long x)
{
  int res = 1000000000;
  for(int i = 2; i <= 100000; i++)
  {
    if(!Sito[i])
    {
      int cnt = 0;
      while(x % i == 0)
      {
        x /= i;
        cnt++;
      }
      if(cnt != 0)
      {
        res = min(res, Count[i] / cnt);
      }
    }
  }
  return res;
}


