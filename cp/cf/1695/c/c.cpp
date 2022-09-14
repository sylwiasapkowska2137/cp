//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
	vector<vector<int>>a(n+1, vector<int>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	if ((n+m+1)&1){
		cout << "NO\n";
		return;
	}
	vector<vector<int>>dp(n+1, vector<int>(m+1, oo));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (i == 1 && j == 1) dp[i][j] = a[i][j];
			else dp[i][j] = min(dp[i-1][j], dp[i][j-1])+a[i][j];
		}
	}
	int mini = dp[n][m];
	dp.assign(n+1, vector<int>(m+1, -oo));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (i == 1 && j == 1) dp[i][j] = a[i][j];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1])+a[i][j];
		}
	}
	int maxi = dp[n][m];
	if (mini <= 0 && maxi >= 0) cout << "YES\n";
	else cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}