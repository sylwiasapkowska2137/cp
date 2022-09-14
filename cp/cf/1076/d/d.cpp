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

struct edge{
	int to, w, i;
	edge (int _to = 0, int _w = 0, int _i = 0){
		to = _to, w = _w, i = _i;
	}
};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vector<edge>>g(n+1);
	
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c, i);
		g[b].emplace_back(a, c, i);
	}	
	set<pair<int, int>>s;
	vector<int>d(n+1, oo);
	d[1] = 0;
	s.insert({0, 1});
	vector<pair<int, int>>par(n+1, {-1, -1});
	while (s.size()){
		int dist = s.begin()->first;
		int v = s.begin()->second;
		s.erase(s.begin());
		if (d[v] < dist) continue;
		for (auto [x, c, i]:g[v]){
			if (dist + c < d[x]){
				d[x] = dist+c;
				par[x] = {v, i};
				s.insert({d[x], x});
			}
		}
	}
	// debug(d);
	// debug(par);
	vector<int>good(m);
	vector<vector<pair<int, int>>>G(n+1);
	for (int i = 1; i<=n; i++){
		if (par[i].first == -1) continue;
		G[i].emplace_back(par[i]);
		G[par[i].first].emplace_back(i, par[i].second);
		good[par[i].second] = 1;
		// debug(i, par[i].first);
	}
	if (k >= n-1){
		cout << n-1 << "\n";
		for (int i = 0; i<m; i++){
			if (good[i]) cout << i+1 << " ";
		}
		cout << "\n";
		return;
	}
	vector<int>deg(n+1);
	queue<int>q;
	for (int i = 1; i<=n; i++) {
		deg[i] = (int)G[i].size();
		if (deg[i] == 1) q.push(i);
	}
	int edges = n-1;
	while (edges > k){
		int v = q.front(); q.pop();
		if (v == 1) continue;
		for (auto [x, i]: G[v]){
			deg[x]--;
			// debug(v, x);
			edges--;
			good[i] = 0;
			if (deg[x] == 1) q.push(x);
		}
	}
	// debug(good);
	cout << k << "\n";
	for (int i = 0; i<m; i++){
		if (good[i]) cout << i+1 << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}