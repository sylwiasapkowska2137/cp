//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
const int oo = 1e18, K = 18;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int, int>>>g(n+1);
	vector<tuple<int, int, int>>e;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
		e.emplace_back(a, b, c);
	}
	vector<int>d(n+1, oo), from(n+1);
	set<pair<int, int>>s;
	for (int i = 1; i<=k; i++){
		d[i] = 0;
		from[i] = i;
		s.insert({0, i});
	}
	function<void()> dijkstra = [&](){
		while (!s.empty()){
			int v = s.begin()->second;
			int D = s.begin()->first;
			s.erase(s.begin());
			if (d[v] < D) continue;
			for (auto [x, c]: g[v]){
				if (d[x] > D+c){
					d[x] = D+c;	
					from[x] = from[v];
					s.insert({d[x], x});
				}
			}
		}
	};
	dijkstra();
	

	vector<int>rep(n+1, 0), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	
	function<int(int)>Find = [&](int a){
		if (a == rep[a]) return a;
		return rep[a] = Find(rep[a]);
	};

	function<bool(int, int)>Union = [&](int a, int b){
		a = Find(a);
		b = Find(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
		return 1;
	};

	vector<tuple<int, int, int>>mst;
	for (auto [a, b, c]:e){
		if (from[a] != from[b]){
			mst.emplace_back(from[a], from[b], d[a]+d[b]+c);
		} 
	}
	vector<vector<pair<int, int>>>G(n+1);
	sort(mst.begin(), mst.end(), [&](auto a, auto b){return get<2>(a) < get<2>(b);});
	for (auto [a, b, c]:mst){
		if (Union(a, b)){
			G[a].emplace_back(b, c);
			G[b].emplace_back(a, c);
		}
	}
	vector<vector<int>>up(n+1, vector<int>(K, 0));
	vector<vector<int>>maxi(n+1, vector<int>(K, -oo));
	vector<bool>vis(k+1);
	vector<int>depth(k+1);

	function<void(int, int, int)>dfs = [&](int v, int pa, int w){
		vis[v] = 1;
		up[v][0] = pa;
		maxi[v][0] = w;
		for (int i = 1; i<K; i++){
			up[v][i] = up[up[v][i-1]][i-1];
			maxi[v][i] = max(maxi[v][i-1], maxi[up[v][i-1]][i-1]);
		}
		for (auto [x, c]: G[v]){
			if (x != pa && !vis[x]){
				depth[x] = depth[v]+1;
				dfs(x, v, c);
			}
		}
	};
	
	for (int i = 1; i<=k; i++){
		if (!vis[i]){
			dfs(i, i, -oo);
		}
	}	
	function<int(int, int)>lca = [&](int a, int b){
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[b]-(1<<i)>=depth[a]){
				b = up[b][i];
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

	function<int(int, int)>query = [&](int a, int l){
		int ans = -oo;
		for (int i = K-1; i>=0; i--){
			if (depth[a] - (1<<i) >= depth[l]){
				ans = max(ans, maxi[a][i]);
				a = up[a][i];
			}
		}
		return ans;
	};
	int q; cin >> q;
	while (q--){
		int a, b, t; cin >> a >> b >> t;
		int ans = 0;
		if (from[a] != from[b]){
			int L = lca(a, b);
			ans = max(query(a, L), query(b, L));
		} 
		if (ans > t) cout << "No\n";
		else cout << "Yes\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}