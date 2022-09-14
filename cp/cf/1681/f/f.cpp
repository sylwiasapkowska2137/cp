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
const int oo = 1e18, K = 20;

void solve(){
	int n; cin >> n;
	vector<vector<pair<int, int>>>g(n+1);
	vector<pair<int, int>>edges[n+1];
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
		edges[c].emplace_back(a, b);
	}
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1), pre(n+1), sub(n+1);
	int czas = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = ++czas;
		up[v][0] = pa;
		sub[v] = 1;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
			sub[v] += sub[x];
		}
	};
	dfs(1, 1);
	
	auto lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a]-(1<<i) >= depth[b]){
				a = up[a][i];
			}
		}
		if (a == b) return a;
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0];
	};

	vector<vector<int>>G(n+1);
	vector<int>bad(n+1);
	vector<int>curr(n+1, -1);
	vector<int>f(n+1);
	int ret = 0;
	for (int tt = 1; tt<=n; tt++){
		if (edges[tt].empty()) continue;

		vector<int>v;
		v.emplace_back(1);
		
		auto fix = [&](){
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			sort(v.begin(), v.end(), [&](auto x, auto y){return pre[x] < pre[y];});
		};

		for (auto &[a, b]:edges[tt]){
			if (depth[a] > depth[b]) swap(a, b);
			v.emplace_back(a);			
			v.emplace_back(b);
			bad[b] = 1;
		}
		fix();
		int s = (int)v.size();
		for (int i = 1; i<s; i++) v.emplace_back(lca(v[i-1], v[i]));
		fix();
		for (int i = 1; i<(int)v.size(); i++){
			int l = lca(v[i], v[i-1]);
			if (l != v[i]) {
				G[l].emplace_back(v[i]);
				G[v[i]].emplace_back(l);
			}
		}
	
		int ans = 0;
		function<void(int, int, int)>DFS = [&](int v, int pa, int from){
			f[v] = from;
			for (auto x: G[v]){
				if (x == pa) continue;
				if (bad[x]) ans -= sub[x];
				else DFS(x, v, from);
			}
		};

		for (auto [a, b]:edges[tt]){
			ans = sub[b];
			DFS(b, a, b);
			curr[b] = ans;
		}
		ans = n;
		DFS(1, 1, 1);
		curr[1] = ans;
		for (auto [a, b]:edges[tt]) ret += curr[b] * (curr[f[a]] == -1 ? curr[1] : curr[f[a]]);

		for (auto x: v){
			G[x].clear();
			bad[x] = 0;
			f[x] = 0;
			curr[x] = -1;
		}
	}
	cout << ret << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}