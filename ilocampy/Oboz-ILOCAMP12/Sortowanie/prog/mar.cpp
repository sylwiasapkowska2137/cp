#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 2000005;

int poz[maxN];
int z, n, a;
int chains, num;

int main(){
	scanf("%d", &z);
	while(z--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &a);
			poz[a] = i;
		}
		//szukamy lancuchow
		chains = 1;
		for(int wsk = 1; wsk < n; wsk++)
			if(poz[wsk] > poz[wsk+1]) chains++;
		
		//liczba potrzebnych zamian to ceil(log2(chains))
		num = 0;
		while(chains != 1){
			num++;
			chains -= (chains / 2);
		}
		printf("%d\n", num);
	}
}

