#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

struct punkt
{
        long double x,y;
};

struct odcinek
{
        punkt a,b;
};

priority_queue< pair<long double, int>, vector< pair <long double, int> >, greater< pair <long double, int> > >Q;
vector< pair<long double, int> >tb[3000];
punkt tab[3000];
odcinek zak[2000],pom;
pair<long double, int>pom2;
long double odl[3000], inf=20000000,wyn,wyn2,wyn3,wyn4;
bool czy;
punkt p,k,a,b,c,d;
int n,j=3,w=1,akt;

int main()
{
scanf("%d%Lf%Lf%Lf%Lf",&n,&p.x,&p.y,&k.x,&k.y);
tab[1]=p;
tab[2]=k;

for(int i=0; i<n; i++)
{
        scanf("%Lf%Lf%Lf%Lf", &a.x,&a.y,&b.x,&b.y);
        tab[j]=a;
        j++;
        tab[j]=b;
        j++;
        pom.a=a;
        pom.b=b;
        zak[w]=pom;
        w++;
        c.x=a.x; c.y=b.y;
        d.x=b.x; d.y=a.y;
        tab[j]=c;
        j++;
        tab[j]=d;
        j++;
        pom.a=c;
        pom.b=d;
        zak[w]=pom;
        w++;
}
for(int i=1; i<j-1; i++)
        for(int g=i+1; g<j; g++)
        {
                czy=false;
                for(int u=1; u<w; u++)
                {
                        a=tab[i];
                        b=tab[g];
                        c=zak[u].a;
                        d=zak[u].b;
                        wyn= a.x * b.y + b.x * c.y + c.x * a.y - b.y * c.x - a.x * c.y - a.y* b.x;
                        wyn2=a.x*b.y+b.x*d.y+d.x*a.y-b.y*d.x-a.x*d.y-a.y*b.x;
                        c=tab[i];
                        d=tab[g];
                        a=zak[u].a;
                        b=zak[u].b;
                                wyn3= a.x * b.y + b.x * c.y + c.x * a.y - b.y * c.x - a.x * c.y - a.y* b.x;
                        wyn4=a.x*b.y+b.x*d.y+d.x*a.y-b.y*d.x-a.x*d.y-a.y*b.x;
                        if((wyn<0&&wyn2>0)||(wyn>0&&wyn2<0)||(wyn==0&&wyn2==0))
                        {
                                if((wyn3<0&&wyn4>0)||(wyn3>0&&wyn4<0)||(wyn3==0&&wyn4==0))
                        {
                                //printf("punkt %.0Lf %.0Lf z %.0Lf %.0Lf nie, \nbo %.0Lf %.0Lf %.0Lf %.0Lf\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);
                                czy=true;
                                break;
                        }
                }
                }
                if(!czy)
                {
                        wyn=(tab[i].x-tab[g].x)*(tab[i].x-tab[g].x)+(tab[i].y-tab[g].y)*(tab[i].y-tab[g].y);
                        wyn=sqrt(wyn);
                        tb[i].push_back(make_pair(wyn,g));
                        tb[g].push_back(make_pair(wyn,i));
                }
        }
                pom2.first=0;
        pom2.second=1;
        for(int i=0; i<=j; i++)odl[i]=inf;
        odl[1]=0;
        Q.push(pom2);
        while(!Q.empty())
        {
            akt=Q.top().second;
                Q.pop();
                for(int i=0; i<tb[akt].size(); i++)
                {
                        if(odl[akt]+tb[akt][i].first<odl[tb[akt][i].second])
                        {
                                odl[tb[akt][i].second]=odl[akt]+tb[akt][i].first;
                                pom2.first=odl[tb[akt][i].second];
                                pom2.second=tb[akt][i].second;
                                Q.push(pom2);
                        }
                }
        }
        if(odl[2]==inf)printf("NIE");
        else printf("%.8Lf", odl[2]);
return 0;
}
 