#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, K;
	cin >> n >> K;
	vector<LL>h(n+1, 0), dp(n+1, INT_MAX);
	for (int i = 1; i<=n; i++){
		cin >> h[i];
	}
	dp[1] = 0;
	for (int i = 1; i<=n; i++){
		for (int k = 1; k<=K; k++) {
			if (i+k <= n) dp[i+k] = min(dp[i+k], dp[i]+abs(h[i]-h[i+k]));
		}
	}
	//for (int i = 1;i<=n;i++) debug(dp[i]);
	cout << dp[n] << "\n";
	return 0;
}
