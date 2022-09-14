#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, p;
	cin >> n >> m >> p;
	vector <unsigned short int> x(n), y(m);
	int dp[n+1][m+1];
	for (int i = 1; i<=n; i++){
		cin >> x[i-1];
		dp[i][0] = -1;
	}
	for (int i = 1; i<=m; i++){
		cin >> y[i-1];
		dp[0][i] = -1;
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (i == 1 && j == 1) dp[1][1] = (x[0]+y[0])%p;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1])+((x[i-1]+y[j-1])%p);
		}
	}
	cout << dp[n][m] << "\n";
	int i = n, j = m;
	string res = "";
	while (i>0 && j>0){
		if (i == 1 && j == 1) break;
		if (dp[i-1][j]>=dp[i][j-1]){
			i--;
			res+="P";
		} else {
			j--;
			res+="G";
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}
