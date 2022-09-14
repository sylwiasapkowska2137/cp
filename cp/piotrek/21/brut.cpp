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
const int oo = 1e18, K = 20;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector up(n+1, vector<int>(K));
	vector<int>depth(n+1);

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	dfs(1, 1);

	vector<int>ans(n+1);

	auto lca = [&](int a, int b){
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[b] - (1<<i) >= depth[a]){
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

	auto d = [&](int a, int b){
		return depth[a]+depth[b]-2*depth[lca(a, b)];
	};

	vector<vector<vector<int>>>ret(n+1);
	for (int mask = 1; mask<(1<<n); mask++){
		int b = __builtin_popcountll(mask);

		vector<int>curr;
		for (int v = 1; v<=n; v++){
			if (mask&(1<<(v-1))){
				curr.emplace_back(v);
			}
		}
		int mn = oo, ile = 1;
		for (int v = 1; v<=n; v++){
			int tmp = 0;
			for (auto x: curr){
				tmp += d(x, v);
			}
			if (tmp < mn){
				mn = tmp;
				ile = 1;
			} else if (tmp == mn) ile++;
		}
		if (ans[b] < ile){
			ans[b] = ile;
			ret[b].clear();
			ret[b].emplace_back(curr);
		} else if (ans[b] == ile){
			ret[b].emplace_back(curr);
		}
	}
	// for (int i = 2; i<=n; i+=2){
	// 	debug(i, ans[i], ret[i]);
	// }	
	for (int i = 1; i<=n; i++){
		cout << ans[i] << "\n";
	}
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
