#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
long long res;

int T[1000006];
long long Res[1000006];

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &T[i]);
  }
  for(int i = 1; i <= n; i++)
  {
    int nwd = T[i];
    long long sum = 0;
    int j = i;
    for(; j <= n; j++)
    {
      nwd = __gcd(nwd, T[j]);
      if(nwd != 1)
      {
        sum += T[j];
      }
      else
      {
        j--;
        break;
      }
    }
    for(int l = i; l <= j; l++)
    {
      Res[l] = max(Res[l], sum);
    }
  }
  for(int i = 1; i <= n; i++)
  {
    printf("%lld ", Res[i]);
  }
  printf("\n");
} 