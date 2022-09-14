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
vi graf[MAX], depth;

void dfs(int v, int pa){
	up[v][0] = pa;
	rep(i, 1, K) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x == pa) continue;
		depth[x] = depth[v]+1;
		dfs(x, v);
	}
}

int lca(int a, int b){
	if (depth[a] > depth[b]) swap(a, b); //depth[b] wieksze
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

bool check(int d, int k){
	if (d <= k && (d-k)%2 == 0) return 1;
	return 0;
}

void solve(){
	int n; cin >> n;
	rep(i, 1, n){
		int a,b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	depth.assign(n+1, 0);
	dfs(1, 1);
	int q; cin >> q;
	while (q--){
		int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
		bool ok = 0;
		if (check(dist(a, b), k)) ok = 1;
		if (check(dist(a, x)+dist(b, y)+1, k)) ok = 1;
		if (check(dist(b, x)+dist(a, y)+1, k)) ok = 1;
		if (ok) cout << "YES\n";
		else cout << "NO\n";
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
