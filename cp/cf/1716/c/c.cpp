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
	int m; cin >> m;
	vector a(3, vector<int>(m+1));
	vector czas(3, vector<int>(m+1));
	vector dp(3, vector<int>(m+1));
	for (int i = 1; i<=2; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
			if (a[i][j]) a[i][j]++;
		}
	}
	dp[1][1] = 0;
	czas[1][1] = 1;
	czas[2][1] = 2;
	dp[2][1] = max(dp[1][1], a[2][1]-czas[2][1]+1);
	for (int i = 2; i<=m; i++){
		if (i&1){
			czas[1][i] = czas[1][i-1]+1;
			czas[2][i] = czas[1][i]+1;
			dp[1][i] = max(dp[1][i-1], a[1][i]-czas[1][i]+1);
			dp[2][i] = max(dp[1][i], a[2][i]-czas[2][i]+1);
		} else {
			czas[2][i] = czas[2][i-1]+1;
			czas[1][i] = czas[2][i]+1;
			dp[2][i] = max(dp[2][i-1], a[2][i]-czas[2][i]+1);
			dp[1][i] = max(dp[2][i], a[1][i]-czas[1][i]+1);
		}
	}
	// for (int i = 1; i<=2; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << czas[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << "\n";

	// for (int i = 1; i<=2; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << dp[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << "\n";

	vector<int> dpU(m+1), dpD(m+1);
	dpU[m] = max(a[1][m], a[2][m]-1);
	for (int j = m-1; j>=1; j--){
		int k = m-j;
		dpU[j] = max({dpU[j+1]-1, a[1][j], a[2][j]-(2*k+2)+1});
	}
	// debug(dpU);
	dpD[m] = max(a[2][m], a[1][m]-1);
	for (int j = m-1; j>=1; j--){
		int k = m-j;
		dpD[j] = max({dpD[j+1]-1, a[2][j], a[1][j]-(2*k+2)-1});
	}
	// debug(dpD);
	int ans = max(dp[1][m], dp[2][m]);
	ans = min(ans, dpU[1]);
	// debug(ans);
	for (int j = 2; j<=m; j++){
		//przechodzimy j-1 kolumn wezykiem
		if (j&1){
			ans = min(ans, dp[1][j-1]+max(0LL, dpU[j]-czas[1][j-1]+1));
		} else {
			ans = min(ans, dp[2][j-1]+max(0LL, dpD[j]-czas[2][j-1]+1));
		}
	}
	// debug(ans);
	cout << ans+2*m-1 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
