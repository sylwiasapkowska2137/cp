// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int tab[4];
int ktab[4];
//tablice, ktore uzyje na koniec

int min1, kmin1, min2, kmin2, min3, kmin3, min4, kmin4, odp, prwd=0;
//najmniejsze liczby i ich indeksy(pierwsza podawana liczba jest nie wazna, wiec jej niepodaje), 
//min 4 to największa z najmniejszych
int a, b, c, d, e, f, ile;
//ile- ile liczb
//f- pusta, niepotrzebna liczba; a,b,c,d- pierwsze wazne wlasciwe liczby

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    
    cin>>ile; //ile liczb
    if (ile==5) //jak jest 5 liczb to wiadomo, ze to druga i czwarta
    {
        cin>>a>>b>>c>>d>>e;
        cout<<b+d;
    }
    else
    {
        cin>>f;
        cin>>a>>b>>c>>d; 
        //określam 4 najmniejsze liczby i ich "indeksy"; indeksy są wazne, bo jak rozerwiemy dwie liczby obok siebie to robimy jedno połamanie

        //na pewno trzeba 4, bo jest sytuacja, ze wyznaczenie trzech nie wystarcza
        //duzo strasznych ifow, ale trudno. nie wiedzialem jak to lepiej zrobic
        if(a>=b && a>=c && a>=d && b>=c && b>=d && c>=d)
        {   
            min1=a;
            kmin1=1;
            min2=b;
            kmin2=2;
            min3=c;
            kmin3=3;
            min4=d;
            kmin4=4;
        }
        else if(a>=b && a>=c && a>=d && b>=c && b>=d && d>=c)
        {   
            min1=a;
            kmin1=1;
            min2=b;
            kmin2=2;
            min3=d;
            kmin3=4;
            min4=c;
            kmin4=e;
        }
        else if(a>=b && a>=c && a>=d && c>=b && c>=d && b>=d)
        {   
            min1=a;
            kmin1=1;
            min2=c;
            kmin2=3;
            min3=b;
            kmin3=2;
            min4=d;
            kmin4=4;
        }
        else if(a>=b && a>=c && a>=d && c>=b && c>=d && d>=b)
        {   
            min1=a;
            kmin1=1;
            min2=c;
            kmin2=3;
            min3=d;
            kmin3=4;
            min4=b;
            kmin4=2;
        }
        else if(a>=b && a>=c && a>=d && d>=b && d>=c && b>=c)
        {   
            min1=a;
            kmin1=1;
            min2=d;
            kmin2=4;
            min3=b;
            kmin3=2;
            min4=c;
            kmin4=3;
        }
        else if(a>=b && a>=c && a>=d && d>=b && d>=c && c>=b)
        {   
            min1=a;
            kmin1=1;
            min2=d;
            kmin2=4;
            min3=c;
            kmin3=3;
            min4=b;
            kmin4=2;
        }
        else if(b>=c && b>=d && b>=a && a>=b && a>=c && d>=c)
        {   
            min1=b;
            kmin1=2;
            min2=a;
            kmin2=1;
            min3=d;
            kmin3=4;
            min4=c;
            kmin4=3;
        }
        else if(b>=c && b>=d && b>=a && a>=b && a>=c && c>=d)
        {   
            min1=b;
            kmin1=2;
            min2=a;
            kmin2=1;
            min3=c;
            kmin3=3;
            min4=d;
            kmin4=4;
        }
        else if(b>=c && b>=d && b>=a && c>=d && c>=a && a>=d)
        {   
            min1=b;
            kmin1=2;
            min2=c;
            kmin2=3;
            min3=a;
            kmin3=1;
            min4=d;
            kmin4=4;
        }
        else if(b>=c && b>=d && b>=a && c>=d && c>=a && d>=a)
        {   
            min1=b;
            kmin1=2;
            min2=c;
            kmin2=3;
            min3=d;
            kmin3=4;
            min4=a;
            kmin4=1;
        }
        else if(b>=c && b>=d && b>=a && d>=a && d>=c && a>=c)
        {   
            min1=b;
            kmin1=2;
            min2=d;
            kmin2=4;
            min3=a;
            kmin3=1;
            min4=c;
            kmin4=3;
        }
        else if(b>=c && b>=d && b>=a && d>=a && d>=c && c>=a)
        {   
            min1=b;
            kmin1=2;
            min2=d;
            kmin2=4;
            min3=c;
            kmin3=3;
            min4=a;
            kmin4=1;
        }
        else if(c>=a && c>=d && c>=b && b>=a && b>=d && a>=d)
        {   
            min1=c;
            kmin1=3;
            min2=b;
            kmin2=2;
            min3=a;
            kmin3=1;
            min4=d;
            kmin4=4;
        }
        else if(c>=a && c>=d && c>=b && b>=a && b>=d && d>=a)
        {   
            min1=c;
            kmin1=3;
            min2=b;
            kmin2=2;
            min3=d;
            kmin3=4;
            min4=a;
            kmin4=1;
        }   
        else if(c>=a && c>=d && c>=b && a>=d && a>=b && b>=d)
        {   
            min1=c;
            kmin1=3;
            min2=a;
            kmin2=1;
            min3=b;
            kmin3=2;
            min4=d;
            kmin4=4;
        }
        else if(c>=a && c>=d && c>=b && a>=d && a>=b && d>=b)
        {   
            min1=c;
            kmin1=3;
            min2=a;
            kmin2=1;
            min3=d;
            kmin3=4;
            min4=c;
            kmin4=3;
        }
        else if(c>=a && c>=d && c>=b && d>=b && d>=a && a>=b)
        {   
            min1=c;
            kmin1=3;
            min2=d;
            kmin2=4;
            min3=a;
            kmin3=1;
            min4=b;
            kmin4=2;
        }
        else if(c>=a && c>=d && c>=b && d>=b && d>=a && b>=a)
        {   
            min1=c;
            kmin1=3;
            min2=d;
            kmin2=4;
            min3=b;
            kmin3=2;
            min4=a;
            kmin4=1;
        }
        else if(d>=a && d>=c && d>=b && c>=b && c>=a && a>=b)
        {   
            min1=d;
            kmin1=4;
            min2=c;
            kmin2=3;
            min3=a;
            kmin3=1;
            min4=b;
            kmin4=2;
        }
        else if(d>=a && d>=c && d>=b && c>=b && c>=a && b>=a)
        {   
            min1=d;
            kmin1=4;
            min2=c;
            kmin2=3;
            min3=b;
            kmin3=2;
            min4=a;
            kmin4=1;
        }
        else if(d>=a && d>=c && d>=b && b>=a && b>=c && a>=c)
        {   
            min1=d;
            kmin1=4;
            min2=b;
            kmin2=2;
            min3=a;
            kmin3=1;
            min4=c;
            kmin4=3;
        }
        else if(d>=a && d>=c && d>=b && b>=a && b>=c && c>=a)
        {   
            min1=d;
            kmin1=4;
            min2=b;
            kmin2=2;
            min3=c;
            kmin3=3;
            min4=a;
            kmin4=1;
        }
        else if(d>=a && d>=c && d>=b && a>=b && a>=c && b>=c)
        {   
            min1=d;
            kmin1=4;
            min2=a;
            kmin2=1;
            min3=b;
            kmin3=2;
            min4=c;
            kmin4=3;
        }
        else if(d>=a && d>=c && d>=b && a>=b && a>=c && c>=b)
        {   
            min1=d;
            kmin1=4;
            min2=a;
            kmin2=1;
            min3=c;
            kmin3=3;
            min4=b;
            kmin4=2;
        }
        //wczytuje reszte liczb 
        for(int i=6;i<ile;i++)
        {
            cin>>f;
            if(f>=min4) continue;
            else if(f<=min1)
            {
                min1=f;
                kmin1=i;
                min2=min1;
                kmin2=kmin1;
                min3=min2;
                kmin3=kmin2;
                min4=min3;
                kmin4=kmin3;
            }
            else if(f<=min2)
            {
                min2=f;
                kmin2=i;
                min3=min2;
                kmin3=kmin2;
                min4=min3;
                kmin4=kmin3;
            }
            else if(f<=min3)
            {
                min3=f;
                kmin3=i;
                min4=min3;
                kmin4=kmin3;
            }
            else if(f<=min4)
            {
                min4=f;
                kmin4=i;
            }     
        }
        cin>>f;
        //wpisuje je w dwie tablice, aby łatwiej po nich chodzić
        
        //tu liczby
        tab[0]=min1;
        tab[1]=min2;
        tab[2]=min3;
        tab[3]=min4;
        
        //tu indeksy, zeby nie lamac dwoch ogniw obok siebie
        ktab[0]=kmin1;
        ktab[1]=kmin2;
        ktab[2]=kmin3;
        ktab[3]=kmin4;
        
        //tutaj chodze po sumie 4 najmniejszych liczb i jak jest mozliwe najmniejsza to stop 
        for(int i=0;i<=3;i++)
        {
            if(prwd==0)
            {
                for(int j=i+1;j<=3;j++)
                {
                    if((abs(ktab[j]-ktab[j-1]))>1)
                    {
                        odp=tab[j]+tab[j-1];
                        prwd=1;
                    }
                }
            }
        }
        cout<<odp;
    }
    return 0;
}