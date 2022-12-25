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
	int a, b, c; 
	T(){}
	T(int _a, int _b, int _c){
		a = _a, b = _b, c = _c;
	}
};

struct Tree{
	vector<int>tab;
	int size = 1;

	Tree(int n, vector<int>&ord, vector<int>&val){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		for (int i = 0; i<(int)ord.size(); i++){
			if (ord[i] > 0) tab[i+size] = val[ord[i]];
			else tab[i+size] = -val[-ord[i]];
		}
		for (int i = size-1; i>=1; i--){
			tab[i] = tab[2*i] + tab[2*i+1];
		}
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
		}
		return ans;
	}
};

void solve(){
	int n, q, w; cin >> n >> q >> w;
	vector<T>edges;
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
		edges.emplace_back(a, b, c);
	}
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1), val(n+1), pre(n+1, -1), ord;
	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		ord.emplace_back(v);
		if (pre[v] == -1) pre[v] = ord.size()-1;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			val[x] = c;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
		ord.emplace_back(-v);
	};
	function<void(int, int)>depth_dfs = [&](int v, int pa){
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			depth_dfs(x, v);
		}
	};

	dfs(1, 1);
	pair<int, int>curr = {-oo, -oo};
	for (int i = 1; i<=n; i++) curr = max(curr, {depth[i], i});
	int L = curr.second;
	depth.assign(n+1, 0);
	depth_dfs(L, L);
	curr = {-oo, -oo};
	for (int i = 1; i<=n; i++) curr = max(curr, {depth[i], i});
	int R = curr.second;
	depth.assign(n+1, 0);
	depth_dfs(1, 1);

	auto lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a] - (1<<i) >= depth[b]){
				a = up[a][i];
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
	Tree t(2*n+2, ord, val);
	debug(ord);
	debug(pre);
	debug(t.tab);
	int last = 0;
	while (q--){
		int d, e; cin >> d >> e;
		d = (d+last)%(n-1);
		e = (e+last)%w;
		auto [a, b, c] = edges[d];
		edges[d].c = e;
		if (depth[a] > depth[b]) swap(a, b);
		t.update(pre[b], e);
		t.update(post[b], -e);

		int d = find(L, )
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
