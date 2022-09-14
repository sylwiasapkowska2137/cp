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

int n, k; 
vector<vector<int>>d, g;
vector<int>t, sub, par, cnt, color;
vector<bool>vis;
int ans;

int dfs(int v, int pa){
	sub[v] = 1;
	for (auto x: g[v]){
		if (x == pa || vis[x]) continue;
		sub[v] += dfs(x, v);
	}
	return sub[v];
}	

int get(int v, int ms, int pa){
	for (auto x: g[v]){
		if (x == pa || vis[x]) continue;
		if (sub[x]*2>ms) return get(x, ms, v);
	}
	return v;
}

void DFS(int v, int pa, int c){
	par[v] = pa;
	cnt[t[v]]+=c;
	for (auto x: g[v]){
		if (x == pa || vis[x]) continue;
		DFS(x, v, c);
	}
}

void centroid(int v){
	v = get(v, dfs(v, v), v);
	DFS(v, v, 1);
	vector<int>toclear;
	toclear.emplace_back(t[v]);
	color[t[v]] = 1;
	if (cnt[t[v]] == (int)d[t[v]].size()){
		queue<int>q;
		int essa = 0;
		bool ok2 = 1;
		for (auto x: d[t[v]]) q.push(x);
		while (!q.empty()){
			int u = q.front(); q.pop();
			u = par[u];
			//debug(u);
			if (color[t[u]]) continue;
			if (cnt[t[u]] != (int)d[t[u]].size()){
				ok2 = 0;
				break;
			}
			color[t[u]] = 1;
			essa++;
			toclear.emplace_back(t[u]);
			for (auto x: d[t[u]]) q.push(x);
		}
		if (ok2) ans = min(ans, essa);
	}
	for (auto x: toclear) color[x] = 0;
	
	DFS(v, v, -1);
	vis[v] = 1;
	for (auto x: g[v]){
		if (!vis[x]){
			centroid(x);
		}
	}
}

void solve(){
	cin >> n >> k;
	d.resize(k+1);
	g.resize(n+1);
	t.resize(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> t[i];
		d[t[i]].emplace_back(i);
	}
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vis.assign(n+1, 0);
	sub.assign(n+1, 0);
	par.assign(n+1, 0);
	cnt.assign(k+1, 0);
	color.assign(n+1, 0);
	ans = k-1;
	centroid(1);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
