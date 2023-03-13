//Zadanie NWD, rozwiazanie brutalne O(n * sqrt A + A), A - najwieksza wartosc w ciagu. 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000005;
int n, k, x;
int cnt[N];
int main()
{
  scanf("%d%d", &n, &k);
  int MX = 0;
  for(int i=1; i<=n; i++)
  {
    scanf("%d", &x);
    MX = max(x, MX);
    int j;
    for(j=1; j*j <= x; j++)
    {
      if(x % j == 0)
      {
	cnt[j]++;
	cnt[x/j]++;
      }
    }
    j--;
    if(j * j == x)cnt[j]--;
  }
  for(int i=MX; i>=1; i--)
  {
    if(cnt[i] >= k)
    {
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}