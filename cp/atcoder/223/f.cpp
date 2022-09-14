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

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		lazy.assign(2*size+1, 0);
		for (int i = 0; i<n;i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return oo;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}

	void update(int x, int lx, int rx, int l, int r, int val){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] += val;
			lazy[x] += val;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}

	int value(int x, int lx, int rx, int pos){
		if (lx == rx) return tab[x];
		push(x, lx, rx);
		int m = (lx+rx)/2;
		if (pos <= m) return value(2*x, lx, m, pos);
		else return value(2*x+1, m+1, rx, pos);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<int>pref(n);
	for (int i = 0; i<n; i++){
		if (s[i] == '(') pref[i]++;
		else pref[i]--;
		if (i) pref[i]+=pref[i-1];
	}
	segtree seg(n, pref);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r; cin >> l >> r;
			l--;r--;
			if (s[l] == s[r]) continue;
			swap(s[l], s[r]);
			if (s[r] == ')') {
				seg.update(1, 0, seg.size-1, r, n-1, 2);
				seg.update(1, 0, seg.size-1, l, r-1, -2);
			} else {
				seg.update(1, 0, seg.size-1, r, n-1, -2);
				seg.update(1, 0, seg.size-1, l, r-1, 2);
			}
		} else {
			int l, r; cin >> l >> r;
			l--;r--;
			int x = seg.query(1, 0, seg.size-1, l, r);
			int y = (l?seg.value(1, 0, seg.size-1, l-1):0);
			if (x-y == 0) cout << "Yes\n";
			else cout << "No\n";
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
