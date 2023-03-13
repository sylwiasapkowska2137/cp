using namespace std;

#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <utility>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

#define oo (1<<30)
#define f first
#define s second
#define ll long long
#define db double
#define II inline
#define mp make_pair
#define pb push_back
#define Size(V) ((int)(V).size())
#define all(V) (V).begin(), (V).end()
#define CC(V) memset((V),0,sizeof((V)))
#define CP(A,B) mempcy((A),(B),sizeof((B)))
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
#define REP(i,b) for(int (i)=(0);(i)<(int)(b);++(i))
#define FORit(it,V) for(__typeof((V).begin()) it = (V).begin();it != (V).end();++it)

#define IN "code.in"
#define OUT "code.out"
#define N_MAX (1<<17)
#define Pars (1<<19)

typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<string> VS;

int K,N,T;
char buffer[Pars];
vector<pi> V;

II void read(int &aux)
{
	aux = 0;
	for(;buffer[K] < '0' || buffer[K] > '9';)
	{
		if(++K == Pars) 
			fread(buffer,1,Pars,stdin),K =0;
	}
	
	for(;buffer[K] >= '0' && buffer[K] <= '9';)
	{
		aux = aux * 10 + buffer[K] - '0';
		if(++K == Pars) 
			fread(buffer,1,Pars,stdin),K = 0;
	}
}

II void scan()
{
	//freopen(IN,"r",stdin);
	//freopen(OUT,"w",stdout);
	scanf("%d",&T);
}

II void solve()
{
	V.resize(0);
	read(N);
	
	int x;
	FOR(i,1,N)
	{
		read(x);
		V.pb( mp(x,i) );
	}
	
	sort( all(V) );
	
	int j = 0,i = 0,cnt = 1,rez = 0,prev = -1;
	
	while(i < N)
	{
		j = i + 1;
		while(j < N && V[j].f == V[i].f)
			++j;
		
		if(V[i].s > prev)
			prev = V[j-1].s;
		else
		{
			++cnt;
			int k = i;
			while(k < j && V[k].s < prev)
				++k;
			
			--k;
			prev = V[k].s;
		}
		i = j;
	}	
	
	for(;cnt > 1;)
	{
		++rez;
		cnt = (cnt + 1) / 2;
	}
	
	printf("%d\n",rez);
}

int main()
{
	scan();
	REP(ti,T)
		solve();
	return 0;
}
