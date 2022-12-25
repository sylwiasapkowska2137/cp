#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int>rep;
	DSU(int n){ rep.resize(n+1);clear(n);}
	void clear(int n){iota(rep.begin(), rep.end(), 0);}
	int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}
	bool u(int a, int b){
		a = f(a);b = f(b);
		if (a == b) return 0;
		rep[b] = a;
		return 1;
	}
};

void read(int &number){
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-'){ negative = true;c = getchar();}
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

void solve(){
	int n, m; read(n); read(m);
	DSU dsu(n+1);
	vector<pair<int, int>>edges;
	vector<int>tree(m), par(n+1), depth(n+1);
	vector<vector<int>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b; read(a); read(b);
		edges.emplace_back(a, b);
		if (dsu.u(a, b)) {
			tree[i] = 1;
			g[a].emplace_back(b);
			g[b].emplace_back(a);	
		}
	}
	function<void(int, int)>dfs = [&](int v, int pa){
		par[v] = pa;
		for (auto x: g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};
	for (int i = 1; i<=n; i++) if (!par[i]) dfs(i, i);
	dsu.clear(n);
	int ans = 0;
	for (int i = 0; i<m; i++){
		if (tree[i]){
			cout << ans << "\n";
			continue;
		}
		int a = edges[i].first;
		int b = edges[i].second;
		ans++;
		a = dsu.f(a); b = dsu.f(b);
		while (a != b){
			if (depth[a] > depth[b]) swap(a, b);
			ans += dsu.u(b, par[b]);
			b = par[b];
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
