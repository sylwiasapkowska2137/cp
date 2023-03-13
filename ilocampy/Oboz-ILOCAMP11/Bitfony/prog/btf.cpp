#include <iostream>

using namespace std;

int tab[1000010]; 

int main()
{
	int n,a,b,x,w,y;

	ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i=1;i<=n ;i++ )
		cin >> tab[i];
	
	cin >> a >> b;

	w=0;
	x=a;
	while (1)
	{
		w++;
		y=x;
		x=tab[x];
		if (x==b || x==0)
			break;
		tab[y]=0;
	}

	if (x!=b)
		w=-1;
	cout <<  w << endl;

	return 0;
}
