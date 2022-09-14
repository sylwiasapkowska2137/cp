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
const int oo = 1e18, oo2 = 1e9+7, K = 20;
const int mod = 998244353;

typedef pair<int, int> T;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>depth(n+1);

	function<void(int,int)>dfs = [&](int v, int pa){
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v] + 1;
			dfs(x, v);
		}
	};

	dfs(1, 1);
	// debug(depth);
	T d = {-oo, -oo};
	for (int i = 1; i<=n; i++) d = max(d, {depth[i], i});
	depth[d.second] = 0;
	dfs(d.second, d.second);
	T e = {-oo, -oo};
	for (int i = 1; i<=n; i++) e = max(e, {depth[i], i});
	int L = d.second, R = e.second;
	vector<vector<T>>que(n+1);
	int q; cin >> q;
	for (int i = 0; i<q; i++){
		int v, k; cin >> v >> k;
		que[v].emplace_back(k, i);
	}
	// debug(L, R);
	vector<int>curr, ans(q, -1);
	function<void(int, int)>DFS = [&](int v, int pa){
		curr.emplace_back(v);
		int s = (int)curr.size();
		for (auto [k, idx]:que[v]){
			if (s - 1 - k >= 0){
				ans[idx] = curr[s-k-1];
			}
		}
		for (auto x: g[v]){
			if (x == pa) continue;
			DFS(x, v);
		}
		curr.pop_back();
	};
	DFS(L, L);
	DFS(R, R);
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
