#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 4e5+7;
vector<int>graf[MAX], vis;
vector<bool>grupa[2]; //s[0] - gray, grupa A, s[1] - black, grupa B
vector<bool>aa, bb;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
		else grupa[vis[x]-1][x] = 1;
	}
	vis[v] = 2;
}

void dfs2(int v, vector<bool>&odw){
	odw[v] = 1;
	for (auto x: graf[v]){
		if (!odw[x]) dfs2(x, odw);
	}
}

void solve(){
	string s;
	getline(cin, s);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i<=n; i++) graf[i].clear();
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
	}
	vis.assign(n+1, 0);
	for (int i = 0; i<2; i++) grupa[i].assign(n+1, 0);
	dfs(1);
	aa.assign(n+1, 0);
	bb.assign(n+1, 0);
	for (int i = 1; i<=n; i++) if (grupa[0][i]) dfs2(i, aa);
	for (int i = 1; i<=n; i++) if (grupa[1][i]) dfs2(i, bb);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) cout << "0 ";
		else {
			int ans = 1;
			if (aa[i]) ans = -1;
			else if (bb[i]) ans = 2;
			cout << ans << " ";
		}
	}
	cout << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
		
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
