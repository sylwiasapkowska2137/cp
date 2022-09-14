//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;
#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	if (n >= 4 && m >= 4) {
		cout << "-1\n";
		return;
	}
	vector<vector<int>>a(n+1, vector<int>(m+1, 0));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			char c; cin >> c;
			if (c == '1') a[i][j] = 1;
		}
	}
	vector<int>val(m+1, 0);
	for (int i = 1; i<=m; i++){
		for (int j = 1; j<=n; j++){
			val[i] += a[j][i]*(1<<(j-1));
		}
	}
	//debug(val);
	vector<vector<int>>dp(m+1, vector<int>((1<<n)+1, oo));
	for (int j = 0; j<(1<<n); j++) dp[1][j] = __builtin_popcountll(val[1]^j);
	for (int i = 2; i<=m; i++){
		for (int j = 0; j<(1<<n); j++){
			for (int k = 0; k<(1<<n); k++){
				bool ok = 1;
				for (int l = 1; l<n; l++){
					int curr = ((j&(1<<l))>0)+((j&(1<<(l-1)))>0)+((k&(1<<l))>0)+((k&(1<<(l-1)))>0);
					ok &= (curr&1);
				}
				if (ok)	dp[i][j] = min(dp[i][j], dp[i-1][k]+(__builtin_popcountll((val[i]^j))));
			}
			//debug(i, j, dp[i][j]);
		}
	}
	int ans = oo;
	for (int j = 0; j<(1<<n); j++) ans = min(ans, dp[m][j]);
	cout << (ans==oo?-1:ans) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}