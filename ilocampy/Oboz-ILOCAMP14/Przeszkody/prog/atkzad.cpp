#include <cstdio>
#include <iostream>

using namespace std;

int n, tests;
long long x;

int Height(long long x)
{
  int res = 0;
  do
  {
    x >>= 1;
    res++;
  }
  while(x != 0);
  return n - res + 1;
}

long long SubTree(int x)
{
  return (1LL << x) - 1;
}

int main()
{
  scanf("%d", &tests);
  while(tests--)
  {
    scanf("%d %lld", &n, &x);
    printf("%lld\n", SubTree(n) - Height(x) - (x == 1 ? 0 : SubTree(Height(x) - 1)));
  }
}



