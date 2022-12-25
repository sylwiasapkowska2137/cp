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

void solve(){
	int n; cin >> n;
	vector<pair<int, int>>tab(n+1);
	int ok = 0;
	for (int i = 1; i<=n; i++) {
		cin >> tab[i].first >> tab[i].second;
		ok |= tab[i].second;
	}
	if (!ok){
		int q; cin >> q;
		while (q--){
			int a, b; cin >> a >> b;
			cout << "TAK\n";
		}
		return;
	}
	
	
	vector<vector<int>>tree(8*n+2);
	vector<int>depth(8*n);
	int cnt = n+1;
	function<void(int, int)>dfs = [&](int v, int odp){
		if (tab[v].first){
			if (tab[odp].first == 0) tab[odp].first = cnt++;
			tree[tab[odp].first].emplace_back(tab[v].first);
			dfs(tab[v].first, tab[odp].first);
		}
		if (tab[v].second){
			if (tab[odp].second == 0) tab[odp].second = cnt++;
			tree[tab[odp].second].emplace_back(tab[v].second);
			dfs(tab[v].second, tab[odp].second);
		}
	};
	int st = 1;
	if (!tab[st].second){
		tree[1].emplace_back(st);
		st = tab[st].first;
	}
	tree[st] = tree[1];
	tree[1].clear();
	int root = st; //korzen
	while (root){
		if (tree.size() <= root) {
			tree.resize(root+3);
			tab.resize(root+3);
		}
		tree[st].emplace_back(root);
		int u = tab[root].second;
		if (u){
			tree[tab[st].second].emplace_back(u);
			dfs(u, tab[st].second);
		} 
		root = tab[root].first;
	}
	vector<int>pos2;
	for (int i = 1; i<(int)tree.size(); i++){
		if (tree[i].size()){
			debug(i, tree[i]);
			for (auto x: tree[i]){
				if (pos2.size() <= x) pos2.resize(x+3);
				pos2[x] = i;
			}
		}
	}
	vector<int>pre;
	function<void(int)>dfs2 = [&](int v){
		for (auto x: tree[v]) {
			pre.emplace_back(x);
			depth[x] = depth[v];
		}
		if (tab[v].first) {
			depth[tab[v].first] = depth[v] + 1;
			dfs2(tab[v].first);
		}
		if (tab[v].second) {
			depth[tab[v].second] = depth[v] + 1;
			dfs2(tab[v].second);
		}
	};
	for (auto x: tree[1]) pre.emplace_back(x);
	dfs2(1);
	debug(pre);
	int mx = *max_element(pre.begin(), pre.end());
	vector<int>pos(mx+2);
	for (int i = 1; i<=n; i++) pos[pre[i]] = i;
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		if (depth[a] < depth[b]) cout << "NIE\n";
		else if (depth[a] > depth[b]) cout << "TAK\n";
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
