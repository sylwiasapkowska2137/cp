//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int oo = 1e18, K = 30;

vector<int>rep, sz;
stack<int>ss;

int Find(int a){
	if (a == rep[a]) return a;
	return Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (sz[a] < sz[b]) swap(a, b);
	rep[b] = a;
	sz[a] += sz[b];
	ss.push(b);
	return 1;
}

void undo(int t){
	while ((int)ss.size() > t){
		int u = ss.top(); ss.pop();
		sz[rep[u]] -= sz[u];
		rep[u] = u;
	}
}

struct segtree{
	vector<vector<pair<int, int>>>tab;
	vector<int>query;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
		query.assign(2*size, -1);
	}

	void add_update(int x, int lx, int rx, int l, int r, pair<int, int>edge){
		if (rx < l || lx > r) return;
		if (lx >= l && rx <= r){
			tab[x].emplace_back(edge);
			return;
		}
		int m = (lx+rx)/2;
		add_update(2*x, lx, m, l, r, edge);
		add_update(2*x+1, m+1, rx, l, r, edge);
	}

	void add_query(int x, int lx, int rx, int pos, int v){
		if (lx == rx){
			query[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) add_query(2*x, lx, m, pos, v);
		else add_query(2*x+1, m+1, rx, pos, v);
	}

	void dfs(int v){
		int t = (int)ss.size();
		for (auto [a, b]:tab[v]) Union(a, b);
		if (v >= size){
			if (query[v] != -1){
				cout << sz[Find(query[v])] << "\n";
			}
		} else {
			dfs(2*v);
			dfs(2*v+1);
		}
		undo(t);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<vector<int>>g(n+1);
	vector<int>par(n+1);
	segtree seg(q+2);
	set<pair<int, int>>s;
	sz.assign(n+1, 1);
	rep.resize(n+1);
	iota(rep.begin(), rep.end(), 0);
	map<pair<int, int>, vector<pair<int, int>>>life;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		if (a > b) swap(a, b);
		life[{a, b}].emplace_back(1, seg.size-1);
		s.insert({a, b});
	}
	function<void(int, int)>dfs = [&](int v, int pa){
		par[v] = pa;
		for (auto x: g[v]){
			if (x == pa) continue;
			dfs(x, v);
		}
	};

	dfs(1, 1);
	for (int i = 2; i<q+2; i++){
		int t; cin >> t;
		if (t == 1){
			int b; cin >> b;
			int a = par[b];
			if (a > b) swap(a, b);
			if (s.find({a, b}) == s.end()){ //byla usunieta
				life[{a, b}].emplace_back(i, seg.size-1);
				s.insert({a, b});
			} else {
				life[{a, b}].back().second = i-1;
				s.erase({a, b});
			}
		} else {
			int v; cin >> v;
			seg.add_query(1, 0, seg.size-1, i, v);
		}
	}
	for (auto x: life){
		for (auto v: x.second){
			seg.add_update(1, 0, seg.size-1, v.first, v.second, x.first);
		}
	}
	seg.dfs(1);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
