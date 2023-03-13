#include <bits/stdc++.h>
using namespace std;
 
struct punkt
{
long long x;
long long y;
};
punkt inus(punkt a,punkt b)
{
a.x-=b.x;
a.y-=b.y;
return a;
}
bool det(punkt a,punkt b,punkt c)
{
    b=inus(b,a);
    c=inus(c,a);
    return (b.x*c.y-b.y*c.x)==0;
}
 
const int N=2*100*1000+10;
int done[N];
punkt tab[N];
int wyn[5][2];
int zost=0;
int ile;
int check(int a,int b)
{
   // cout <<"CHECK" << " "<<a<< " "<<b<<"\n";
    int wyn=0;
    int fail=0;
    for (int i=0;i<ile;i++)
    {
        if (det(tab[a],tab[b],tab[i]))
        {
            if (done[i]==0)
            {
            zost--;
            wyn++;
            }
            done[i]=1;
 
        }
    }
 
    return wyn;
}
map<pair<int,int>,int >mapa;
int k;
void pisz()
{
    cout <<"TAK\n";
    for (int i=0;i<k;i++)
    {
 
        int a=wyn[i][0];
        int b=wyn[i][1];
        cout <<tab[a].x<<" "<<tab[a].y<<" "<<tab[b].x<<" "<<tab[b].y<<"\n";
    }
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(nullptr);
    cin >>ile;
 
    srand(time(NULL));
    cin >>k;
    for (int i=0;i<ile;i++)
    {
        cin >>tab[i].x>>tab[i].y;
        if (mapa[make_pair(tab[i].x,tab[i].y)] !=0){ile--; i--;}
        mapa[make_pair(tab[i].x,tab[i].y)]=1;
 
    }
    if (ile==1)
    {
        cout <<"TAK\n";
        for (int i=0;i<k;i++)cout <<tab[0].x<<" "<<tab[0].y<<" "<<tab[0].x+1<<" "<<tab[0].y<<"\n";
        return 0;
    }
    int last=0;
    for (int i=0;i<1000;i++)
    {
        zost=ile;
        fill(done,done+ile,0);
        for (int q=0;q<last;q++)
        {check(wyn[q][0],wyn[q][1]);}
        //cout <<zost<<"\n";
        int a=rand()%ile;
        if (zost!=0)
        {
            while (done[a]==1)
            {
                a=rand()%ile;
            }
        }
        int b=rand()%ile;
        int pom=0;
        while (a==b)
        {
            pom++;
            b=rand()%ile;
            if (zost!=0&&done[b]==1){b=a;}
            if (zost==1&&done[a]==0){b=rand()%ile; break;}
 
        }
        int _pom=check(a,b);
        if ((k-last)>0&&_pom>k-last)
        {
            //cout <<_pom<<"\n";
           // cout <<"ADD"<< " "<<a<<" "<<b<<"\n";
            //cout <<zost<<"\n";
                wyn[last][0]=a;
                wyn[last][1]=b;
                last++;
 
        }
 
    }
    zost=ile;
    fill(done,done+ile,0);
    for (int q=0;q<last;q++)
    {check(wyn[q][0],wyn[q][1]);}
 
    if (zost>5*k){cout <<"NIE\n"; return 0;}
    for (int i=0;i<1000000;i++)
    {
        //cout <<"\n";
        //cout <<i<<"AAAAAAAAAAA\n";
 
        for (int q=0;q<k-last;q++)
        {
 
 
        zost=ile;
        fill(done,done+ile,0);
        for (int w=0;w<last+q;w++)
        {check(wyn[w][0],wyn[w][1]);}
        for (int e=0;e<ile;e++)
        {
        //cout <<done[e]<<" ";
 
        }
        //cout <<"\n";
        int a=rand()%ile;
        if (zost!=0)
        {
            while (done[a]==1)
            {a=rand()%ile;}
        }
        int b=rand()%ile;
 
        while (a==b||done[b]==1)
        {
            if (zost==0){b=(a+1)%ile; break;}
            b=rand()%ile;
            if (zost!=0&&done[b]==1){b=a;}
            if (zost==1&&done[a]==0){b=(a+1)%ile; break;}
        }
 
                wyn[last+q][0]=a;
                wyn[last+q][1]=b;
                check(a,b);
          //      cout <<a<<" "<<b<<"\n";
                if (zost==0){last=last+q+1;  break;}
 
 
        }
 
    }
 
    while (zost==0&&k>last)
    {
        wyn[last][1]=1;
        wyn[last][0]=0;
        last++;
    }
    //cout <<zost<<"\n";
    //cout <<last<<"\n";
 
    if (last==k&&zost==0)
    {
        pisz();
        return 0;
    }
    cout <<"NIE\n";
}
