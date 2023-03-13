/* Input generating program for the task Neighbours
 * Author: Jakub Radoszewski
 * Date: 05.06.2007
 */

#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

int los(int m)
{
  return (int) ((double)m * (rand() / (RAND_MAX + 1.0)));
}

set<PII> zb;
vector<PII> wyn;
/* grid is gx times gy, n points in the grid, m points apart from the grid */
void grid_and_rand(string name,int sr,int w,int h,int gx,int gy,int n,int m)
{
  freopen(name.c_str(),"w",stdout);
  srand(sr);
  set<int> xx,yy;
  REP(i,gx) { int x=los(w+1); if (xx.find(x)!=xx.end()) i--; else xx.insert(x); }
  REP(i,gy) { int y=los(h+1); if (yy.find(y)!=yy.end()) i--; else yy.insert(y); }
  VI x,y;
  FOREACH(it,xx) x.PB(*it);
  FOREACH(it,yy) y.PB(*it);
  zb.clear();
  REP(i,n)
  {
    PII p=MP(x[los(gx)],y[los(gy)]);
    if (zb.find(p)!=zb.end()) i--; else zb.insert(p);
  }
  REP(i,m)
  {
    int ch=los(4);
    if (i==m-1) ch=0;
    if (ch<=1)
    {
      PII p=MP(los(w+1),los(h+1));
      if (zb.find(p)!=zb.end()) i--; else zb.insert(p);
    } else if (ch==2)
    {
      PII p=MP(los(w+1),los(h+1));
      PII q=MP(los(w+1),p.SE);
      if (los(10)==0) q.FI=min(p.FI+1,w);
      if (zb.find(p)!=zb.end() || zb.find(q)!=zb.end()) i--; else
      { zb.insert(p); zb.insert(q); i++; }
    } else
    {
      PII p=MP(los(w+1),los(h+1));
      PII q=MP(p.FI,los(h+1));
      if (los(10)==0) q.SE=min(p.SE+1,h);
      if (zb.find(p)!=zb.end() || zb.find(q)!=zb.end()) i--; else
      { zb.insert(p); zb.insert(q); i++; }
    }
  }
  printf("%d %d %u\n",w,h,zb.size());
  wyn.clear(); FOREACH(it,zb) wyn.PB(*it);
  random_shuffle(ALL(wyn));
  FOREACH(it,wyn) printf("%d %d\n",(*it).FI,(*it).SE);
}

void vertical(string name,int sr,int w,int h,int n)
{
  freopen(name.c_str(),"w",stdout);
  srand(sr);
  set<int> pom;
  REP(i,n) { int a=los(h+1); if (pom.find(a)!=pom.end()) i--; else pom.insert(a); }
  VI pom1; FOREACH(it,pom) pom1.PB(*it);
  random_shuffle(ALL(pom1));
  int b=los(w+1);
  printf("%d %d %d\n",w,h,n);
  REP(i,n) printf("%d %d\n",b,pom1[i]);
}

void horizontal(string name,int sr,int w,int h,int n)
{
  freopen(name.c_str(),"w",stdout);
  srand(sr);
  set<int> pom;
  REP(i,n) { int a=los(w+1); if (pom.find(a)!=pom.end()) i--; else pom.insert(a); }
  VI pom1; FOREACH(it,pom) pom1.PB(*it);
  random_shuffle(ALL(pom1));
  int b=los(h+1);
  printf("%d %d %d\n",w,h,n);
  REP(i,n) printf("%d %d\n",pom1[i],b);
}

void random(string name,int sr,int w,int h,int n)
{
  freopen(name.c_str(),"w",stdout);
  srand(sr);
  zb.clear();
  REP(i,n)
  {
    PII p=MP(los(w+1),los(h+1));
    if (zb.find(p)!=zb.end()) i--; else zb.insert(p);
  }
  printf("%d %d %u\n",w,h,zb.size());
  wyn.clear(); FOREACH(it,zb) wyn.PB(*it);
  random_shuffle(ALL(wyn));
  FOREACH(it,wyn) printf("%d %d\n",(*it).FI,(*it).SE);
}

#define MLD 1000000000

int main()
{
  fprintf(stderr,"This program runs for about 10 seconds.\nBe patient!\n");
  /* Passed by O(wh) solutions */
  random("nei1a.in",214610,9,5,17);
  freopen("nei1b.in","w",stdout);
  printf("2 2 1\n1 1\n");

  random("nei2.in",214776,20,50,111);

  grid_and_rand("nei3.in",214888,1000,1000,99,101,987,777);

  grid_and_rand("nei4.in",214590,3000,3000,1000,1000,100000,400000);

  /* Passed by better brute-force solutions */
  grid_and_rand("nei5.in",214596,MLD,MLD,100,100,1000,1000);

  grid_and_rand("nei6a.in",214592,MLD,MLD,1000,1000,100000,300);
  freopen("nei6b.in","w",stdout);
  printf("%d %d 4\n",MLD,MLD);
  printf("0 0\n0 %d\n%d 0\n%d %d\n",MLD,MLD,MLD,MLD);

  /* Passed by model solution only */
  grid_and_rand("nei7.in",214581,721656221,929190128,100,40000,150000,120000);
  
  grid_and_rand("nei8.in",214580,10000000,10000000,50000,7000,300000,100000);
  
  random("nei9a.in",214568,MLD,MLD,500000);
  horizontal("nei9b.in",214567,MLD,MLD,500000);
  grid_and_rand("nei9c.in",212580,100000000,100000000,200000,100000,350000,150000);
  
  grid_and_rand("nei10a.in",214565,MLD,MLD,8000,8000,250000,250000);
  vertical("nei10b.in",214566,MLD,MLD,500000);
  return 0;
}
