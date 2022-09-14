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
vector<pair<int, int>>edges;
vector<int>A, vis, post;
bool cycle;
vector<vector<int>>g;
int n, k;

void dfs(int v){
	vis[v] = 1;
	for (auto x:g[v]){
		if (!vis[x]){
			dfs(x);
		} else if (vis[x] == 1){
			cycle = 1;
			return;
		}
	}
	vis[v] = 2;
	post.emplace_back(v);
}

bool check(int mid){
	for (int i = 1; i<=n; i++) g[i].clear();
	post.clear();
	vector<int>in(n+1);
	for (auto [a, b]:edges){
		if (A[a] <= mid && A[b] <= mid){
			g[a].emplace_back(b);
			in[b]++;
		}
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			cycle = 0;
			dfs(i);
			if (cycle) return 1;
		}
	}
	queue<int>q;
	for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
	vector<int>topo;
	while (!q.empty()){
		int v = q.front(); q.pop();
		topo.emplace_back(v);
		for (auto x: g[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	vector<int>dp(n+1, 0);
	reverse(topo.begin(), topo.end());
	for (auto v: topo){
		for (auto x: g[v]){
			dp[v] = max(dp[v], dp[x]);
		}
		dp[v]++;
	}
	int p = 0;
	for (int i = 1; i<=n; i++){
		if (A[i] <= mid){
			p = max(p, dp[i]);
		}
	}
	if (p < k) return 0;
	return 1;
}

void solve(){
	int m; cin >> n >> m >> k;
	A.resize(n+1);
	for (int i = 1; i<=n; i++) cin >> A[i];
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
	}
	
	g.resize(n+1);
	const int MAX = 1e9+7;
	int ans = MAX;
	int L = 1, R = MAX;
	while (R>=L){
		int m = (L+R)/2;
		if (check(m)){
			ans = m;
			R = m-1;
		} else L = m+1;
	}
	if (ans == MAX) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}