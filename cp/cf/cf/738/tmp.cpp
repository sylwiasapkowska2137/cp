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

const LL MOD = 998244353;

void solve(){
	int n, sum;
	cin >> n >> sum;
	vector<int>left(n), right(n);
	rep(i, 0, n) cin >> left[i] >> right[i];
	
	
	rep(i, 0, n+1){
		rep(j, 0, sum+1){
			debug(dp[i][j]);
		}
		cerr << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}


