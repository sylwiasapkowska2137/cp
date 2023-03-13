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

LL p = 100001;
int mod = 1e9 + 7;
const int slow = 13;
const int MXN = 1e5+5;

int dlu[slow];
char in[slow][MXN];
int h[slow][MXN];
int pot[MXN];

struct slo
  {
  int nr;
  int a, b;
  int *h; // wskaźnik na tablice haszy
    slo(int _nr, int _a,int _b,int *_h)
      {
      nr = _nr; a = _a; b = _b; h = _h;
      }
  };



int hasz(int a,int b, int *h)
    {
    if(a == 0)return h[b];
    int x = (h[b]-(LL)h[a-1]*pot[b-a+1])%mod;
    if(x<0)x+=mod;
    return x;
    }
inline bool rowne(slo x,slo y,int k)//czy pierwsze k+1 znakow od x i y sa rowne
    {
    if(x.a + k >= dlu[x.nr] || y.a + k >= dlu[y.nr])return 0;
    return hasz(x.a, x.a+k, x.h) == hasz(y.a, y.a+k, y.h);
    }
int firstdif(slo x,slo y)
    {
    int poc = -1;
    int kon = min(dlu[x.nr] - x.a, dlu[y.nr]-y.a)+2;
    int sr=0;
    while(sr!=(poc+kon)/2)
        {
        sr=(poc+kon)/2;
        if(rowne(x, y, sr))poc=sr;
        else kon=sr;
        }  
//   while(rowne(x, y, sr))sr++;
//    while(sr>0 && !rowne(x, y, sr-1))sr--;
    return poc+1;
    }
int cmp(slo x, slo y)
    {
    int k = firstdif(x, y);
    if(x.b < x.a + k || y.b < y.a + k)return x.b - x.a < y.b - y.a;
    return in[x.nr][x.a+k] < in[y.nr][y.a+k];
    }
int lcp(slo x, slo y)
  {
//  cerr<<"lcp: "<<x.a<<" "<<x.nr<<" y: "<<y.a<<" "<<y.nr<<" = ";
  int r = firstdif(x, y);
  mini(r, x.b - x.a + 1);
  mini(r, y.b - y.a + 1);
//  cout<<r<<endl;
  return r;
  }

int x, q;

void pre()
    {
    pot[0] = 1;
    FOR(i, 1, 1e5+2)pot[i] = (LL)pot[i-1]*p % mod;
    REP(i, x+1)
      {
      h[i][0] = in[i][0];
      FOR(j, 1, dlu[i])
          h[i][j] = ((LL)h[i][j-1] * p + in[i][j])%mod;
      }
    }


PII tprev[MXN*2][slow];//tprev[j][i] poprzedni nad j (lub j) typu i, oraz lcp
PII tnxt[MXN*2][slow];
vector<slo> V;

void calctprev()
  {
  REP(i, x+1)tprev[0][i].f = -1;
  tprev[0][V[0].nr].f = 0;
  tprev[0][V[0].nr].s = dlu[V[0].nr] - V[0].a;

  REP(i, V.size())
    {
    if(i == 0)continue;
    REP(j, x+1)
      {
      tprev[i][j].f = tprev[i-1][j].f;
      }
    tprev[i][V[i].nr].f = i;
    tprev[i][V[i].nr].s = dlu[V[i].nr] - V[i].a;
    
    REP(j, x+1)
      {
      if(tprev[i][j].f==-1){tprev[i][j].s = 0; continue;}
      tprev[i][j].s = lcp(V[tprev[i][j].f], V[i]);
      }
    }
  }
  
int miejsce[MXN];
  
int dp[1<<(slow-1)];
bool go(int mask, int a, int b)//wolne
  {
  REP(mask, 1<<x)dp[mask] = a;
  
  REP(mask, 1<<x)
    {
    a = dp[mask];
    if(a > b)return 1;
    int idx = miejsce[a];
    REP(i, x)
      {
      if(mask & (1<<i))continue;    
      int dlu = max(tprev[idx][i].s, tnxt[idx][i].s); 
      maxi(dp[mask | (1<<i)], a + dlu);
//      if(a + dlu > b)return 1;
      }
    }
  return 0;
  }

int main()
{
scanf("%d%d",&x,&q);

REP(i, x+1)
  {
  scanf("%d",&dlu[i]);
  REP(j, dlu[i])
    {
    scanf(" %c",&in[i][j]);
    }
  }
pre();
// 50minut?


REP(i, x+1)
  {
  REP(j, dlu[i])
    V.PB(slo(i, j, dlu[i]-1, h[i]));
  }
sort(ALL(V), cmp);

/*
REP(i, V.size())
  {
  cerr<<i<<" poc: "<<V[i].a<<" nr: "<<V[i].nr<<endl;
  }
*/


reverse(ALL(V));
calctprev();
FOR(i, 0, (int)V.size()-1)
  {
  REP(j, x+1)
    {
    int x = tprev[V.size()-i-1][j].f;
    if(x == -1){tnxt[i][j].f = -1; continue;}
    tnxt[i][j].f = V.size() - x - 1;
    tnxt[i][j].s = tprev[V.size()-i-1][j].s;
    
    }
  }
reverse(ALL(V));

calctprev();
REP(i, V.size())
  {
  if(V[i].nr == x)miejsce[V[i].a] = i;
  }

/*FOR(i, 0, V.size()-1)
  {
  REP(j, x+1)
    {
    cerr<<i<<" "<<j<<" poc: "<<V[i].a<<" nr: "<<V[i].nr<<" prev: "<<
      tprev[i][j].f<<" lcp: "<<tprev[i][j].s<<endl;
    }
  cerr<<endl;
  }*/


REP(i, q)
  {
  int a, b;
  scanf("%d%d",&a,&b);
  a--;
  b--;
  puts(go(0, a, b)?"TAK":"NIE");
  }
  

  
}
/*
4 10
2 aa
2 bb 
2 cc
2 dd
13 abcdaabbccdde
1 4

0 poc: 1 nr: 0
1 poc: 0 nr: 0
2 poc: 0 nr: 4
3 poc: 5 nr: 4
4 poc: 4 nr: 4
5 poc: 1 nr: 1
6 poc: 0 nr: 1
7 poc: 7 nr: 4
8 poc: 6 nr: 4
9 poc: 1 nr: 4
10 poc: 2 nr: 4
11 poc: 9 nr: 4
12 poc: 8 nr: 4
13 poc: 1 nr: 2
14 poc: 0 nr: 2
15 poc: 3 nr: 4
16 poc: 1 nr: 3
17 poc: 0 nr: 3
18 poc: 10 nr: 4
19 poc: 11 nr: 4
20 poc: 12 nr: 4


4 10
2 aa
2 bb 
2 cc
2 dd
13 abcdaabbccdde
5 6
TAK
5 8
TAK
5 12
TAK
5 13
NIE

*/
