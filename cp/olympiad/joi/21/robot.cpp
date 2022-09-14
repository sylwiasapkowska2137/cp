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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct T{
	int b, c, p;
	T(int _b = 0, int _c = 0, int _p = 0){
		b = _b, c = _c, p = _p;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<map<int, vector<pair<int, int>>>>g(n+1);
	vector<map<int, int>>curr(n+1);
	vector<map
	for (int i = 0; i<m; i++){
		int a, b, c, p; cin >> a >> b >> c >> p;
		g[a][c].emplace_back(b, p);
		g[b][c].emplace_back(a, p);
		curr[a][c] += p;
		curr[b][c] += p;
	}
	// for (int i = 1; i<=n; i++){
	// 	debug(i, curr[i]);
	// }
	s.insert({0LL, 1, 0});
	set<tuple<int, int, int>>s;
	vector<int>dist(n+1, oo);
	dist[1] = 0;
	while (s.size()){
		auto [d, v, w] = s.begin();
		s.erase(s.begin());
		if (dist[v] < d) continue;
		if (w){
			if (dp2[v][w] > d) continue;
			for (auto [x, c, p]:g[v]){
				if (dist[x] + curr[])
			}
		}
		for (auto [x, c, p]:g[v]){
			int cost = oo;
			if (curr[v][c].first == 1){
				cost = 0;
			} else if (curr[v].size() < m){
				cost = p;
			} else {
				for (auto u: curr[v]){
					int b = u.second.second;
					if (u.first == c) continue;
					cost = min(cost, b);
				}
				cost += p;
			}
			// debug(v, x, cost, dist[v]);
			if (dist[x] > dist[v] + cost){
				dist[x] = dist[v] + cost;
				s.insert({dist[x], x});
			}
		}
	}
	cout << (dist[n] == oo? -1:dist[n]) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
