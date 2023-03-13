#include <iostream>
#include <cstdio>

int n, d, k;

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    scanf("%d%d", &d, &k);
    if(k%2==0)
      d-=k/2;
    else
      d-=k/2 + 1 ;
    printf("%d\n", d);
  }
  return 0;
}