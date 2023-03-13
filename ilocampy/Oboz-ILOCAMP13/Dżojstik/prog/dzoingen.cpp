// input generator
// may work few seconds
#include <fstream>
#include "oi.h"
#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(int)(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
using namespace std;

oi::Random RG(13444);

const char* code = "dzo";
int n, m;

void output(int number, char letter, int points = 0)
{
    char S[20];
    if(points == 0)
      sprintf(S,"%s%d%c.in",code,number,letter);
    else
      sprintf(S,"%s%d%c-%dp%d.in",code,number,letter,number,points);
    
    printf("Writing %s...\n",S);
    FILE* out = fopen(S,"w");
    
    fprintf(out,"%d %d\n", n, m);
   
    fclose(out);
}
int R(int a, int b)
  {
  return RG.rand() % (b-a+1) + a;
  }
  
VPII V = {MP(3, 5), MP(4, 4), MP(100, 100), MP(1, 100), MP(100, 1), MP(1, 4), MP(1, 1), MP(8, 8), MP(7, 2), MP(24, 15), MP(19, 30), MP(15, 31), MP(14, 15), MP(58, 33), MP(15, 25), MP(59, 45), MP(3, 73), MP(48, 1), MP(100, 25), MP(40, 49), MP(85, 73), MP(29, 1), MP(74, 25), MP(24, 57), MP(23, 12), MP(2, 99), MP(98, 2), MP(2, 97), MP(30, 54), MP(32, 53), MP(32, 54), MP(1, 2), MP(2, 1), MP(2, 2), MP(1, 3), MP(3, 1), MP(1, 4), MP(2, 3), MP(3, 2), MP(10, 11)};


int main()
  {
  REP(i, V.size()/2)
    {
    REP(j, 2)
      {
      n = V[i * 2 + j].f;
      m = V[i * 2 + j].s;
      output(i+1, 'a' + j);
      }
    }  
  }
