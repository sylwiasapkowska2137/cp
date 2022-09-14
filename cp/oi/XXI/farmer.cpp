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
	vector<int>a(n+1);
	for (int i = 1;i<=n; i++) cin >> a[i];
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>sub(n+1), dp(n+1);

	function<void(int, int)>dfs = [&](int v, int pa){
		vector<int>curr;
		sub[v] = 1;
		for (auto x: g[v]){
			if (x == pa) continue;
			curr.emplace_back(x);
			dfs(x, v);
			sub[v] += sub[x];
		}
		sort(curr.begin(), curr.end(), [&](auto a, auto b){return dp[a]-2*sub[a] > dp[b]-2*sub[b];});
		dp[v] = a[v];
		int czas = 0;
		for (auto x: curr){
			czas++;
			dp[v] = max(dp[v], czas+dp[x]);
			czas += 2*(sub[x]-1)+1;
		}
	};

	dfs(1, 1);
	dp[1] = max(dp[1], a[1]+2*(n-1));
	cout << dp[1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
