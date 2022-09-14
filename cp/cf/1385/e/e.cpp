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
const int oo = 1e18, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>>edges, dir;
	vector<vector<int>>g(n+1);
	vector<int>in(n+1, 0);
	for (int i = 0; i<m; i++){
		int t, a, b; cin >> t >> a >> b;
		if (t) {
			g[a].emplace_back(b);
			in[b]++;
			dir.emplace_back(a, b);
		} else {
			edges.emplace_back(a, b);
		}
	}

	vector<int>vis(n+1, 0);
	bool cycle = 0;

	function<void(int)> dfs = [&](int v){
		vis[v] = 1;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			} else if (vis[x] == 1){
				cycle = 1;
			}
		}
		vis[v] = 2;
	};

	for (int i = 1; i<=n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	if (cycle){
		cout << "NO\n";
		return;
	} 
	queue<int>q;
	for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
	vector<int>topo, pos(n+1);
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.emplace_back(v);
		for (auto x: g[v]){
			in[x]--;
			if (in[x] == 0) q.push(x);
		}
	}
	//debug(topo);
	for (int i = 0; i<(int)topo.size(); i++) pos[topo[i]] = i;
	cout << "YES\n";
	for (auto &[a, b]:edges){
		if (pos[a] > pos[b]) swap(a, b);
		cout << a << " " << b << "\n";
	}
	for (auto [a, b]:dir) {
		cout << a << " " << b << "\n";
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