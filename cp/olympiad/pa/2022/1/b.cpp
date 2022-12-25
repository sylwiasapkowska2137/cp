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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector dp(n+1, vector<vector<int>>(2, vector<int>(2, oo)));
	dp[1][0][0] = dp[1][1][0] = 0;
	dp[1][0][1] = dp[1][1][1] = 1;
	for (int i = 2; i<=n; i++){
		dp[i][0][0] = min((a[i] < a[i-1] ? dp[i-1][1][0]+1: oo), dp[i-1][1][1]);
		dp[i][0][1] = min(dp[i-1][0][1], dp[i-1][0][0])+1;
		dp[i][1][0] = min((a[i] > a[i-1] ? dp[i-1][0][0]+1: oo), dp[i-1][0][1]);
		dp[i][1][1] = min(dp[i-1][1][0], dp[i-1][1][1])+1;
	}
	int ans = oo;
	for (int i = 0; i<2; i++){
		for (int j = 0; j<2; j++){
			ans = min(ans, dp[n][i][j]);
		}
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
