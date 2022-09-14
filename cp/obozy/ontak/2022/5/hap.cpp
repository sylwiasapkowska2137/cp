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

const int oo = 1e9+7, K = 20;

struct e{
	int a, b, c;
	e(int _a = 0, int _b = 0, int _c = 0){
		a = _a, b = _b, c = _c;
	}
};

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<vector<pair<int, int>>>g(n+1);
	vector<e>edges;
	map<pair<int, int>, int>minn;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		if (a == b) continue;
		if (minn.find({a, b}) == minn.end()) minn[{a, b}] = c;
		else minn[{a, b}] = min(minn[{a, b}], c);
		// g[a].emplace_back(b, c);
		// edges.emplace_back(a, b, c);
	}
	for (auto x: minn){
		g[x.first.first].emplace_back(x.first.second, x.second);
		edges.emplace_back(x.first.first, x.first.second, x.second);
	}
	vector<int>vis(n+1), D(n+1), depth(n+1), pre(n+1);
	vector<vector<int>>up(n+1, vector<int>(K, 0));
	int czas = 0;
	set<pair<int, int>>s;
	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		pre[v] = ++czas;
		vis[v] = 1;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]:g[v]){
			if (vis[x]) continue;
			s.insert({v, x});
			D[x] = D[v]+c;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};
	
	dfs(1, 1);

	function<int(int, int)>lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a]-(1<<i)>=depth[b]){
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

	vector<int>big, sp(n+1, -1);
	for (auto &[a, b, c]:edges){
		if (s.find({a, b}) != s.end()) continue;
		big.emplace_back(a);
		big.emplace_back(b);
		// debug(a, b, c);
	}
	sort(big.begin(), big.end());
	big.erase(unique(big.begin(), big.end()), big.end());
	sort(big.begin(), big.end(), [&](auto x, auto y){return pre[x] < pre[y];});
	vector<int>v = big;
	for (int i = 0; i<(int)big.size(); i++){
		int nx = (i == (int)big.size()-1?0:i+1);
		v.emplace_back(lca(big[i], big[nx]));
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i<(int)v.size(); i++) sp[v[i]] = i;
	sort(v.begin(), v.end(), [&](auto a, auto b){return pre[a] < pre[b];});
	int S = (int)v.size();
	vector<vector<pair<int, int>>>G(S+1);
	for (int i = 0; i<(int)v.size(); i++){
		int nx = (i == (int)v.size()-1?0:i+1);
		int l = lca(v[i], v[nx]);
		// debug(v[i], v[nx], l);
		if (l != v[nx])	{
			// debug(l, v[nx], D[v[nx]]-D[l]);
			G[sp[l]].emplace_back(sp[v[nx]], D[v[nx]]-D[l]);
		}
	}
	// debug(s);
	for (auto [a, b, c]:edges){
		if (s.find({a, b}) != s.end()) continue;
		G[sp[a]].emplace_back(sp[b], c);
	}
	vector<vector<int>>dist(S+1, vector<int>(S+1, oo));

	function<void(int)>dijkstra = [&](int from){
		dist[from][from] = 0;
		set<pair<int, int>>s;
		s.insert({0, from});
		while (s.size()){
			auto [d, v] = *s.begin();
			s.erase(s.begin());
			if (dist[from][v] < d) continue;
			for (auto [x, c]:G[v]){
				if (d+c < dist[from][x]){
					dist[from][x] = d+c;
					s.insert({dist[from][x], x});
				}
			}
		}
	};
	for (auto from: v) dijkstra(sp[from]);
	vector<vector<pair<int, int>>>graf(n+1);
	for (auto [a, b, c]:edges){
		if (s.find({a, b}) != s.end()){
			graf[a].emplace_back(b, c);
			graf[b].emplace_back(a, c);
			// debug(a, b);
		}
	}

	// return;
	// for (int i = 0; i<S; i++){
	// 	for (int j = 0; j<S; j++){
	// 		cerr << dist[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	vector<int>upp(n+1, -1), down(n+1, -1);
	vis.assign(n+1, 0);
	function<void(int, int, int)>DFS = [&](int v, int pa, int hi){
		if (sp[v] != -1) hi = v;
		upp[v] = hi;
		vis[v] = 1;
		for (auto [x, c]:graf[v]){
			if (vis[x]) continue;
			D[x] = D[v]+c;
			DFS(x, v, hi);
			if (down[x] != -1) down[v] = down[x];
		}
		if (sp[v] != -1) down[v] = v;
	};

	DFS(1, 1, -1);
	// debug(upp, down);
	// debug(D);
	while (q--){
		int a,b; cin >> a >> b;
		int l = lca(a, b);
		int ans = oo;
		if (l == a) ans = min(ans, D[b]-D[a]);
		if (down[a] != -1 && upp[b] != -1) {
			// debug(2137);
			// debug(a, down[a], b, upp[b]);
			ans = min(ans, D[down[a]]-D[a]+dist[sp[down[a]]][sp[upp[b]]]+D[b]-D[upp[b]]);
			// debug(dist[sp[down[a]]][sp[upp[b]]]);
		}

		if (ans == oo) cout << "-1\n";
		else cout << ans << "\n";
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
