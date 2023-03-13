#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int INF=2000000000;
vector<int> v;
int n, odp;

int main()
{
  odp=INF;
  scanf("%d", &n);
  for(int i=1; i*i<=n; i++)
    if(n%i==0)
      v.push_back(i);
  for(int i=0; i<v.size(); i++)
    odp=min(odp, (v[i]+(n/v[i]))*2);
  printf("%d", odp);
  return 0;
}