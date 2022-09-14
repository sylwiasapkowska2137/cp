#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
const int MAX = 255;
int tab[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a, x, z;
	cin >> n >> z;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> x;
			tab[i][j] = x+tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1];
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			int a = max(1, i-z);
			int b = max(1, j-z);
			int c = min(n, i+z);
			int d = min(n, j+z);
			int res = tab[c][d]-tab[a-1][d]-tab[c][b-1]+tab[a-1][b-1];
			cout << res << " ";
		}
		cout << "\n";
	}
	return 0;
}
