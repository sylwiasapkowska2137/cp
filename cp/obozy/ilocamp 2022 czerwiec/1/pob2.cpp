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

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n+1);
	
	int s = 1, k = 1;
	while (s <= n){
		s*=2;
		k++;
	}
	debug(k);
	vector<vector<int>>graf((n+1)*k+1);
	vector<vector<int>>up(n+1, vector<int>(k+1, 0));
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		a--;b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		graf[a].emplace_back(b);
		graf[b].emplace_back(a);
	}
	vector<int>depth(n+1);
	int cnt = n+1;
	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<k; i++) up[v][i] = up[up[v][i-1]][i-1]; 
		for (int i = 1; i<k; i++){
			graf[i*n+v].emplace_back((i-1)*n+v);
			graf[i*n+v].emplace_back(up[v][i-1]+(i-1)*n);
		}
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;		
			dfs(x, v);
		}
	};

	dfs(0, 0);
	for (int i = 0; i<=n*k; i++){
		for (auto x: graf[i]){
			cerr << i << " " << x << "\n";
		}
	}

	function<int(int, int)>lca = [&](int a, int b){
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = k-1; i>=0; i--){
			if (depth[b]-(1<<i) >= depth[a]){
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
	};

	function<void(int, int, int)>add = [&](int a, int l, bool rev){
		for (int i = k-1; i>=0; i--){
			
		}
	};

	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		int l = lca(a, b);
		if (l == a){

		} else if (l == b){
			
		} else {
			
		}
		
		graf[b].emplace_back(a);
	}
	vector<int>vis((n+1)*k);
	bool cycle = 0;

	function<void(int)>dfs2 = [&](int v){
		vis[v] = 1;
		for (auto x: graf[v]){
			if (!vis[x]){
				dfs2(x);
			} else if (vis[x] == 1){
				cycle = 1;
			}
		}
		vis[v] = 2;
	};

	for (int i = 0; i<n*k; i++){
		if (!vis[i]){
			dfs2(i);
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
