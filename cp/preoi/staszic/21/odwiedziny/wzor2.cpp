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

const int MAX = 5e4+7, K = 17;
vi graf[MAX], c, depth, parent;
int up[MAX][K];

void init(int n){
	depth.assign(n+1, 0);
	c.assign(n+1, 0);
}

void dfs1(int v, int pa){
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
		if (depth[b]-(1<<i)>=depth[a]){
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

int dist(int a, int b){
	return depth[a]+depth[b]-2*depth[lca(a, b)];
}

void dfs(int v, int pa){
	parent[v] = pa;
	for (auto x: graf[v]){
		if (x!=pa) {
			dfs(x, v);
		}
	}
}

void solve(){
	int n; cin >> n;
	init(n);
	rep(i, 1, n+1) cin >> c[i];
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	vi a(n), D(n-1);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n-1) cin >> D[i];
	rep(i, 1, n){
		parent.assign(n+1, 0);
		dfs(a[i-1], a[i-1]);
		int v = a[i];
		vi order;
		while (v != a[i-1]){
			order.pb(v);
			v = parent[v];
		}
		order.pb(a[i-1]);
		//for (auto x: order) debug(x);
		reverse(all(order));
		//cerr << "\n";
		LL ans = 0LL;
		rep(j, 0, sz(order)){
			if (j%D[i-1] == 0){
				ans += (LL)c[order[j]];
			}
		}
		cout << ans << "\n";
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
