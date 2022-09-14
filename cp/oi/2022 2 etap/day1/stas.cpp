#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n, k, c;
vector<LL> primes;

void factor(LL x)
{
    for(LL i=2;i*i<=x;i++)
    {
        if(x%i==0)primes.push_back(i);
        while(x%i==0)
        {
            x/=i;
        }
    }
    if(x>=2)primes.push_back(x);
}

LL invmob(LL x)
{
    LL a=primes.size();
    LL b=1<<a;
    LL res=x;
    for(LL i=1;i<b;i++)
    {
        LL y=1;
        LL cnt=0;
        LL cntb=__builtin_popcount(i);
        for(LL j=1;j<b;j*=2)
        {
            if(i&j)
            {
                y*=primes[cnt];
            }
            cnt++;
        }
        if(cntb%2==1)
        {
            res-=x/y;
        }
        else
        {
            res+=x/y;
        }
    }
    return res;
}

bool iscopr(LL x)
{
    for(LL i=0;i<primes.size();i++)
    {
        if(x%primes[i]==0)return 0;
    }
    return 1;
}

LL binsearch(LL l, LL r, LL val)
{
    LL mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(invmob(mid)==val)
        {
            if(invmob(mid-1)<val)return mid;
            else
            {
                r=mid;
            }
        }
        if(invmob(mid)<val)
        {
            l=mid+1;
        }
        if(invmob(mid)>val)
        {
            r=mid;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>c;
    factor(n);
    if(c<=100)
    {
        for(LL i=k;i<k+c;i++)
        {
            cout<<binsearch(0LL, 1e18, i)<<' ';
        }
    }
    else
    {
        LL beg=binsearch(0LL, 1e18, k);
        LL cnt=0;
        for(LL i=beg;cnt<c;i++)
        {
            if(iscopr(i))
            {
                cout<<i<<' ';
                cnt++;
            }
        }
    }
    return 0;
}
