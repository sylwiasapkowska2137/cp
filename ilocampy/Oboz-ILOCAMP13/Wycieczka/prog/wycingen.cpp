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

const char* code = "wyc";
int n, q;
VPII V;

const int MXN = 1e6+6;
int kraw[MXN];
PII zap[MXN];

void output(int number, char letter, int points = 0)
{
    char S[20];
    if(points == 0)
      sprintf(S,"%s%d%c.in",code,number,letter);
    else
      sprintf(S,"%s%d%c-%dp%d.in",code,number,letter,number,points);
    
    printf("Writing %s...\n",S);
    FILE* out = fopen(S,"w");
    
    fprintf(out,"%d %d %d\n", n, (int)V.size(), q);
    for(auto it:V)fprintf(out, "%d %d\n",it.f, it.s);
    
    REP(i, q)
      {
      if(kraw[i] >= (int)V.size())assert(false);
      fprintf(out, "%d %d %d %d\n",zap[i].f, zap[i].s, V[kraw[i]].f, V[kraw[i]].s);
      }
   
    fclose(out);
}
int R(int a, int b)
  {
  return RG.rand() % (b-a+1) + a;
  }
  

const int maxn = 5e5+5;
int ff[maxn + 1];
int find(int x)
  {
  return ff[x] == x ? x : ff[x] = find(ff[x]);
  }
bool unio(int x, int y)
  {
  x = find(x);
  y = find(y);
  if(x == y)return false;
  ff[x] = y;
  return true;
  }
VPII gen_tree1(int _n) // spójne=
  {
  int m = _n - 1;
  VPII V;
  n = _n;
  V.clear();
  for(int i = 0; i <= n; i++)ff[i] = i;
  REP(i, m)
    {
    int a, b;
    do
      {
      a = R(1, n);
      b = R(1, n);
      }
    while(unio(a, b) == 0);
    V.PB(MP(a, b));
    }
  return V;
  }
VPII gen_dep_tree(int _n, int last)
  {
  int m = _n-1;
  maxi(_n, 1);
  maxi(m, 0);
//  cerr<<"a: "<<_n<<" "<<m<<" "<<last<<endl;
  VPII V;
  n = _n;
  VI pom;
  FOR(i, 1, n)pom.PB(i);
  RG.randomShuffle(ALL(pom));
  
  
  V.clear();
  FOR(i, 2, n)
    {
    V.PB(MP(pom[R(max(1, i-last), i-1) - 1], pom[i-1]));
    }
  RG.randomShuffle(ALL(V));
  while((int)V.size() > m)V.pop_back();
  return V;
  }
void gen_test(int tri, int _n, int _m, int _q)
  {
  cerr<<tri<<" "<<_n<<" "<<_m<<" "<<_q<<endl;
  n = _n;
  int m = _m;
  q = _q;
  if(tri == 0)V = gen_tree1(n);
  else V = gen_dep_tree(n, tri);
  set<PII> S;
  for(auto it:V)
    {
    S.insert(it);
    S.insert(MP(it.s, it.f));
    }

  FOR(i, n, m)
    {
    int a = 1;
    int b = 1;
    while(a == b || S.count(MP(a, b)))
      {
      a = R(1, n);
      b = R(1, n);
      }
    S.insert(MP(a, b));
    S.insert(MP(b, a));
    V.PB(MP(a, b));
    }
  
  FOR(i, 0, q-1)
    {
    int a = R(1, n);
    int b = R(1, n-1);
    if(b >= a)b++;
    zap[i] = MP(a, b);
    kraw[i] = R(0, m-1);
    }  
  }

int main()
  {
  int a;
  REP(i, 10)
    {
    a = 0;
    if(R(0, 1))a = R(2, 4);
    gen_test(a, 10, R(9, 20), 10);
    output(1, 'a' + i, 10);
    }
  
  REP(i, 10)
    {
    a = 0;
    if(R(0, 1))a = R(2, 10);
    gen_test(a, 100, R(99, 200), R(100, 200));
    output(2, 'a' + i, 10);
    }
  REP(i, 10)
    {
    a = 0;
    if(R(0, 1))a = R(4, 40);
    gen_test(a, 3000, R(3000-1, 10000), 4000);
    output(3, 'a' + i, 10);
    }
    
  REP(i, 10)
    {
    a = 0;
    if(R(0, 1))a = R(4, 400);
    gen_test(a, 40000, R(40000-1, 60000), 40000);
    output(4, 'a' + i, 20);
    }
  REP(i, 5)
    {
    a = 0;
    if(R(0, 1))a = R(4, 60);
    gen_test(a, 400, R(50000, 60000), 40000);
    output(4, 'a' + i + 10, 20);
    }
    
    
  REP(i, 10)
    {
    a = 0;
    if(R(0, 1))a = R(4, 800);
    gen_test(a, 300000, R(200000, 300000), 400000);
    output(5, 'a' + i, 20);
    }
  
  REP(i, 10)
    {
    a = 0;
    if(R(0, 1))a = R(4, 800);
    gen_test(a, R(990000, 1000000), 1000000, 1000000);
    output(6, 'a' + i, 30);
    }
  }
