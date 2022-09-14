//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

struct segtree{
	vector<int>tab, lazy;
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		lazy.assign(2*size+1, -1);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = tab[2*i]^tab[2*i+1];
	}

	void push(int x, int lx, int rx){
		if (lx == rx || lazy[x] == -1) return;
		int half = (rx-lx+1)/2;
		if (half&1){
			tab[2*x] = lazy[x];
			tab[2*x+1] = lazy[x];
		} else{
			tab[2*x] = tab[2*x+1] = 0;
		}
		lazy[2*x] = lazy[x];
		lazy[2*x+1] = lazy[x];
		lazy[x] = -1;
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r) {
			if ((rx-lx+1)&1) tab[x] = v;
			else tab[x] = 0;
			lazy[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = tab[2*x]^tab[2*x+1];
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)^query(2*x+1, m+1, rx, l, r);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	segtree seg(n+1, a);
	while (q--){
		int t; cin >> t;
		if (t){
			int l, r; cin >> l >> r;
			--l;--r;
			cout << seg.query(1, 0, seg.size-1, l, r) << "\n";
		} else{
			int l, r, v; cin >> l >> r >> v;
			--l;--r;
			seg.update(1, 0, seg.size-1, l, r, v); 
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
