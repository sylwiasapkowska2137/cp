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
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
using namespace std;
const int MXN=1e6+6;
const int MXF=2e4+1;
int remflow[MXF];


const int inf=1e9;
struct MAXFLOWMINCOST
  {
  struct edge
    {
    int to,flow,cost,index;    
    edge(int _to,int _flow,int _cost,int _index)
      {
      to=_to;
      flow=_flow;
      cost=_cost;
      index=_index;      
      }
    };
  vector<edge> *V;
  int *cost;
  PII *pop;
  int s,t,n;
  int FLOW;
  int COST;
  MAXFLOWMINCOST(int _n,int _s,int _t)
    {
    n=_n;
    s=_s;
    t=_t;
    V=new vector<edge>[n+1]; 
    cost=new int[n+1]; 
    pop=new PII[n+1];
    FLOW=COST=0;
    }
  void addedge(int a,int b,int flow,int cost)
    {
    V[a].PB(edge(b,flow,cost,V[b].size()));
    V[b].PB(edge(a,0,-cost,V[a].size()-1));
    }
  void findpath(int s)//SPFA, ale najszybsze na randomowych
    {
    FOR(i,0,n)cost[i]=inf;
    FOR(i,0,n)pop[i]=MP(-1,0);
    cost[s]=0;
    queue<PII> q;
    q.push(MP(0,s));
    while(q.size())
      {
      int v=q.front().s;
      int c=q.front().f; 
//      cerr<<v<<" "<<c<<endl;
      q.pop();
      if(c!=cost[v])continue;
      REP(i,V[v].size())
        {
        if(V[v][i].flow==0)continue;
        if(cost[V[v][i].to]<=cost[v]+V[v][i].cost)continue;
        cost[V[v][i].to]=cost[v]+V[v][i].cost;
        pop[V[v][i].to]=MP(v,i);
        q.push(MP(cost[V[v][i].to],V[v][i].to));
        }
      }
    }
  void reduce(int a,int index)
    {
    V[a][index].flow--;
    int b=V[a][index].to;
    int in2=V[a][index].index;
    V[b][in2].flow++;
    }
  void calc()  
    {
    while(1)
      {
      findpath(s);
      if(pop[t].f==-1)break;
      COST+=cost[t];
      FLOW++;
      remflow[FLOW]=COST;
      int x=t;
      while(x!=s)
        {
        reduce(pop[x].f,pop[x].s);
        x=pop[x].f;        
        }
      }
    }
  };
//************************
int m,S,P,q,a,b,c,d;
int tS[101];
int tP[101];

main()
{
scanf("%d%d%d",&m,&S,&P);
//sklepy od 1 do 100
MAXFLOWMINCOST FFF(202,0,201);
FOR(i,1,S)
	{
	scanf("%d",&a);
	FFF.addedge(0,i,a,0);
	}
FOR(i,1,P)
	{
	scanf("%d",&a);
	FFF.addedge(100+i,201,a,0);
	}
FOR(i,1,m)
	{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	FFF.addedge(b,a+100,c,d);
	}
FFF.calc();
cerr<<FFF.FLOW<<" "<<FFF.COST<<endl;
scanf("%d",&q);
FOR(i,1,q)
	{
	scanf("%d",&a);
	if(FFF.FLOW<a)
		{
		puts("-1");
		continue;
		}
	printf("%d\n",remflow[a]);
	}
}

