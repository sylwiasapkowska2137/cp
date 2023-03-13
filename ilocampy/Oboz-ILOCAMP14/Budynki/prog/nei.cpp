/* Model solution for the task Neighbours
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
#include <fcntl.h>
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

#define MAX_N 500000

int w,h,n;
/* first the point, then a value: 1 - first in a row, 2 - last in a row,
 * 3 - both, 4 - none. */
pair<PII,int> t[MAX_N];

/* Two interval trees. */
int one[4100000],two[4100000]; // old: 1100000
int num;

/* y rescaling */
inline int inside(int y)
{
  return max(min(y,h),0);
}
VI y;
int maxy;
void yrescale()
{
  REP(i,n) FOR(e,-1,1) y.PB(inside(t[i].FI.SE+e));
  y.PB(0); y.PB(h);
  sort(ALL(y));
  y.erase(unique(ALL(y)),y.end());
  maxy=y.size();
  REP(i,n) t[i].FI.SE=lower_bound(ALL(y),t[i].FI.SE)-y.begin();
}

/* Operations on interval trees */
void insert(int *tree,int x,int val)
{
  int v=num+x;
  tree[v]=val;
  while (v!=1)
  {
    v/=2;
    tree[v]=tree[2*v]+tree[2*v+1];
  }
}
int query(int *tree,int a,int b)
{
  int va=num+a,vb=num+b;
  int w=tree[va];
  if (vb!=va) w+=tree[vb];
  while (va/2!=vb/2)
  {
    if (va%2==0) w+=tree[va+1];
    if (vb%2==1) w+=tree[vb-1];
    va/=2; vb/=2;
  }
  return w;
}

ll res[5];

/* Analyze all points in the empty stripe */
void empty_stripe(int x1,int x2)
{
  int a=query(one,0,maxy-1);
  int b=query(two,0,maxy-1);
  ll how_many=x2-x1+1;
  res[1]+=how_many*a; res[2]+=how_many*b;
  res[0]+=how_many*(h+1-a-b);
}

int main()
{
  // MJ
#if 0
  close(0);
  open("nei.in", O_RDONLY);
  close(1);
  open("nei.out", O_WRONLY | O_CREAT | O_TRUNC, 0666);
#endif

  scanf("%d%d%d",&w,&h,&n);
  /* for each point we need to count t[i].SE */
  REP(i,n) scanf("%d%d",&(t[i].FI.SE),&(t[i].FI.FI));
  sort(t,t+n);
  int i=0;
  while (i<n)
  {
    int i0=i;
    while (i0<n && t[i0].FI.FI==t[i].FI.FI) i0++;
    t[i].SE++; t[i0-1].SE+=2;
    i=i0;
  }

  /* back to (x,y) */
  REP(j,n) swap(t[j].FI.FI,t[j].FI.SE);
  sort(t,t+n);

  /* rescale y-coefficients of points */
  yrescale();
  /* build interval trees */
  num=1;
  while (num<maxy) num*=2;
  
  /* The main loop */
  REP(j,n) if (t[j].SE & 1) insert(one,t[j].FI.SE,1);
  if (t[0].FI.FI>0) empty_stripe(0,t[0].FI.FI-1);
  i=0;
  while (i<n)
  {
    int i0=i;
    /* below all points */
    if (t[i].FI.SE>0)
    {
      int a=query(one,0,t[i].FI.SE-1);
      int b=query(two,0,t[i].FI.SE-1);
      res[2]+=a; res[3]+=b;
      res[1]+=y[t[i].FI.SE]-a-b;
    }
    while (i0<n && t[i0].FI.FI==t[i].FI.FI) i0++;
    FOR(j,i,i0-2) if (t[j].FI.SE+1<t[j+1].FI.SE)
    {
      /* in the middle */
      int a=query(one,t[j].FI.SE+1,t[j+1].FI.SE-1);
      int b=query(two,t[j].FI.SE+1,t[j+1].FI.SE-1);
      res[3]+=a; res[4]+=b;
      res[2]+=y[t[j+1].FI.SE]-y[t[j].FI.SE]-1-a-b;
    }
    /* above all points */
    if (t[i0-1].FI.SE<maxy-1)
    {
      int a=query(one,t[i0-1].FI.SE+1,maxy-1);
      int b=query(two,t[i0-1].FI.SE+1,maxy-1);
      res[2]+=a; res[3]+=b;
      res[1]+=(h-y[t[i0-1].FI.SE])-a-b;
    }
    /* changing the points' states in the interval trees */
    FOR(j,i,i0-1) if (t[j].SE!=3 && t[j].SE!=0)
    {
      if (t[j].SE & 2)
      {
        /* the last point in the line */
        insert(two,t[j].FI.SE,0);
        insert(one,t[j].FI.SE,1);
      } else
      {
        /* the first point in the line */
        insert(one,t[j].FI.SE,0);
        insert(two,t[j].FI.SE,1);
      }
    }
    if (i0<n && t[i].FI.FI+1<t[i0].FI.FI)
      empty_stripe(t[i].FI.FI+1,t[i0].FI.FI-1);
    i=i0;
  }
  if (t[n-1].FI.FI<w) empty_stripe(t[n-1].FI.FI+1,w);

  /* the result */
  REP(i,4) printf("%lld ",res[i]);
  printf("%lld\n",res[4]);
  return 0;
}
