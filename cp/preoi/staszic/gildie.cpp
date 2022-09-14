//https://codeforces.com/problemset/problem/1470/D
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 3e5+7;
vector <int> graf[MAX];
vector <bool>vis, color;

void dfs(int v){
	int flag = 0;
	for (auto y:graf[v]) flag|=color[y];
	if (!flag) color[v]=1;
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x]) dfs(x);
}

void solve(){
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	vis.assign(n+1, 0);
	color.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (graf[i].size() == 0) {
			cout << "NIE\n";
			return;
		}
		if (!vis[i]) dfs(i);
	}
	cout << "TAK\n";
	for (int i = 1; i<=n; i++) {
		if (color[i]) cout << "K\n";
		else cout << "S\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

