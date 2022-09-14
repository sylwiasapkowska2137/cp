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
const int oo = 1e9+7, K = 30;
const int s = 120;

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>>g(n+1), gt(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> b >> a;
		gt[b].emplace_back(a);
		g[a].emplace_back(b);
	}
	vector<vector<pair<int, int>>>dist(n+1);
	vector<int>vis(n+1);
	priority_queue<pair<int, int>>pq;
	for (int v = 1; v<=n; v++){
		vector<int>ptr((int)g[v].size()+1);
		while (pq.size()) pq.pop();
		for (int i = 0; i<(int)g[v].size(); i++) pq.push({dist[g[v][i]][ptr[i]].first, i});
		while (pq.size() && (int)dist[v].size() <= s){
			int d = pq.top().first;
			int f = pq.top().second;
			pq.pop();
			int t = dist[g[v][f]][ptr[f]].second;
			if (!vis[t]) {
				vis[t] = 1;
				dist[v].emplace_back(d+1, t);
			}
			ptr[f]++;
			if (ptr[f] < (int)dist[g[v][f]].size()) pq.push({dist[g[v][f]][ptr[f]].first, f});
		}
		int t = (dist[v].size() ? dist[v].back().first -1 : -1);
		for (auto x: g[v]){
			for (auto [d, u]:dist[x]){
				if (d < t) break;
				vis[u] = 0;
			}
		}
		if ((int)dist[v].size() < s) dist[v].emplace_back(0, v);
	}
	// for (int i = 1; i<=n; i++){
	// 	debug(i, dist[i]);
	// }
	vector<int>bad(n+1);
	while (q--){
		int v, k; cin >> v >> k;
		vector<int>x(k);
		for (int i = 0; i<k; i++) {
			cin >> x[i];
			bad[x[i]] = 1;
		}
		int ans = -1;
		if (k < s){
			for (auto [d, u]:dist[v]){
				if (bad[u]) continue;
				ans = d;
				break;
			}
		} else {
			vector<int>dp(n+1);
			for (int i = 1; i<=n; i++){
				if (bad[i]) dp[i] = -oo;
				for (auto j: g[i]) dp[i] = max(dp[i], dp[j]+1);
			}
			ans = max(ans, dp[v]);
		}
		cout << ans << "\n";
		for (auto u: x) bad[u] = 0;
	}

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
