/* Brute force solution (O(wh)) for the task Neighbours
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

short int t[3010][3010];
bool tab[3010][3010];
int w,h,n;
int res[5];

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
  REP(i,n)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    tab[a][b]=1;
  }
  w++; h++;
  /* western */
  REP(i,w)
  {
    int a=0;
    REP(j,h) { a|=tab[i][j]; t[i][j]+=a; }
  }
  /* eastern */
  REP(i,w)
  {
    int a=0;
    FORD(j,h-1,0) { a|=tab[i][j]; t[i][j]+=a; }
  }
  /* northern */
  REP(j,h)
  {
    int a=0;
    REP(i,w) { a|=tab[i][j]; t[i][j]+=a; }
  }
  /* southern */
  REP(j,h)
  {
    int a=0;
    FORD(i,w-1,0) { a|=tab[i][j]; t[i][j]+=a; }
  }
  REP(i,w) REP(j,h) if (!tab[i][j]) res[t[i][j]]++;
  REP(i,4) printf("%d ",res[i]); printf("%d\n",res[4]);
  return 0;
}
