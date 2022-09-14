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
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	bool any = 0;
	vector<int>big(n+1);
	for (int i = 1; i<=n; i++){
		char c; cin >> c;
		if (c == '1') {
			big[i] = 1;
			any = 1;
		}
	}
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	
	if (!any){
		cout << "0\n";
		return;
	}
	int ans = 0;
	vector<int>dp(n+1);

	function<void(int, int)>dfs = [&](int v, int pa){
		for (auto x: g[v]){
			if (x == pa) continue;
			dfs(x, v);
			dp[v] += dp[x];
			ans = max(ans, big[v] + dp[x]);
		}
		if (big[v]) dp[v] = max(dp[v]-1, 1LL);
		ans = max(ans, dp[v]);
	};

	dfs(1, 1);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
