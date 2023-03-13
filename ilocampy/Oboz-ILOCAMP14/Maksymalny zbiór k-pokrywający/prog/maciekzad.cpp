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
const int MXN = 1e5+5;
VPII V[MXN];
int cnt[MXN];
int R(int a, int b)
    {
    return rand() % (b-a+1) + a;
    }

LL result;



void addvertex(int v)
    {
    assert(cnt[v] == 0);
    for(auto it : V[v])
        {
        if(cnt[it.f] == 0)
            {
            result += it.s;
            }
        }
    cnt[v] = 1;
    }
void removevertex(int v)
    {
    assert(cnt[v] == 1);
    for(auto it : V[v])
        {
        if(cnt[it.f] == 0)
            {
            result -= it.s;
            }
        }
    cnt[v] = 0;
    }
void change(int x)
    {
    if(cnt[x] == 1)removevertex(x);    
    else if(cnt[x] == 0)addvertex(x);
    }
main()
{
int n, k;
scanf("%d%d", &n, &k);

VPII zach;
FOR(i, 1, n-1)
    {
    int a, b, w;
    scanf("%d%d%d",&a,&b,&w);
    V[a].PB(MP(b, w));
    V[b].PB(MP(a, w));
    
    zach.PB(MP(w, R(0, 1) == 0 ? a : b));
    }
sort(ALL(zach));
reverse(ALL(zach));

int cn = 0;
for(auto it : zach)
    {
    if(cnt[it.s] == 0)
        {
        addvertex(it.s);
        cn++;
        }
    if(cn == k)break;
    }
int x = 1;
while(cn < k)
    {
    while(cnt[x] == 0)x++;
    cnt[x] = 1;
    x++;
    cn++;
    }
    
    
int bezzmiany = 0;
REP(uuu, 1000000)
    {
    bezzmiany++;
    int a = 1; 
    int b = 1; 
    do
        {
        a = R(1, n);
        b = R(1, n);
        }
    while(cnt[a] == cnt[b]);
    
    LL resbefore = result;
    change(a);
    change(b);
    LL resafter = result;

//    cerr<<resafter<<endl;

    if(resafter > resbefore || bezzmiany > 100000)
        {
        bezzmiany = 0;
        //ok
        }   
    else
        {
        change(a);
        change(b);
        } 
    }
cerr<<result<<endl;
int kkk = 0;

printf("%lld\n", result);
FOR(i, 1, n)
    if(cnt[i])
        {
        kkk++;
        printf("%d ", i);
        }
//cerr<<kkk<<" "<<k<<endl;
assert(kkk == k);
}
