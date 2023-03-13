#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<tr1/unordered_map>
#include<queue>
#include<cstdlib>
#include<list>
#include<set>
#include<map>
#include<cmath>
#define MP make_pair
#define PB push_back
#define s second
#define f first
#define PII pair<int,int>
#define VI vector <int>
#define abs(a) max((a),-(a))
#define LL long long
#define LD long double
#define ALL(x) x.begin(),x.end()
#define PU putchar_unlocked
#define GU getchar_unlocked
using namespace std;
int a,b,c,d,e,f,n,m,mx,l,z,r,k,q;
LD odl(LD a,LD b,LD c,LD d)
{
return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
VI wynik;
LD ile=0;

void look(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
if(MP(x1,y1)==MP(x2,y2)||MP(x1,y1)==MP(x3,y3)||MP(x1,y1)==MP(x4,y4)||MP(x3,y3)==MP(x2,y2)||MP(x4,y4)==MP(x2,y2)||MP(x4,y4)==MP(x3,y3))return;


LD x=odl(x1,y1,x2,y2)+odl(x3,y3,x2,y2)+odl(x3,y3,x4,y4);
if(x>ile)
   {
   wynik.clear();
   wynik.PB(x1);
   wynik.PB(y1);
   wynik.PB(x2);
   wynik.PB(y2);
   wynik.PB(x3);
   wynik.PB(y3);
   wynik.PB(x4);
   wynik.PB(y4);
   ile=x;
   }
}
void solve()
{
cin>>n>>m;/*
for(int i=0;i<=n;i++)
   for(int j=0;j<=m;j++)
      for(int i1=0;i1<=n;i1++)
         for(int j1=0;j1<=m;j1++)
               for(int i2=0;i2<=n;i2++)
                 for(int j2=0;j2<=m;j2++)
                   for(int i3=0;i3<=n;i3++)
                     for(int j3=0;j3<=m;j3++)look(i,j,i1,j1,i2,j2,i3,j3);
printf("%d %d\n%d %d\n%d %d\n%d %d\n",wynik[0],wynik[1],wynik[2],wynik[3],wynik[4],wynik[5],wynik[6],wynik[7]);
return;*/
if(n==0||m==0)
   {
   if(n==0)
      {
      printf("0 %d\n",1);
      printf("0 %d\n",m);
      printf("0 %d\n",0);
      printf("0 %d\n",m-1);
      }
   if(m==0)
      {
      printf("%d 0\n",1);
      printf("%d 0\n",n);
      printf("%d 0\n",0);
      printf("%d 0\n",n-1);
      }
   return;
   }
look(0,1,n,m,0,0,n,m-1);
look(1,0,n,m,0,0,n-1,m);
look(0,0,n,m,0,m,n,0);
look(0,0,n,m,n,0,0,m);
look(0,0,n,m,1,0,n-1,m);
look(0,0,n,m,0,1,n,m-1);


cerr<<ile<<endl;
printf("%d %d\n%d %d\n%d %d\n%d %d\n",wynik[0],wynik[1],wynik[2],wynik[3],wynik[4],wynik[5],wynik[6],wynik[7]);
}
int main()
{
solve();
}
