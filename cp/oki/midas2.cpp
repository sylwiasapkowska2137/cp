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

// #define int long long
// const int oo = 1e18, oo2 = 1e9+7, K = 30;
// const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<pair<int, int>>tab(4*n+1);
	vector<int>par(n+1);
	for (int i = 1; i<=n; i++){
		cin >> tab[i].first >> tab[i].second;
		if (tab[i].first) par[tab[i].first] = i;
		if (tab[i].second) par[tab[i].second] = i;
	}
	vector<int>shift;
	int r = 1;
	while (r){
		shift.emplace_back(r);
		r = tab[r].first;
	}
	// debug(shift);
	vector<vector<int>>tree(4*n+1);
	reverse(shift.begin(), shift.end());
	vector<int>vis(4*n+1);
	int cnt = n+1;
	function<void(int, int)>dfs = [&](int v, int odp){
		vis[v] = 1;
		tree[odp].emplace_back(v);
		if (tab[v].first && !vis[tab[v].first]){
			if (!tab[odp].first) tab[odp].first = cnt++;
			dfs(tab[v].first, tab[odp].first);
		}
		if (tab[v].second && !vis[tab[v].second]){
			if (!tab[odp].second) tab[odp].second = cnt++;
			dfs(tab[v].second, tab[odp].second);
		}
	};
	for (auto &root: shift) {
		dfs(root, 1);
		tab[par[root]].first = 0;
	}
	vector<int>pos2;
	for (int i = 1; i<(int)tree.size(); i++){
		if (tree[i].size()){
			// debug(i, tree[i], tab[i]);
			for (auto x: tree[i]){
				if ((int)pos2.size() <= x) pos2.resize(x+3);
				pos2[x] = i;
			}
		}
	}
	vector<int>pre, depth(4*n+1);
	function<void(int)>dfs2 = [&](int v){
		// debug(v, depth[v]);
		for (auto x: tree[v]) pre.emplace_back(x);
		if (tab[v].first) {
			depth[tab[v].first] = depth[v]+1;
			dfs2(tab[v].first);
		}
		if (tab[v].second) {
			depth[tab[v].second] = depth[v]+1;
			dfs2(tab[v].second);
		}
	};
	dfs2(1);
	// debug(pre);
	int mx = *max_element(pre.begin(), pre.end());
	vector<int>pos(mx+2);
	for (int i = 0; i<(int)pre.size(); i++) pos[pre[i]] = i;
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		if (depth[pos2[a]] > depth[pos2[b]]) cout << "TAK\n";
		else if (depth[pos2[a]] < depth[pos2[b]]) cout << "NIE\n";
		else {
			if (pos[a] >= pos[b] || pos2[a] == pos2[b]) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
