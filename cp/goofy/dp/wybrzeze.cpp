#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 1e4+7,INF = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, z;
	cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	vector<int>dp(n), prev(n);
	for (int i = 0; i<n; i++) {
		prev[i] = i;
		dp[i] = i;
	}
	for (int i = 1; i<=k; i++){
		for (int v = 0; v<n; v++){
			dp[v] = min(dp[v], prev[v]);
			if (a[v]!=-1) dp[a[v]] = min(min(dp[a[v]], prev[a[v]]), prev[v]+1);
		}
		for (int v = 1; v<n; v++)dp[v] = min(dp[v], dp[v-1]+1);
		swap(dp, prev);
	}
	cout << prev[n-1] << "\n";
	return 0;
}
