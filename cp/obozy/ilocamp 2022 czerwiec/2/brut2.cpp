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
 
const int oo = ((1<<30)-1), K = 30;
vector<vector<int>>G;
vector<vector<pair<int, int>>>g;
vector<bool>vis;
vector<int> scaler;
vector<tuple<int, int, int>>edges; 
int n;

void dfs(int v){
	vis[v] = 1;
	for (auto x: G[v]) if (!vis[x]) dfs(x);
}
 
void dijkstra(int src, int X){
	vector<int>dist(n+1, oo);
	dist[src] = 0;
	set<pair<int, int>>s;
	s.insert({0LL, src});
	while (s.size()){
		int v = s.begin()->second;
		int d = s.begin()->first;
		s.erase(s.begin());
		if (dist[v] < d) continue;
		for (auto [x, c]: g[v]){
			if ((d|c) < dist[x]){
				dist[x] = (d|c);
				s.insert({dist[x], x});
			}
		}
	}
	for (int i = 0; i<(int)scaler.size(); i++){
		edges.emplace_back(i+1, X, dist[scaler[i]]);
	}
}

void solve(){
	int m; cin >> n >> m;
	for (int i = 1; i<=n; i++){
		int x; cin >> x;
		if (x) scaler.emplace_back(i);
	}
	g.resize(n+1);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
		edges.emplace_back(a, b, c);
	}
	int S = (int)scaler.size();
	if (S == 2){
		G.resize(n+1);
		int mask = (1<<K)-1;
		for (int i = K-1; i>=0; i--){
			mask ^= (1<<i);
			for (int i = 1; i<=n; i++) G[i].clear();
			for (auto [a, b, c]:edges){
				if ((mask&c) == c){
					G[a].emplace_back(b);
					G[b].emplace_back(a);
				}
			}
			vis.assign(n+1, 0);
			dfs(1);
			if (!vis[n]) mask ^= (1<<i);
		}
		cout << mask << "\n";
		return;
	}

	edges.clear();

	for (int i = 0; i<(int)scaler.size(); i++){
		dijkstra(scaler[i], i+1);
	}
	sort(edges.begin(), edges.end(), [&](auto a, auto b){return get<2>(a) < get<2>(b);});
	// for (auto [a, b, c]:edges){
	// 	debug(a, b, c);
	// }
	int L = 0, R = (1<<K)-1;
	int ans = oo;
	G.resize(S+1);
	while (R>=L){
		int mid = (L+R)/2;
		for (int i = 0; i<=S; i++) G[i].clear();
		for (auto [a, b, c]:edges){
			if (c <= mid){
				G[a].emplace_back(b);
			} else break;
		}
		vis.assign(S+1, 0);
		dfs(1);

		if (vis[S]){
			ans = mid;
			R = mid-1;
		} else L = mid+1;
	}
	cout << ans << "\n";
}
 
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}