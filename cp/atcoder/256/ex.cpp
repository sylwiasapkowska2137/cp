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
		lazy.assign(2*size+1, -1);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = tab[2*i]+tab[2*i+1];
	}

	void push(int x, int lx, int rx){
		if (lx == rx || lazy[x] == -1) return;
		tab[2*x] = lazy[x];
		tab[2*x+1] = lazy[x];
		lazy[2*x] = lazy[x];
		lazy[2*x+1] = lazy[x];
		lazy[x] = -1;
	}

	void set(int x, int lx, int rx, int l, int r, int val){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r) {
			tab[x] = (rx-lx+1)*val;
			lazy[x] = val;
			return;
		}
		int m = (lx+rx)/2;
		set(2*x, lx, m, l, r, val);
		set(2*x+1, m+1, rx, l, r, val);
		tab[x] = tab[2*x]+tab[2*x+1];
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	segtree seg(n+1, a);
	set<pair<int, int>>s;
	s.insert({1, a[1]});
	for (int r = 2; r<=n; r++){
		if (a[r] != a[r-1]){
			s.insert({r, a[r]});
		}
	}
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r, xx; cin >> l >> r >> xx;
			vector<pair<int, int>>check;
			auto it = s.lower_bound({l, 0});
			if (it != s.begin()) {
				auto it2 = prev(it);
				check.emplace_back(*it2);
				s.erase(it2);
			}
			while (1){
				auto it = s.lower_bound({l, 0});
				if (it == s.end()) break;
				check.emplace_back(*it);
				s.erase(it);
				if (it->first > r) break;
			}
			// debug(check);
			for (int i = 0; i<(int)check.size(); i++){
				int R = (i == (check.size()-1)?n:check[i+1].first-1);
				int L = check[i].first;
				
				if (R < l || L > r) {
					s.insert(check[i]);
					continue;
				}
				// debug(L, R);
				if (L < l){
					s.insert({L, check[i].second});
					seg.set(1, 0, seg.size-1, l, min(R, r), check[i].second/xx);
					s.insert({l, check[i].second/xx});
					if (R > r && R!=n) s.insert({R+1, check[i].second});
				} else {
					if (L != l) s.insert({l, check[i].second});
					s.insert({L, check[i].second/xx});
					if (R <= r){
						seg.set(1, 0, seg.size-1, L, R, check[i].second/xx);
					} else {
						seg.set(1, 0, seg.size-1, L, r, check[i].second/xx);
						if (r+1 != n) s.insert({r+1, check[i].second});
					}
				}
			}
			// debug(s);
			
		}
		
		if (t == 2){
			int l, r, y; cin >> l  >> r >> y;
			vector<pair<int, int>>check;
			auto it = s.lower_bound({l, 0});
			if (it != s.begin()) {
				auto it2 = prev(it);
				check.emplace_back(*it2);
				s.erase(it2);
			}
			while (1){
				auto it = s.lower_bound({l, 0});
				if (it == s.end()) break;
				check.emplace_back(*it);
				s.erase(it);
				if (it->first > r) break;
			}
			debug(check);
			for (int i = 0; i<(int)check.size(); i++){
				int R = (i == (check.size()-1)?n:check[i+1].first-1);
				int L = check[i].first;
				
				if (R < l || L > r) {
					s.insert(check[i]);
					continue;
				}
				// debug(L, R);
				if (L < l){
					s.insert({L, check[i].second});
					seg.set(1, 0, seg.size-1, l, min(R, r), y);
					s.insert({l, y});
					if (R > r && R!=n) s.insert({R+1, check[i].second});
				} else {
					if (L != l) s.insert({l, check[i].second});
					s.insert({L, y});
					if (R <= r){
						seg.set(1, 0, seg.size-1, L, R, y);
					} else {
						seg.set(1, 0, seg.size-1, L, r, y);
						if (r+1 != n) s.insert({r+1, check[i].second});
					}
				}
			}
			// debug(s);
		}
		if (t == 3){
			int l, r; cin >> l >> r;
			cout << seg.query(1, 0, seg.size-1, l, r) << "\n";
		}
		debug(s);
		// cerr << "\n";
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
