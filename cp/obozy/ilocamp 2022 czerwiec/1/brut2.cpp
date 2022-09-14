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

const int oo = 1e9+7, K = 30;

vector<vector<int>>g, G;
vector<int>par, depth, vis;
bool cycle;
vector<vector<int>>up, upup, updown;
int k, n, m, C;

void DFS(int v){
	vis[v] = 1;
	for (auto x: G[v]){
		if (!vis[x]) DFS(x);
		else if (vis[x] == 1) cycle = 1;
	}
	vis[v] = 2;
}

void dfs(int v, int pa){
	up[v][0] = pa;
	for (int i = 1; i<k; i++) up[v][i] = up[up[v][i-1]][i-1]; 
	upup[v][0] = v+n;
	updown[v][0] = v;
	for (int i = 1; i<k; i++){
		upup[v][i] = C++;
		updown[v][i] = C++;
	}
	for (auto x: g[v]){
		if (x == pa) continue;
		depth[x] = depth[v]+1; 
		dfs(x, v);
	}
	for (int i = 1; i<k; i++){
		G[upup[v][i]].emplace_back(upup[v][i-1]);
		G[upup[v][i]].emplace_back(upup[up[v][i-1]][i-1]);
		G[updown[v][i-1]].emplace_back(updown[v][i]);
		G[updown[up[v][i-1]][i-1]].emplace_back(updown[v][i]);
	}
}

int jump(int v, int ile){
	for (int i = k-1; i>=0; i--){
		if (ile&(1<<i)){
			v = up[v][i];
		}
	}
	return v;
}

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	b = jump(b, depth[b]-depth[a]);
	if (a == b) return a;
	for (int i = k-1; i>=0; i--){
		if (up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

void add(int nr, int a, int ile){
	if (ile <= 0) return;
	int l = __lg(ile);
	int b = jump(a, ile-(1<<l));
	G[nr].emplace_back(upup[a][l]);
	G[nr].emplace_back(upup[b][l]);
}

void add_down(int nr, int a, int ile){
	if (ile <= 0) return;
	int l = __lg(ile);
	int b = jump(a, ile-(1<<l));
	G[updown[a][l]].emplace_back(nr);
	G[updown[b][l]].emplace_back(nr);
}

void solve(){
	cin >> n >> m;
	C = n+n+m+1;
	g.assign(n+1, vector<int>());
	G.assign(40*n, vector<int>());
	int s = 1; k = 1;
	while (s < n) s*=2, k++;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	depth.assign(n+1, 0);
	up.assign(n+1, vector<int>(k, 0));
	upup.assign(n+1, vector<int>(k, 0));
	updown.assign(n+1, vector<int>(k, 0));
	dfs(1, 1);
	// for (int i = 0; i<(int)G.size(); i++){
	// 	debug(i, G[i]);
	// }	
	for (int i = 1; i<=m; i++){
		int a, b; cin >> a >> b;
		G[2*n+i].emplace_back(a);
		G[b+n].emplace_back(2*n+i);
		int l = lca(a, b);
		//debug(a, b, l);
		if (l == a){
			add_down(i+2*n, b, depth[b]-depth[l]); 
			add(i+2*n, up[b][0], depth[b]-depth[l]); 
			continue;
		}
		if (l == b){
			add_down(i+2*n, up[a][0], depth[a]-depth[l]);
			add(i+2*n, a, depth[a]-depth[l]);
			continue;
		}
		add_down(i+2*n, up[a][0], depth[a]-depth[l]);
		add_down(i+2*n, b, depth[b]-depth[l]+1);
		add(i+2*n, a, depth[a]-depth[l]+1);
		add(i+2*n, up[b][0], depth[b]-depth[l]);
	}
	vis.assign((int)G.size(), 0);
	cycle = 0;
	for (int i = 1; i<(int)G.size(); i++){
		if (!vis[i]){
			DFS(i);
			if (cycle){
				cout << "NIE\n";
				return;
			}
		}
	}
	cout << "TAK\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
