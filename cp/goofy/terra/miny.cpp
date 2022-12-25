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

const int oo = 1e9+7;

struct T{
	int p, r, c; 
	T(){}
	T(int _p, int _r, int _c){p = _p, r = _r, c = _c;}
	void read(){cin >> p >> r >> c;}
};

vector<int>s;
vector<vector<int>>g, gt;
vector<int>post, vis, numer, in, what;

struct Tree{
	int size = 1;

	void add(int a, int b){
		g[a].emplace_back(b);
		gt[b].emplace_back(a);
	}

	Tree(int n){
		while (size < n) size*=2;
		g.resize(2*size);
		gt.resize(2*size);
		what.assign(2*size, 1);
		in.assign(2*size, 0);
		numer.assign(2*size, 0);
		vis.assign(2*size, 0);
		for (int i = 1; i<size; i++){
			add(i, 2*i);
			add(i, 2*i+1);
		}
	}

	void update(int x, int lx, int rx, int l, int r, int nr){
		if (s[lx] > r || s[rx] < l) return;
		if (s[lx] >= l && s[rx] <= r){
			add(nr+size, x);
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, nr);
		update(2*x+1, m+1, rx, l, r, nr);
	}

	void d(){
		for (int i = 1; i<(int)g.size(); i++){
			// debug(i, g[i]);
			for (auto x: g[i]){
				cerr << i << " " << x << "\n";
			}
		}
	}

	void dfs(int v){
		vis[v] = 1;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
		post.emplace_back(v);
	}

	void dfs2(int v, int nr){
		vis[v] = 1;
		numer[v] = nr;
		for (auto x: gt[v]){
			if (!vis[x]){
				dfs2(x, nr);
			}
		}
	}

	void scc(){
		for (int i = 1; i<(int)g.size(); i++){
			if (!vis[i]){
				dfs(i);
			}
		}
		reverse(post.begin(), post.end());
		vis.assign(2*size, 0);
		int cnt = 0;
		for (auto x: post){
			if (!vis[x]){
				cnt++;
				dfs2(x, cnt);
			}
		}
		// debug(numer);
	}

	void scc_cd(){
		for (int v = 1; v < (int)g.size(); v++){
			for (auto x: g[v]){
				if (numer[x] != numer[v] && !what[numer[v]]){
					in[numer[x]]++;
				}
			}
		}
		for (int v = 1; v < (int)g.size(); v++){
			for (auto x: g[v]){
				if (numer[x] != numer[v] && what[numer[v]] && in[numer[v]]){
					in[numer[x]]++;
				}
			}
		}
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<T>a(n);
	for (int i = 0; i<n; i++){
		a[i].read();
		s.emplace_back(a[i].p);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	auto get = [&](int x){return lower_bound(s.begin(), s.end(), x)-s.begin();};
	Tree t(n);
	while ((int)s.size() < (int)t.size) s.emplace_back(oo);
	for (auto [p, r, c]: a) t.update(1, 0, t.size-1, p-r, p+r, get(p));
	// t.d();
	t.scc();
	for (int i = 0; i<n; i++) what[numer[i+t.size]] = 0;
	t.scc_cd();
	vector<multiset<int>>costs(2*t.size);
	for (int i = 0; i<n; i++) costs[numer[i+t.size]].insert(a[i].c);
	long long ans = 0;
	for (int i = 1; i<(int)costs.size(); i++){
		if (!in[i] && !what[i] && costs[i].size()){
			ans += (long long)*costs[i].begin();
		}
	}
	while (q--){
		int i, x; cin >> i >> x;
		--i;
		int curr = numer[i+t.size];
		if (!in[curr]){
			ans -= (long long)*costs[curr].begin();
			costs[curr].erase(costs[curr].find(a[i].c));
			a[i].c = x;
			costs[curr].insert(x);
			ans += (long long)*costs[curr].begin();
		}
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
