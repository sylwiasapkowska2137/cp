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

const int MAX = 3e5+7;
int REP[MAX], sz[MAX];
stack<int>s;
int cnt;

int Find(int a){
	if (a == REP[a]) return a;
	return Find(REP[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	REP[b] = a;
	sz[a]+=sz[b];
	cnt--;
	s.push(b);
}

void undo(int t){
	while (sz(s) > t){
		int u = s.top(); s.pop();
		sz[REP[u]] -= sz[u];
		REP[u] = u; cnt++;
	}
}

struct segtree{
	vector<vpii>tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.resize(2*size+1);
	}

	void add(int x, int lx, int rx, int l, int r, pii e){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x].pb(e);
			return;
		}
		int m = (lx+rx)/2;
		add(2*x, lx, m, l, r, e);
		add(2*x+1, m+1, rx, l, r, e);
	}
	
	void add(int x){
		tab[x+size].pb({-1, -1});
	}
	
	void dfs(int v, int n){
		if (v >= size){
			if (tab[v].empty()) return;
			if (tab[v][0].st == -1){
				cout << cnt << "\n";
			}
			return;
		}
		int t = sz(s);
		for (auto [a, b]: tab[v]){
			Union(a, b);
		}
		//debug(v);
		//rep(i, 1, n+1) debug(REP[i]);
		//cerr << "\n";
		
		if (v < size){
			dfs(2*v, n);
			dfs(2*v+1, n);
		}
		undo(t);
		//debug(v);
		//rep(i, 1, n+1) debug(REP[i]);
		//cerr << "\n";
	}
};

void solve(){
	int n,q; cin >> n >> q;
	cnt = n;
	iota(REP, REP+n+1, 0);
	fill(sz, sz+n+1, 1);
	map<pii, vpii>life;
	vi query;
	segtree seg;
	seg.init(q+1);
	rep(i, 0, q){
		char type; cin >> type;
		if (type == '+'){
			int a, b; cin >> a >> b;
			if (a > b) swap(a, b);
			life[{a, b}].pb({i, seg.size-1});
		} else if (type == '-'){
			int a, b; cin >> a >> b;
			if (a > b) swap(a, b);
			life[{a, b}].back().nd = i;
		} else {
			query.pb(i);
		}
	}
	for (auto x: life){
		for (auto v: x.nd){
			seg.add(1, 0, seg.size-1, v.st, v.nd, x.st);
		}
	}
	for (auto x: query){
		seg.add(x);
	}
	seg.dfs(1, n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	freopen ("connect.in","r",stdin);
	freopen ("connect.out","w",stdout);
	
	solve();
	
	return 0;
}
