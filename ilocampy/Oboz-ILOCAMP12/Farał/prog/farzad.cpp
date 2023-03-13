#include <bits/stdc++.h>

using namespace std;

int n;
long long X,a,T=1,P;

int main()
{
  scanf("%d%lld",&n,&X);
  for(int i=1;i<=n;i++)
  {
    scanf("%lld",&a);
    
    if(i==1&&a>X)
    {
      printf("NIE");
      return 0;
    }
    
    long long To=max(0LL,(long long)ceil(double(P+a-X)/double(2*(i-1))));
    T+=To;
    X+=(i-1)*To;
    P-=(i-1)*To;
    P+=a;  
  }
  printf("%lld",T);
}
