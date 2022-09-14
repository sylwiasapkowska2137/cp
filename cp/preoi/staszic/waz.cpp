#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)

const int MAX = 1e3+7;
LL tab[MAX][MAX];

int main(){
	fastio;
	int n, m;
	LL x;
	cin >> n >> m;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> x;
			if (i == 1 && j == 1) tab[i][j] = x;
			else if (i == 1) tab[i][j] = tab[i][j-1]+x;
			else if (j == 1) tab[i][j] = tab[i-1][j]+x;
			else tab[i][j] = max(tab[i-1][j], tab[i][j-1])+x;
		}
	}
	cout << max(0LL, tab[n][m]);
	return 0;
}

