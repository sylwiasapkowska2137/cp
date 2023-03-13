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
int n;
map<int,int> M;
int in[MXN];
int ID;
VI V[MXN];
int res;
const int BASE=1<<21;
const int ADD=MXN+4;
struct TREE
	{
	int t[BASE*2];
	VI q;
	TREE()
		{
		REP(i,2*BASE)
			t[i]=1e9;
		}
	void insert(int a,int v,bool b=1)
		{
		if(b)q.PB(a);
		a+=ADD;
		a+=BASE;
		mini(t[a],v);
		a/=2;
		while(a)
			{
			t[a]=min(t[a*2],t[a*2+1]);
			a/=2;
			}
		}
	int query(int y)//minimum z mniejszych od x
		{
		y+=ADD;
		y+=BASE;
		int x=BASE;
		int ret=1e9;
		while(x/2!=y/2)
			{
			if(x%2==0)mini(ret,t[x+1]);
			if(y%2==1)mini(ret,t[y-1]);
			x/=2;
			y/=2;
			}
		return ret;
		}
	void clear()
		{
		REP(i,q.size())
			{
			t[q[i]+BASE+ADD]=1e9;
			insert(q[i],1e9,0);
			}
		q.clear();
		}
	}X;
int sumpref[MXN];

void calc(int x)
	{
	int sum=0;
	int poz=0;
	X.insert(0,0);
	REP(i,V[x].size())
		{
		sum-=(V[x][i]-poz-1);
		poz=V[x][i]-1;
		X.insert(sum,poz);
		sumpref[poz]=sum;
		sum++;
		poz++;
		int pom=X.query(sum);
		int zostalo=pom+(n-poz);
		//przedział [pom,poz]
		int dl=poz-pom+min(sum-sumpref[pom]-1,zostalo);
//		cout<<"val = "<<x<<" idx= ["<<pom+1<<", "<<poz<<"] wyn= "<<dl<<endl;
		maxi(res,dl);
		}
	X.clear();
	}
main()
{
scanf("%d",&n);
FOR(i,1,n)
	{
	scanf("%d",&in[i]);
	M[in[i]]=1;
	}

for(auto &it:M)
	it.s=++ID;

FOR(i,1,n)
	{
	in[i]=M[in[i]];
	V[in[i]].PB(i);
	}
FOR(i,1,n)calc(i);
printf("%d\n",res);
}
