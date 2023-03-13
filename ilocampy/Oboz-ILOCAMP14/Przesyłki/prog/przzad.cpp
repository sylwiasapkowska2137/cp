#include <cstdio>
#include <iostream>

using namespace std;

int n, cnt, pocz, last, res;

int T[1000005];
int Pref[1000005];
bool Wyst[1000005];
bool Pocz[1000005];

int main()
{
  scanf("%d", &n);
  res = 2 * (n - 1);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &T[i]);
  }
  Pref[0] = -1;
  for(int i = 1; i <= n; i++)
  {
    Pref[i] = Pref[i - 1] + 1;
    if(i != T[i])
    {
      if(cnt == 0)
      {
        pocz = i;
        Pocz[i] = true;
      }
      Wyst[i] = (Wyst[i] == false);
      Wyst[T[i]] = (Wyst[T[i]] == false);
      cnt += (Wyst[i]) ? 1 : -1;
      cnt += (Wyst[T[i]]) ? 1 : -1;
      if(cnt == 0)
      {
        Pref[i] += 2 * (i - pocz);
        last = i;
      }
    }
  }
  for(int i = 1; i <= n; i++)
  {
    if(Pocz[i]) 
    {
      res = min(res, Pref[i] + (last - i) * 2);
    }
  }
  printf("%d\n", res);
}