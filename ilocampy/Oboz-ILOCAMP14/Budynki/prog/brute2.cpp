/* Weryfikacja zadania "Neighbours" O(n^2)
 * Tomasz Idziaszek */

#include <cstdio>
#include <algorithm>
#include <fcntl.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long LL;

struct pkt {
   int x,y,ox,oy;
};

const int N=510000;
int w,h,n,xn,yn;
pkt p[N];
int x[N],y[N];
int mx[N],Mx[N],my[N],My[N],mox[N],Mox[N],moy[N],Moy[N];
LL wyn[4];

int main() {
  // MJ
#if 0
  close(0);
  open("nei.in", O_RDONLY);
  close(1);
  open("nei.out", O_WRONLY | O_CREAT | O_TRUNC, 0666);
#endif

   scanf("%d%d%d",&w,&h,&n);
   REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
   REP(i,n) x[i]=p[i].ox=p[i].x,y[i]=p[i].oy=p[i].y;
   sort(x,x+n);
   sort(y,y+n);
   xn=unique(x,x+n)-x;
   yn=unique(y,y+n)-y;
   REP(i,n) p[i].x=lower_bound(x,x+xn,p[i].x)-x;
   REP(i,n) p[i].y=lower_bound(y,y+yn,p[i].y)-y;
   REP(i,n) mx[i]=my[i]=n+3, Mx[i]=My[i]=-1;
   REP(i,n) mox[i]=moy[i]=1100000000, Mox[i]=Moy[i]=-1;
   REP(i,n) mx[p[i].y]=min(mx[p[i].y],p[i].x),
      my[p[i].x]=min(my[p[i].x],p[i].y),
      Mx[p[i].y]=max(Mx[p[i].y],p[i].x),
      My[p[i].x]=max(My[p[i].x],p[i].y);
   REP(i,n) mox[p[i].y]=min(mox[p[i].y],p[i].ox),
      moy[p[i].x]=min(moy[p[i].x],p[i].oy),
      Mox[p[i].y]=max(Mox[p[i].y],p[i].ox),
      Moy[p[i].x]=max(Moy[p[i].x],p[i].oy);
   wyn[0]=LL(w+1-xn)*(h+1-yn);
   REP(i,xn) wyn[1] += (moy[i]-my[i]) + (h+1-Moy[i]-yn+My[i]);
   REP(i,yn) wyn[1] += (mox[i]-mx[i]) + (w+1-Mox[i]-xn+Mx[i]);
   REP(i,yn) for(int j=mx[i]; j<=Mx[i]; ++j)
      wyn[3 + (i>=my[j] && i<=My[j])]++;
   REP(i,xn) for(int j=my[i]; j<=My[i]; ++j)
      wyn[3 + (i>=mx[j] && i<=Mx[j])]++;
   wyn[4]/=2;
   wyn[4]-=n;
   wyn[2]=LL(w+1)*(h+1)-wyn[0]-wyn[1]-wyn[3]-wyn[4]-n;
   printf("%lld %lld %lld %lld %lld\n",wyn[0],wyn[1],wyn[2],wyn[3],wyn[4]);
}

