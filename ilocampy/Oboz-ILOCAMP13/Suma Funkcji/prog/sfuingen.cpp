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

const char* code = "sfu";
const int MXN = 1e5 + 5;
int n;
int tab[MXN];
PII fun[MXN];
int q;
int qt[MXN];
PII qv[MXN];

void output(int number, char letter)
{
    char S[20];
    sprintf(S,"%s%d%c.in",code,number,letter);
    printf("Writing %s...\n",S);
    FILE* out = fopen(S,"w");
    
    fprintf(out,"%d\n", n);
    FOR(i, 1, n-1)fprintf(out, "%d ", tab[i]);
    fprintf(out, "%d\n", tab[n]);
    
    FOR(i,1,n)fprintf(out, "%d %d\n",fun[i].f, fun[i].s);
    
    fprintf(out,"%d\n", q);
    
    FOR(i,1,n)fprintf(out, "%d %d %d\n",qt[i],qv[i].f,qv[i].s);
    
    fclose(out);
}
int R(int a, int b)
  {
  return RG.rand() % (b-a+1) + a;
  }

void generate_random(int mn, int mxn, int mq, int mxq, int val, int t1=50, int t2=50)
  {
  n = R(mn, mxn);
  q = R(mq, mxq);
  
  FOR(i, 1, n)
    tab[i] = R(1, val);
  
  FOR(i, 1, n)
    {
    int a = R(1, n);
    int b = R(a, n);
    fun[i] = MP(a, b);
    }
  
  FOR(i, 1, q)
    {
    if(R(1, t1+t2) <= t1)
      {
      qt[i] = 1;
      qv[i] = MP(R(1, n), R(1, val));    
      }
    else
      {
      qt[i] = 2;
      int a = R(1, n);
      int b = R(a, n);
      qv[i] = MP(a, b);
      }
    }
  
  }


int main()
  {
  REP(i, 7)
    {
    if(i < 4)generate_random(3, 6, 3, 6, 5);
    else generate_random(10, 14, 10, 15, 10);
    output(1, 'a' + i);
    }
    
  REP(i, 12)
    {
    if(i < 4)generate_random(500, 2000, 1000, 2000, 1e8);
    else if(i < 8)generate_random(500, 2000, 1000, 2000, 1e8, 1, 99);
    else generate_random(500, 2000, 1000, 2000, 1e8, 99, 1);
    output(2, 'a' + i);
    }
  
  REP(i, 12)
    {
    if(i < 4)generate_random(20000, 40000, 20000, 40000, 1e8);
    else if(i < 8)generate_random(20000, 40000, 20000, 40000, 1e8, 1, 99);
    else generate_random(20000, 40000, 20000, 40000, 1e8, 99, 1);
    output(3, 'a' + i);
    }
    
  REP(i, 9)
    {
    if(i < 3)generate_random(50000, 60000, 50000, 60000, 1000);
    else if(i < 6)generate_random(50000, 60000, 50000, 60000, 1000, 1, 99);
    else generate_random(50000, 60000, 50000, 60000, 1000, 99, 1);
    output(4, 'a' + i);
    }
    
  REP(i, 9)
    {
    if(i < 3)generate_random(95000, 100000, 95000, 100000, 1e8);
    else if(i < 6)generate_random(95000, 100000, 95000, 100000, 1e8, 1, 99);
    else generate_random(95000, 100000, 95000, 100000, 1e8, 99, 1);
    output(5, 'a' + i);
    }
  }
