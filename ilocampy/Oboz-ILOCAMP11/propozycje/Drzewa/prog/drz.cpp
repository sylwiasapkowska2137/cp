#include<cstdio>
#include<algorithm>
using namespace std;
const int INF =  1000000002;
int n,d,nr;
int W[302],P[302],D[302][2],T[302][602];
int Dfs(int j) {
	int sum=0;
	for(int d=0;d<P[j];d++) {
		sum+=Dfs(D[j][d]);
	}
	int d1=D[j][0],d2=D[j][1];
	for(int x=-n;x<=n;x++) {
		T[j][n+x]=INF;
		for(int d=0;d<P[j];d++)
			T[j][n+x]=min(T[D[j][d]][n+x],T[j][n+x]);
		if(P[j]==2) {
			for(int a=-n;a<=n;a++) {
				if(x-a>=-n && x-a<=n)
					T[j][n+x]=min(T[j][n+x],T[d1][n+a]+T[d2][n+x-a]);
			}
		}
	}
	sum+=W[j];
	T[j][n+sum]=1;
	T[j][n+0]=0;
	/*for(int x=-n;x<=n;x++) {
		if(T[j][n+x]!=INF) {
			printf("W Wierzcholku %d moge uzyskac %d w %d cieciach\n",j,x,T[j][n+x]);
		}
	}*/
	return sum;
}
int main() {
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) {
		scanf("%d",&nr);
		scanf("%d%d",&W[nr],&P[nr]);
		if(!W[nr]) W[nr]--;
		for(int j=0;j<P[nr];j++)
			scanf("%d",&D[nr][j]);
	}
	int sum=Dfs(0);
	if(sum-d>=-n && sum-d<=n && T[0][n+sum-d]!=INF) printf("%d\n",T[0][n+sum-d]);
	else printf("-1\n");
}

