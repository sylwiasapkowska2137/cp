#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int odp = 2000000000, n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    if(n%i==0)
      odp=min(odp, 2*(n/i + i));
  printf("%d", odp);
  return 0;
}