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
const int oo = 1e9+7, K = 20;

struct edge{
	int a, b, c;
	edge(int _a = 0, int _b = 0, int _c = 0){
		a = _a, b = _b, c = _c;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<edge>e[2];
	for (int i = 0; i<m; i++){
		int a, b, w, c; cin >> a >> b >> w >> c;
		e[c].emplace_back(a, b, w);
	}
	for (int w = 0; w<2; w++){
		sort(e[w].begin(), e[w].end(), [&](auto a, auto b){return a.c < b.c;});	
	}
	
	int N = 2*n+2;
	vector<int>rep(N), sz(N, 1), val(N, oo);
	iota(rep.begin(), rep.end(), 0);
	
	function<int(int)> Find = [&](int a){
		if (a == rep[a]) return a;
		return rep[a] = Find(rep[a]);
	};

	int cnt = n+1;
	vector<vector<int>>G(N);

	auto Union2 = [&](int a, int b, int c){
		a = Find(a);
		b = Find(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		// debug(cnt, a);
		// debug(cnt, b);
		G[cnt].emplace_back(a);
		G[cnt].emplace_back(b);
		rep[b] = cnt;
		rep[a] = cnt;
		val[cnt] = c;
		cnt++;
		return 1;
	};
	
	for (auto [a, b, c]:e[1]) Union2(a, b, c);	
	int czas = 0;
	vector<int>pre(N), depth(N);
	vector<vector<int>>up(N, vector<int>(K));
	vector<int>vis(N);
	int nr = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = ++czas;
		up[v][0] = pa;
		vis[v] = nr;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto x: G[v]){
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	for (int i = cnt-1; i>=1; i--){
		if (!vis[i]){
			nr++;
			dfs(i, i);
		}
	}

	// debug(pre);
	// debug(vis);
	iota(rep.begin(), rep.end(), 0);
	sz.assign(N, 1);
	vector<set<pair<int, int>>>tab(N);
	for (int i = 1; i<=n; i++) tab[i].insert({pre[i], i});
	int ans = oo;

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

	auto Union = [&](int a, int b, int c){
		a = Find(a);
		b = Find(b);
		if (a == b) return 0;
		if (tab[a].size() < tab[b].size()) swap(a, b);
		for (auto [x, y]:tab[b]){
			auto it = tab[a].lower_bound({x, y});
			if (it != tab[a].end()){
				int z = it->second;
				if (vis[y] == vis[z]) {
					int l = lca(y, z); 
					ans = min(ans, c+val[l]);
				}
			} 
			if (it != tab[a].begin()){
				int z = (prev(it))->second;
				if (vis[y] == vis[z]) {
					int l = lca(y, z); 
					ans = min(ans, c+val[l]);
				}
			}
		}
		for (auto x:tab[b]) tab[a].insert(x);
		rep[b] = a;	
		return 1;
	};

	for (auto [a, b, c]:e[0]){
		Union(a, b, c);
	}
	if (ans == oo) cout << "-1\n";
	else cout << ans << endl;
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
