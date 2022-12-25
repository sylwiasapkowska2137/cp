#include <bits/stdc++.h>
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define f0(a,b) for(int a=0;a<b;a++)
#define f1(a,b) for(int a=1;a<=b;a++)
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
const int N=1e6+69;
vector <pii> G[N];
int odl[N][2],odw[N];
int n,m,a,b,c,wynik=1e9;
priority_queue <pii> q;
void dij(int);
inline void read(int &x)
{
    int c = getchar_unlocked();
    x=0;
    while(c<48 || c>57) c=getchar_unlocked();
    for (; c>47 && c<58; c = getchar_unlocked())
    {
        x=(x<<1)+(x<<3)+(c-48);
    }
}
int main(void) {
    read(n);
    read(m);
    for(int i=0;i<m;i++) {
        read(a);
        read(b);
        read(c);
        G[a].PB(MP(b,c));
        G[b].PB(MP(a,c));
    }
    int zap=100;
    while(zap>1) {
        dij(zap);
        wynik=min(wynik,odl[n][0]+odl[n][1]);
        zap=odl[n][1]-2;
        if(odl[n][1]==1e9) break;
    }
    printf("%d\n", wynik);
}
 
void dij(int ma) {
    for(int i=1;i<=n;i++) odl[i][0]=odl[i][1]=1e9, odw[i]=0;
    odl[1][0]=0;
    odl[1][1]=0;
    q.push(MP(0,1));
    while(!q.empty()) {
        int v=q.top().s;
        q.pop();
        if(odw[v]==1) continue;
        odw[v]=1;
        for(int i=0;i<G[v].size();i++) {
            int w=G[v][i].f;
            int wag=G[v][i].s;
            if(wag>ma) continue;
            //if(wag>3)cout<<"huj\n";
            if(odl[v][0]+wag<odl[w][0]) {
                odl[w][0]=odl[v][0]+wag;
                odl[w][1]=max(odl[v][1],wag);
                q.push(MP(-odl[w][0],w));
            }
            else if(odl[v][0]+wag==odl[w][0]&&max(odl[v][1],wag)<odl[w][1]) {
                odl[w][0]=odl[v][0]+wag;
                odl[w][1]=max(odl[v][1],wag);
                q.push(MP(-odl[w][0],w));
            }
        }
    }
}