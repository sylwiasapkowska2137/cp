#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int q, point;

vector<vector<int> >G;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    {
        int a1=1, a2=1;
        vector<int> V;
        V.assign(q+2, 0);
        V[0]=1;
        V[1]=2;
        point =2;
        for(int i=0;i<q;i++)
        {
            char x;
            int a;
            cin>>x>>a;
            if(x=='?')
            {
                if(V[a-1]==1)cout<<a2<<endl;
                else cout<<a1<<endl;
            }
            if(x=='Z')
            {
                if(V[a-1]==1)
                {
                    V[point]=1;
                    a1++;
                }
                else
                {
                    V[point]=2;
                    a2++;
                }
                point++;
            }
        }
    }

    return 0;
}
