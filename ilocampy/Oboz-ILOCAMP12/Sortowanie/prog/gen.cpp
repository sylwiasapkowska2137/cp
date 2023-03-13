#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;
int random(int a,int b) { return rand()%(b-a+1)+a; }
vector<int> v;
int t[2000002];
int main(int argc,char *argv[]) {
	srand(time(NULL)*atoi(argv[1]));
	int N = atoi(argv[2]);
	int S = atoi(argv[3]);
	while(S>0) {
		int maks = min(S,N);
		int a = random(1,maks);
		S -= a;
		v.push_back(a);
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++) {
		int n = v[i];
		printf("%d\n",n);
		for(int i=0;i<n;i++) t[i] = i+1;
		random_shuffle(t,t+n);
		for(int i=0;i<n;i++) printf("%d ",t[i]);
		printf("\n");
	}
}