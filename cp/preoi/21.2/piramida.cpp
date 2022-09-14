#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n, ans = 0;
	cin >> n;
	vector <int> a(n), dp(n, 0), dp2(n, 0);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 1; i<n; i++){
		if (a[i]>dp[i-1]) dp[i] = dp[i-1]+1;
		else dp[i] = min(dp[i-1], a[i]);
	}
	reverse(a.begin(), a.end());
	for (int i = 1; i<n; i++){
		if (a[i]>dp2[i-1]) dp2[i] = dp2[i-1]+1;
		else dp2[i] = min(dp2[i-1], a[i]);
	}
	reverse(dp2.begin(), dp2.end());
	for (int i = 0;i<n; i++) ans = max(ans, min(dp[i], dp2[i]));
	cout << ans << "\n";
	return 0;
}
