/***** Author : Kunal *****/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <cmath>
#include <cstdio>
#include <queue>
#include <list>
#include <stack>
#include <utility>
#include <numeric>
#include <map>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <set>

using namespace std;

#define F(a,b) for(int a=0;a<b;a++)
#define REP(a,b) for(int a=0;a<b;a++)
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)

#define S scanf
#define P printf

#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define INF 1000000000

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;

//int d[][2]={{-1.0},{1,0},{0,-1},{0,1}};

PII A[2000005];

int main()
{
	int t; S("%d",&t);
	int n;
	while( t-- )
	{
		S("%d", &n);
		REP(i, n)
		{
			S("%d", &A[i].first);
			A[i].second = i;
		}
		sort( A, A+n);
		int ctr = 0 ;
		int prev = -1;
		int prevVal = -1;
		int lastend = -1;
		int nxtlastend = -1;
		REP(i,n)
		{
			if( prevVal != A[i].first )
			{
				if( prev > A[i].second ) ctr++;
				prev = A[i].second;
				prevVal = A[i].first;
				lastend = nxtlastend;
				nxtlastend = prev;
			}
			else
			{
				if( lastend < A[i].second && prev < lastend )
				{;
				}
				else
				{
					if( prev > A[i].second ) { ctr++; }
					prev = A[i].second;
					prevVal = A[i].first;
					nxtlastend = prev;
				}
			}

		}
		/*if( ctr < 3 )
			P("%d\n", ctr );
		else if( ctr == 3 ) P("2\n");
		else P("3\n");*/
		REP(i,20 )
		{
			if( ctr < (1<<i) ) { P("%d\n", i ); break; }
		}
	}
	return 0;
}