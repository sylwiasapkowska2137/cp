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

const char* code = "mag";
VI p;

void output(int number, char letter, int points = 0)
{
    char S[20];
    if(points == 0)
      sprintf(S,"%s%d%c.in",code,number,letter);
    else
      sprintf(S,"%s%d%c-%dp%d.in",code,number,letter,number,points);
    
    printf("Writing %s...\n",S);
    FILE* out = fopen(S,"w");
    
    fprintf(out,"%d %d %d\n", p[0], p[1], p[2]);
    fprintf(out,"%d %d %d\n", p[3], p[4], p[5]);
   
    fclose(out);
}
int R(int a, int b)
  {
  return RG.rand() % (b-a+1) + a;
  }

vector<VI> V = {{4, 4, 0, 2, 1, 2},{5, 6, 1, 2, 7, 2},{3, 3, 3, 2, 2, 2},{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 1},{0, 1, 0, 0, 0, 0},{1, 0, 0, 1, 0, 0},{2, 2, 1, 1, 1, 2},{1, 3, 1, 2, 1, 1},{1000000, 1000000, 1000000, 1000000, 1000000, 1000000},{1000000, 500000, 500000, 0, 750000, 750000},{500000, 1000000, 500000, 750001, 0, 750000},{499999, 500000, 1000000, 750000, 750000, 0},{500000, 500000, 0, 0, 0, 500000},{0, 500001, 499999, 500000, 0, 0},{1000000, 500000, 1000000, 500000, 1000000, 500000},{1000000, 1000000, 499999, 500000, 500000, 1000000},{500000, 1000000, 1000000, 1000000, 500001, 500000},{1000000, 500000, 500000, 0, 1000000, 500000},{500000, 500000, 1000000, 500001, 1000000, 0},{500000, 999999, 500000, 1000000, 0, 500000},{4, 0, 3, 2, 2, 1},{0, 2, 4, 2, 0, 2},{3, 1, 0, 1, 1, 1},{4, 4, 1, 1, 3, 2},{1, 2, 4, 2, 1, 3},{1, 1, 0, 0, 0, 1},{4, 0, 0, 0, 1, 1},{0, 3, 0, 1, 0, 1},{0, 0, 3, 1, 0, 1},{1, 12, 1, 4, 0, 4},{4, 0, 4, 1, 2, 1},{4, 4, 0, 1, 1, 3},{0, 9, 0, 2, 2, 2},{0, 10, 0, 2, 2, 2},{9, 0, 9, 0, 8, 0},{0, 9, 9, 9, 0, 0},{9, 10, 0, 0, 0, 9},{10, 0, 9, 0, 10, 0},{0, 10, 10, 10, 0, 0},{10, 10, 0, 0, 0, 11},{307075, 152060, 414033, 381653, 222949, 123101},{569950, 228830, 153718, 162186, 357079, 229352},{149416, 303568, 749016, 238307, 493997, 190377},{438332, 298094, 225324, 194220, 400244, 245231},{293792, 300060, 511272, 400687, 382150, 133304},{295449, 518151, 368838, 382897, 137148, 471892},{191789, 291147, 691092, 324321, 416045, 176232},{286845, 704749, 266526, 392296, 104421, 461239},{135522, 188282, 377041, 245719, 212473, 108265},{404239, 359124, 133292, 180069, 184791, 332544},{191906, 624432, 244408, 340002, 367217, 205432},{275980, 429361, 101824, 274288, 302579, 166062},{136092, 364927, 395302, 149173, 343146, 390922},{613852, 334661, 146012, 363786, 326286, 275233},{348369, 104625, 525203, 285621, 215396, 366411},{225307, 153572, 114545, 154753, 153282, 149967},{438576, 124465, 629784, 375118, 276028, 390116},{447521, 327510, 158732, 395759, 178458, 259139},{8, 5, 5, 5, 5, 5},{100, 100, 100, 1, 1, 1},{100, 100, 100, 0, 0, 0},{3, 2, 3, 2, 3, 2},{5, 4, 3, 2, 2, 2},{14, 9, 8, 12, 5, 10},{10, 10, 10, 1, 1, 1},{6, 3, 3, 3, 3, 3},{10, 0, 4, 2, 4, 2},{100, 100, 100, 2, 2, 2},{4, 6, 0, 2, 1, 2},{4, 6, 3, 4, 2, 3},{5, 5, 5, 1, 1, 1},{41, 17, 34, 0, 19, 24},{8, 8, 8, 3, 3, 3},{7, 7, 1, 1, 1, 2},{6, 6, 0, 2, 2, 2},{5, 5, 5, 2, 2, 2},{400, 400, 400, 1, 1, 1},{4, 4, 4, 2, 2, 2}, {4, 1, 4, 2, 2, 2}};


int main()
  {
  REP(i, V.size()/4)
    {
    REP(j, 4)
      {
      p = V[i*4+j];
      output(i+1, 'a' + j);
      }
    }
  }
