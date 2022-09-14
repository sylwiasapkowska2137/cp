//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
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

// #define int long long
// const int oo = 1e18, K = 30;

struct node{
	long long sum;
	int v, l = -1, f = -1;	
};

struct segtree{
	vector<node>tab;
	int size = 1;

	void print(){
		for (int i = 1; i<(int)tab.size(); i++){
			cerr << i << " " << tab[i].sum << " " << tab[i].v << " " << tab[i].f << "\n";
		}
	}

	node leaf(int v){
		node ret;
		ret.f = 1;
		ret.sum = ret.v = v;
		return ret;
	}

	node f(node a, node b){
		if (a.f == -1) return b;
		if (b.f == -1) return a;
		node ret;
		if (a.f && b.f && a.v == b.v) ret.f = 1;
		else ret.f = 0;
		ret.v = a.v;
		ret.sum = a.sum + b.sum;
		return ret;
	}

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.resize(2*size);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = leaf(a[i]);
		for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
	}

	void push(int x, int lx, int rx){
		if (tab[x].l == -1 || lx == rx) return;
		tab[2*x].f = tab[2*x+1].f = 1;
		tab[2*x].l = tab[2*x+1].l = tab[x].l;
		tab[2*x].v = tab[2*x+1].v = tab[x].l;
		int h = (rx-lx+1)/2;
		tab[2*x].sum = tab[2*x+1].sum = (long long)tab[x].l*h;
		tab[x].l = -1;
	}

	void set(int x, int lx, int rx, int pos, int val){
		if (lx == rx){
			tab[x] = leaf(val);
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		if (pos <= m) set(2*x, lx, m, pos, val);
		else set(2*x+1, m+1, rx, pos, val);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}

	long long query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x].sum;
		push(x, lx, rx);
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}

	void update(int x, int lx, int rx, int l, int r, int k){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r && tab[x].f) {
			tab[x].v /= k;
			tab[x].sum = (long long)tab[x].v*(rx-lx+1);
			tab[x].l = tab[x].v;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, k);
		update(2*x+1, m+1, rx, l, r, k);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}
};

void solve(){
	int n, q, k; cin >> n >> q >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	segtree seg(n+1, a);
	while (q--){
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) seg.set(1, 0, seg.size-1, x, y);
		if (t == 2 && k != 1) seg.update(1, 0, seg.size-1, x, y, k);
		if (t == 3) cout << seg.query(1, 0, seg.size-1, x, y) << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
