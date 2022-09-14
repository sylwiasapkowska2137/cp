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

const int MAX = 1e5+7;
vpii graf[MAX];
vi check[MAX];

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
		REP[b] = a;
		sz[a]+=sz[b];
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vpii edges(m+1);
	rep(i, 1, m+1){
		int a, b; cin >> a >> b;
		graf[a].pb({b, i});
		graf[b].pb({a, i});
		edges[i] = {a, b};
	}
	int q; cin >> q;
	vi x(q), y(q), z(q);
	rep(i, 0, q) cin >> x[i] >> y[i] >> z[i];
	
	DSU dsu;
	vi L(q, 0), R(q, m);
	while (1){
		dsu.init(n);
		rep(i, 0, m+1) check[i].clear();
		bool ok = 1;
		rep(i, 0, q){
			if (L[i] < R[i]){
				int mid = (L[i]+R[i])/2;
				check[mid].pb(i);
				ok = 0;
			}
		}
		if (ok) break;
		rep(i, 0, m+1){
			if (i) dsu.Union(edges[i].st, edges[i].nd);
			for (auto j: check[i]){
				int X = dsu.Find(x[j]);
				int Y = dsu.Find(y[j]);
				int S = dsu.sz[X];
				if (X != Y) S+=dsu.sz[Y];
				int mid = (L[j]+R[j])/2; 
				if (S >= z[j]) R[j] = mid;
				else L[j] = mid+1;
			}
		}
	}
	rep(i, 0, q) cout << R[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
