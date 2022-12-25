#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
#define st first
#define nd second
//#define p first
//#define k second
//#define op pair<int,int>
#define mp make_pair
 
const int roz = 2 * 1e5 + 10;
const ll mod = 1e9 + 7;
 
ll sum[roz];
ll ssum[roz];//suma sum
int ciag[roz];
pair <int, int> sor[roz];
ll wyn[roz];
 
struct op
{
    int p, k;//poczatek i koniec
};
bool operator <(const op& x, const op& y)
{
    return x.p < x.k;
}
set <pair <int, op> > prze;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n, i, j;
    cin>>n;
 
    for(i = 1; i <= n; i++)
    {
        cin>>ciag[i];
        sor[i] = make_pair(ciag[i], i);
    }
    sort(sor, sor + n + 1);
 
    for(i = 1; i <= n; i++)
    {
        sum[i] = (sum[i - 1] + i) % mod;
    }
 
    for(i = 1; i <= n; i++)
    {
        ssum[i] = (ssum[i - 1] + sum[i]) % mod;
    }
 
 
    ll aktsum = 0;//suma na ile mozna wybrac przedzialy poza przedzialem w ktorym sie aktualnie znajduje
    op pom;
    pom.p = 1;
    pom.k = n;
    prze.insert(make_pair(pom.p, pom));
    aktsum = (aktsum + sum[pom.k - pom.p + 1]) % mod;
    //cout<<1;
 
    for(i = 1; i <= n; i++)
    {
        //cout<<i<<" "<<sor[i].nd<<" "<<sor[i].st<<"\n";
        //for(set<pair<int, op> >::iterator it = prze.begin(); it != prze.end(); it++)
        //    cout<<it->first<<" "<<it->second.p<<" "<<it->second.k<<", ";
        wyn[sor[i].nd] = 0;
 
        op pom;
        pom.p = mod;
        set <pair <int, op> >::iterator it = prze.upper_bound(make_pair(sor[i].nd, pom));
        //cout<<(it == prze.end());
        it--;
 
        pom = (it)->second;
        //cout<<pom.p<<" "<<pom.k<<" ";
        //cout<<"!!!"<<((it) == prze.end());
        ll p = 1;
        ll k = pom.k - pom.p + 1;
        ll a = sor[i].nd - pom.p + 1;
        wyn[sor[i].nd] = (mod + aktsum - sum[k - p + 1]) % mod;
        //cout<<" "<<wyn[sor[i].nd];
        wyn[sor[i].nd] = (((wyn[sor[i].nd] * (k - a + 1)) % mod) * a) % mod;
        //cout<<"\n"<<wyn[sor[i].nd];
        //cout<<"\n"<<((k - a + 1) * (ssum[a - 1])) % mod<<" "<<((a - p + 1) * (ssum[k - a])) % mod<<"\n";
        wyn[sor[i].nd] = (mod + wyn[sor[i].nd] + ((k - a + 1) * (ssum[a - 1])) % mod) % mod;
        wyn[sor[i].nd] = (mod + wyn[sor[i].nd] + ((a - p + 1) * (ssum[k - a])) % mod) % mod;
 
        //cout<<pom.p<<" "<<pom.k<<" "<<sor[i].st<<" "<<sor[i].nd<<", ."<<p<<" "<<a<<" "<<k<<". ";
 
        aktsum = (mod + aktsum - sum[k - p + 1]) % mod;
        aktsum = (aktsum + sum[a - 1] + sum[k - a]) % mod;
        //cout<<3;
        op pom2;
        pom2.p = mod;
        prze.erase(it);
        p = pom.p;
        k = pom.k;
        //cout<<4;
 
        pom.p = p;
        pom.k = sor[i].nd - 1;
        //cout<<"\n"<<p<<" "<<pom.p<<" "<<pom.k;
        if(pom.k - pom.p >= 0)
            prze.insert(mp(p, pom));
        //prze.insert(make_pair(pom.p, pom));
        //cout<<5;
        pom.p = sor[i].nd + 1;
        pom.k = k;
        if(pom.k - pom.p >= 0)
            prze.insert(mp(pom.p, pom));
        //cout<<i;
        //cout<<"\n\n";
    }
 
    //for(i = 1; i <= n; i++)
    //    cout<<wyn[i]<<" ";
 
    ll odp = 0;
    for(i = 1; i <= n; i++)
    {
        odp = (odp + (wyn[i] * ciag[i]) % mod) % mod;
    }
    cout<<odp;
}