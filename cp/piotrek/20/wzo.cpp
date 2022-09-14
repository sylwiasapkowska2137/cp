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
const int oo = 2e9+7;

struct dom{
	int a, b, p;
	dom(int _a = 0, int _b = 0, int _p = 0){
		a = _a, b = _b, p = _p;
	}
	void read(){cin >> a >> b >> p;}
};

struct segtree{
	vector<int>tab, diff, lazy;
	int size = 1;
	
	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		diff.assign(2*size, -1);
		lazy.assign(2*size, 0);
	}

	void push(int x, int lx, int rx){
		if (lazy[x] == 0 || lx == rx) return;
		lazy[2*x] = max(lazy[2*x], lazy[x]);
		lazy[2*x+1] = max(lazy[2*x+1], lazy[x]);
		diff[2*x] = max(diff[2*x], lazy[x]-tab[2*x]);
		diff[2*x+1] = max(diff[2*x+1], lazy[x]-tab[2*x+1]);
		lazy[x] = 0;
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return -oo;
		if (lx >= l && rx <= r) {
			// debug(x, lx, rx, diff[x], tab[x]);
			return diff[x];
		}
		int m = (lx+rx)/2;
		return max(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

	void set(int x, int lx, int rx, int pos, int v){
		if (lx == rx) {
			tab[x] = v;
			lazy[x] = 0;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		if (pos <= m) set(2*x, lx, m, pos, v);
		else set(2*x+1, m+1, rx, pos, v);
		tab[x] = min(tab[2*x], tab[2*x+1]);
		diff[x] = max(diff[2*x], diff[2*x+1]);
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			lazy[x] = max(lazy[x], v);
			// debug(lazy[x], tab[x], diff[x], lazy[x]-tab[x]);
			diff[x] = max(diff[x], lazy[x]-tab[x]);
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = min(tab[2*x], tab[2*x+1]);
		diff[x] = max(diff[2*x], diff[2*x+1]);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<dom>a(n);
	for (int i = 0; i<n; i++) a[i].read();
	
	vector<pair<int, int>>que(q);
	vector<int>ans(q, -1);
	for (auto &[x, y]: que) {
		cin >> x >> y;
		x--;y--;
	}

	auto calc = [&]{
		vector<vector<pair<int, int>>>sweep(n+2);
		vector<vector<pair<int, int>>>Q(n+1);
		for (int i = 0; i<q; i++) Q[que[i].second].emplace_back(que[i].first, i);
		segtree seg(n+1);
		for (int i = 0; i<n; i++){
			// debug(sweep[i]);
			// debug(i);
			for (auto [pos, type]: sweep[i]){
				if (type) seg.set(1, 0, seg.size-1, pos, a[pos].p);
				else seg.set(1, 0, seg.size-1, pos, oo);
			}
			if (i + a[i].a < n) sweep[i+a[i].a].emplace_back(i, 1);
			if (i + a[i].b + 1 < n) sweep[i+a[i].b+1].emplace_back(i, 0);
			if (i-a[i].a >= 0) seg.update(1, 0, seg.size-1, max(0, i-a[i].b), i-a[i].a, a[i].p);
			for (auto [l, idx]:Q[i]) ans[idx] = max(ans[idx], seg.query(1, 0, seg.size-1, l, i));
		}
	};

	calc();
	for (auto &[a, b]:que){
		a = n-a-1;
		b = n-b-1;
		swap(a, b);
		// debug(a, b);
	}
	reverse(a.begin(), a.end());
	calc();
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
