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

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	vector<vector<int>>c(k+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		c[a[i]].emplace_back(i);
	}
	vector<vector<int>>G(n+1);
	vector<pair<int, int>>edges;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		// G[a].emplace_back(b);
		// G[b].emplace_back(a);
		edges.emplace_back(a, b);
	}
	// vector<int>par(n+1), depth(n+1);
	// function<void(int, int)>dfs = [&](int v, int pa){
	// 	par[v] = pa;
	// 	for (auto x: g[v]){
	// 		if (x == pa) continue;
	// 		depth[x] = depth[v]+1;
	// 		dfs(x, v);
	// 	}
	// };

	// dfs(1, 1);
	// vector<int>numer(n+1, -1), color(k+1);
	// int nr = 1;
	
	// function<void(int)>find = [&](int v){
	// 	queue<int>q;
	// 	vector<int>curr;
	// 	for (auto x: c[a[v]]) {
	// 		q.push(x);
	// 		curr.emplace_back(x);
	// 		numer[x] = nr;
	// 	}
	// 	while (q.size()){
	// 		int u = q.front();q.pop();
	// 		u = par[u];
	// 		if (numer[u] == nr) continue; 
	// 		curr.emplace_back(u);
	// 		numer[u] = nr;
	// 		if (color[a[u]]) continue;
	// 		color[a[u]] = 1;
	// 		for (auto x: c[a[u]]) {
	// 			curr.emplace_back(x);
	// 			numer[x] = nr;
	// 			q.push(x);
	// 		}
	// 	}
	// 	debug(v, curr);
	// 	for (auto x: curr){
	// 		// debug(x);
	// 		for (auto y: g[x]){
	// 			if (numer[y] == -1){
	// 				// par[y] = y;
	// 				nr++;
	// 				find(y);
	// 			}
	// 		}
	// 	}
	// };

	// find(1);
	vector<int>numer(n+1);
	for (int i = 1; i<=n; i++) numer[i] = i;
	map<int, int>mapa;
	vector<int>scaler;
	for (int i = 1; i<=n; i++) scaler.emplace_back(numer[i]);
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	int s = (int)scaler.size();
	if (s == 1){
		cout << "0\n";
		return;
	}
	for (int i = 0; i<s; i++) mapa[scaler[i]] = i+1;
	// vector<vector<int>>G(s+1);
	vector<pair<int, int>>e;
	for (auto [a, b]:edges){
		if (numer[a] > numer[b]) swap(a, b);
		if (numer[a] < numer[b]) e.emplace_back(mapa[numer[a]], mapa[numer[b]]);
	}
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.end());
	for (auto [a, b]:e){
		debug(a, b);
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	int ans = 0;
	for (int i = 1; i<=s; i++){
		if (G[i].size() == 1){
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
