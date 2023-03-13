#include<bits/stdc++.h>
using namespace std;
int n,d,mini,a[1000010],ile_scal;
multiset <int> se;
pair <int,int> tab[1000010];
long long tree[4000010],m=1;
long long query(int L, int R)
{
    L+=m-1;
    R+=m+1;
    long long wyn=0;
    while(L/2!=R/2)
    {
        if(L%2==0)wyn=max(tree[L+1],wyn);
        if(R%2!=0)wyn=max(tree[R-1],wyn);
        L=L/2;
        R=R/2;
    }
    return wyn;
}
void Add(int gdzie,long long co)
{
    gdzie+=m;
    while(gdzie>0)
    {
        tree[gdzie]=max(co,tree[gdzie]);
        gdzie=gdzie/2;
    }
}
int main()
{
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i].first;
        tab[i].second=i-1;
    }
    sort(tab+1,tab+n+1);
    for(int i=1;i<=n;i++)
    {
        if(tab[i].first!=tab[i-1].first) ile_scal++;
        a[tab[i].second]=ile_scal;
    }
    while(ile_scal+2>m)
    {
        m=m*2;
    }
    mini=ile_scal+1;
    for(int i=n-1;i>0;i--)
    {
        if(i<=n-d-1)
        {
            mini=max(*se.begin(),mini);
            se.erase(se.find(a[i+d]));
        }
        if(a[i]<=mini) Add(a[i],query(a[i]+1,mini)+1);
        se.insert(a[i]);
        
    }
    cout<< query(0,ile_scal+1);
}