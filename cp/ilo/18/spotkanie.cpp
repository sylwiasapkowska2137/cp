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
	vector<vector<int>>g(n+1), gt(n+1);
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		g[i].emplace_back(x);
		gt[x].emplace_back(i);
	}
	vector<int>vis(n+1), order, numer(n+1);
	vector<vector<int>>G(n+1), GT(n+1);
	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
		order.emplace_back(v);
	};
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	vis.assign(n+1, 0);
	int curr = 0;
	vector<int>sz(n+1);
	vector<vector<int>>which(n+1);
	function<void(int)>dfs2 = [&](int v){
		numer[v] = curr;
		which[curr].emplace_back(v);
		sz[curr]++;
		vis[v] = 1;
		for (auto x: gt[v]){
			if (!vis[x]){
				dfs2(x);
			}
		}
	};

	for (auto v: order){
		if (!vis[v]){
			curr++;
			dfs2(v);
		}
	}
	debug(numer);
	debug(curr);
	vector<int>in(curr+1);
	for (int i = 1; i<=n; i++){
		for (auto x: g[i]){
			if (numer[i] != numer[x]){
				G[numer[i]].emplace_back(numer[x]);
				GT[numer[x]].emplace_back(numer[i]);
				in[numer[x]]++;
			}
		}
	}
	queue<int>q;
	for (int i = 1; i<=curr; i++) if (!in[i]) q.push(i);
	vector<int>topo;
	while (q.size()){
		int v = q.front();q.pop();
		topo.emplace_back(v);
		for (auto x: G[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	debug(topo);
	int ans = *max_element(sz.begin(), sz.end());
	vector<int>dp(curr+1);
	for (auto v: topo){
		if (sz[v] == 1){
			for (auto x: GT[v]){
				dp[v] = max(dp[v], dp[x]);
			}
			dp[v]++;
		}
	}
	debug(dp);
	curr = 0;
	for (int v = 1; v <= n; v++){
		int best = 0, second_best = 0;
		
		for (auto x: gt[v]){
			debug(x, dp[x]);
			if (dp[numer[x]] >= best){
				second_best = best;
				best = dp[numer[x]];
			} else if (dp[numer[x]] >= second_best) {
				second_best = dp[numer[x]];
			}
		}
		debug(v, best, second_best);
		ans = max(ans, best+second_best);
	}

	for (auto v: topo){
		if (sz[v] == 2){
			int best = 0, second_best = 0;
			debug(which[v]);
			int a = which[v][0], b = which[v][1];
			for (auto x: gt[a]) best = max(best, dp[x]);
			for (auto x: gt[b]) {
				second_best = max(second_best, dp[x]);
				debug(x);
			}
			debug(best, second_best);
			curr += 2 + best + second_best;
		}
	}
	ans = max(ans, curr);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
