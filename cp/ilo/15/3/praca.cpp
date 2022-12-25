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

//dp[l][r][k] = minimalny koszt usunięcia palindromów z przedziału [L, R], by pozostały palindrom miał rozmiar k

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s = "$"+s;
	vector<int>c(n+1);
	for (int i = 1; i<=n; i++) cin >> c[i];
	vector<vector<vector<int>>>dp(n+2, vector<vector<int>>(n+2, vector<int>(n+2, 0)));
	for (int len = 1; len <= n; len++){
		for (int l = 1; l<=n; l++){
			int r = l+len-1;
			if (r > n) break;
			for (int j = 1; j<=len; j++){
				dp[l][r][j] = oo;
				for (int ii = r; l+j<=ii; ii--){
					dp[l][r][j] = min(dp[l][r][j], dp[l][ii-1][j]+dp[ii][r][0]);
				}
				for (int ii = l; ii+j<=r; ii++){
					dp[l][r][j] = min(dp[l][r][j], dp[l][ii][0]+dp[ii+1][r][j]);
				}
				if (j == 1){
					dp[l][r][1] = min({dp[l][r][1], dp[l+1][r][0], dp[l][r-1][0]});
				} else if (s[l] == s[r]) {
					dp[l][r][j] = min(dp[l][r][j], dp[l+1][r-1][j-2]);
				}
			}
			dp[l][r][0] = oo;
			for (int j = 1; j<=len; j++){
				dp[l][r][0] = min(dp[l][r][0], dp[l][r][j] + c[j]);
			}
		}
	}
	cout << dp[1][n][0] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
