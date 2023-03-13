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

const char* code = "pkt";
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
  
VPII V = {MP(1, 1), MP(0, 10), MP(10, 10), MP(100, 100), MP(10, 100), MP(20, 1000), MP(1000, 20), MP(100, 10), MP(2, 2), MP(3, 3), MP(2, 15), MP(15, 2), MP(1000, 1000), MP(1000, 999), MP(999, 1000), MP(987, 567), MP(555, 555), MP(555, 1), MP(1, 4), MP(955, 956), MP(4, 0), MP(0, 3), MP(3, 0), MP(2, 3), MP(3, 2), MP(3, 4), MP(4, 3), MP(3, 5), MP(5, 3), MP(3, 6), MP(6, 3), MP(4, 4), MP(4, 5), MP(5, 4), MP(4, 6), MP(6, 4), MP(4, 7), MP(7, 4), MP(3, 100), MP(100, 3), MP(4, 100), MP(100, 4), MP(30, 1000), MP(1000, 30), MP(1000, 40), MP(40, 1000), MP(2, 10), MP(9, 3), MP(2, 1000), MP(100, 2), MP(3, 1), MP(2, 100), MP(3, 7), MP(2, 50), MP(1, 5), MP(3, 1000), MP(5, 2), MP(10, 0), MP(20, 0), MP(1000, 3), MP(1000, 500), MP(2, 5), MP(2, 1), MP(1000, 2), MP(6, 5), MP(2, 4), MP(20, 10), MP(10, 1)};


VI groups = {8, 22, 30, 50, 80, 150, 300, 600, 2000};
VI pkts =   {10, 5, 5,  5,  5,  10,  20,  20,  20};
int main()
  {
  RG.randomShuffle(ALL(V));
  REP(i, (int)groups.size())
    {
    char ch = 'a';
    for(auto it:V)
      {
      if(it.f + it.s <= groups[i] && (i == 0 || groups[i-1] > it.f + it.s || R(0, 15) == 0))
        {
        n = it.f;
        m = it.s;
        output(i+1, ch, pkts[i]);
        ch++;
        }
      if(ch == 'z' + 1)break;
      }
    }  
  }
