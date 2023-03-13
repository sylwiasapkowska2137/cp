#include <iostream>

using namespace std;

int tab[1000010]; 

int main()
{
	int n,a=0,b=1000010,x;

	ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i=0;i<n ;i++ )
		cin >> tab[i];
	
	for (int i=0;i<n ;i++ )
	{
		cin >> x;
		if (x)
		{
			if (tab[i]>a)
				a=tab[i];
		}
		else
		{
			if (tab[i]<b)
				b=tab[i];
		}
	}
	
	cout << ((a<=b)?"TAK":"NIE") << endl;

	return 0;
}
