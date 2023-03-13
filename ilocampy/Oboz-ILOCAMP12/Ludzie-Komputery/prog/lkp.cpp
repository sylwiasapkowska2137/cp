#include <iostream>
#include <cstdio>
using namespace std;

int n, t[1000010], biggest, lowest;
bool higher[1000010], lower[1000010];

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &t[i]);
  biggest = t[0];
  for(int i=1; i<n; i++)
  {
    biggest = max(biggest, t[i]);
    if (t[i] < biggest) lower[i]=1;
  }
  lowest = t[n-1];
  for(int i=n-2; i>=0; i--)
  {
    lowest = min(lowest, t[i]);
    if(t[i] > lowest) higher[i]=1;
  }
  int pocz=-1; int kon=-1;
  for(int i=0 ; i<n; i++)
  {
    if(pocz == -1 && (higher[i]==1 || lower[i]==1))
      pocz = i;
    if (higher[i]==1 || lower[i]==1)
      kon = max(kon, i);
  }
  if(pocz==kon && pocz==-1)
    printf("0");
  else
    printf("%d", kon-pocz+1);
  return 0;
}