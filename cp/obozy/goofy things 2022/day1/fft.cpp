#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;

#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for(int i = a; i>=b; i--)
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define sz(x) (int)((x).size())

const LL MOD = 998244353;

void solve(){
	LL n, m; cin >> n >> m;
	LL dp[n+2][m+2];
	memset(dp, 0LL, sizeof(dp));
	rep(i, 1, m+1) dp[0][i] = 1;
	rep(i, 0, n){
		rep(j, 1, m+1){
			for (LL k = 1; k*j<=m; k++){
				dp[i+1][j*k]+=dp[i][j];
				dp[i+1][j*k] %= MOD;
			}
		}
	}
	/*
	rep(i, 0, n){
		rep(j, 1, m+1){
			debug(dp[i][j]);
		}
		cerr << "\n";
	}
	cerr << "\n";
	*/
	LL ans = 0LL;
	rep(i, 1, m+1){
		ans += dp[n-1][i];
		ans %= MOD;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
