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
 void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int n;
const int INF = 1e9+7, MAX = 2e5+7, K = 20;
vi vis;
vpii graf[MAX];
vi dist, REP, sz, depth;
vector<vi>up;

void dsu_init(int N){
	REP.assign(N+1, 0);
	iota(all(REP), 0);
	sz.assign(N+1, 1);
}

void clear(int v, int pa = -1){
	 vis[v] = 0;
	 for (auto [x, c]:graf[v]){
		 if (x!=pa) clear(x, v);
	 }
}

void dfs(int v, int pa){
	vis[v] = 1;
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto [x, c]:graf[v]){
		if (!vis[x]){
			dist[x] = dist[v]+1;
			depth[x] = depth[v]+c;
			dfs(x, v);
		}
	}
}

int Find(int a){
	if (a == REP[a]) return a;
	return REP[a] = Find(REP[a]);
}

void Union(int a, int b, int m){
	int A = Find(a);
	int B = Find(b);
	if (sz[A] < sz[B]) {
		swap(a, b);
		swap(A, B);
	}
	//b->a
	//debug(b, a, m);
	clear(b);
	depth[b] = depth[a]+m;
	dist[b] = dist[a]+1;
	dfs(b, a);
	REP[B] = A;
	sz[A] += sz[B];
}

void init(int N, int subtask){
	n = N;
	dsu_init(n+1);
	depth.assign(n+1, 0);
	vis.assign(n+1, 0);
	dist.assign(n+1, 0);
	up.resize(n+1, vi(K, 0));
};

void build(int x, int y, int m){
	Union(x, y, m);
	graf[x].pb({y, m});
	graf[y].pb({x, m});
}

int lca(int x, int y){
	if (dist[x] < dist[y]) swap(x, y);
	repd(i, K-1, 0){
		if (dist[x]-(1<<i)>=dist[y]){
			x = up[x][i];
		}
	}
	if (x == y) return x;
	repd(i, K-1, 0){
		if (up[x][i] != up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
		//debug(ans);
	}
	return up[x][0];
}

int path(int x, int y){
	int L = lca(x, y);
	return depth[x]+depth[y]-2*depth[L];
}
