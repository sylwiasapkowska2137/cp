#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, l, x;
	cin >> n >> m >> k >> l;
	vector<int>dp(n+k+l+5, 1e7);
	vector<int>plotki(dp.size(), 0); 
	for (int i = 0; i<m; i++){
		cin >> x;
		plotki[x]++;
	}
	dp[0] = dp[1] = 0;
	for (int i = 1; i<(int)dp.size(); i++){
		plotki[i]+=plotki[i-1];
		//debug(plotki[i]);
	}
	for (int i = 2; i<=n+k+1; i++){
		if (plotki[i-1]==plotki[i-2]) dp[i] = min(dp[i], dp[i-1]);
		if (i>k && plotki[i+l-1] == plotki[i-1]) dp[i+l] = min(dp[i+l], dp[i-k]+1);
	}
	int ans = 1e7;
	for(int i = n+1; i < (int)dp.size();i++) ans = min(ans, dp[i]);	
	if(ans == 1e7) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}

