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

const char* code = "wrs";

int x, q;
string slo[14];
VPII V;
int maxdl = 1e5/2;

void output(int number, char letter, int points = 0)
{
    char S[20];
    if(points == 0)
      sprintf(S,"%s%d%c.in",code,number,letter);
    else
      sprintf(S,"%s%d%c-%dp%d.in",code,number,letter,number,points);
    
    printf("Writing %s...\n",S);
    FILE* out = fopen(S,"w");
    
    
    fprintf(out,"%d %d\n", x, q);
    REP(i, x+1)fprintf(out, "%d %s\n",(int)slo[i].size(), slo[i].c_str());
    
    REP(i, q)
      {
      fprintf(out, "%d %d\n",V[i].f+1, V[i].s+1);
      }
   
    fclose(out);
}
int R(int a, int b)
  {
  return RG.rand() % (b-a+1) + a;
  }
void gen_test(int alf, int _x, int sdl, int mxdl, int _q, int rozneoda = 0)
  {
  x = _x;
  q = _q;
  REP(i, x)
    {
    slo[i] = "";
    }
  V.clear();
  
  int ddl = 0;
  REP(i, x)
    {
    int dl = R(1, max(1, min(min(mxdl,sdl-ddl), sdl/(x-i)*3)));
    REP(j, dl)
      {
      slo[i] += (R(0, rozneoda) > 0) ? 'a' : 'a' + R(0, alf-1);
      }
    ddl += slo[i].size();
    }
  
  slo[x] = "";
  
  VPII que;
  REP(i, q)
    {
    if((int)slo[x].size() >= sdl)
      {
      int xxx = R(0, 1);
      if(xxx == 0 || que.size() < 2)
        {
        PII x = que[R(0, que.size()-1)];
        int a = R(x.f, x.s);
        int b = R(a, x.s);
        V.PB(MP(a, b));
        }
      else if(xxx == 1)
        {
        int idx =  R(1, que.size()-1);
        int a = R(que[idx-1].f, que[idx].s);
        int b = R(a, que[idx].s);
        V.PB(MP(a,b)); 
        }
      }
    else
      {
      int pocslo = slo[x].size();
      
      int t = R(1, x);
      REP(j, t)
        {
        int nrslowa = R(0, x-1);
        
        int poc = R(0, (int)slo[nrslowa].size() -1);
        int kon = R(poc, max(poc + mxdl -1, (int)slo[nrslowa].size()-1));
//        poc++; kon++;
        slo[x] += slo[nrslowa].substr(poc, kon-poc+1);
        
        }
      int konslo = slo[x].size() - 1;
      
      while((int)slo[x].size() > maxdl)slo[x].erase(slo[x].begin() + slo[x].size() - 1);
      mini(pocslo, maxdl);
      mini(konslo, maxdl);
      if(R(0, 6) == 0)
        slo[x][R(pocslo, konslo)] = 
          (R(0, rozneoda) > 0) ? 'a' : 'a' + R(0, alf-1);//czy psuć
      que.PB(MP(pocslo, konslo));
      V.PB(MP(pocslo, konslo));
      }
    
    }
  
  RG.randomShuffle(ALL(V));
  } 
//void gen_test(int alf, int _x, int sdl, int mxdl, int _q, int mxdl)

int main()
  {
  /*
  //do testowania
  FOR(j, 1, 20)
  REP(i, 26)
    {
    gen_test(2, 5, 15, 5, 3);
    output(j, 'a' + i);
    }*/
  
  
  REP(i, 12)
    {
    if(i < 6)gen_test(2, 5, 15, 5, 10);
    else gen_test(3, 6, 20, R(3, 5), 10, 3);
    output(1, 'a'+i); 
    }
  REP(i, 12)
    {
    if(i < 6)gen_test(2, R(1, 8), 100, 20, 100);
    else gen_test(R(2, 5), R(1, 8), 100, 20, 100, 5);
    if(i == 11)gen_test(26, R(4, 8), 100, 20, 100);
    output(2, 'a'+i); 
    }
    
  REP(i, 16)
    {
    if(i < 6)gen_test(2, R(8, 10), 5000, 1000, 5000);
    else if(i < 12)gen_test(R(2, 5), R(1, 10), 5000, 300, 4000, 40);
    else gen_test(26, R(8, 10), 5000, 1000, 5000);
    output(3, 'a'+i); 
    }
    
  REP(i, 16)
    {
    if(i < 6)gen_test(2, R(8, 10), 50000, 10000, 10000);
    else if(i < 12)gen_test(R(2, 7), R(1, 10), 50000, 8000, 10000, 40);
    else gen_test(26, R(8, 10), 5000, 1000, 10000);
    output(4, 'a'+i); 
    }
    
  REP(i, 16)
    {
    if(i < 6)gen_test(2, R(8, 10), 50000, 10000, 10000);
    else if(i < 12)gen_test(R(2, 5), R(1, 10), 50000, 3000, 10000, 400);
    else gen_test(26, R(8, 10), 50000, 20000, 10000, R(10, 100));
    output(5, 'a'+i); 
    }
    
    
  }
  
  /*
  5 3
  5 aaabb
  5 bbbab
  4 aabb
  1 b
  1 b
  19 bbaabbbbbbabbabbbaa
  11 19
  1 6
  7 10
  
  
  
  5 1
5 aaabb
5 bbbab
4 aabb
1 b
1 b
9 abbabbbaa
1 9
  */
