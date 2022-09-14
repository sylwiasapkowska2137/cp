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
	vector<int>row(n+1), col(m+1);
	for (int i = 1; i<=n; i++) cin >> row[i];
	for (int j = 1; j<=m; j++) cin >> col[j];
	vector a(n+1, vector<int>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			char c; cin >> c;
			if (c == '1') a[i][j] = 1;
		}
	}
	vector dp(n+2, vector<vector<int>>(m+2, vector<int>(2, oo)));
	dp[1][1][a[1][1]] = 0;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			for (int k = 0; k<2; k++){x
				for (int l = 0; l<2; l++){
					if (k != l){
						dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][l] + col[i]);
						dp[i][j+1][k] = min(dp[i+1][j][k], dp[i][j][l] + row[j]);
					} else {
						dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][l]);
						dp[i][j+1][k] = min(dp[i][j+1][k], dp[i][j][l]);
					}
					
				}
			}
		}
	}
	cout << dp[n][n][a[1][1]];
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
