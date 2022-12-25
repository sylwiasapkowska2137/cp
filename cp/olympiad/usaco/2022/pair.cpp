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

void solve1(){
	int n, k; cin >> n >> k;
	vector<int>x(n+1, -oo), w(n+1, -oo);
	for (int i = 1; i<=n; i++) cin >> x[i] >> w[i];
	vector<vector<int>>dp(n+1, vector<int>(2, oo));
	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = w[1], dp[1][1] = 0;
	for (int i = 2; i<=n; i++){
		if (x[i] - x[i-1] <= k){
			dp[i][0] = dp[i-1][1]+w[i];
			dp[i][1] = dp[i-1][0]-w[i-1];
		}
		if (x[i] - x[i-2] <= k){
			dp[i][1] = min(dp[i][1], dp[i-2][0]-w[i-2]+w[i-1]);
			dp[i][0] = oo;
		}
		// debug(i, dp[i][0], dp[i][1]);
	}
	cout << min(dp[n][0], dp[n][1]) << "\n";
}

void solve2(){
	int n, k; cin >> n >> k;
	vector<int>x(n+1, -oo), w(n+1);
	for (int i = 1; i<=n; i++) cin >> x[i] >> w[i];
	vector<int>dp(n+1);
	for (int i = 1; i<=n; i++){
		for (int j = i-1; j>=0; j-=3){
			if (x[i] - x[j] > k) dp[i] = max(dp[i], dp[j] + w[i]);
			if (x[j-1] - x[j-2] > k) break;
		}
	}
	debug(dp);
	cout << dp[n] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	if (t == 1) solve1();
	else solve2();
	
	return 0;
}
