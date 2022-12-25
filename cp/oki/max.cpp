//https://codeforces.com/gym/101853/submission/178025398
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
	vector a(n+1, vector<int>(n+1));
	for (int i = 0; i<n; i++){
		for (int j = 1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	vector<vector<int>>dp(n+1, vector<int>((1<<n)+2));
	for (int i = 1; i<=n; i++){
		for (int mask = 0; mask<(1<<n); mask++){
			bool bad = 0;
			for (int k = 1; k<n; k++){
				if (mask&(1<<k)){
					if (mask&(1<<(k-1))){
						bad = 1;
						break;
					}
				}
			}
			if (bad) continue;
			int sum = 0;
			for (int k = 0; k<n; k++){
				if (mask&(1<<k)){
					sum += a[k][i];
				}
			}
			int rev = 0;
			for (int k = 0; k<n; k++){
				if ((mask&(1<<k)) || (k > 0 && (mask&(1<<(k-1)))) || (k < n-1 && (mask&(1<<(k+1))))){
					;
				} else rev += (1<<k);
			}
			dp[i][mask] = max(dp[i][mask], dp[i-1][rev] + sum);
		}
		for (int k = 0; k<n; k++){
			for (int mask = 0; mask<(1<<n); mask++){
				if (mask&(1<<k)){
					dp[i][mask] = max(dp[i][mask], dp[i][mask^(1<<k)]);
				}
			}
		}
		// debug(i, dp[i]);
	}
	int ans = 0;
	for (int i = 0; i<(1<<n); i++){
		ans = max(ans, dp[n][i]);
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
