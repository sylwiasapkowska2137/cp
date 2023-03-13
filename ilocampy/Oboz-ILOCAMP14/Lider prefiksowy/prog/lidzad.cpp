#include <iostream>
#include <map>
#include <vector>
using namespace std;
map <int,int> powtorzenia;
map <int,int> powtorzenia_prefiksow;
vector<int> v;
int main()
{
        ios_base::sync_with_stdio(0);
        int n, tmp;
        int l = 0;
        int w = 0;
 
        cin>>n;
        for(int i = 1; i <= n; i++)
        {
                cin>>tmp;
 
                powtorzenia[tmp]++;
 
                if( tmp != w && i != 1 && l > 0  ) l--;
                else
                {
                        w = tmp;
                        l++;
                }
               
 
                if(l > 0 && powtorzenia[w] > i/2)
                {
                        powtorzenia_prefiksow[w]++;
                        v.push_back(w);
                }
        }
 
 
        for(int i = 0; i < v.size(); i++)
        {
                if(powtorzenia_prefiksow[ v[i] ] > n/2)
                {
                        cout<<v[i];
                        return 0;
                }
        }
        cout<<"NIE";
 
        return 0;
}
