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
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>pre(n+1), low(n+1), vis(n+1);
	int t = 0;
	vector<pair<int, int>>b;
	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	function<int(int)>f = [&](int a){return a == rep[a] ? a : rep[a] = f(rep[a]);};
	function<void(int, int)>u = [&](int a, int b){
		a = f(a);b = f(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		rep[b] = a;
		sz[a] += sz[b];
	};

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = low[v] = ++t;
		vis[v] = 1;
		for (auto x: g[v]){
			if (x == pa) continue;
			if (vis[x]) low[v] = min(low[v], pre[x]);
			else {
				dfs(x, v);
				low[v] = min(low[v], low[x]);
				if (low[x] > pre[v]) b.emplace_back(x, v);
				else u(x, v);
			}
		}
	};

	dfs(1, 1);
	// debug(rep);
	vector<int>s = rep;
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	auto get = [&](int v){return (int)(lower_bound(s.begin(), s.end(), v)-s.begin());};
	int S = (int)s.size();
	vector<vector<int>>G(S+1);
	for (auto [x, y]:b){
		// debug(x, y, get(x), get(y));
		G[get(x)].emplace_back(get(y));
		G[get(y)].emplace_back(get(x));
	}
	vector<int>depth(S+1);
	pair<int, int>ans = {-oo, -oo};
	function<void(int, int)>dfs2 = [&](int v, int pa){
		ans = max(ans, {depth[v], v});
		for (auto x: G[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs2(x, v);
		}
	};

	dfs2(1, 1);
	int a = ans.second;
	ans = {-oo, -oo};
	depth[a] = 0;
	dfs2(a, a);
	cout << ans.first << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}