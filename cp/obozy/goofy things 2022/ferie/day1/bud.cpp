//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 1e5+7, K = 20;
vpii graf[MAX], comp[MAX];
int up[MAX][K];
vi low, pre, depth, value, UP, DOWN;
vb vis;
vector<tuple<int, int, int>>bridge;
int czas;
map<pii, int>ecnt;

void init(int n){
	low.assign(n, 0);
	pre.assign(n, 0);
	vis.assign(n, 0);
}

struct DSU{
	vi REP;
	int n;
	
	void init(int s){
		n = s;
		REP.resize(n+1);
		rep(i, 1, n+1) REP[i] = i;
	}
	
	int Find(int a){
		if (a == REP[a]) return a;
		return REP[a] = Find(REP[a]);
	}
	
	void Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if (a == b) return;
		REP[b] = a;
	}
} dsu;

void dfs(int v, int pa = -1){
	vis[v] = 1;
	pre[v] = low[v] = ++czas;
	for (auto [x, c]: graf[v]){
		if (x == pa) continue;
		if (vis[x]) low[v] = min(low[v], pre[x]);
		else {
			dfs(x, v);
			low[v] = min(low[v], low[x]);
			if (low[x] > pre[v] && ecnt[{min(x, v), max(x, v)}] == 1) bridge.pb({v, x, c});
			else dsu.Union(x, v);
		}
	}
}
 
void dfs1(int v, int pa){
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto [x, c]: comp[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			value[x] = c;
			dfs1(x, v);
		}
	}
}

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b);
	repd(i, K-1, 0){
		if (depth[b]-(1<<i) >= depth[a]){
			b = up[b][i];
		}
	}
	if (a == b) return a;
	repd(i, K-1, 0){
		if (up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

void dfs2(int v, int pa = -1){
	for (auto [x, c]: comp[v]){
		if (x!=pa){
			dfs2(x, v);
			UP[v] += UP[x];
			DOWN[v] += DOWN[x];
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		if (a > b) swap(a, b);
		ecnt[{a, b}]++;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	init(n+1);
	dsu.init(n);
	dfs(1);
	/*
	for (auto [a, b, c]: bridge){
		debug(a);
		debug(b);
		cerr << "\n";
	}
	rep(i, 1, n+1) debug(dsu.REP[i]);
	cerr << "\n";
	*/
	vi scaler = dsu.REP;
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int, int>mapa;
	//for (auto x: scaler) debug(x);
	//cerr << "\n";
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	for (auto& [a, b, c]: bridge){
		a = mapa[dsu.Find(a)];
		b = mapa[dsu.Find(b)];
		comp[a].pb({b, c});
		comp[b].pb({a, c});
	}
	int N = sz(scaler);
	/*
	rep(v, 1, N+1){
		for (auto x: comp[v]){
			debug(v);
			debug(x.st);
			cerr << "\n";
		}
	}
	*/
	depth.assign(N+1, 0);
	value.assign(N+1, 0);
	int s = mapa[dsu.Find(1)];
	dfs1(s, s);
	//rep(i, 1, N+1) debug(value[i]);
	//cerr << "\n"; 
	int q; cin >> q;
	UP.assign(N+1, 0);
	DOWN.assign(N+1, 0);
	while (q--){
		int a, b; cin >> a >> b;
		a = mapa[dsu.Find(a)];
		b = mapa[dsu.Find(b)];
		int L = lca(a, b);
		UP[a]++;
		UP[L]--;
		DOWN[L]--;
		DOWN[b]++;
	}
	dfs2(s, s);
	/*
	rep(i, 1, N) debug(UP[i]);
	cerr << "\n";
	rep(i, 1, N) debug(DOWN[i]);
	cerr << "\n";
	*/
	LL ans = 0LL;
	rep(i, 1, N+1){
		ans += (LL)min(UP[i], DOWN[i])*(LL)value[i];
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
