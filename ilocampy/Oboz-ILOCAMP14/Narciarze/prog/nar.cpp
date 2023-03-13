#include <iostream>
#include <cstdio>
using namespace std;
int n, theSame, t[1000010];
long long int ans;

int main()
{
  scanf("%d", &n);
  ans = (long long) (n + 1) * n / 2 ;
  for(int i=0; i<n; i++) 
    scanf("%d", &t[i]);
  for(int i=0; i<n; i++)
  {
    theSame = 1;
    while (i + theSame < n && t[i + theSame] == t[i])
      theSame++;
    i += theSame - 1;
    ans -= (long long) (theSame + 1) * theSame / 2;
  }
  printf("%lld", ans);
  return 0;
}