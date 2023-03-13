//Przemyslaw Jakub Kozlowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
char s[5003];

int ttmp1[5003];
int ttmp2[5003];
int *tab1 = ttmp1;
int *tab2 = ttmp2;

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
    //P
    for(int i = 1;i <= n;i++) s[n+i] = s[i];
	//K

	for(int i = 1;i <= n-1;i++)
	{
		for(int j = 1;j+i <= 2*n;j++)
		{
			if(s[j] != s[j+i])
				tab1[j] = min(tab2[j],tab2[j+1])+1;
			else
				tab1[j] = tab1[j+1];
		}
		swap(tab1,tab2);
	}

    //P
    int wyn = 2000000009;
    for(int i = 1;i <= n;i++) wyn = min(wyn, tab2[i]);
	printf("%d\n", wyn);
	//printf("%d\n",tab2[1]);
	//K
	return 0;
}
