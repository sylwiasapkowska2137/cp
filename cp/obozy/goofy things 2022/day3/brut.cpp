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
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

const LL INF = 5e14+2137;
const int MAX = 1e5+7;
vpii graf[MAX];
vector<pair<int, LL>> graf2[MAX];
vll dist;
vb vis;

void dijkstra(int S, int n){
	dist.assign(n+1, INF);
	vis.assign(n+1, 0);
	dist[S] = 0;
	pqg<pll>s;
	s.push({0LL, S});
	while (!s.empty()){
		int v = s.top().nd;
		LL d = s.top().st;
		s.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto [x, c]: graf[v]){
			if (d+c < dist[x]){
				dist[x] = d+c;
				s.push({dist[x], x});
			}
		}
	}
}

struct DSU{
	vi REP, sz;
	int curr = 0;
	
	void init(int n){
		curr = 1;
		REP.resize(n+1, 0);
		sz.assign(n+1, 1);
		rep(i, 0, n+1) REP[i] = i;
	}
	
	int Find(int a){
		if (a == REP[a]) return a;
		return REP[a] = Find(REP[a]);
	}
	
	void Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		REP[b] = a;
		sz[a]+=sz[b];
	}
};


struct E{
	int a, b;
	LL c;
	E() {}
	E(int a, int b, LL c): a(a), b(b), c(c) {}
};

bool cmp(E a, E b){
	return a.c < b.c;
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
	rep(i, 1, n+1){
		if (bar[i]){
			dijkstra(i, n);
			rep(j, 1, n+1){
				if (i == j || !bar[j]) continue;
				graf2[i].pb({j, dist[j]});
			}
		}
	}
	vector<E>edges;
	rep(v, 1, n+1){
		for (auto [x, c]: graf2[v]){
			if (x > v){
				/*
				debug(v);
				debug(x);
				debug(c);
				cerr << "\n";
				*/
				edges.pb({v, x, c});
			}
		}
	}
	sort(all(edges), cmp);
	DSU dsu;
	vpii Q(q);
	rep(i, 0, q) cin >> Q[i].st >> Q[i].nd;
	vll L(q, 0), R(q, INF);
	while (1){
		dsu.init(n+1);
		map<LL, vi>check;
		bool ok = 1;
		rep(i, 0, q){
			if (L[i] < R[i]){
				LL mid = (L[i]+R[i])/2;
				check[mid].pb(i);
				ok = 0;
			}
		}
		if (ok) break;
		int k = 0;
		for (auto x: check){
			while (k < sz(edges) && edges[k].c <= x.st){
				dsu.Union(edges[k].a, edges[k].b);
				k++;
			}
			for (auto v: x.nd){
				if (dsu.Find(Q[v].st) == dsu.Find(Q[v].nd)){
					R[v] = x.st;
				} else L[v] = x.st+1;
			}
		}
	}
	rep(i, 0, q) cout << R[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
