#include <cstdio>
#include "oi.h"
const int maxn = 500 * 1000;
int f[maxn + 1];
int find(int x)
  {
  return f[x] == x ? x : f[x] = find(f[x]);
  }
bool unio(int x, int y)
  {
  x = find(x);
  y = find(y);
  if(x == y)return false;
  f[x] = y;
  return true;
  }
int main() 
{   
    for(int i = 0; i <= maxn; i++)f[i] = i;
    
    oi::Scanner in(stdin, oi::PL);
    int n = in.readInt(1, maxn);
    in.readSpace();
    int m = in.readInt(0, maxn-1);
    in.readEoln();
    for(int i = 0; i < m;i++)
      {
//      if(a != 1 && i == 0)in.error("Pierwsze zapytanie nie jest dodaniem!\n");
      int a = in.readInt(1, n);
      in.readSpace();
      int b = in.readInt(1, n);
      in.readEoln();
      
      if(!unio(a, b))in.error("Las nie jest lasem i ma cykl!");
      }
    in.readEof();
    printf("OK, n = %d.\n",n);
}

