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
#define int LL
const int MXN = 1e5+5;
const int DZIEL = 700;
LL wart[MXN];
LL hasz[MXN][DZIEL];//hasz części 'urotowanej'
LL numa[MXN][DZIEL];//pierwszy większy wyżej podzielny przez dzielnik[dziel] 
LL siz[MXN];
LL ha[MXN];
VI V[MXN];
vector<int> dziel; // możliwe wielkości części

int expectedhasz[DZIEL]; // dla itego dzielnika jaki jest oczekiwany czas
int dzielok[DZIEL]; // ile jest okej haszy dla itego dzielnika
int expectedok[DZIEL]; // rozmiar dla dzielok (n / dziel[i])
int res; // ile dzielników ma dzielok[i] = expectedok[i]
int dfs(int a, int p)
    {
    siz[a] = 1;
    for(auto it : V[a])
        {
        if(it == p)continue;
        siz[a] += dfs(it, a);
        }
    return siz[a];
    }
void dfs2(int a, int p)
    {
    REP(i, dziel.size())
        {
        if(siz[a] % dziel[i] == 0)
            numa[a][i] = a;
        else
            numa[a][i] = numa[p][i];
        }
    for(auto it : V[a])
        {
        if(it == p)continue;
        dfs2(it, a);
        }
    }
void change_numa(int v, LL val)
    {
    REP(i, dziel.size())
        {
        int fat = numa[v][i];
        int prev = hasz[fat][i] == expectedhasz[i];
        hasz[fat][i] += val - wart[v];
        int now = hasz[fat][i] == expectedhasz[i];
        int prevok = dzielok[i] == expectedok[i];
        if(prev == 1 && now == 0)dzielok[i]--;
        if(prev == 0 && now == 1)dzielok[i]++;
        int nowok = dzielok[i] == expectedok[i];
        if(prevok == 1 && nowok == 0)res--;
        if(prevok == 0 && nowok == 1)res++;
        }
    wart[v] = val;
    }
main()
{
int n, q, k;
scanf("%lld%lld%lld",&n,&k,&q);
FOR(i, 1, k)
    ha[i] = rand();// * 1000000000LL + rand();

FOR(i, 1, n/k)
    if(n % (i * k) == 0)dziel.PB(i * k);
REP(i, dziel.size())
    {
    FOR(j, 1, k)
        {
        expectedhasz[i] += ha[j] * (dziel[i]/k);
        cerr<<j<<" "<<expectedhasz[i]<<endl;
        expectedok[i] = n / dziel[i];
        }
    
    }

REP(i, n-1)
    {
    int a, b;
    scanf("%lld%lld", &a, &b);
    V[a].PB(b);
    V[b].PB(a);
    }
dfs(1, 0);
dfs2(1, 0);

FOR(i, 1, n)
    {
    int x;
    scanf("%d", &x);
    change_numa(i, ha[x]);
    }
cerr<<dziel.size()<<endl;
REP(i, dziel.size())
    {
    cerr<<i<<" rozmiar spójnej: "<<dziel[i]<<" ile spójnych: "<<dzielok[i]<<" "<<expectedok[i]<<endl;
    FOR(j, 1, n)
        {
        if(numa[j][i] == j)
            {
            cerr<<i<<" "<<hasz[j][i]<<" "<<expectedhasz[i]<<endl;
            }
        }
    }
printf("%d\n", res);
REP(i, q)
    {
    int v, x;
    scanf("%d%d", &v, &x);
    change_numa(v, ha[x]); 
    printf("%d\n", res);
    }
}
