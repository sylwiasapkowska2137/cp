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

// #define int long long
const int oo2 = 1e9+1, K = 30;
// const int mod = 998244353;

void solve(){
	typedef pair<int, int> T;
	int n, m, k; cin >> n >> m >> k;
	vector<vector<T>>g(n+1);
	vector<int>in(n+1);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		in[b]++;
	}
	queue<int>q;
	for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
	vector<int>topo;
	while (q.size()){
		int v = q.front();q.pop();
		topo.emplace_back(v);
		for (auto [x, c]: g[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	// debug(topo);
	reverse(topo.begin(), topo.end());
	vector<vector<int>>dp(n+1, vector<int>(n+1, oo2));
	int ans = 1;
	for (auto v: topo){
		dp[v][1] = 0;
		for (int i = 2; i<=n; i++){
			for (auto [x, c]: g[v]){
				if (dp[x][i-1] >= oo2) continue;
				dp[v][i] = min(dp[v][i], dp[x][i-1]+c);
			}
		}
	}
	// for (int v = 1; v <= n; v++){
	// 	cerr << v << " ";
	// 	for (int u = 1; u <= n; u++){
	// 		cerr << dp[v][u] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	for (int i = 1; i<=n; i++){
		if (dp[1][i] <= k){
			ans = i;
		}
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
