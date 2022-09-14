#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int n, odlmin=INF, pozi, pozj;
pair<int, int> p, k;
char tab[1006][1006], tab1[1006][1006];
bool odw[1006][1006];
int odl[1006][1006];
string sc;

void BFSnasterydach(int a, int b)
{
    queue<pair<int, pair<int, int> > >setds;
    setds.push(make_pair(0, make_pair(a, b)));
    odl[a][b]=0;
    odw[a][b]=1;
    while(!setds.empty())
    {
        pair<int, pair<int, int> >tmp=setds.front();
        int i=tmp.second.first;
        int j=tmp.second.second;
        setds.pop();
        if(i>0)
        {
            if(!odw[i-1][j]&&tab[i-1][j]!='X'&&tab[i-1][j]!='#')
            {
                odw[i-1][j]=1;
                setds.push(make_pair(odl[i][j]+1, make_pair(i-1, j)));
                odl[i-1][j]=odl[i][j]+1;
            }
        }
        if(j>0)
        {
            if(!odw[i][j-1]&&tab[i][j-1]!='X'&&tab[i][j-1]!='#')
            {
                odw[i][j-1]=1;
                setds.push(make_pair(odl[i][j]+1, make_pair(i, j-1)));
                odl[i][j-1]=odl[i][j]+1;
            }
        }
        if(i<n-1)
        {
            if(!odw[i+1][j]&&tab[i+1][j]!='X'&&tab[i+1][j]!='#')
            {
                odw[i+1][j]=1;
                setds.push(make_pair(odl[i][j]+1, make_pair(i+1, j)));
                odl[i+1][j]=odl[i][j]+1;
            }
        }
        if(j<n-1)
        {
            if(!odw[i][j+1]&&tab[i][j+1]!='X'&&tab[i][j+1]!='#')
            {
                odw[i][j+1]=1;
                setds.push(make_pair(odl[i][j]+1, make_pair(i, j+1)));
                odl[i][j+1]=odl[i][j]+1;
            }
        }
    }
}

void sciezka()
{
    int i=k.first;
    int j=k.second;
    while(true)
        {
            if(i>0)
            {
                if(odl[i-1][j]==odl[i][j]-1)
                {
                    sc='D'+sc;
                    i--;
                }
            }
            if(j>0)
            {
                if(odl[i][j-1]==odl[i][j]-1)
                {
                    sc='P'+sc;
                    j--;
                }
            }
            if(i<n-1)
            {
                if(odl[i+1][j]==odl[i][j]-1)
                {
                    sc='G'+sc;
                    i++;
                }
            }
            if(j<n-1)
            {
                if(odl[i][j+1]==odl[i][j]-1)
                {
                    sc='L'+sc;
                    j++;
                }
            }
            if(odl[i][j]==0)break;
        }
}

void wypisz()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<odl[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char a;
            cin>>a;
            if(a=='P')
            {
                p.first=i;
                p.second=j;
            }
            if(a=='K')
            {
                k.first=i;
                k.second=j;
            }
            tab[i][j]=a;
            tab1[i][j]=a;
            odw[i][j]=0;
            odl[i][j]=INF;
        }
    }


    if(n<50)
    {
        for(int q=0;q<n;q++)
        {
            for(int r=0;r<n;r++)
            {
                if(tab[q][r]!='X')
                {
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            tab[i][j]=tab1[i][j];
                            odw[i][j]=0;
                            odl[i][j]=INF;
                        }
                    }

                    for(int i=q;i<n;i++)
                    {
                        if(tab[i][r]=='X')break;
                        else if(tab[i][r]=='#')tab[i][r]='.';
                    }
                    for(int i=q;i>=0;i--)
                    {
                        if(tab[i][r]=='X')break;
                        else if(tab[i][r]=='#')tab[i][r]='.';
                    }
                    for(int i=r;i<n;i++)
                    {
                        if(tab[q][i]=='X')break;
                        else if(tab[q][i]=='#')tab[q][i]='.';
                    }
                    for(int i=r;i>=0;i--)
                    {
                        if(tab[q][i]=='X')break;
                        else if(tab[q][i]=='#')tab[q][i]='.';
                    }

                    BFSnasterydach(p.first, p.second);
                    //wypisz();
                    if(odl[k.first][k.second]<odlmin)
                    {
                        odlmin=odl[k.first][k.second];
                        pozi=q;
                        pozj=r;
                        sc="";
                        sciezka();
                    }

                }
            }
        }
        if(odlmin==INF)
        {
            cout<<"NIE";
            exit(0);
        }
        cout<<odlmin<<endl;
       // cout<<pozi+1<<' '<<pozj+1<<endl;
        //cout<<sc;
    }


    else
    {
        BFSnasterydach(p.first, p.second);
        if(odl[k.first][k.second]!=INF){
            cout<<odl[k.first][k.second]<<endl;
           // cout<<p.first+1<<' '<<p.second+1<<endl;
            //sc="";
            //sciezka();
            //cout<<sc;
        }
        else cout<<"NIE";
    }

    return 0;
}
