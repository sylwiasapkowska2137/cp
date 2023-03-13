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
const int MXN = 1e6+5;
int in[MXN];
int out[MXN];
int low[MXN];
int acctime = 1;
VI V[MXN];
void dfs(int a, int pp = 0)
  {
  in[a] = low[a] = acctime++;
  
  for(auto it:V[a])
    {
    if(it == pp)continue;
    if(in[it])
      {
      mini(low[a], in[it]);
      continue;
      }
    dfs(it, a);
    mini(low[a], low[it]);
    }
  
  out[a] = acctime++;
  }
bool subtree(int a, int b)//czy b jest pod a
  {
  return in[a] <= in[b] && out[b] <= out[a];
  }
bool ans(int a, int b, int x, int y)
  {
  if(in[x] > in[y])swap(x, y);//x nad y
  if(low[y] <= in[x])return 1;
  if(subtree(y, a) + subtree(y, b) == 1)return 0;
  return 1;
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
  
  dfs(1);
  //FOR(i,1,n)cerr<<i<<" "<<low[i]<<" "<<in[i]<<" "<<out[i]<<endl;
  int nie = 0;
  REP(i, q)
    {
    int a, b, x, y;
    scanf("%d%d%d%d",&a,&b,&x,&y); // x,y - usunieta krawedz
    bool r = ans(a, b, x, y);
    puts(r?"TAK":"NIE");
    if(r == 0)nie++;
    }
  cerr<<"nie: "<<nie<<endl;
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
