#include<iostream>

using namespace std;

int main()
{
        int i,j,n,m,t,l;
        cin>>n>>m;
        l = 0;
        for(i=1;i<=n;i++)
        {
                cin>>j;
                if(j%m==0)
                        j /= m;
                else
                        j = j/m +1;

                if(j >= l)
                {
                        l = j;
                        t = i;
                }
        }
        cout<<t<<"\n";

        return 0;
}