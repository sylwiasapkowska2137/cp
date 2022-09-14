#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAXN = 107, MAXK = 1e5+7, MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, a;
	cin >> n >> k;

	static LL dp[2][MAXK];
	dp[1][0] = 1;
	for (int i = 1; i<=n; i++) {
		cin >> a;
		for (int j = 1; j<=k; j++) dp[i&1][j] = ((dp[i&1][j-1] + dp[i&1][j])%MOD+MOD)%MOD;
		for (int j = 0; j <= k; j++) dp[!(i&1)][j] = ((dp[i&1][j] -  (j>a ? dp[i&1][j-a-1] : 0))%MOD+MOD)%MOD;
	}
	cout << dp[k&1][k] << '\n';
	//cout << dp[1][k] << '\n';
	
	return 0;
}
