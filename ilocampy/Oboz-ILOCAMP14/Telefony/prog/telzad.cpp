#include <cstdio>
#include <iostream>

using namespace std;

int n, res;

int main()
{
  scanf("%d", &n);
  int parz = 0, nparz = 0;
  for(int i = 100; i <= 999; i++)
  {
    int sum = (i % 10) + (i / 10 % 10) + (i / 100 % 10);
    if(sum == n)
    {
      if(i % 2) nparz++; 
      else parz++;
    }
  }
  printf("%d\n", parz * nparz * (parz + nparz - 2));
}