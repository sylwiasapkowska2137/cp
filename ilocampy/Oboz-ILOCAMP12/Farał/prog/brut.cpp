#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
using namespace std;
int n;
LL x,T,tab[1000005];
int main()
{
  scanf("%d%lld",&n,&x);
  
  for(int i=1;i<=n;i++)scanf("%lld",&tab[i]);
  if(tab[1]>x)
  {
    printf("NIE");
    return 0;
  }
  while(++T)
  {
    LL temp=x;
    int nie=0;
    for(int i=1;i<=n;i++)
    {
      if(tab[i]<=temp)
      {
	temp-=tab[i];
      }
      else
      {
	nie=1;
	x+=(i-1);
	for(int j=i-1;j>=1;j--)tab[i]--;
	break;
      }
    }
    
    if(nie==0)
    {
      printf("%lld",T);
      return 0;
    }
    
  }
  
}