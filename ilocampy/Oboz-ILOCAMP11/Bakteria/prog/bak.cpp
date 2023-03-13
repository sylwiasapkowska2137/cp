#include <iostream>
#include <cstdio>
int n, m, a, b, x, y;
int main()
{
  scanf("%d %d %d", &n, &a, &b);
  x = std::max(n-a, a-1);
  y = std::max(n-b, b-1);
  printf("%d", x+y);
  return 0;
}