#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " ";
const int MAX = 107;
int dp[MAX][MAX];

int cnt(int m, int n){
	int xmin = 1e9+7;
	int ymin = 1e9+7;
	if (m == n) return 1;
	if (dp[m][n]) return dp[m][n];
	for (int i = 1; i <= m/2; i++) ymin = min(cnt(i, n) + cnt(m-i, n), ymin); 
	for (int j = 1; j <= n/2; j++) xmin = min(cnt(m, j) + cnt(m, n-j), xmin);
	dp[m][n] = min(xmin, ymin); 
	return dp[m][n];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	cout << cnt(m, n);
	return 0;
}
 
