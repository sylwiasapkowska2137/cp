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
typedef pair<int, int> T;

vector<int>sub, vis, fix, clear, depth, par;
vector<vector<int>>g;
vector<T>t, curr;

struct F{
	int mx = -oo, mx2 = -oo, sz = -1, sz2 = -2;
};

struct TreeMax{
	vector<F>tab;
	int size = 1;

	void init(int n){
		while (size < n) size*=2;
		tab.resize(2*size+1);
	}

	void merge(int x, int v, int sz){
		if (tab[x].sz == sz){
			if (v >= tab[x].mx2){
				tab[x].mx2 = v;
				tab[sz].sz2 = sz;
			}
		} else {
			if (v >= tab[x].mx){
				tab[x].mx2 = tab[x].mx;
				tab[x].sz2 = tab[x].sz;
				tab[x].mx = v;
				tab[x].sz = sz;
			}
		}
	}

	F f(F a, F b){
		vector<T>tab;
		for (int rep = 0; rep < 2; rep++){
			tab.emplace_back(a.mx, a.sz);
			tab.emplace_back(a.mx2, a.sz2);
			swap(a, b);
		}
		sort(tab.begin(), tab.end());
		F ret;
		ret.mx = tab.back().first;
		ret.sz = tab.back().second;
		for (int i = (int)tab.size()-2; i>=0; i--){
			if (ret.sz != tab[i].second){
				ret.mx2 = tab[i].first;
				ret.sz2 = tab[i].second;
				return ret;
			}
		}
		assert(false);
	}

	void update(int l, int r, int len, int sz){
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) merge(l+1, len, sz);
			if (r&1) merge(r-1, len, sz);
		}
	}

	int query(int x){
		x += size;
		F ans = tab[x];
		while (x){
			x/=2;
			ans = f(ans, tab[x]);
		}
		return max(ans.mx, ans.mx + ans.mx2);
	}
} tree;

int dfs(int v, int pa){
	sub[v] = 1;
	for (auto x: g[v]){
		if (x == pa || vis[x]) continue;
		sub[v] += dfs(x, v);
	}
	return sub[v];
}

int get(int v, int pa, int ms){
	for (auto x: g[v]){
		if (x == pa || vis[x]) continue;
		if (2*sub[x] > ms) return get(x, v, ms);
	}
	return v;
}

void DFS(int v, int pa, int which){
	fix.emplace_back(v);
	par[v] = which;
	curr[v] = curr[pa];
	curr[v].first = max(curr[v].first, t[v].first);
	curr[v].first = min(curr[v].second, t[v].second);
	for (auto x: g[v]){
		if (x == pa || vis[x]) continue;
		depth[x] = depth[v]+1;
		DFS(x, v, which);
	}
}

void centroid(int v){
	v = get(v, v, dfs(v, v));
	// debug(v);
	fix.emplace_back(v);
	curr[v] = t[v];
	par[v] = v;
	for (auto x: g[v]){
		if (vis[x]) continue;
		DFS(x, v, x);
	}
	for (auto u: fix){
		tree.update(curr[u].first, curr[u].second, depth[u], par[u]);
		curr[u] = {-oo, oo};
		depth[u] = 0;
		par[u] = 0;
	}
	fix.clear();

	vis[v] = 1;
	for (auto x: g[v]){
		if (vis[x]) continue;
		centroid(x);
	}
}


void solve(){
	int n, q; cin >> n >> q;
	t.resize(n+1);
	vector<int>s;
	for (int i = 1; i<=n; i++) cin >> t[i].first;
	for (int i = 1; i<=n; i++) cin >> t[i].second;
	for (int i = 1; i<=n; i++){
		s.emplace_back(t[i].first);		
		s.emplace_back(t[i].second);	
	}
	g.resize(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>Q(q);
	for (int i = 0; i<q; i++){
		cin >> Q[i];
		s.emplace_back(Q[i]);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	auto get = [&](int x){return (int)(lower_bound(s.begin(), s.end(), x)-s.begin());};
	for (int i = 1; i<=n; i++) t[i] = make_pair(get(t[i].first), get(t[i].second));
	for (int i = 0; i<q; i++) Q[i] = get(Q[i]);
	sub.assign(n+1, 0);
	vis.assign(n+1, 0);
	par.assign(n+1, 0);
	depth.assign(n+1, 0);
	curr.assign(n+1, {-oo, oo});
	tree.init(3*n+12);
	centroid(1);
	for (auto v: Q) {
		int x = tree.query(v);
		if (x < 0) cout << "0\n";
		else cout << x << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
