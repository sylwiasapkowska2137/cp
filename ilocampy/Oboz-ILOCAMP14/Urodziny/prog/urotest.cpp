#include <iostream>
using namespace std;
const int N=500,R=3,MN=15,M=999999900;
int k;
int main()
{
	srand(time(NULL));
	printf("%d\n",N);
	for(int i=0;i<=N;i++)
	{
		k=rand()%M+1;
		printf("%d %d\n",k,k+(rand()%R)*MN);
	}

}