#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int S = 3000000;
char w[2*S+3];
int n,m,res;
int licz1[S+3],licz2[S+3],pr[2*S+3];

void pref(char *t,int n,int *p)
{
	int r=0;
	p[0]=0;
	for (int j=1; j<n; j++)
	{
		if(j<r+p[r])
			if(r+p[r]-j <= p[j-r])
				p[j] = r + p[r] - j;
			else
				p[j] = p[j-r];
		else
			p[j] = 0;
		if(r+p[r] <= j+p[j]) {
			r = j;
			while(j+p[j] < n && t[j+p[j]] == t[p[j]]) p[j]++;
		}
	}
}

int	main() {
	scanf("%d%d",&n,&m);
	scanf(" %s %s",w+m+1,w);
	w[m] = '#';
	pref(w,m+n+1,pr);
	for(int i=m+1;i<m+n+1;i++) licz1[pr[i]]++;
	reverse(w,w+m);
	reverse(w+m+1,w+m+n+1);
	pref(w,m+n+1,pr);
	for(int i=m+1;i<m+n+1;i++) licz2[pr[i]]++;
	for(int i=m;i>=1;i--) {
		licz1[i] += licz1[i+1];
		licz2[i] += licz2[i+1];
	}
	for(int i=1;i<m;i++) {
		res = max(res,min(licz1[i],licz2[m-i]));
	}
	printf("%d\n",res);
}