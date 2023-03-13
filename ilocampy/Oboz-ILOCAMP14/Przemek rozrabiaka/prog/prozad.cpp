#include <cstdio>
#include <iostream>

using namespace std;

int n;
long long k;

int main()
{
  scanf("%d", &n);
  while(n--)
  {
    scanf("%lld", &k);
    puts( k % 4 == 2 ? "TAK" : "NIE" );
  }
}
