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

// #define int long long
const int oo = 1e9+7, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n+1);
	vector<vector<int>>adj(n+1, vector<int>(n+1));
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		adj[a][b] = adj[b][a] = 1;
	}
	int czas = 0;
	vector<int>vis(n+1), pre(n+1), low(n+1), p;

	function<void(int, int)>dfs = [&](int v, int pa){
		vis[v] = 1;
		pre[v] = low[v] = ++czas;
		int children = 0;
		for (auto x: g[v]){
			if (x == pa) continue;
			else if (vis[x]) low[v] = min(low[v], pre[x]);
			else {
				dfs(x, v);
				low[v] = min(low[v], low[x]);
				if (low[x] >= pre[v] && pa != -1) p.emplace_back(v);
				children++;
			}
		}
		if (pa == -1 && children > 1) p.emplace_back(v);
	};

	dfs(1, -1);
	if(p.empty()){
		if (m == n*(n-1)/2){
			cout << "YES\n";
			cout << n+1 << "\n";
			for (int i = 1; i<=n; i++){
				cout << 1 << " " << i+1 << "\n";
			}
		} else cout << "NO\n";
		return;
	}
	map<vector<int>, int>f;
	// debug(p);
	int cnt = 1;
	vector<vector<int>>G(n+2);
	vector<int>deg(n+2);
	vector<pair<int, int>>edges;
	int edgecount = 0;

	auto add = [&](int a, int b){
		G[a].emplace_back(b);
		G[b].emplace_back(a);
		edges.emplace_back(a, b);
		// debug(a, b);
		edgecount++;
	};

	for (auto v:p){
		vector<int>A = {v}, B = {v};
		for (auto x: g[v]){
			bool ok = 1;
			for (auto y: A) ok &= adj[x][y];
			if (ok) A.emplace_back(x);
			else B.emplace_back(x);
		}
		bool ok = 1;
		for (int i = 0; i<(int)B.size(); i++){
			for (int j = i+1; j<(int)B.size(); j++){
				ok &= adj[B[i]][B[j]];
			}
		}
		if (!ok){
			cout << "NO\n";
			return;
		}
		if (B.size() == 1){
			if (f.find(A) == f.end()) {
				f[A] = cnt++;
				deg[f[A]] = (int)A.size();
			}
		} else {
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());
			if (f.find(A) == f.end()) {
				f[A] = cnt++;
				deg[f[A]] = (int)A.size()-1;
			}
			if (f.find(B) == f.end()) {
				f[B] = cnt++;
				deg[f[B]] = (int)B.size()-1;
			}
			add(f[A], f[B]);
		}
		// debug(A, B, v);
	}
	// debug(deg);
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<deg[i]; j++){
			add(i, cnt);
			cnt++;
		}
	}
	if (edgecount != n) {
		cout << "NO\n";
		return;
	}
	// debug(deg);
	int cnt2 = 0;
	function<void(int, int)>dfs2 = [&](int v, int pa){
		cnt2++;
		for (auto x: G[v]){
			if (x == pa) continue;
			dfs2(x, v);
		}
	};
	dfs2(1, -1);
	if (n != cnt2-1) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << n+1 << "\n";
		for (auto [a, b]:edges){
			cout << a << " " << b << endl;
		}
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
