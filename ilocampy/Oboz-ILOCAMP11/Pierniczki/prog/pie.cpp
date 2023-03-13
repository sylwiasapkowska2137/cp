#include<cstdio>
using namespace std;
int n,t[500002];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&t[i]);
	}
	int p=n;
	for(int i=n-1;i>=0;i--) {
		if(t[i]==p) p--;
	}
	printf("%d\n",p);
}