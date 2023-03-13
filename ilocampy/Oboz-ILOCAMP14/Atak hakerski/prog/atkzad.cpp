#include <cstdio>
#include <iostream>
 
using namespace std;
 
typedef long long LL;
 
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
 
long long SumSubTree(int a, int b)
{
  long long sum = 0;
  for(int i = a; i <= b; i++)
  {
    sum += SubTree(i);
  }
  return sum;
}
 
int main()
{
  scanf("%d", &tests);
  while(tests--)
  {
    scanf("%d %d", &n, &x);
    if(x == 1)
    {
      printf("%lld\n", SubTree(n) - n);
    }
    else
    {
      int hdol = Height(x);
      int hgora = n - Height(x);
      LL res1 = SubTree(n) - Height(x) - SubTree(Height(x) - 1);
      LL res2 = SubTree(n) - n - SumSubTree(max(0, Height(x) - 2 - hgora + 1), Height(x) - 2);
      printf("%lld\n", max(res1, res2));
    }
  }
}