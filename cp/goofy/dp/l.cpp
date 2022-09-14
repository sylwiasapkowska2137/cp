#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int>t(n+1);
	for(int i = 1; i<=n; i++) cin >> t[i];
	vector<vector<LL> >dp(n+1);
	dp[1].resize(n+1);
	for(int i = 1; i<=n; i++) dp[1][i] = t[i];
	for(int dl = 2; dl<=n; dl++){
		dp[dl].resize(n+2-dl);
		for(int i = 1; i<(int)dp[dl].size(); i++) dp[dl][i] = max(t[i]-dp[dl-1][i+1],t[i+dl-1]-dp[dl-1][i]);
	}
	cout << dp[n][1] << "\n";
	return 0;
}
