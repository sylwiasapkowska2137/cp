#include <cstdio>
#include <iostream>

using namespace std;

int n;
int k;

int main()
{
  scanf("%d", &n);
  while(n--)
  {
    scanf("%d", &k);
    puts( k % 4 == 2 ? "TAK" : "NIE" );
  }
}
