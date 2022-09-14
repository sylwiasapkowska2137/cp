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
	vector<vector<pair<int, int>>>g(n+1);
	vector<tuple<int, int, int>>edges;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
		edges.emplace_back(a, b, c);
	}
	
	int c1 = 0, c2 = 0;
	
	function<void()>dijkstra = [&](){
		set<pair<pair<int, int>, int>>s;
		vector<int>dist(n+1, oo);
		vector<int>last(n+1);
		dist[1] = 0;
		s.insert({{0, 0},1});
		while (s.size()){
			int d = s.begin()->first.first;
			int v = s.begin()->second;
			s.erase(s.begin());
			if (dist[v] < d) continue;
			for (auto [x, c]:g[v]){
				if (d+c < dist[x]){
					dist[x] = d+c;
					last[x] = c;
					s.insert({{dist[x], c}, x});
				}
			}
		}
		//debug(last);

		for (int i = 2; i<=n; i++) c1 += last[i];
	};

	dijkstra();
	sort(edges.begin(), edges.end(), [&](auto a, auto b){return get<2>(a) < get<2>(b);});
	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	
	function<int(int)>Find = [&](int a){
		if (a == rep[a]) return a;
		return rep[a] = Find(rep[a]);
	};

	function<bool(int, int)>Union = [&](int a, int b){
		a = Find(a);
		b = Find(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
		return 1;
	};

	for (auto [a, b, c]:edges){
		if (Union(a, b)){
			//debug(a, b);
			c2+=c;
		}
	}
	//debug(c1, c2);
	if (c1 == c2){
		cout << "TAK\n";
	} else {
		cout << "NIE\n";
	}

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
