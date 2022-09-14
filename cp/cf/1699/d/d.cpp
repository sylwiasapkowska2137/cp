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
	int n; cin >> n;
	vector<int>a(n);
	vector<vector<int>>dp(n, vector<int>(n));
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int l = 0; l<n; l++){
		vector<int>cnt(n+1);
		int mx = 0;
		for (int r = l; r<n; r++){
			cnt[a[r]]++;
			mx = max(mx, cnt[a[r]]);
			if ((r-l+1) % 2 == 0 && 2 * mx <= (r-l+1)){
				dp[l][r] = 1;
			}
		}
	}
	vector<int>DP(n, -oo);
	DP[0] = 1;
	for (int i = 1; i<n; i++) if (dp[0][i-1]) DP[i] = 1;
	
	for (int i = 0; i<n; i++){
		for (int j = 0; j<i; j++){
			if (a[j] == a[i] && (dp[j+1][i-1] || j == i-1)){
				DP[i] = max(DP[i], DP[j]+1);
			}
		}
	}
	int ans = 0;	
	for (int i = 0; i<n; i++){
		if (i == n-1 || dp[i+1][n-1]){
			ans = max(ans, DP[i]);
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}