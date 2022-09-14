#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 307;
LL tab[MAX][MAX], dp[MAX][MAX][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++) cin >> tab[i][j];
	}
	for (int p = 1; p<=2*n-1; p++){
		for (int i = 1;i<=n; i++){
			for (int j = 1; j<=n; j++){
				for (int k = 0; k<2; k++){
					for (int l = 0; l<2; l++){
						dp[p][i][j] = max(dp[p][i][j],dp[p-1][i-k][j-l]);
					}
				}
				dp[p][i][j]+=tab[i][p-i];
			}
		}
	}
	debug(dp[n][n][1]);
	return 0;
}
