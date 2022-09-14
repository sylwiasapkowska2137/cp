#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<bool> vb;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

const LL INF = 1e18;
const int MAX = 5e5+7, K = 20;
vpii graf[MAX];
vpll G[MAX];
vll dist;
int up[MAX][K];
LL maxi[MAX][K];
vi depth;

struct E{
	int a, b;
	LL c;
	E() {}
	E(int a, int b, LL c): a(a), b(b), c(c) {}
};

bool cmp(E a, E b){
	return a.c < b.c;
}

struct DSU{
	vi REP;
	
	void init(int n){
		REP.resize(n+1, 0);
		rep(i, 0, n+1) REP[i] = i;
	}
	
	int Find(int a){
		if (a == REP[a]) return a;
		return REP[a] = Find(REP[a]);
	}
	
	void Union(int a, int b, LL c){
		int A = a, B = b;
		a = Find(a);
		b = Find(b);
		if (a == b) return;
		REP[b] = a;
		G[A].pb({B, c});
		G[B].pb({A, c});
	}
};


void dfs(int v, int p, LL w = -INF){
	up[v][0] = p;
	maxi[v][0] = w;
	rep(i, 1, K){
		up[v][i] = up[up[v][i-1]][i-1];
		maxi[v][i] = max(maxi[v][i-1], maxi[up[v][i-1]][i-1]);
	}
	for (auto x: G[v]){
		if (x.st!=p){
			depth[x.st] = depth[v]+1;
			dfs(x.st, v, x.nd);
		}
	}
}

int lca(int x, int y){
	if (depth[x]<depth[y]) swap(x, y);
	repd(i, K-1, 0){
		if (depth[x]-(1<<i)>=depth[y]) x = up[x][i];
	}
	if (x == y)return x;
	repd(i, K-1, 0){
		if (up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

LL call(int a, int b){
	LL res = -INF;
	repd(i, K-1, 0){
		if (depth[a]-(1<<i)>=depth[b]){
			res = max(res, maxi[a][i]);
			a = up[a][i];
		}
	}
	return res;
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vi bar(n+1);
	rep(i, 1, n+1) cin >> bar[i];
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	dist.assign(n+1, INF);
	vi inf(n+1, 0);
	set<pll>s;
	rep(i, 1, n+1){
		if (bar[i]){
			dist[i] = 0LL;
			inf[i] = i;
			s.insert({0LL, i});
		}
	}
	vb vis(n+1, 0);
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto [x, c]: graf[v]){
			if (c+d < dist[x]){
				dist[x] = c+d;
				inf[x] = inf[v];
				s.insert({dist[x], x});
			}
		}
	}
	//rep(i, 1, n+1) debug(inf[i]);
	//cerr << "\n";
	vector<E>edges;
	rep(v, 1, n+1){
		for (auto [x, c]:graf[v]){
			if (inf[v]!=inf[x] && v > x){
				edges.pb({inf[v], inf[x], dist[x]+dist[v]+c});
			}
		}
	}
	sort(all(edges), cmp);
	DSU dsu;
	dsu.init(n+1);
	for (auto [x, v, c]: edges) dsu.Union(x, v, c);
	rep(i, 0, n+1){
		rep(j, 0, K){
			maxi[i][j] = -INF;
		}
	}
	depth.assign(n+1, 0);
	rep(i, 1, n+1){
		if (bar[i]){
			dfs(i, i);
			break;
		}
	}
	while (q--){
		int a, b; cin >> a >> b;
		a = inf[a], b = inf[b];
		if (inf[a] == inf[b]){
			cout << "0\n";
			continue;
		}
		int l = lca(a, b);
		LL ans = max(call(a, l), call(b, l));
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
