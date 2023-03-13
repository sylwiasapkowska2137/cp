#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int random(int a,int b) { return rand()%(b-a+1)+a; }
int main(int argc, char *argv[]) {
	if(argc<3) {
		printf("Podano %d argumentow\n",argc);
		return 0;
	}
	srand(time(NULL)*atoi(argv[1]));
	int n = atoi(argv[2]);
	int *t = new int[n+1];
	printf("%d\n",n);
	for(int i=1;i<=n;i++) {
		t[i] = i;
	}
	random_shuffle(t+1,t+n+1);
	for(int i=1;i<=n;i++) {
		printf("%d ",t[i]);
	}
	printf("\n");
}