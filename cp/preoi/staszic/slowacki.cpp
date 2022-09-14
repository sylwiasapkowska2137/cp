#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 5e5+7, H = 20;
vector<int> graf[MAX];
int p[MAX][H], depth[MAX];
LL suma[MAX], num[MAX];
LL sum = 0;

struct edge {
	int a, b, c;
	edge (int a, int b, int c): a(a), b(b), c(c) {}
};

vector <edge> graph;

void dfs(int v, int pa = 0, int _depth = 0){
	p[v][0] = pa;
	for (int i = 1; i<=H; i++) p[v][i] = p[p[v][i-1]][i-1];
	depth[v] = _depth;
	for (auto x: graf[v]){
		if (x != pa) dfs(x, v, _depth+1);
	}
}

int lca(int a, int b){
	if (depth[a]>depth[b]) swap(a, b);
	for (int i = H; i>=0; i--) if(depth[p[b][i]]>=depth[a]) b = p[b][i];
	if (a == b) return a;
	for (int i = H; i>=0; i--){
		if (p[a][i]!=p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

void dfs2(int v, int pa = -1){
	sum += num[v];
	suma[v] = sum;
	for (auto x: graf[v]){
		if (x != pa) dfs2(x, v);
	}
	sum-=num[v];
}

int main(){
	fastio;
	int n, a, b, c;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b >> c;
		graf[a].pb(b);
		graf[b].pb(a);
		graph.pb({a, b, c});
	}
	dfs(1);
	for (auto x: graph){
		if (depth[x.a]>depth[x.b]) num[x.a] = (LL)x.c;
		else num[x.b] = (LL)x.c;
	}
	dfs2(1);
	while (cin >> a && a != -1){
		cin >> b;
		cout << suma[a]+suma[b]-2*suma[lca(a, b)] << "\n";
	}
	return 0;
}



