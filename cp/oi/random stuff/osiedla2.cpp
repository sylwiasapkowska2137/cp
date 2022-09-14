#include <bits/stdc++.h>
using namespace std;

#define LL long long //nadac odpowiedni kierunek krawedziom
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back

const int MAX = 1e6+7;
vector <pii> graf[MAX], edges;
vector <int> low, preorder;
vector <bool> vis, ans, drzewo;
int czas, bridges, curr;

void dfs(int v, int val = -1){
	vis[v] = 1;
	preorder[v] = low[v] = czas++;
	for (auto x: graf[v]){
		if (x.nd == val) continue;
		if (vis[x.st]) low[v] = min(low[v], preorder[x.st]);
		else{
			dfs(x.st, x.nd);
			low[v] = min(low[v], low[x.st]);
			if (low[x.st] == preorder[x.st]) {
				curr++;
			}
		}
	}
}

void dfs2(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x.st]) {
			//cerr << x.nd << " " <<  v << " --> " << x.st << "\n";
			if (edges[x.nd].st == v) ans[x.nd] = 1;
			drzewo[x.nd] = 1;
			dfs2(x.st);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	edges.resize(m+1);
	for (int i = 0; i<m; i++){
		cin >> edges[i].st >> edges[i].nd;
		graf[edges[i].st].pb({edges[i].nd, i});
		graf[edges[i].nd].pb({edges[i].st, i});
	}
	ans.assign(m+1, 0);
	drzewo.assign(m+1, 0);
	low.assign(n+1, 0);
	preorder.assign(n+1, 0);
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		curr = 0;
		if (!vis[i]){
			dfs(i);
			bridges += (curr+1);
		}
	}
	vis.assign(n+1, 0);
	cout << bridges << "\n";
	
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs2(i);
	}
	for (int i = 0; i<m; i++){
		debug(ans[i]);
		debug(drzewo[i]);
		cerr << "\n";
	}
	
	for (int i = 0; i<m; i++){
		if (ans[i]) cout << ">";
		else cout << "<";
	}
	cout << "\n";
	return 0;
}
