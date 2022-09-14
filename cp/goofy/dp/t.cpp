#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 3007;
const LL MOD = 1e9+7;
LL dp[2][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	
	for (int i = 0; i<=n; i++) dp[0][i] = 1;
	//cerr << "1\n";
	for (int i = 1; i<n; i++){
		vector<LL>pref(i+2, 0);
		for (int j = 1; j<=i+1; j++) pref[j] = pref[j-1]+dp[!(i&1)][j];
		for (int j = 1; j<=i+1; j++){
			if (s[i-1]=='>') dp[i&1][j] = (pref[i]-pref[j-1]);
			else dp[i&1][j] = pref[j-1];
			
			if (dp[i&1][j]>=MOD) dp[i&1][j]%=MOD;
			//debug(dp[i][j]);
		}
		//cerr << "\n";
	}
	LL ans = 0LL;
	for (int i = 1; i<=n; i++) {
		ans += dp[(n-1)&1][i];
		if (ans >= MOD) ans%=MOD;
	}
	cout << ans << "\n";
	return 0;
}
