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

struct segtree{
	vector<int>tab, lazy;
	int size = 1;

	segtree(int n){
		while (size < n+1) size*=2;
		tab.assign(2*size+1, 0);
		lazy.assign(2*size+1, 0);
		for (int i = 1; i<=n; i++) tab[i+size] = i;
		for (int i = size-1; i>=0; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, int v){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] += v;
			lazy[x] += v;
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
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	vector<pair<int, int>> b;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		b.emplace_back(a[i], i);
	}
	segtree seg(n);
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	vector<int>s(n+1, -1);
	for (auto [v, pos]:b){
		int x = seg.query(1, 0, seg.size-1, pos, n);
		if (x >= 2){
			s[pos] = 1;
			seg.update(1, 0, seg.size-1, pos, n, -2);
		} else if (x >= 1){
			s[pos] = 0;
			seg.update(1, 0, seg.size-1, pos, n, -1);
		}
	}
	int ans = 0;
	for (int i = 1; i<=n; i++) ans += s[i]*a[i];
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
