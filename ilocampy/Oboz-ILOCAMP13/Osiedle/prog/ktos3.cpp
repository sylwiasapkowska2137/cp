#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int n,x,x2,y2,y,xp,yp,xk,yk,wx,wy;
int wierzowiec[701][4];
vector< pair <int, long double> >tab[2810];
long double dl[2810];
long double const niesk=1000000000000;
bool odwiedzeni[2810];
int det(int ax,int ay,int bx,int by, int cx,int cy)
{
        return (ax*by+ay*cx+bx*cy-by*cx-ax*cy-ay*bx);
}
int sign(int w)
{
        if(w>0) return 1;
        if(w<0) return -1;
        return 0;
}
bool czy_ok(int a, int b,int c,int d,int bud)
{
        int x1b=wierzowiec[bud][0],y1b=wierzowiec[bud][1],x3b=wierzowiec[bud][2],y3b=wierzowiec[bud][3];
        int xmax=max(a,c),xmin=min(a,c),ymax=max(b,d),ymin=min(b,d),xminb=min(x1b,x3b),xmaxb=max(x1b,x3b),yminb=min(y1b,y3b),ymaxb=max(y1b,y3b);
        if(xminb>=xmax || xmaxb<=xmin || yminb>=ymax || ymaxb<=ymin)
                return true;
        int d1=sign(det(a,b,c,d,x1b,y1b)), d2=sign(det(a,b,c,d,x1b,y3b)), d3=sign(det(a,b,c,d,x3b,y1b)), d4=sign(det(a,b,c,d,x3b,y3b));
        if(d1==d2 && d1==d3 && d1==d4)
        return true;
        return false;
}
bool czy(int a,int b,int c, int d)
{
        for(int i=0;i<n;i++)
        {
                if(!czy_ok(a,b,c,d,i))
                        return false;
        }
        return true;
}
void pkt_na_xy(int l)
{
        if(l==0)
        {
                        wx=xp;
                        wy=yp;
                        return;
        }
        if(l==(4*n)+1)
        {
                        wx=xk;
                        wy=yk;
                        return;
        }
        int c=l%4,g=l/4;
                        if(c==0 || c==2)
                        {
                                wx=wierzowiec[g][c];
                                wy=wierzowiec[g][c+1];
                        }
                        if(c==1)
                        {
                                wx=wierzowiec[g][c+1];
                                wy=wierzowiec[g][c];
                        }
                        if(c==3)
                        {
                                wx=wierzowiec[g][c-3];
                                wy=wierzowiec[g][c];
                        }
}
priority_queue< pair <long double, int> > kolejka;
void dij(int p)
{
        kolejka.push(make_pair(0,p));
        while(!kolejka.empty())
        {
                long double od=(-1)*kolejka.top().first;
                int k=kolejka.top().second;
                //cout<<k<<"\n";
                pkt_na_xy(k);
                int a=wx,b=wy;
                //cout<<"od "<<k<<"\n";
                kolejka.pop();
                if(odwiedzeni[k]==1)
                continue;
                if(k==(4*n)+1)
                return;
                odwiedzeni[k]=1;
                for(int i=1;i<=(n*4)+1;i++)
                {
                        if(i==k)
                        continue;
                        pkt_na_xy(i);
                        int c=wx,d=wy;
                        if(!czy(a,b,c,d))
                                continue;
                        long double ile=sqrt((a-c)*(a-c)+(b-d)*(b-d));
                        if(odwiedzeni[i]==0 && dl[i]>od+ile)
                        {
                                dl[i]=od+ile;
                                kolejka.push(make_pair(-1*(od+ile),i));
                        }
                }
        }
}
int main()
{
        scanf("%d%d%d%d%d", &n, &xp, &yp, &xk, &yk);
        for(int i=1;i<=(4*n)+1;i++)
                dl[i]=niesk;
        for(int i=0;i<n;i++)
        {
                scanf("%d%d%d%d", &x, &y, &x2, &y2);
                wierzowiec[i][0]=x;
                wierzowiec[i][1]=y;
                wierzowiec[i][2]=x2;
                wierzowiec[i][3]=y2;
        }
        dij(0);
        if(dl[(4*n)+1]==(long double)niesk)
                printf("NIE\n");
        else
                printf("%.8Lf\n", dl[(4*n)+1]);


}