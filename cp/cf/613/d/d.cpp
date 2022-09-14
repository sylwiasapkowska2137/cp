//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
const int oo = 1e18, K = 20;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	
	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1), pre(n+1);
	int czas = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = ++czas;
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto x:g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	dfs(1, 1);

	auto lca = [&](int a, int b){
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[b]-(1<<i) >= depth[a]){
				b = up[b][i];
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


	int q; cin >> q;
	vector<int>to_clear;
	vector<int>big(n+1), disc(n+1);
	vector<vector<pair<int, int>>>G(n+1);
	while (q--){
		int k; cin >> k;
		vector<int>s(k);
		for (int i = 0; i<k; i++) {
			cin >> s[i];
			big[s[i]] = 1;
		}
		auto clear = [&](){
			for (auto v: to_clear){
				big[v] = 0;
				disc[v] = 0;
				G[v].clear();
			}
			to_clear.clear();
		};
		sort(s.begin(), s.end(), [&](auto x, auto y){return pre[x] < pre[y];});
		bool ok = 1;
		for (int i = 1; i<k; i++) {
			int l = lca(s[i-1], s[i]);
			s.emplace_back(l);
		}
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		sort(s.begin(), s.end(), [&](auto x, auto y){return pre[x] < pre[y];});
		to_clear = s;
		for (int i = 1; i<(int)s.size(); i++){
			int l = lca(s[i-1], s[i]);
			if (l != s[i]){
				G[s[i]].emplace_back(l, depth[s[i]]-depth[l]);
				G[l].emplace_back(s[i], depth[s[i]]-depth[l]);
				if (depth[s[i]]-depth[l] == 1 && big[s[i]] && big[l]) ok = 0;
				// debug(l, s[i], depth[s[i]]-depth[l]);
			}
		}
		if (!ok) {
			clear();
			cout << "-1\n";
			continue;
		}
		function<int(int, int)> DFS = [&](int v, int pa){
			int ans = 0, ile = 0;
			for (auto [x, c]:G[v]){
				if (x == pa) continue;
				ans += DFS(x, v);
				ile += disc[x];
			}
			if (big[v]) {
				disc[v] = 1;
				return ans+ile;
			}
			if (ile > 1) {
				disc[v] = 0;
				return ans+1;
			}
			disc[v] = ile;
			return ans;
		};

		int ret = DFS(s[0], s[0]);
		clear();
		cout << ret << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}