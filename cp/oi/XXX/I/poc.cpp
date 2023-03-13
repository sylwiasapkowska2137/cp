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
	int n, m, k; cin >> n >> m >> k;
	vector<int>a(n+2), b(m+2);
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=m; i++) cin >> b[i];
	vector<vector<int>>DP(2);
	vector<int>ans(n+2, 1);
	for (int rep = 0; rep < 2; rep++){
		b[m+1] = -1;
		vector<int>dp(n+2);
		vector<int>first(k+1, oo);
		for (int i = 1; i<=m; i++) {
			if (first[b[i]] == oo){
				first[b[i]] = i;
			}
		}
		for (int i = 1; i<=n; i++){
			if (a[i] == b[dp[i-1]+1]){
				dp[i] = dp[i-1]+1;
			} else {
				dp[i] = dp[i-1];
			}
		}
		// for (int i = 1; i<=n; i++){    
		// 	if (dp[i] < first[a[i]]){
		// 		ans[i] = 0;
		// 	}
		// }
		reverse(ans.begin(), ans.end());
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		DP[rep] = dp;
	}
	// reverse(ans.begin(), ans.end());
	reverse(DP[1].begin(), DP[1].end());
	for (int i = 1; i<=n; i++) DP[1][i] = m-DP[1][i]+1;
	vector<vector<int>>idx(k+1);
	for (int i = 1; i<=m; i++){
		idx[b[i]].emplace_back(i);
	}
	debug(DP[0]);
	debug(DP[1]);
	for (int i = 1; i<=n; i++){
		if (!ans[i]) continue;
		if (DP[0][i] < DP[1][i]) {
			ans[i] = 0;
			continue;
		}
		auto it = (lower_bound(idx[a[i]].begin(), idx[a[i]].end(), DP[1][i])-idx[a[i]].begin());
		// debug(DP[1][i], DP[0][i], idx[a[i]][it]);
		if (it >= idx[a[i]].size() || idx[a[i]][it] > DP[0][i]){
			ans[i] = 0;
		}
	}

	for (int i = 1; i<=n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}

