#include <iostream>

using namespace std;

int w[100010][2]; 



int main()
{
	int n,m,x,y,r,i;

	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	r=0;
	for (i=0;i<m ;i++ )
	{
		cin >> x >> y;
		w[x][0]++;
		w[y][1]++;
		if (w[x][0]==n || w[y][1]==n)
			break;
		r^=1;
	}
	
	if (i==m)
		cout << -1 << endl;
	else
		cout  << i+1 << ' '  << (r?'J':'M')<< endl;

	return 0;
}
