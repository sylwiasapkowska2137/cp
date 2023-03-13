//Zadanie NWD, rozwiazanie wzorcowe O(n log n)
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
    MX = max(MX, x);
    cnt[x]++;
  }
  
  int ans = 1;
  
  for(int i=2; i<=MX; i++)
  {
    int count = 0;
    for(int j=i; j<=MX; j+=i)
    {
      count += cnt[j];
      if(count >= k)
      {
	ans = i;
	break;
      }
    }
  }
  
  printf("%d", ans);
  return 0;
}