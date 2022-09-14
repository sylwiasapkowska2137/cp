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

// aaaaaaaa
const int MAX = 1e5+7, K = 20;
vi graf[MAX], color, pre, depth;
set<pii> pos[MAX];
LL ans[MAX];
int czas;
int up[MAX][K];

void dfs1(int v, int pa = 1){
	pre[v] = ++czas;
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
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

LL dist(int a, int b){
	int L = lca(a, b);
	return (LL)(depth[a]+depth[b]-2*depth[L]);
}

pii Find(int v) {
	int c = color[v];
	auto it = pos[c].find({pre[v], v});
	int a = (v == pos[c].begin()->nd ? pos[c].rbegin()->nd : (--it)->nd);
	if (it->nd != v) ++it;
	assert(it->nd == v);
	int b = (v == pos[c].rbegin()->nd ? pos[c].begin()->nd : (++it)->nd);
	return {a, b};
}

void remove(int v){
	auto [a, b] = Find(v);
	//cerr << "remove " << a << " " << v << " " << b << "\n";
	ans[color[v]] += dist(a, b);
	ans[color[v]] -= dist(a, v);
	ans[color[v]] -= dist(b, v);
	pos[color[v]].erase({pre[v], v});
}

void add(int v, int c){
	color[v] = c;
	pos[c].insert({pre[v], v});
	auto [a, b] = Find(v);
	//cerr << "add " << x << " " << v << " " << y << "\n";
	ans[c] -= dist(a, b);
	ans[c] += dist(a, v);
	ans[c] += dist(b, v);
}

void solve(){
	int n; cin >> n;
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	color.resize(n+1);
	rep(i, 1, n+1) cin >> color[i];
	pre.assign(n+1, 0);
	depth.assign(n+1, 0);
	dfs1(1);
	rep(i, 1, n+1) pos[color[i]].insert({pre[i], i});
	rep(i, 1, MAX){
		if (sz(pos[i]) <= 1) continue;
		int prev = -1;
		for (auto x: pos[i]){
			if (prev != -1)	ans[i] += dist(prev, x.nd);
			prev = x.nd;
		}
		ans[i] += dist(prev, pos[i].begin()->nd);
	}
	/*
	rep(i, 1, maxi+1) debug(ans[i]);
	cerr << "\n";
	rep(i, 1, n+1) debug(pre[i]);
	cerr << "\n";
	*/
	int q; cin >> q;
	while (q--){
		char type; cin >> type;
		if (type == 'Q'){
			int c; cin >> c;
			//cerr << "query ";
			if (pos[c].empty()) cout << "-1\n";
			else cout << ans[c]/2 << "\n";
		} else {
			int v, c; cin >> v >> c;
			remove(v);
			add(v, c);
			//cerr << "ans ";
			//rep(i, 1, maxi+1) debug(ans[i]);
			//cerr << "\n";
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
