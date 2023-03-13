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
int n, m, q;
const int MXN = 1e6;
int in[MXN];
VI V[MXN];
int acctime = 1;
bool dfs(int a, int b, int x, int y)
  {
//  cerr<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
  if(a == b)return 1;
  in[a] = acctime;
  
  for(auto it:V[a])
    {
    if(in[it] == acctime)continue;
    if((a == x && it == y) || (a == y && it == x))continue;
    if(dfs(it, b, x, y))
      return 1;
    }
  return 0;
  }

int main()
  {
  scanf("%d%d%d",&n, &m, &q);
  REP(i, m)
    {
    int a, b;
    scanf("%d%d",&a,&b);
    V[a].PB(b);
    V[b].PB(a);
    }
  REP(i, q)
    {
    acctime++;
    int a, b, x, y;
    
    scanf("%d%d%d%d",&a,&b,&x,&y); // x,y - usunieta krawedz
    puts(dfs(a, b, x, y)?"TAK":"NIE");
    }
  }
  
/*
5 4 2
1 2
2 3
3 4
4 5
1 4
1 5 4 5
1 5 1 4

NIE
TAK
*/
