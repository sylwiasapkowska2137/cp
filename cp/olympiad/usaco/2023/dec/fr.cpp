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

struct dsu{
	vector<int>rep, sz;
	int cnt = 1;

	dsu(int n){
		rep.assign(n+1, 0);
		sz.assign(n+1, 1);
		iota(rep.begin(), rep.end(), 0);
	}

	int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}

	void u(int a, int b){
		a = f(a);b = f(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
		cnt = max(cnt, sz[a]);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<set<int>>g(n+1);
	vector<vector<int>>G(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace(b);
		g[b].emplace(a);
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	vector<int>curr;
	vector<int>vis(n+1);
	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		curr.emplace_back(v);
		for (auto x: G[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
	};
	int ans = 0;
	dsu D(n+1);
	vector<int>active(n+1);
	auto count = [&](){
		D.cnt = 0;
		// debug(curr);
		int cnt = (int)curr.size();
		set<pair<int, int>>s;
		for (auto i: curr) s.insert({g[i].size(), i});
		ans = max(ans, cnt*s.begin()->first);
		vector<pair<int, int>>ord;
		while (s.size()){
			auto [sz, v] = *s.begin();
			s.erase(s.begin());
			//delete v
			ord.emplace_back(v, sz);
			cnt--;
			for (auto x: g[v]){
				s.erase({g[x].size(), x});
				g[x].erase(g[x].find(v));
				s.insert({g[x].size(), x});
			}
			g[v].clear();
		}
		reverse(ord.begin(), ord.end());
		// debug(ord);
		for (auto [v, deg]: ord){
			active[v] = 1;
			for (auto x: G[v]){
				if (active[x]){
					D.u(v, x);
				}
			}
			ans = max(ans, D.cnt*deg);
		}
	};
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			curr.clear();
			dfs(i);
			count();
		}
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