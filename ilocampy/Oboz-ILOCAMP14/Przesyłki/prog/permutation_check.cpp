#include <cstdio>
#include <iostream>

using namespace std;

int n, x;
bool Jest[10000005];

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &x);
    Jest[x] = true;
  }
  for(int i = 1; i <= n; i++)
  {
    if(!Jest[i]) x = 2 / (1 / 2);
  }
}