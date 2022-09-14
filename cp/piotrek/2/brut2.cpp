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
	int n, d; cin >> n >> d;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector<vector<int>>dp(n+1, vector<int>(n+1));
	for (int i = 1; i<=n; i++){
		dp[i][a[i]] = 1;
		int mx = a[i];
		for (int j = max(1LL, i-d); j<i; j++){
			for (int mx2 = 1; mx2 <= n; mx2++){
				if (!dp[j][mx2]) continue;
				//dp[i][mx], dp[j][mx2]
				if (mx2 < mx){
					dp[i][mx] = max(dp[i][mx], dp[j][mx2]+1);
				} else {
					dp[i][mx2] = max(dp[i][mx2], dp[j][mx2]);
				}
			}
		}
	}
	// for (int i = 1; i<=n; i++){
	// 	for (int mx = 1; mx <= n; mx++){
	// 		cerr << dp[i][mx] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	int ans = 1;
	for (int i = 0; i<=n; i++){
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
