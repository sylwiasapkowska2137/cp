#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();
	vector<int>last(30, -1);
	vector<LL> dp(n+2), pref(n+2);
	dp[0] = 1;
	pref[0] = 1;
	pref[1] = 0;
	rep(i, 0, n){
		if (last[s[i]-'a']<=0) dp[i+2] = pref[i];
		else {
			int pos = last[s[i]-'a'];
			dp[i+2] = pref[i]-pref[pos];
			if (dp[i+2]>=MOD)dp[i+2]%=MOD;
		} 
		pref[i+2] = pref[i+1]+dp[i+2];
		if (pref[i+2]>=MOD) pref[i+2]%=MOD;
		last[s[i]-'a'] = i;
	}
	LL ans = 0LL;
	rep(i, 2, n+2) {
		ans += dp[i];
		debug(dp[i]);
		if (ans>=MOD) ans%=MOD;
	}
	cout << ans << "\n";
	
	return 0;
}
