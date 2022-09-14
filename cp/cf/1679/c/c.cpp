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
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void update(int x, int lx, int rx, int pos, int v){
		if (lx == rx){
			tab[x] += v;
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) update(2*x, lx, m, pos, v);
		else update(2*x+1, m+1, rx, pos, v);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}

	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return oo;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void solve(){
	int n, q; cin >> n >> q;
	segtree poziom(n+1), pion(n+1);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int x, y; cin >> x >> y;
			poziom.update(1, 0, poziom.size-1, x, 1);
			pion.update(1, 0, pion.size-1, y, 1);
		} else if (t == 2){
			int x, y; cin >> x >> y;
			poziom.update(1, 0, poziom.size-1, x, -1);
			pion.update(1, 0, pion.size-1, y, -1);
		} else {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			int x = poziom.query(1, 0, poziom.size-1, x1, x2);
			int y = pion.query(1, 0, pion.size-1, y1, y2);
			if (x > 0 || y > 0) cout << "Yes\n";
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
