#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int S = 3000000;
char t[S+3],w[S+3],tmp[2*S+3];
int kmp[2*S+3];
int n,m,res,r1,r2;
int count(char *text,int n, char *w, int m) {
	int res = 0;
	for(int i=0;i<m;i++)
		tmp[i+1] = w[i];
	tmp[m+1] = '#';
	for(int i=0;i<n;i++)
		tmp[i+m+2] = text[i];
	kmp[0] = kmp[1] =0;
	int p = 0;
	for(int i=2;i<=n+m+1;i++) {
		while(tmp[i]!=tmp[p+1] && p>0) p = kmp[p];
		if(tmp[i] == tmp[p+1]) p++;
		kmp[i] = p;
		if(kmp[i] == m) res++;
	}
	return res;
}
void doit(int s) {
	r1 = count(t,n,w,s);
	r2 = count(t,n,w+s,m-s);
	res = max(res,min(r1,r2));
	//printf("Dla s=%d, r1=%d, r2=%d\n",s,r1,r2);
}
int	main() {
	scanf("%d%d",&n,&m);
	scanf(" %s %s",t,w);
	int p=1,k=m-1;
	while(p<k) {
		int s = (p+k)/2;
		doit(s);
		if(r1>=r2) p=s+1;
		else k=s;
	}
	doit(p);
	printf("%d\n",res);
}