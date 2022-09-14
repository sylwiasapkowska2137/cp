#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 402;
const LL INF = 1e18;
LL dp[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<LL>a(n+1), pref(n+1);
	pref[0] = 0;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	for (int i = 1; i<=n; i++){
		for (int j = i; j<=n; j++) dp[i][j] = INF;
	}
	for (int i = 1; i<=n; i++) dp[i][i] = 0;
	for (int i = 1; i<=n; i++) dp[i][i+1] = a[i]+a[i+1];
	
	
	for (int i = n; i>=1; i--){
		for (int j = i+2; j<=n; j++){
			for (int k = i; k<j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
			dp[i][j]+=pref[j]-pref[i-1];
		}
	}
	cout << dp[1][n] << "\n";
	return 0;
}
