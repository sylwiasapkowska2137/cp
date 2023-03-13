#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define DEBUG(lol) cout<<#lol<<" "<<(lol)<<endl;
#define INF 1000000000
#define MAX_N 1000005
using namespace std;
const int czapa=131072+1;
int drz[2*czapa+1];
int tab[100005];
LL prawo[100005];
LL lewo[100005];
int t,n;
void wrzuc(int poz)
{
  poz+=czapa;
  while(poz>=1)
  {
    drz[poz]++;
    poz>>=1;
  }
  
}

int szukaj(int poza,int pozb)
{
  poza+=czapa;
  pozb+=czapa;
  int ret=drz[poza];
  if(poza!=pozb)ret+=drz[pozb];
  while(poza/2!=pozb/2)
  {
    if(poza%2==0)ret+=drz[poza+1];
    if(pozb%2==1)ret+=drz[pozb-1];
    poza>>=1;
    pozb>>=1;
  }
  return ret;
}

int main()
{
  scanf("%d",&t);
  while(t--)
  {
    for(int i=1;i<=2*czapa;i++)
      drz[i]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&tab[i]);
    
      
      if(tab[i]<0)tab[i]*=-1;
      

    }
    
    prawo[n]=0;
    wrzuc(tab[n]);
    LL suma=0;
    for(int i=n-1;i>=1;i--)
    {
	if(0>tab[i]-1)prawo[i]=0;else
      prawo[i]=szukaj(0,tab[i]-1);
      suma+=prawo[i];
      wrzuc(tab[i]);
    }
  //   cout<<suma<<endl;
    for(int i=1;i<=2*czapa;i++)
      drz[i]=0;
    
    lewo[1]=0;
    wrzuc(tab[1]);
    for(int i=2;i<=n;i++)
    {
      if(0>tab[i]-1)lewo[i]=0;else
      lewo[i]=szukaj(0,tab[i]-1);
      wrzuc(tab[i]);
    }
    LL wynik=suma;
    for(int i=1;i<=n;i++)
    {
  //     cout<<i<<" "<<lewo[i]<<" "<<prawo[i]<<endl;
      wynik=min(wynik,wynik-prawo[i]+lewo[i]);
    }
    
    printf("%lld\n",wynik);
  }
  
}