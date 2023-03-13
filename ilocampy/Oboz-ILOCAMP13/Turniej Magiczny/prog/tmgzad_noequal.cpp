#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define INF 1e9+7

using namespace std;

int ilosc, a, b, c, mn, mx;

vector <int> V[1000000];
vector <int> Res;

int main()
{
   scanf("%d", &ilosc);
   for(int i = 1; i <= ilosc; i++)
   {
      scanf("%d %d %d", &a, &b, &c);
      V[i].PB(a);
      V[i].PB(b);
      V[i].PB(c);
      sort(ALL(V[i]));
      mn = max(mn,V[i][0]);
      mx = max(mx,V[i][1]);
   }
   for(int i = 1; i <= ilosc; i++)
      if(V[i][2] >= mx && V[i][1] >= mn)
     Res.PB(i);
   sort(ALL(Res));
   printf("%d\n", Res.size());
   for(int i = 0; i < Res.size(); i++)
      printf("%d ",Res[i]);
}
