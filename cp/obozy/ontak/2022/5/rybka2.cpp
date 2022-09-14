//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
	int l, r, f = -1, min, max, sum, xorr;

	void d(){
		cerr << l << " " << r << " " << f << " " << min << " " << max << " " << sum << " " << xorr << "\n";
	}
} xd;

struct segtree{
	vector<node>tab;
	vector<int>lazy;
	int size = 1;

	node leaf(int val, int pos){
		node ret;
		ret.f = 1;
		ret.sum = ret.min = ret.max = ret.xorr = val;
		ret.l = ret.r = pos;
		return ret;
	}

	node f(node a, node b){
		if (a.f == -1) return b;
		if (b.f == -1) return a;
		node ret;
		if (a.f && b.f && a.min == b.min) ret.f = 1;
		else ret.f = 0;
		ret.min = min(a.min, b.min);
		ret.max = max(a.max, b.max);
		ret.l = a.l;
		ret.r = b.r;
		ret.sum = a.sum+b.sum;
		ret.xorr = a.xorr^b.xorr;
		return ret;
	}

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.resize(2*size+1);
		lazy.assign(2*size, -1);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = leaf(a[i], i);
		for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
		// for (int i = 0; i<(int)tab.size(); i++){
		// 	cerr << i << " ";tab[i].d();
		// }
	}

	void push(int x, int lx, int rx){
		if (lx == rx || lazy[x] == -1) return;
		
		for (int k = 0; k<2; k++){
			tab[2*x+k].min = tab[2*x+k].max = lazy[x];
			tab[2*x+k].sum = (tab[2*x+k].r-tab[2*x+k].l+1)*lazy[x];
			if ((tab[2*x+k].r-tab[2*x+k].l+1) % 2 == 0) tab[2*x+k].xorr = 0;
			else tab[2*x+k].xorr = lazy[x];
			tab[2*x+k].f = 1;
			lazy[2*x+k] = lazy[x];
		}
		lazy[x] = -1;
	}

	void update(int x, int lx, int rx, int l, int r, int k, int t){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			if (t == 1){
				//ustaw k na przedziale
				tab[x].f = 1;
				tab[x].min = tab[x].max = k;
				tab[x].sum = (tab[x].r-tab[x].l+1)*k;
				if ((tab[x].r-tab[x].l+1)%2 == 0) tab[x].xorr = 0;
				else tab[x].xorr = k;
				lazy[x] = k;
				return;
			}
			if (t == 2){
				//dodaj k na przedziale
				if (tab[x].f){
					tab[x].f = 1;
					tab[x].min += k;
					tab[x].max += k;
					tab[x].sum += (tab[x].r-tab[x].l+1)*k;
					if ((tab[x].r-tab[x].l+1)%2 == 0) tab[x].xorr = 0;
					else tab[x].xorr = tab[x].min;
					lazy[x] = tab[x].min;
					return;
				}
			}
			if (t == 3){
				if (tab[x].max <= k){
					tab[x].f = 1;
					tab[x].min = tab[x].max = k;
					tab[x].sum = (tab[x].r-tab[x].l+1)*k;
					if ((tab[x].r-tab[x].l+1)%2 == 0) tab[x].xorr = 0;
					else tab[x].xorr = k;
					lazy[x] = k;
					return;
				}
				if (tab[x].min > k){
					return;
				}
			}
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, k, t);
		update(2*x+1, m+1, rx, l, r, k, t);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}

	node query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return xd;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return f(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

struct query{
	int t, l1, l2, r1, r2;
	query(int _t = 0, int _l1 = 0, int _l2 = 0, int _r1 = 0, int _r2 = 0){
		t = _t;l1 = _l1; l2 = _l2; r1 = _r1; r2 = _r2;
	}
}

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1), scaler;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		scaler.emplace_back(a[i]);
	}
	segtree seg(n+1, a);
	vector<query>Q;
	for (int i = 0; i<q; i++){
		int t; cin >> t;
		if (t){
			int l, r, k; cin >> l >> r >> k;
			Q.emplace_back(t, l, r, k, -1);
			scaler.emplace_back(k);
		} else {
			int l1, l2, r1, r2; cin >> l1 >> r1 >> l2 >> r2;
			Q.emplace_back(0, l1, l2, r1, r2);
		}
	}
	for (auto [t, l1, l2, r1, r2]:Q){
		if (r2 == -1){

		}
	}
	while (q--){
		int t; cin >> t;
		if (t){
			int l, r, k; cin >> l >> r >> k;
			seg.update(1, 0, seg.size-1, l, r, k, t);
		} else {
			int l1, l2, r1, r2; cin >> l1 >> r1 >> l2 >> r2;
			node A = seg.query(1, 0, seg.size-1, l1, r1);
			node B = seg.query(1, 0, seg.size-1, l2, r2);
			// A.d();
			// B.d();
			bool ok = 1;
			ok &= (A.sum == B.sum);
			ok &= (A.min == B.min);
			ok &= (A.max == B.max);
			ok &= (A.xorr == B.xorr);
			if (ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}