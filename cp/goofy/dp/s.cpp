#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define nd second
#define st first
#define pb push_back

const int MAX = 1e4+7, SUMA = 107;
const LL MOD = 1e9+7;
LL dp[MAX][SUMA];

int toint(char c){
	return (int)(c-'0');
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int d;
	cin >> s >> d;
	int n = s.size();
	
	dp[n][0] = 1;
	for (int i = n-1; i>=0; i--){
		for (int j = 0; j<d; j++){
			for (int k = 0; k<10; k++){
				dp[i][j] += dp[i+1][(j+k)%d];
				if (dp[i][j]>=MOD) dp[i][j]%=MOD;
			}
		}
	}
	
	int suma = 0;
	LL ans = 0LL;
	for (int i = 0; i<n; i++){
		int t = toint(s[i]);
		for (int k = 0; k<t; k++){
			ans += dp[i+1][(suma+k)%d];
			if (ans >= MOD) ans %= MOD;
		}
		suma += t;
		if (suma >= d) suma%=d;
	}
	if (!suma) ans++;
	if (--ans < 0) ans += MOD;
	cout << ans << "\n";
	return 0;
}
