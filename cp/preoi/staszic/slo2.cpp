#include <bits/stdc++.h> 
using namespace std;
#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>

const int MAX = 5e5+7, H = 20;
vector <pii> graf[MAX];
int lca[MAX][H];
LL suma[MAX];
vector <int> d;

void dfs(int v, int u = -1, int depth = 0){
	lca[v][0] = u;
	d[v] = depth;
	for (int j = 1; j<H; j++) if (lca[v][j-1] != 0) lca[v][j] = lca[lca[v][j-1]][j-1];
	for (auto x: graf[v]){
		if (x.st != u){
			suma[x.st] = suma[v]+(LL)x.nd;
			dfs(x.st, v, depth+1);
		}
	}
}

int LCA(int a, int b){
	if (d[a]>d[b]) swap(a, b);
	int diff = d[b]-d[a];
	while (diff > 0){
		int i = log2(diff);
		b = lca[b][i];
		diff -= (1<<i);
	}
	if (a == b) return a;
	while (lca[a][0]!=lca[b][0]){
		a = lca[a][0];
		b = lca[b][0];
	}
	return lca[a][0];
}

int main(){ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b, c;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	d.assign(n+1, 0);
	dfs(1);
	while (cin >> a && a!=-1){
		cin >> b;
		cout << suma[a]+suma[b]-2*suma[LCA(a, b)] << "\n";
	}
	return 0;
}
