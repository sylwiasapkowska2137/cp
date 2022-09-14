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

struct segment{
	int x, y1, y2, add;
	segment(int _x, int _y1, int _y2, int _add){
		x = _x, y1 = _y1, y2 = _y2, add = _add;
	}
};

struct segtree{
	vector<int>tab, lazy;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		lazy.assign(2*size+1, 0);
	}

	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int lx, int rx, int l, int r, int val){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r) {
			tab[x] += val;
			lazy[x] += val;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = max(tab[2*x],tab[2*x+1]);
	}
};

void solve(){
	int n; cin >> n;
	vector<segment>sweep;
	vector<int>scaler;
	for (int i = 0; i<n; i++){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		sweep.emplace_back(x1, y1, y2, 1);
		sweep.emplace_back(x2, y1, y2, -1);
		scaler.emplace_back(y1);
		scaler.emplace_back(y2);
	}
	sort(sweep.begin(), sweep.end(), [&](auto a, auto b){
		if (a.x == b.x) return a.add > b.add;
		return a.x < b.x;
	});
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	map<int, int>mapa;
	for (int i = 0; i<(int)scaler.size(); i++) mapa[scaler[i]] = i;
	int S = (int)scaler.size();
	segtree seg(S+2);
	
	int ans = 0;
	for (auto [x, y1, y2, add]:sweep){
		// debug(x, mapa[y1], mapa[y2], add);
		seg.update(1, 0, seg.size-1, mapa[y1], mapa[y2], add);
		ans = max(ans, seg.tab[1]);
	}
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
