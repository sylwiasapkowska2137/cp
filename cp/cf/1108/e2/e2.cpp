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
	vector<pair<int, int>>tab;
	vector<int>lazy;
	int size = 1;

	pair<int, int>merge(pair<int, int>a, pair<int, int>b){
		if (a.first == b.first) return {a.first, a.second+b.second};
		return max(a, b);
	}

	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x].first += lazy[x];
		tab[2*x+1].first += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, {-oo, oo});
		lazy.assign(2*size+1, 0);
		for (int i = 0; i<n; i++) tab[i+size] = {a[i], 1};
		for (int i = size-1; i>=1; i--){
			tab[i] = merge(tab[2*i], tab[2*i+1]);
		}
	}

	void update(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x].first--;
			lazy[x]--;
			return;
		} 
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r);
		update(2*x+1, m+1, rx, l, r);
		tab[x] = merge(tab[2*x], tab[2*x+1]);
	}

	pair<int, int>query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return {-oo, oo};
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return merge(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n);
	vector<pair<int, int>>tab;
	for (int i = 0; i<n; i++) cin >> a[i];
	segtree seg(n, a);
	vector<int>ans;
	for (int i = 0; i<m; i++){
		int l, r; cin >> l >> r;
		--l, --r;
		pair<int, int> t = seg.query(1, 0, seg.size-1, l, r);
		if ((seg.tab[1].first > t.first) || (seg.tab[1].first == t.first && seg.tab[1].second > t.second)){
			seg.update(1, 0, seg.size-1, l, r);
			ans.emplace_back(i+1);
		}
	}
	vector<int>b(n);
	for (int i = 0; i<n; i++) b[i] = seg.query(1, 0, seg.size-1, i, i).first;
	int m1 = *min_element(b.begin(), b.end());
	int m2 = *max_element(b.begin(), b.end());
	cout << m2-m1 << "\n" << (int)ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}