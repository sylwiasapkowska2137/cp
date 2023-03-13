#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long mod=1000000007;

vector <long long> dzie;
long long phi[1000007];

long long wyn;

long long pot(long long a, long long b)
{
    a%=mod;
    long long ret=1;
    while(b)
    {
        if (b&1)
        {
            ret*=a;
            ret%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ret;
}

long long dziel(long long a, long long b)
{
    return (a*pot(b, mod-2))%mod;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    for (long long i=1; i*i<=n; i++)
    {
        if (!(n%i))
        {
            dzie.push_back(i);
            if (i*i!=n)
                dzie.push_back(n/i);
        }
    }
    sort(dzie.begin(), dzie.end());
    phi[0]=1;
    for (int i=1; i<(int)dzie.size(); i++)
    {
        for (int j=i-1; 1; j--)
        {
            if (!(dzie[i]%dzie[j]))
            {
                long long x=dzie[i]/dzie[j];
                phi[i]=phi[j];
                if (!((dzie[i]/x)%x))
                    phi[i]*=x;
                else
                    phi[i]*=x-1;
                break;
            }
        }
    }
    for (int i=0; i<(int)dzie.size(); i++)
    {
        wyn+=pot(k, n/dzie[i])*phi[i];
        wyn%=mod;
    }
    wyn=dziel(wyn, n);
    printf("%lld\n", wyn);
    return 0;
}
