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
	int n1, n2, m, q; cin >> n1 >> n2 >> m >> q;
	int n = n1+n2;
	vector<vector<int>>g(n+1);
	map<pair<int, int>, int>edges;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		b += n1;
		// cerr << a << " " << b << "\n";
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		edges[{a, b}] = edges[{b, a}] = i+1;
	}
	// return;
	vector<int>match(n+1, -1), vis(n+1);
	function<bool(int)>dfs = [&](int v){
		vis[v] = 1;
		for (auto x: g[v]){
			if (match[x] == -1){
				match[v] = x;
				match[x] = v;
				return 1;
			}
		}
		for (auto x: g[v]){
			if (!vis[match[x]] && dfs(match[x])){
				match[v] = x;
				match[x] = v;
				return 1;
			}
		}
		return 0;
	};
	while (1){
		vis.assign(n+1, 0);
		bool any = 0;
		for (int i = 1; i<=n; i++) if (match[i] == -1 && dfs(i)) any = 1;
		if (!any) break;
	}
	// debug(match);
	vector<vector<int>>G(n+1);
	for (int i = 1; i<=n1; i++){
		if (match[i] != -1){
			G[match[i]].emplace_back(i);
			// debug(match[i], i);
		}
		for (auto x: g[i]){
			if (x == match[i]) continue;
			G[i].emplace_back(x);
			// debug(i, x);
		}
	}
	vis.assign(n+1, 0);
	function<void(int)>DFS = [&](int v){
		vis[v] = 1;
		for (auto x: G[v]){
			if (!vis[x]){
				DFS(x);
			}
		}
	};
	for (int i = 1; i<=n1; i++) if (match[i] == -1) DFS(i);
	// debug(vis);
	vector<int>cover;
	for (int i = 1; i<=n1; i++) if (!vis[i]) cover.emplace_back(i);
	for (int i = n1+1; i<=n1+n2; i++) if (vis[i]) cover.emplace_back(i);
	// debug(cover);
	// return;
	int sum = 0, mx = 0;
	for (int i = 1; i<=n1; i++){
		if (match[i] != -1){
			mx++;
			sum += edges[{i, match[i]}];
		}
	}
	// debug(mx);
	// debug(sum);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int v = cover.back();
			int x = match[cover.back()];
			cout << 1 << "\n" << (v > n1 ? -(v-n1) : v) << "\n";
			assert(x != -1);
			match[x] = -1;
			match[v] = -1;
			sum -= edges[{x, v}];
			cover.pop_back();
			mx--;
			cout << sum << "\n";
		} else {
			cout << mx << "\n";
			for (int i = 1; i<=n1; i++){
				if (match[i] != -1){
					cout << edges[{i, match[i]}] << " ";
				}
			}
			cout << "\n";
		}
		// cout << "\n";
		cout.flush();
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}