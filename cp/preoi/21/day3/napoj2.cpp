#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+7;
vector<int> graf[MAX], G[MAX];
bitset<MAX> vis, c;
bool ok;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
}

void dfs2(int v){
	vis[v] = 1;
	c[v] = 1;
	for (auto x: G[v]){
		if (!vis[x]) dfs2(x);
		else if (c[x]) ok = 0;
	}
	c[v] = 0;
}

void solve(){
	int n, m, m2; cin >> n >> m >> m2;
	vector<pair<int, int>> edges;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
	}
	set<int>good;
	for (int i = 0; i<m2; i++){
		int a, b; cin >> a >> b;
		edges.emplace_back(a, b);
		good.insert(a), good.insert(b);
	}
	for (auto x: good){
		vis.reset();
		dfs(x);
		for (int i = 1; i<=n; i++){
			if (good.find(i) != good.end() && vis[i] && i!=x){
				G[x].push_back(i);
			}
		}
	}
	int ans = 0;
	c.reset();
	for (int mask = 0; mask<(1<<m2); mask++){
		for (int i = 0; i<m2; i++){
			if (mask&(1<<i)){
				G[edges[i].first].push_back(edges[i].second);
			}
		}
		vis.reset();
		ok = 1;
		for (auto x: good) if (!vis[x] && ok) dfs2(x);
		if (ok) ans = max(ans, __builtin_popcount(mask));
		for (int i = 0; i<m2; i++){
			if (mask&(1<<i)){
				G[edges[i].first].pop_back();
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
