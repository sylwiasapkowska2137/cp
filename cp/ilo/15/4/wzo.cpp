#include <set>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
 
int ile;
int res = 0;
ll ile_przedz;
vector< int > calaSuma;
vector< int > ileprzedz;
set< pair< int, int > > S;
vector< pair< int, int > > tab;
 
inline int licz ( int l, int p )
{
        return ( (ll)( p - l + 1 ) * ( p - l + 2 ) / 2 ) % mod;
}
 
inline int foo ( int l, int p )
{
        int tmp = ( (ll)calaSuma[l] * (p + 1) ) % mod;
        int tmp2 = ( (ll)calaSuma[p] * (l + 1) ) % mod;
        return ( tmp + tmp2 ) % mod;
}
 
void dodaj ( int v, int ind )
{
//      cout << v << ' ' << ind << '\n';
        set< pair< int, int > >::iterator it = S.lower_bound( { ind, 0 } );
        ile_przedz = ( ( ( ile_przedz - licz( (*it).second, (*it).first ) ) % mod ) + mod ) % mod;
        int l = ind - (*it).second;
        int p = (*it).first - ind;
//      cout << "lp " << l << ' ' << p << '\n';
        res = ( res + ( ( ( ( ( (ll)(l + 1) * (p + 1) ) % mod * ile_przedz ) % mod ) * v ) % mod ) ) % mod;
        res = ( res + ( ( (ll)foo( l, p ) * v ) % mod ) ) % mod;
//      cout << ( ( ( ( ( (ll)(l + 1) * (p + 1) ) % mod * ile_przedz ) % mod ) * v ) % mod ) << ' ';
//      cout << ( ( (ll)foo( l, p ) * v ) % mod );
//      cout << '\n';
        if ( ind != (*it).first )
        {
                S.insert( { (*it).first, ind + 1 } );
                ile_przedz = ( ile_przedz + licz( ind + 1, (*it).first ) ) % mod;
        }
        if ( ind != (*it).second )
        {
                S.insert( { ind - 1, (*it).second } );
                ile_przedz = ( ile_przedz + licz( (*it).second, ind - 1 ) ) % mod;
        }
        S.erase( it );
}
 
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> ile;
        tab.resize( ile );
        ileprzedz.resize( ile + 1 );
        calaSuma.resize( ile + 1 );
        for ( int i = 1; i <= ile; ++i )
                ileprzedz[i] = ( ( (ll)i * ( i + 1 ) ) / 2 ) % mod;
        for ( int i = 1; i <= ile; ++i )
                calaSuma[i] = ( calaSuma[i - 1] + ileprzedz[i] ) % mod;
        S.insert( { ile - 1, 0 } );
        ile_przedz = ( ile_przedz + licz( 0, ile - 1 ) ) % mod;
        for ( int i = 0; i < ile; ++i )
        {
                cin >> tab[i].first;
                tab[i].second = i;
        }
        sort( tab.begin(), tab.end() );
        for ( int i = 0; i < ile; ++i )
                dodaj( tab[i].first, tab[i].second );
        cout << res << '\n';
}
 