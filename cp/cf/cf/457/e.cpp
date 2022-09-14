//Sylwia Sapkowska
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

const int MAX = 1e5+7, K = 20;
int up[MAX][K];
vi graf[MAX], order, sub, depth, uord;
vll values;
int root = 1, k;

struct segtree{
	int size = 1;
	vll tab, lazy;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		lazy.assign(2*size, 0);
		rep(i, 0, n) tab[i+size] = values[uord[i]];
		repd(i, size-1, 1) tab[i] = tab[2*i]+tab[2*i+1];
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		LL half = lazy[x]/2;
		tab[2*x]+=half;
		tab[2*x+1]+=half;
		lazy[2*x]+=half;
		lazy[2*x+1]+=half;
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, LL val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			LL len = rx-lx+1;
			tab[x] += val*len;
			lazy[x] += val*len;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = tab[2*x]+tab[2*x+1];
	}
	
	LL query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x];
		push(x, lx, rx);
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}
};

void init(int n){
	sub.assign(n+1, 1);
	values.resize(n+1);
	depth.assign(n+1, 0);
	order.assign(n+1, 0);
	uord.assign(n+1, 0);
}

void dfs(int v, int pa = 1){
	order[v] = k;
	uord[k] = v;
	k++;
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
			sub[v]+=sub[x];
		}
	}
}

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b); //depth[b] wieksze
	repd(i, K-1, 0){
		if (depth[b]-(1<<i)>=depth[a]) {
			b = up[b][i];
		}
	}
	if (a == b) return a;
	repd(i, K-1, 0){
		if (up[a][i]!=up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

int ancestor(int a, int b){
	repd(i, K-1, 0){
		if (b&(1<<i)) a = up[a][i];
	}
	return a;
}

void solve(){
	int n, q; cin >> n >> q;
	int lbound = 0, rbound = n-1;
	init(n);
	rep(i, 1, n+1) cin >> values[i];
	
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1);
	//for (auto x: order) debug(x);
	//cerr << "\n";
	segtree seg;
	seg.init(n+1);
	//for (auto x: seg.tab) debug(x);
	//cerr << "\n";
	while (q--){
		int type; cin >> type;
		if (type == 1){
			cin >> root;
			lbound = order[root], rbound = order[root]+sub[root]-1;
		}
		if (type == 2){
			int u, v, x; cin >> u >> v >> x;
			int L, ile = 0;
			if (lbound<=order[u] && order[u]<=rbound) ile++;
			if (lbound<=order[v] && order[v]<=rbound) ile++;
			if (ile == 2) L = lca(u, v);
			else if (ile == 1) L = root;
			else {
				int a = lca(u, v), b = lca(v, root), c = lca(u, root);
				L = a;
				if (depth[a] < depth[b]) L = b;
				if (depth[b] < depth[c]) L = c;
			}
			//debug(L);
			//dodać x do poddrzewa L
			
			if (L == root) seg.update(1, 0, seg.size-1, 0, seg.size-1, (LL)x); 
			else if (lbound<order[L] && order[L]<=rbound) seg.update(1, 0, seg.size-1, order[L], order[L]+sub[L]-1, (LL)x);
			else if (order[L]<order[root] && order[root]<=order[L]+sub[L]-1){
				seg.update(1, 0, seg.size-1, 0, seg.size-1, (LL)x);
				int dep_diff = depth[root]-depth[L];
				int undo = ancestor(root, dep_diff-1);
				seg.update(1, 0, seg.size-1, order[undo], order[undo]+sub[undo]-1, -x);
			} else seg.update(1, 0, seg.size-1, order[L], order[L]+sub[L]-1, (LL)x);
			
		}
		if (type == 3){
			
			int L; cin >> L;
			LL ans;
			if (L == root) ans = seg.query(1, 0, seg.size-1, 0, seg.size-1); 
			else if (lbound<order[L] && order[L]<=rbound) ans = seg.query(1, 0, seg.size-1, order[L], order[L]+sub[L]-1);
			else if (order[L]<order[root] && order[root]<=order[L]+sub[L]-1){
				ans += seg.query(1, 0, seg.size-1, 0, seg.size-1);
				int dep_diff = depth[root]-depth[L];
				int undo = ancestor(root, dep_diff-1);
				ans -= seg.query(1, 0, seg.size-1, order[undo], order[undo]+sub[undo]-1);
			} else ans = seg.query(1, 0, seg.size-1, order[L], order[L]+sub[L]-1);
			cout << ans << "\n";
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
