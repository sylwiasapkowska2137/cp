//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC target("popcnt")
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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

vector<vector<int>>g, gt, G;
vector<bool>vis;
vector<int>numer, post;
int nr;

const int mx = 5e4+1;
bitset<mx>b[mx];

void dfs(int v){
	vis[v] = 1;
	for (auto x: g[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
	post.emplace_back(v);
}

void dfs2(int v){
	numer[v] = nr;
	vis[v] = 1;
	for (auto x: gt[v]){
		if (!vis[x]){
			dfs2(x);
		}
	}
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	g.resize(n+1);
	gt.resize(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		gt[b].emplace_back(a);
	}

	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			dfs(i);
		}
	}
	reverse(post.begin(), post.end());
	vis.assign(n+1, 0);
	numer.resize(n+1);
	for (auto v: post){
		if (!vis[v]){
			nr++;
			dfs2(v);
		}
	}
	G.resize(n+1);
	// debug(numer);
	// debug(nr);
	vector<int>in(n+1);
	for (int v = 1; v <= n; v++){
		for (auto x: g[v]){
			if (numer[v] != numer[x]){
				G[numer[v]].emplace_back(numer[x]);
				in[numer[x]]++;
			}
		}
	}
	queue<int>que;
	vector<int>topo;
	for (int i = 1; i<=nr; i++){
		if (!in[i]) que.push(i);
	}
	while (que.size()){
		int v = que.front();que.pop();
		topo.emplace_back(v);
		for (auto x: G[v]){
			in[x]--;
			if (!in[x]) que.push(x);
		}
	}
	// debug(topo);
	reverse(topo.begin(), topo.end());
	for (auto v: topo){
		b[v].set(v);
		for (auto x: G[v]){
			b[v] |= b[x]; 
		}
	}
	while (q--){
		int x, y; cin >> x >> y;
		if (numer[x] == numer[y]){
			cout << "TAK\n";
			continue;
		}
		if (b[numer[x]][numer[y]]) cout << "TAK\n";
		else cout << "NIE\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
