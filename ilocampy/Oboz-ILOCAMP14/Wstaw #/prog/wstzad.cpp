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
const int MXN = 1e5+6;
LL p = 211, P = 1e18+7; 
LL h[MXN];
LL pot[MXN];
char buf[MXN];
int n;
LL il(LL a, LL b)
    {
    return __int128_t(a) * b % P;
    }
LL hasz(int a, int b)
    {
    return ((h[b] - il(h[a-1], pot[b-a+1])) % P + P) % P;
    }
map<LL, int> m;
int usu;
bool check(int k) 
    //jeśli po usunięciu każdego znaku istnieje równa para słów o długości k daje 0
    //jeśli istnieje taki znak że para słów jest różna to wynik to 1
    {
    m.clear();
    int cntok = 0;
    FOR(i, 2, n-k+1)
        {
        m[hasz(i, i+k-1)]++;
        if(m[hasz(i, i+k-1)] == 2)cntok++;
        }
    usu = 1;
    if(cntok == 0)return 1;
    FOR(i, 2, n)
        {
        if(i + k - 1 <= n)
            {
            m[hasz(i, i+k-1)]--;
            if(m[hasz(i, i+k-1)] == 1)cntok--;
            }
        if(1 <= i - k)
            {
            m[hasz(i-k,i-1)]++;
            if(m[hasz(i-k,i-1)] == 2)cntok++;
            }
        if(cntok == 0){usu = i;return 1;}
        }
    return 0;
    }
int main()
{
scanf("%d ", &n);
pot[0] = 1;
FOR(i, 1, n)
    {
    buf[i] = getchar_unlocked();
    pot[i] = il(pot[i-1], p);
    h[i] = (il(h[i-1], p) + buf[i]) % P;
    }
int poc = 1;
int kon = n;
int sr = -1;
while(sr != (poc + kon) >> 1)
    {
    sr = (poc + kon) >> 1;
    if(check(sr))kon = sr;
    else poc = sr + 1;
    }

while(check(poc) == 0)poc++;
assert(check(poc) == 1);
printf("%d %d\n", poc, usu);
}
