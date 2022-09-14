//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
	int pref, suf, first, last, value;
	bool empty, inc;
} neutral;

struct segtree{
	vector<node>tab;	
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		neutral.empty = 1;
		tab.resize(2*size+1);
		build(1, 0, size-1, a);
	}

	node merge(node a, node b){
		if (a.empty) return b;
		if (b.empty) return a;
		node ans;
		ans.empty = 0;
		ans.inc = ((a.inc && b.inc && a.last <= b.first)?1:0);
		ans.first = a.first, ans.last = b.last;
		ans.pref = ((a.inc && a.last <= b.first)? a.pref + b.pref: a.pref);
		ans.suf = ((b.inc && a.last <= b.first)? b.suf + a.suf: b.suf);
		ans.value = a.value + b.value + (a.last <= b.first ? a.suf*b.pref : 0);
		return ans;
	}

	void build(int x, int lx, int rx, vector<int>&a){
		if (lx == rx){
			if (lx < (int)a.size()){
				tab[x].empty = 0;
				tab[x].inc = 1;
				tab[x].first = tab[x].last = a[lx];
				tab[x].pref = tab[x].suf = tab[x].value = 1; 
			} else {
				tab[x].empty = 1;
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x, lx, m, a);
		build(2*x+1, m+1, rx, a);
		tab[x] = merge(tab[2*x], tab[2*x+1]);
	}

	void update(int x, int lx, int rx, int pos, int val){
		if (lx == rx){
			tab[x].first = val;
			tab[x].last = val;
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) update(2*x, lx, m, pos, val);
		else update(2*x+1, m+1, rx, pos, val);
		tab[x] = merge(tab[2*x], tab[2*x+1]);
	}

	node query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return neutral;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return merge(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

	void print(){
		for (int i = 1; i<(int)tab.size(); i++){
			auto x = tab[i];
			debug(i, x.value, x.pref, x.suf, x.first, x.last, x.inc, x.empty);
			//debug(i, x.pref, x.suf, x.inc);
		}
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	segtree seg(n, a);
	//seg.print();
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, v; cin >> x >> v;
			x--;
			seg.update(1, 0, seg.size-1, x, v);
		} else {
			int l, r; cin >> l >> r;
			--l;--r;
			cout << seg.query(1, 0, seg.size-1, l, r).value << "\n";
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
