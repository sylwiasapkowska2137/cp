#include <iostream>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, h;
    long long x, w;
    long long pot[61];
    pot[0] = 1;
    for(int i=1; i<= 60; i++)
        pot[i] = pot[i-1]*2;
 
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n >> x;
        if( x==1)
            w = n;
        else
        {
            if( x >= pot[n-1])
                w = 1;
            else
            {
                h = 0;
                while( x > 0)
                {
                    h++;
                    x /= 2;
                }
                h = n-h;
                if( 2*h < n)
                    w = h + pot[h];
                else
                    w = h - 1 + pot[n-h] + (pot[n-h-1]-1)*(pot[2*h-n+1]-2);
            }
        }
        cout <<  pot[n] - 1 - w << "\n";
 
    }
    return 0;
}