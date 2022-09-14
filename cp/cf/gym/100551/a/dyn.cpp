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
	
	void dfs(int v, int n, int q){
		int t = sz(s);
		for (auto [a, b]: tab[v]) Union(a, b);
		if (v >= size){
			if (v > size && v-size < q+2){
				cout << cnt << " ";
			}
		} else {
			dfs(2*v, n, q);
			dfs(2*v+1, n, q);
		}
		undo(t);
	}
};

void solve(){
	int n, m, q; cin >> n >> m >> q;
	cnt = n;
	iota(REP, REP+n+1, 0);
	fill(sz, sz+n+1, 1);
	map<pii, vpii>life;
	segtree seg;
	seg.init(q+2);
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		life[{a, b}].pb({1, seg.size-1});
	}
	rep(i, 2, q+2){
		int type, a, b; cin >> type >> a >> b;
		if (a > b) swap(a, b);
		if (type == 1) life[{a, b}].pb({i, seg.size-1});
		else life[{a, b}].back().nd = i-1;
	}
	for (auto x: life){
		for (auto v: x.nd){
			seg.add(1, 0, seg.size-1, v.st, v.nd, x.st);
		}
	}
	seg.dfs(1, n, q);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen ("connect.in","r",stdin);
	//freopen ("connect.out","w",stdout);
	solve();
	
	return 0;
}
