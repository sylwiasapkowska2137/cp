#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int random(int a,int b) { return rand()%(b-a+1)+a; }
int main(int argc, char *argv[]) {
	if(argc<5) {
		printf("Podano za malo %d argumentow\n",argc);
		return 0;
	}
	srand(time(NULL)*atoi(argv[1]));
	int n = atoi(argv[2]);
	int m = atoi(argv[3]);
	printf("%d %d\n",n,m);
	int x = atoi(argv[4]);
	for(int i=0;i<n;i++) {
		printf("%c",random('a','a'+x));
	}
	printf("\n");
	for(int i=0;i<m;i++) {
		printf("%c",random('a','a'+x));
	}
	printf("\n");
}