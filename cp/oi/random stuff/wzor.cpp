#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector <int> a(n), dp(n), dp2(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	dp[0] = 1;
	for (int i = 1; i<n; i++){
		if (a[i]>dp[i-1]) dp[i] = dp[i-1]+1;
		else dp[i] = min(dp[i-1], a[i]);
	}
	reverse(a.begin(), a.end());
	dp2[0] = 1;
	for (int i = 1; i<n; i++){
		if (a[i]>dp[i-1]) dp2[i] = dp2[i-1]+1;
		else dp2[i] = min(dp2[i-1], a[i]);
	}
	reverse(dp2.begin(), dp2.end());
	int ans = 0;
	for (int i = 0;i<n; i++){
		debug(dp[i]);
		debug(dp2[i]);
		cerr << "\n";
		ans = max(ans, min(dp[i], dp2[i]));
	}
	cout << ans << "\n";
	return 0;
}
