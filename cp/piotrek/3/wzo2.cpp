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
// const int oo = 1e18, K = 30;

void solve(){
	int n, k; cin >> n >> k;
	vector<vector<int>>t(k+1);
	vector<pair<int, int>>edges;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	for (int i = 1; i<=n; i++) {
		int x; cin >> x;
		t[x].emplace_back(i);
	}
	vector<int>pre(n+1), par(n+1), depth(n+1);
	int czas = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = ++czas;
		par[v] = pa;
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	dfs(1, 1);

	vector<int>rep(n+1);
	vector<vector<int>>G(n+1);
	iota(rep.begin(), rep.end(), 0);

	function<int(int)> Find = [&](int a){ return rep[a] == a ? a : rep[a] = Find(rep[a]);};
	
	auto Union = [&](int a, int b){
		a = Find(a), b = Find(b);
		if (a == b) return 0;
		rep[a] = b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		// debug(a, b);
		return 1;
	};

	for (int i = 1; i<=k; i++){
		sort(t[i].begin(), t[i].end(), [&](int x, int y){return pre[x] < pre[y];});
		for (int j = 1; j<(int)t[i].size(); j++){
			int a = Find(t[i][j-1]), b = Find(t[i][j]);
			while (a != b){
				if (depth[a] > depth[b]) swap(a, b);
				Union(b, par[b]);
				b = Find(b);
			}
		}
	}

	vector<int>nr(n+1, -1);
	int curr = 0;

	function<void(int, int)>dfs2 = [&](int v, int pa){
		nr[v] = curr;
		for (auto x: G[v]){
			if (x == pa) continue;
			dfs2(x, v);
		}
	};


	for (int i = 1; i<=n; i++){
		if (nr[i] == -1){
			curr++;
			dfs2(i, i);
		}
	}

	// debug(nr);
	vector<int>deg(curr+1);
	for (auto [a, b]:edges){
		if (nr[a] != nr[b]){
			deg[nr[a]]++;
			deg[nr[b]]++;
		}
	}
	int ans = 0;
	for (int i = 1; i<=curr; i++){
		if (deg[i] == 1){
			ans++;
		}
	}
	cout << (ans+1)/2 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
