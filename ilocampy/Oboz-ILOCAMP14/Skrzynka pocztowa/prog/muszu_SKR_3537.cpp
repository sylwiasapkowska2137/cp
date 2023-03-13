#include <bits/stdc++.h>
using namespace std;
int n,lista,sasiad;
int t[1000005];
int main ()
{
    ios_base::sync_with_stdio(0);

    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> t[i];
    }

    for(int i=1; i<=n; i++)
    {

        if(t[i]==1)
        {
            sasiad++;
        }
        if(t[i]==1 && t[i+1]==0 && i!=n)
        {
            lista++;
        }



    }
    cout << lista + sasiad;

}
