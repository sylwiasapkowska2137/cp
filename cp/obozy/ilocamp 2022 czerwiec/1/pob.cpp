//Sylwia Sapkowska
#include <bits/stdc++.h>
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

namespace IO {
  const int MAXSIZE = 1 << 18 | 1;
  char buf[MAXSIZE], *p1, *p2;
 
  inline int Gc() {
    return p1 == p2 &&
      (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
  }
  template<typename T> inline void read(T& x) {
    x = 0; int f = 0, ch = Gc();
    while (!isdigit(ch)) f |= ch == '-', ch = Gc();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
    if (f) x = -x;
  }
}
using IO::read;

vector<vector<int>>up, g, G;
vector<pair<int, int>>paths;
vector<int>depth, vis;
int k;
bool cycle = 0;
bool ok = 1;

void dfs(int v, int pa){
	up[v][0] = pa;
	for (int i = 1; i<k; i++) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: g[v]){
		if (x == pa) continue;
		depth[x] = depth[v]+1;
		dfs(x, v);
	}
}

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = k-1; i>=0; i--){
		if (depth[b]-(1<<i)>=depth[a]){
			b = up[b][i];
		}
	}
	if (a == b) return a;
	for (int i = k-1; i>=0; i--){
		if (up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

bool onpath(int c, int d, int a){
	int l = lca(c, d);
	if ((lca(c, a) == a || lca(d, a) == a) && lca(l, a) == l) return 1;
	return 0;
}

void add(int i, int j){
	bool x = onpath(paths[j].first, paths[j].second, paths[i].first);
	bool y = onpath(paths[j].first, paths[j].second, paths[i].second);
	if (x && y) ok = 0;
	else if (x && !y) G[i].emplace_back(j);
	else if (!x && y) G[j].emplace_back(i);
}

void DFS(int v){
	vis[v] = 1;
	for (auto x: G[v]){
		if (!vis[x]){
			DFS(x);
		} else if (vis[x] == 1){
			cycle = 1;
			return;
		}
	}
	vis[v] = 2;
}

void solve(){
	int n, m; read(n);read(m);
	g.resize(n+1);
	ok = 1;
	cycle = 0;
	G.resize(m);
	for (int i = 1; i<=n; i++){
		g[i].clear();
	}
	for (int i = 0; i<m; i++){
		G[i].clear();
	}
	for (int i = 1; i<n; i++){
		int a, b; read(a);read(b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	paths.clear();
	for (int i = 0; i<m; i++){
		int a, b; read(a);read(b);
		paths.emplace_back(a, b);
	}
	int s = 1;
	k = 1;
	while (s <= n){
		s*=2;
		k++;
	}
	up.assign(n+1, vector<int>(k, 0));
	depth.assign(n+1, 0);

	dfs(1, 1);
	
	vis.assign(m, 0);
	//debug(paths);
	for (int i = 0; i<m; i++){
		for (int j = 0; j<m; j++){
			if (i == j) continue;
			add(i, j);
			if (!ok){
				cout << "NIE\n";
				return;
			}
		}
	}
	for (int i = 0; i<m; i++){
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

	int t = 1; read(t);
	while (t--) solve();
	
	return 0;
}
