#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back

const int MAX = 1e5+7, MOD = 1e9+7;
int dp[MAX][10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	string t = "chokudai";
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=8; j++){
			if (j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = 0;
			else {
				if (s[i-1]==t[j-1]){
					dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
					if (dp[i][j]>=MOD) dp[i][j]%=MOD;
				} else dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][8] << "\n";
	return 0;
}


