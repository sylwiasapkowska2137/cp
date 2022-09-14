#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)

int main(){
	fastio;
	int n;
	LL suma = 0;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		suma += (LL)a[i];
		a[i] = 9-a[i];
	}
	vector <LL> dp[2];
	dp[0].assign(n, 0);
	dp[1].assign(n, 0);
	dp[0][0] = a[0];
	for (int i = 1; i<n; i++){
		dp[0][i] = dp[1][i-1]+(LL)a[i];
		dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
	}
	suma += max(dp[0][n-1], dp[1][n-1]);
	cout << suma;
	return 0;
}

