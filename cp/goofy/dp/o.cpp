#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 20, MOD = 1e9+7;
bool c[MAX][MAX];
LL dp[(1<<MAX)];
int n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int q, a, b;
	cin >> n >> q;
	for (int i = 0; i<q; i++){
		cin >> a >> b;
		c[b-1][a-1] = 1;
	}
	dp[0] = 1;
	for (int maska = 0; maska<(1<<n); maska++){
		//int num = __builtin_popcount(maska);
		for (int j = 0; j<n; j++){
			bool x = 0;
			for (int k = 0; k<n; k++) if (maska&(1<<k)) x |= (c[j][k]);
			if (maska&(1<<j) || x) continue;
			dp[maska|(1<<j)] += dp[maska];
		}
		//debug(dp[maska]);
	}
	cout << dp[(1<<n)-1] << "\n";
	return 0;
}
