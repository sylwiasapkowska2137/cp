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

struct segtree{
	int size = 1;
	vll tab, lazy;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		lazy.assign(2*size, 0);
	}
	
	void build(vi a){
		rep(i, 1, sz(a)) tab[i+size]=a[i];
		repd(i, size-1, 1) tab[i] = tab[2*i]+tab[2*i+1];
	}
	
	void push(int x, int lx, int rx){
		if (!lazy[x] || lx == rx) return;
		tab[2*x] %= lazy[x];
		tab[2*x+1] %= lazy[x];
		lazy[2*x] = x;
		lazy[2*x+1] = x;
		lazy[x] = 0;
	}
	
	void set(int x, int lx, int rx, int pos, LL val){
		if (lx == rx){
			tab[pos] = val;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		if (pos <= m) set(2*x, lx, m, pos, val);
		else set(2*x+1, m+1, rx, pos, val);
	}
	
	void update(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] %= val;
			lazy[x] = val;
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

void solve(){
	int n, m; cin >> n >> m;
	vi a(n+1, 0);
	rep(i, 1, n+1) cin >> a[i];
	segtree seg;
	seg.init(n+1);
	seg.build(a);
	while (m--){
		int type; cin >> type;
		if (type == 1){
			int l, r; cin >> l >> r;
			cout << seg.query(1, 0, seg.size-1, l, r) << "\n";
		} else if (type == 2){
			int l, r, x; cin >> l >> r >> x;
			seg.update(x, 0, seg.size-1, l, r, x);
		} else {
			int k, x; cin >> k >> x;
			seg.set(x, 0, seg.size-1, k, x);
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
