#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back

const int INF = 1e9+7;
vector<int>a, b, dp[2];

int Find(int index, int x, int y){
	int ans = INF;
	if (a[index]<x && b[index]<y) ans = min(ans, dp[0][index]);
	if (b[index]<x && a[index]<y) ans = min(ans, dp[1][index]);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> b[i];
	dp[0].resize(n);
	dp[1].resize(n);
	dp[0][0] = 0;
	dp[1][0] = 1;
	for (int i = 1; i<n; i++){
		dp[0][i] = Find(i-1, a[i], b[i]);
		dp[1][i] = Find(i-1, b[i], a[i]);
		if (dp[1][i] != INF) dp[1][i]++;
	}
	
	int ans = min(dp[0][n-1], dp[1][n-1]);
	if (ans == INF) cout << "NIE\n";
	else cout << ans << "\n";
	return 0;
}
