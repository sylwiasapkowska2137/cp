#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 2e5+7;
struct q{ int a, b, c; };
vector<int>graf[MAX], depth, parent, rep;
vector <pii> g[MAX];
vector <q> query;
LL ans = 0LL, ile = 0;
bool cmp(q a, q b){ return (a.c < b.c); }

void dfs1(int v, int pa = -1, int d = 0){
	depth[v] = d;
	parent[v] = pa;
	for (auto x: graf[v]){
		if (x != pa) dfs1(x, v, d+1);
	}
}

void dfs2(int v, int pa = -1){
	for (auto x: g[v]){
		if (x.st != pa){
			ile++;
			ans+=(LL)x.nd;
			dfs2(x.st, v);
		}
	}
}

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b, int c){
	a = Find(a);
	int d = b;
	b = Find(b);
	if (a != b){
		rep[a] = b;
		g[b].pb({a,c});
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	query.resize(m);
	depth.resize(n+1);
	parent.resize(n+1);
	rep.resize(n+1);
	for (int i = 0; i<m; i++) cin >> query[i].a >> query[i].b >> query[i].c;
	sort(query.begin(), query.end(), cmp);
	dfs1(1);
	for (int i = 1; i<=n; i++)rep[i] = i;
	for (auto &x: query){
		if (depth[x.a]<depth[x.b]) swap(x.a, x.b);
		int diff = depth[x.a]-depth[x.b];
		while (diff > 0){
			Union(x.a, parent[x.a], x.c);
			x.a = parent[x.a];
			diff--;
		}
		while (x.a!=x.b){
			Union(x.a, parent[x.a], x.c);
			x.a = parent[x.a];
			Union(x.b, parent[x.b], x.c);
			x.b = parent[x.b];
		}
	}
	//for (int i = 1; i<=n; i++){
	//	for (auto x: g[i])debug(x.st);
	//	cerr << "\n";
	//}
	//for (int i = 1; i<=n; i++)debug(rep[i]);
	dfs2(1);
	cout << ile+1 << " " << ans << "\n";
	return 0;
}
