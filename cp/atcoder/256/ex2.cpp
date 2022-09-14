//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

#define int long long
const int oo = 1e18, K = 30;

struct node{
	int v, s, l, f = -1;
	void d() {
		cerr << v << " " << s <<"  " << l << " " << f<< endl;
	}
} e;

struct segtree{
	vector<node>tab;
	vector<int>lazy;
	int size = 1;

	node l(int v){
		node x;
		x.v = x.s = v;
		x.l = x.f = 1;
		return x;
	}

	node comb(node a, node b){
		if (a.f == -1) return b;
		if (b.f == -1) return a;
		node xd;
		xd.l = a.l+b.l;
		xd.s = a.s+b.s;
		xd.v = a.v;
		if (a.f && a.v == b.v && b.f) xd.f = 1;
		else xd.f = 0;
		return xd;
	}

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.resize(2*size);
		lazy.assign(2*size, -1);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = l(a[i]);
		for (int i = size-1; i>=1; i--) tab[i] = comb(tab[2*i], tab[2*i+1]);
	}

	void push(int x, int lx, int rx){
		if (lazy[x] == -1 || lx == rx) return;
		for (int k = 0; k<2; k++){
			tab[2*x+k].v = lazy[x];
			tab[2*x+k].s = tab[2*x+k].v * tab[2*x+k].l;
			tab[2*x+k].f = 1;
			lazy[2*x+k] = lazy[x];
		}
		lazy[x] = -1;
	}

	void update(int x, int lx, int rx, int l, int r, int t, int y){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			if (t == 1 && tab[x].f == 1){
				tab[x].v /= y;
				tab[x].s = tab[x].v*tab[x].l;
				lazy[x] = tab[x].v;
				return;
			} else if (t == 2){
				tab[x].v = y;
				tab[x].f = 1;
				tab[x].s = y*tab[x].l;
				lazy[x] = tab[x].v;
				return;
			}
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, t, y);
		update(2*x+1, m+1, rx, l, r, t, y);
		tab[x] = comb(tab[2*x], tab[2*x+1]);
	}

	node query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return e;
		if (lx >= l && rx <= r) return tab[x];		
		int m = (lx+rx)/2;
		return comb(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	segtree seg(n+1, a);
	while(q--){
		int t; cin >> t;
		if (t <= 2){
			int l, r, x; cin >> l >> r >> x;
			seg.update(1, 0, seg.size-1, l, r, t, x);
		} else{
			int l, r; cin >> l >> r;
			cout << seg.query(1, 0, seg.size-1, l, r).s << "\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
