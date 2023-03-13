#include <cstdio>
#include <iostream>

using namespace std;

int n, res;

int suma(int x)
{
  return (x / 100) + (x / 10 % 10) + (x % 10);
}

int main()
{
  scanf("%d", &n);
  for(int i = 100; i <= 999; i++)
  {
    for(int j = 100; j <= 999; j++)
    {
      for(int l = 100; l <= 999; l++)
      {
        if(i != j && j != l && l != i)
        {
          if(i % 2 == 0 && j % 2 == 1)
          {
            if(suma(i) == n && suma(j) == n && suma(l) == n)
            {
              res++;
            }
          }
        }
      }
    }
  }
  printf("%d\n", res);
}