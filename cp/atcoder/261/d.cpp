//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>dp(n+1, vector<int>(n+1, -oo));
	vector<int>x(n+1);
	for (int i = 1; i<=n; i++) cin >> x[i];
	vector<int>c(n+1);
	for (int i = 0; i<m; i++){
		int cc, y; cin >> cc >> y;
		c[cc]+=y;
	}
	dp[0][0] = 0;
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<=i; j++){
			if (j) dp[i][j] = dp[i-1][j-1]+x[i]+c[j];
			dp[i][0] = max(dp[i][0], dp[i-1][j]+c[0]);
		}
	}
	int ans = 0;
	for (int i = 0; i<=n;i++){
		ans = max(ans, dp[n][i]);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
