#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

const int MAX = 1e5+7;
int dp[3][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b, c;
	cin >> n;
	for (int i = 1; i<=n; i++){
		cin >> a >> b >> c;
		dp[0][i] = max(dp[1][i-1], dp[2][i-1])+a;
		dp[1][i] = max(dp[0][i-1], dp[2][i-1])+b;
		dp[2][i] = max(dp[1][i-1], dp[0][i-1])+c;
	}
	cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << "\n";
	return 0;
}

