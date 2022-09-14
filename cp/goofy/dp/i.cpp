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

const int MAX = 3001, HALF = 1507;
LD dp[MAX][HALF];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cout << setprecision(10) << fixed;
	cin >> n;
	vector<LD>p(n);
	for (int i = 0; i<n; i++) cin >> p[i];
	int ile = n/2+1;
	for (int i = 0; i<=n; i++)dp[i][0] = 1;
	
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=ile; j++){
			dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
		}
	}
	cout << dp[n][ile] << "\n";
	return 0;
}





