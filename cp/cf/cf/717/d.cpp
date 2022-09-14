#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

const int MOD = 1e9+7, MAX = 1e5+7, S = 350, K = 20;
int dp[MAX][K], Next[MAX];
vector<int>p[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, x, y;
	cin >> n >> q;
	vector<int>a(n);
	rep(i, 0, n) cin >> a[i];
	int koniec = 0;
	
	rep(i, 2, MAX){
		if (p[i].empty()){
			Next[i] = n;
			for (int j = i; j<MAX; j+=i) p[j].pb(i); //wszystkie dzielniki pierwsze
		}
	}
	dp[n][0] = n;
	
	repd(i, n-1, 0){
		dp[i][0] = dp[i+1][0];
		for (auto x: p[a[i]]){
			dp[i][0] = min(dp[i][0], Next[x]);
			Next[x] = i;
		}
	}
	
	rep(l, 1, K){
		rep(x, 0, n){
			dp[x][l] = dp[dp[x][l-1]][l-1];
			if (!dp[x][l]) dp[x][l] = n;
			//debug(dp[x][l]);
		}
		//cerr << "\n";
	}
	while (q--){
		cin >> x >> y;
		x--;y--;
		int ans = 0;
		for (int i = K-1; i>=0; i--){
			if (dp[x][i]<=y){
				x = dp[x][i];
				ans+=(1<<i);
			}
		}
		cout << ans+1 << "\n";
	}
	
	return 0;
}

