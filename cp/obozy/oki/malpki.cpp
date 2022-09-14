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

const int MAX = 2e5+7;
vi graf[MAX];
vpii uchwyt;

struct DSU{
	vi REP, sz;
	
	DSU(int n){
		REP.resize(n+1);
		sz.assign(n+1, 1);
		rep(i, 1, n+1) REP[i] = i;
	}
	
	int Find(int a){
		if (a == REP[a]) return a;
		return REP[a] = Find(REP[a]);
	}
	
	void Union(int a, int b){
		a = Find(a);b = Find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		REP[b] = a;
		sz[a] += sz[b]; //przylaczamy mniejszy do wiekszego
	}
	
	bool check(int x){
		
	}
};


void solve(){
	int n, m; cin >> n >> m;
	uchwyt.resize(n+1);
	rep(i, 1, n+1){
		int a, b; cin >> a >> b;
		uchwyt[i].st = a;
		uchwyt[i].nd = b;
		if (a != -1){
			graf[i].pb(a);
			graf[a].pb(i);
		}
		if (b != -1){
			graf[i].pb(a);
			graf[i].pb(b);
		}
	}
	set<pii>s;
	vpii edges;
	while (m--){
		int a, b; cin >> a >> b;
		int x;
		if (b == 1) x = uchwyt[a].nd;
		else x = uchwyt[a].st;
		if (a > x) swap(a, x);
		s.insert({a, x}); //a < x
		edges.pb({a, x});
	}
	DSU(n) dsu;
	reverse(all(edges));
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			pii e = {x, v};
			if (e.st > e.nd) swap(e.st, e.nd);
			if (s.find(e) == s.end()){
				dsu.Union(e.st, e.nd);
			}
		} 
	}
	int czas = sz(edges);
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
