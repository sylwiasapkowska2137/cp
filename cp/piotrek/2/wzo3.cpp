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
const int oo = 1e9+7, K = 30;

struct segtree{
	vector<int>tab, lazy;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, -oo);
		lazy.assign(2*size, 0);
	}

	void push(int x, int lx, int rx){
		if (lx == rx || !lazy[x]) return;
		tab[2*x] = lazy[x];
		tab[2*x+1] = lazy[x];
		lazy[2*x] = lazy[x];
		lazy[2*x+1] = lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int lx, int rx, int l, int r, int v, bool f){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			if (!f){
				tab[x] = max(tab[x], v); 
				return;
			}
			tab[x] = v;
			lazy[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v, f);
		update(2*x+1, m+1, rx, l, r, v, f);
		tab[x] = max(tab[2*x], tab[2*x+1]);
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return -oo;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return max(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

struct segmin{
	vector<int>tab, lazy;
	int size = 1;

	segmin(int n){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		lazy.assign(2*size, oo);
	}

	void push(int x, int lx, int rx){
		if (lx == rx || lazy[x] == oo) return;
		tab[2*x] = lazy[x];
		tab[2*x+1] = lazy[x];
		lazy[2*x] = lazy[x];
		lazy[2*x+1] = lazy[x];
		lazy[x] = oo;
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] = v;
			lazy[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return oo;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

	pair<int, int> erase(){
		int L = left(1, 0, size-1);
		int R = right(1, 0, size-1);
		update(1, 0, size-1, L, R, oo);
		return {L, R};
	}

	int left(int x, int lx, int rx){
		if (lx == rx) return lx;
		int m = (lx+rx)/2;
		push(x, lx, rx);
		if (tab[2*x] <= tab[2*x+1]) return left(2*x, lx, m);
		else return left(2*x+1, m+1, rx);
	}

	int right(int x, int lx, int rx){
		if (lx == rx) return lx;
		int m = (lx+rx)/2;
		push(x, lx, rx);
		if (tab[2*x] >= tab[2*x+1]) return right(2*x+1, m+1, rx);
		else return right(2*x, lx, m);
	}
};

void solve(){
	int n, d; cin >> n >> d;
	vector<int>a(n+1), ss;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		ss.emplace_back(a[i]);
	}
	sort(ss.begin(), ss.end());
	ss.erase(unique(ss.begin(), ss.end()), ss.end());
	for (int i = 1; i<=n; i++){
		a[i] = (int)(lower_bound(ss.begin(), ss.end(), a[i])-ss.begin())+1;
	}
	segtree seg(n+1);
	segmin czas(n+1);
	for (int i = 1; i<=n; i++){
		if (czas.tab[1] < i-d) {
			auto [lx, rx] = czas.erase();
			debug(lx, rx);
			seg.update(1, 0, seg.size-1, lx, rx, -oo, 1);
		}
		// int x = seg.query(1, 0, seg.size-1, a[i], n);
		czas.update(1, 0, czas.size-1, a[i], n, i);
		int curr = max(0, seg.query(1, 0, seg.size-1, 0, a[i]-1))+1;
		seg.update(1, 0, seg.size-1, a[i], a[i], curr, 0);
		// print(i);
	}
	cout << seg.query(1, 0, seg.size-1, 0, n) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
