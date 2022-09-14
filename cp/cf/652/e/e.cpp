#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

struct edge{
	int a, b, c;
};

const int MAX = 3e5+7;
vpii graf[MAX], comp[MAX];
vector<edge> bridge; 
vi pre, low, depth, post, is;
vpii parent;
vb vis;
int czas, A, B;
set<pii>s;
bool ok;

bool subtree(int x, int y){
	return (pre[x] <= pre[y] && post[x] >= post[y]);
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
			depth[x] = depth[v]+1;
			dfs(x, v);
			low[v] = min(low[v], low[x]);
			if (low[x] > pre[v]){
				bridge.pb({v, x, c});
			} else dsu.Union(x, v);
		}
	}
	post[v] = ++czas;
}

void dfs2(int v, int pa = 0, int c = 0){
	parent[v] = {pa, c};
	for (auto [x, c]: comp[v]){
		if (x != pa){
			dfs2(x, v, c);
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	dsu.init(n);
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		if (a > b) swap(a, b);
		if (c) s.insert({a, b});
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	cin >> A >> B;
	parent.assign(n+1, {0, 0});
	pre.assign(n+1, 0);
	low.assign(n+1, 0);
	vis.assign(n+1, 0);
	depth.assign(n+1, 0);
	post.assign(n+1, 0);
	dfs(1);
	/*
	for (auto x: bridge){
		debug(x.a);
		debug(x.b);
		cerr << "\n";
	}
	rep(v, 1, n+1) debug(dsu.REP[v]);
	cerr << "\n";
	*/
	vi scal = dsu.REP;
	sort(all(scal));
	scal.erase(unique(all(scal)), scal.end());
	//for (auto x: scal) debug(x);
	//cerr << "\n";
	map<int, int>mapa;
	rep(i, 0, sz(scal)) mapa[scal[i]] = i;
	for (auto [a, b, c]: bridge){
		a = mapa[dsu.Find(a)];
		b = mapa[dsu.Find(b)];
		comp[a].pb({b, c});
		comp[b].pb({a, c});
	}
	int N = sz(scal);
	/*
	rep(v, 1, N+1){
		for (auto x: comp[v]){
			debug(v);
			debug(x.st);
			cerr << "\n";
		}
	}
	*/
	is.assign(N+1, 0);
	rep(v, 1, n+1){
		for (auto [x, c]: graf[v]){
			if (depth[x] > depth[v] && low[x] <= pre[v] && c){
				is[mapa[dsu.Find(x)]] = 1;
			}
		}
	}
	//rep(i, 1, N) debug(is[i]);
	//cerr << "\n";
	dfs2(mapa[dsu.Find(A)]);
	int v = mapa[dsu.Find(B)];
	bool ok = 0;
	while (1){
		//debug(v);
		ok |= parent[v].nd;
		ok |= is[v];
		v = parent[v].st;
		if (!v) break;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
