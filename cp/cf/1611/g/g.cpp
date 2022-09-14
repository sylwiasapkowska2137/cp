//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
	string s; getline(cin, s);
	int n, m; cin >> n >> m;
	vector<vector<int>>a(n+1, vector<int>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			char c; cin >> c;
			if (c == '1') a[i][j] = 1;
		}
	}
	vector<vector<int>>dp(n+2, vector<int>(m+2));
	vector<int>ans = {0, 0};
	for (int j = 1; j<=m; j++){
		for (int i = 1; i<=n; i++){
			dp[i][j] = max(dp[i-1][j-1], dp[i+1][j-1]);
			dp[i][j] = max(dp[i][j], (j > 2 ? dp[i][j-2] : 0) + a[i][j]);
			// debug(i, j, dp[i][j]);
			ans[(i+j)%2] = max(ans[(i+j)%2], dp[i][j]);
		}
	}
	cout << ans[0] + ans[1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}