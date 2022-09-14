#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)

const int MAX = 1e3+7, MOD = 1e6;
int tab[MAX][MAX];

int main(){
	fastio;
	int n, x;
	cin >> n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> x;
			if (i == 1 && j == 1) tab[1][1] = 1;
			else if (x==1) tab[i][j] = 0;
			else tab[i][j] = (tab[i-1][j]+tab[i][j-1]+MOD)%MOD;
		}
	}
	tab[n][n]%=MOD;
	cout << tab[n][n];
	return 0;
}
