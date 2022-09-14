#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

const int MAX = 3e5+7, K = 20;
vector<pii>graf[MAX];
int up[MAX][K];
vector<int> Rep, XOR, euler, depth, first;
vector<bool>vis, cycle;

struct edge{
	int a, b, val;
};

void dfs(int v, int pa){
	vis[v] = 1;
	euler.pb(v);
	if (first[v] == -1) first[v] = euler.size()-1;
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (!vis[x.st]){
			XOR[x.st] = XOR[v]^x.nd;
			depth[x.st] = depth[v]+1;
			dfs(x.st, v);
			euler.pb(v);
		}
	}
}

int Find(int a){
	if (a == Rep[a]) return a;
	return Rep[a] = Find(Rep[a]);
}

void Union(int a, int b, int val, int index){
	if (a > b) swap(a, b);
	int c = Find(a);
	int d = Find(b);
	if (c!=d){
		cycle[index] = 1;
		Rep[d] = c;
		graf[a].pb({b, val});
		graf[b].pb({a, val});
	}
}

int LCA(int a, int b){
	if (depth[a]<depth[b]) swap(a, b); //a jest głebiej
	for (int i = K-1; i>=0; i--){
		if (depth[a]-(1<<i)>=depth[b]) a = up[a][i];
	}
	if (a == b) return a;
	for (int i = K-1; i>=0; i--){
		if (up[a][i]!=up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

struct segtree{
	vector<int>tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans+=tab[l+1];
			if (r&1) ans+=tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
	
	void update(int pos){
		pos+=size;
		tab[pos]++;
		while (pos>0){
			pos/=2;
			tab[pos]++;
		}
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	vector<edge>edges(q);
	Rep.resize(n+1);
	cycle.assign(q, 0);
	rep(i, 1, n+1) Rep[i] = i;
	rep(i, 0, q) {
		cin >> edges[i].a >> edges[i].b >> edges[i].val;
		Union(edges[i].a, edges[i].b, edges[i].val, i);
	}
	vis.assign(n+1, 0);
	XOR.assign(n+1, 0);
	depth.assign(n+1, 0);
	first.assign(n+1, -1);
	rep(i, 1, n+1) if (!vis[i]) dfs(i, i);
	
	rep(i, 1, n+1){
		debug("i");
		debug(i);
		cerr << "\n";
		for (auto x: graf[i]) debug(x.st);
		cerr << "\n";
	}
	
	for (auto x: euler) debug(x);
	cerr << "\n";
	
	
	
	return 0;
}
