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
int n, k;
map<PII, int> memo;
int calc(int ruch, int jed)
    {
    if(jed < 0 || jed > n)return -1e9;
    if(memo.count(MP(ruch, jed)))return memo[MP(ruch, jed)];
    int zer = n - jed;
    if(0 == ruch)return jed;
    int r = 0;
    FOR(i, 0, min(jed, k))
        {
        int jee = i;
        int zee = k - i;
        if(zee > zer)continue;
        int newjed = jed - jee + zee;
        int newzer = zer - zee + jee; 
        maxi(r, calc(ruch - 1, newjed));
        }
    memo[MP(ruch, jed)] = r;
    return r;
    }
int main()
{

scanf("%d%d",&n,&k);
int jed = 0;
FOR(i, 1, n)
    {
    char ch;
    scanf(" %c", &ch);
    if(ch == '1')jed++;
    }
FOR(i, 1, n)
    cout<<calc(i, jed)<<endl;
}
