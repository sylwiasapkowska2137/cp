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

const int lg = 25; 
bitset<1<<lg> B; //33554432, 4MB
int main()
{
int n;           // 5e7
int toand = (1<<lg) - 1;
int mask = 0;
scanf("%d ", &n);
VI pom;
FOR(i, 1, n)
    {
    int x = getchar_unlocked() - '0';
    mask <<= 1;
    mask &= toand;
    mask |= x;
    if(i <= lg)pom.PB(mask);
    else B[mask] = 1;
    }
int res = lg + 1;
FORD(i, lg, 1)
    {
    B[pom.back()] = 1;
    pom.pop_back();
    REP(j, 1<<i)
        {
        if(B[j] == 0)
            {
            mini(res, i);
            }
//        cerr<<i<<" "<<bitset<7>(j)<<" "<<B[j]<<endl;
        }
//    B |= B >> (1<<(i-1));
    FOR(j, (1<<(i-1)), (1<<i)-1)
        B[j - (1<<(i-1))] = B[j - (1<<(i-1))] | B[j];
    }
printf("%d\n", res);
}
