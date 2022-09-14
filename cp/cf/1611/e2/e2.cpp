//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
const int oo = 1e18, K = 20;

void solve(){
	string s; getline(cin, s);
	int n, k; cin >> n >> k;
	vector<int>x(k);
	vector<int>bad(n+1);
	for (int i = 0; i<k; i++) {
		cin >> x[i];
		bad[x[i]] = 1;
	}
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1);
	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++){
			up[v][i] = up[up[v][i-1]][i-1];
		} 
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};
	dfs(1, 1);
	auto jump = [&](int v, int ile){
		for (int i = K-1; i>=0; i--){
			if (ile&(1<<i)){
				v = up[v][i];
			}
		}
		return v;
	};

	vector<int>used(n+1);
	for (auto v: x){
		used[jump(v, depth[v]/2)] = 1;
	}
	bool ok = 0;
	int ans = 0;

	function<void(int, int)>DFS = [&](int v, int pa){
		if (v != 1 && (int)g[v].size() == 1){
			ok = 1;
		}
		for (auto x: g[v]){
			if (used[x]) ans++;
			if (x == pa || used[x]) continue;
			DFS(x, v);
		}
	};
	DFS(1, 1);

	if (ok) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1; cin >> t;

	while (t--) solve();
	
	return 0;
}