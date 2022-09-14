//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

#define int long long
const int oo = 1e18, K = 30;

#define N \
cout << "NO\n";\
return;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>adj(n+1, vector<int>(n+1));
	vector<vector<int>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		adj[a][b] = adj[b][a] = 1;
	}

	vector<int>vis(n+1), p, point(n+1);
	vector<int>pre(n+1), low(n+1);
	int czas = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		vis[v] = 1;
		pre[v] = low[v] = ++czas;
		int ch = 0;
		for (auto x: g[v]){
			if (x == pa) continue;
			if (vis[x]) low[v] = min(low[v], pre[x]);
			else {
				dfs(x, v);
				low[v] = min(low[v], low[x]);
				if (low[x] >= pre[v] && pa != -1){
					point[v] = 1;
				}
				ch++;
			}
		} 
		if (pa == -1 && ch > 1) point[v] = 1;
	};
	dfs(1, -1);
	int s = accumulate(vis.begin(), vis.end(), 0);
	if (s != n) {
		N
	}
	for (int i = 1; i<=n; i++){
		if (point[i]) {
			p.emplace_back(i);
		}
	}
	// debug(p);
	if (p.empty()){
		if (m == n*(n-1)/2){
			cout << "YES\n";
			cout << n+1 << "\n";
			for (int i = 1; i<=n; i++) cout << 1 << " " << i+1 << "\n";
			return;
		} else {
			N
		} 
	}
	map<vector<int>, int>f;
	int cnt = 1;
	vector<vector<int>>G(2*n+2);
	vector<int>deg(2*n+2);
	vector<pair<int, int>>edges;

	auto add = [&](int a, int b){
		if (max(a, b) > (int)G.size()) G.resize(max(a, b)+2);
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		edges.emplace_back(a, b);
		// debug(a, b);
	};
	// debug(p);
	for (auto v:p){
		vector<int>A = {v}, B = {v};
		for (auto x: g[v]){
			bool ok = 1;
			for (auto y: A) ok &= adj[x][y];
			if (ok) A.emplace_back(x);
			else B.emplace_back(x);
		}
		if (B.size() == 1) {
			N
		}
		bool ok = 1;
		for (int i = 0; i<(int)B.size(); i++){
			for (int j = i+1; j<(int)B.size(); j++){
				ok &= adj[B[i]][B[j]];
			}
		}
		if (!ok) {
			N
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		// debug(A, B);
		if (f.find(A) == f.end()) {
			f[A] = cnt++;
			if ((int)deg.size() < cnt) deg.resize(cnt+2);
			deg[f[A]] = (int)A.size();
		}
		if (f.find(B) == f.end()) {
			f[B] = cnt++;
			if ((int)deg.size() < cnt) deg.resize(cnt+2);
			deg[f[B]] = (int)B.size();
		}
		add(f[A], f[B]);
		// debug(A, B, v);
	}
	// debug(deg);
	for (int i = 1; i<(int)deg.size(); i++){
		deg[i] -= (int)G[i].size();
	}
	for (int i = 1; i<(int)deg.size(); i++){
		// debug(i, deg[i]);
		for (int j = 0; j<deg[i]; j++){
			add(i, cnt);
			cnt++;
		}
	}
	if ((int)edges.size() != cnt-2) {
		N
	}

	int cnt2 = 0;
	function<void(int, int)>dfs2 = [&](int v, int pa){
		cnt2++;
		for (auto x: G[v]){
			if (x == pa) continue;
			dfs2(x, v);
		}
	};
	dfs2(1, -1);
	if (cnt-1 != cnt2) {
		N
	}
	cout << "YES\n";
	cout << (int)edges.size()+1 << "\n";
	for (auto [a, b]:edges){
		cout << a << " " << b << endl;
	}	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
