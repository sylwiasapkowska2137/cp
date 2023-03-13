#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

string s,t,ans;
int main()
{
        cin >> s >> t;
        int n = s.size(), f = 0;
        ans = s;
        for (int i = 0; i < n; i++)
                if ((int)s[i] + 1 < (int)t[i])
                {
                        f = 1;
                        ans[i] = (char)((int)s[i]+1);
                        break;
                }
                else
                        if (s[i] < t[i])
                        {
                                for (int j = i + 1; j < n; j++)
                                        if (ans[j] < 'z')
                                        {
                                                ans[j] = 'z';
                                                f = 1;
                                                break;
                                        }
                        }
        if (f) cout << ans << endl;
        else cout<<"NIE"<<endl;
        //system("pause");
        return 0;
}