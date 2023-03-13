#include <iostream>

using namespace std;

int tab[1000010];

int minusl[1000010];
int plusl[1000010];

int minusp[1000010];
int plusp[1000010];

int main()
{
	int n,a;
	int wynik=-1;
	ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i=0;i<n ;i++ )
	{
		cin >> a;
		
		if (a<0)
		{
			tab[-a]|=1;
			if (minusl[-a]==0)
				minusl[-a]=i+1;
			minusp[-a]=i+1;
		}
		else
		{
			tab[a]|=2;
			if (plusl[a]==0)
				plusl[a]=i+1;
			plusp[a]=i+1;
		}
	}

	if (plusp[0]!=plusl[0])
		wynik=plusp[0]-plusl[0];


	for (int i=1;i<1000005 ;i++ )
	{
		if (tab[i]==3)
		{
			if (wynik<plusp[i]-minusl[i])
				wynik=plusp[i]-minusl[i];
			
			if (wynik<minusp[i]-plusl[i])
				wynik=minusp[i]-plusl[i];
		}
	}


	cout << wynik << endl;

	return 0;
}
