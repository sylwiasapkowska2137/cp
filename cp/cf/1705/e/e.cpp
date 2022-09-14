//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
const int M = 2e5+100;
// const int M = 10;

int msb(int x){
	for (int i = K-1; i>=0; i--){
		if (x&(1<<i)){
			return i;
		}
	}
	assert(false);
}

struct segtree{
	vector<int>tab, lazy;
	int size = 1;

	segtree(int n, vector<int>&cnt){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		lazy.assign(2*size, -1);
		for (int i = 0; i<(int)cnt.size(); i++) tab[i+size] = cnt[i];
		for (int i = size-1; i>=0; i--) tab[i] = tab[2*i]+tab[2*i+1];
	}

	void push(int x, int lx, int rx){
		if (lazy[x] == -1 || lx == rx) return;
		lazy[2*x] = lazy[x];
		lazy[2*x+1] = lazy[x];
		int h = (rx-lx+1)/2;
		tab[2*x] = lazy[x]*h;
		tab[2*x+1] = lazy[x]*h;
		lazy[x] = -1;
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] = (rx-lx+1)*v;
			lazy[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = tab[2*x]+tab[2*x+1];
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}

	void set(int x, int lx, int rx, int pos, int v){
		if (lx == rx){
			tab[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		push(x, lx, rx);
		if (pos <= m) set(2*x, lx, m, pos, v);
		else set(2*x+1, m+1, rx, pos, v);
		tab[x] = tab[2*x] + tab[2*x+1];
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	vector<int>cnt(M+1, 0);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i<M; i++){
		while (cnt[i]>1) {
			cnt[i+1]++;
			cnt[i]-=2;
		}
	}
	segtree seg(M+2, cnt);
	while (q--){
		int pos, val; cin >> pos >> val;
		int prev = a[pos];
		if (seg.query(1, 0, seg.size-1, prev, prev) == 1){
			seg.set(1, 0, seg.size-1, prev, 0);
		} else {
			int l = prev, r = M, ans = M;
			while (r>=l){
				int mid = (l+r)/2;
				if (seg.query(1, 0, seg.size-1, prev, mid) > 0){
					ans = mid;
					r = mid-1;
				} else {
					l = mid+1;
				}
			}
			seg.set(1, 0, seg.size-1, ans, 0);
			seg.update(1, 0, seg.size-1, prev, ans-1, 1);
		}
		a[pos] = val;
		if (seg.query(1, 0, seg.size-1, val, val) == 0){
			seg.set(1, 0, seg.size-1, val, 1);
		} else {
			int l = val, r = M, ans = M;
			while (r>=l){
				int mid = (l+r)/2;
				if (seg.query(1, 0, seg.size-1, val, mid) == mid-val+1){
					l = mid+1;
				} else {
					ans = mid;
					r = mid-1;
				}
			}
			seg.set(1, 0, seg.size-1, ans, 1);
			seg.update(1, 0, seg.size-1, val, ans-1, 0);
		}
		int l = 1, r = M, ans = M;
		while (r>=l){
			int mid = (l+r)/2;
			if (seg.query(1, 0, seg.size-1, 0, mid) == seg.tab[1]){
				ans = mid;
				r = mid-1;
			} else l = mid+1;
		}
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}