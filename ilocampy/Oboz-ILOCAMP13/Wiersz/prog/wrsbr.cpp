#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
string s[15], slowo;
int a, b, odw[15], wyn, t, n;
void funk(int i, int po, int ko)
{
  if(wyn==0)
  {
    odw[i]=1;
    int akt=po;
    for(int p=0; p<(int)s[i].size(); p++)
    {
      if(s[i][p]==slowo[po])
      {
        for(int pp=p; pp<(int)s[i].size(); pp++)
        {
          if(s[i][pp]==slowo[po+pp-p])
          {
            if(akt<po+pp-p+1)akt=po+pp-p+1;
          }
          else break;
        }
      }
    }
    if(akt>ko)
    {
      wyn=1;
    }
    else
    {
      for(int p=0; p<n; p++)
      {
        if(odw[p]==0)funk(p, akt, ko);
      }
    }
    odw[i]=0;
  }
}
int main()
{
  cin>>n>>t;
  for(int p=0; p<n; p++)
  {
    cin>>a;
    cin>>s[p];
  }
  cin>>a;
  cin>>slowo;
  for(int p=0; p<t; p++)
  {
    cin>>a>>b;
    a--;
    b--;
    wyn=0;
    for(int pp=0; pp<n; pp++)
    {
      funk(pp, a, b);
    }
    if(wyn==1)cout<<"TAK\n";
    else cout<<"NIE\n";
  }
  return 0;
}
