#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
using namespace std;
struct rec
{
	short int X,Y,wic,wre;
};
short int K,a[5010],b[5010],nxta[5010][5010],nxtb[5010][5010],t[2],vis[5010],where[5010],which[5010];
rec h[5010][5010];
void read(short int &x)
{
	char ch=getchar();int mark=1;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());if (ch=='-') mark=-1,ch=getchar();
	for(x=0;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mark;
}
inline rec Make(int x,int y,int Wic,int Wre){rec tmp;tmp.X=x,tmp.Y=y;tmp.wic=Wic,tmp.wre=Wre;return tmp;}
void dfs(int st,int i)
{
	if (st)
	{
		dfs(st-1,h[st][i].wre);
		printf("%d ",h[st][i].wic);
	}
}
int main()
{
	read(K);
	read(a[0]);for(int i=1;i<=a[0];i++) read(a[i]);
	for(int i=1;i<=K;i++) nxta[a[0]][i]=nxta[a[0]+1][i]=a[0]+1;
	for(int i=a[0]-1;i>=0;i--)
	{
		memcpy(nxta[i],nxta[i+1],sizeof(nxta[i]));
		nxta[i][a[i+1]]=i+1;
	}
	read(b[0]);for(int i=1;i<=b[0];i++) read(b[i]);
	for(int i=1;i<=K;i++) nxtb[b[0]][i]=nxtb[b[0]+1][i]=b[0]+1;
	for(int i=b[0]-1;i>=0;i--)
	{
		memcpy(nxtb[i],nxtb[i+1],sizeof(nxtb[i]));
		nxtb[i][b[i+1]]=i+1;
	}
	h[0][++t[0]]=Make(0,0,0,0);
	for(int st=1;;st++)
	{
		for(int i=1;i<=a[0]+1;i++) vis[i]=0;
		for(int i=1;i<=t[st-1];i++)
		{
			int x=h[st-1][i].X,y=h[st-1][i].Y;
			for(int k=1;k<=K;k++)
			{
				int x1=nxta[x][k],y1=nxtb[y][k];
				if (vis[x1]<y1)
				{
					vis[x1]=y1;which[x1]=k;where[x1]=i;
				}
			}
		}
		for(int i=1;i<=a[0]+1;i++) 
			if (vis[i])
			{
				if (vis[i]==b[0]+1&&i==a[0]+1)
				{
					printf("%d\n",st);
					dfs(st-1,where[i]);
					printf("%d\n",which[i]);
					return 0;
				}
				t[st]++;
				h[st][t[st]]=Make(i,vis[i],which[i],where[i]);
			}
	}
	return 0;
}
