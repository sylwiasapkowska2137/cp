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

#define int long long
const int oo = 1e18, K = 30;

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
		int len = (rx-lx+1)/2;
		tab[2*x] += lazy[x]*len;
		tab[2*x+1] += lazy[x]*len;
		lazy[2*x] = lazy[x];
		lazy[2*x+1] = lazy[x];
		lazy[x] = 0;
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (l > rx || lx > r) return 0;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		push(x, lx, rx);
		if (l > rx || lx > r) return;
		if (lx >= l && rx <= r) {
			tab[x] += (rx-lx+1)*v;
			lazy[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = tab[2*x]+tab[2*x+1];
	}
};

struct segment{
	int x, y1, y2, add;
	segment(int _x = 0, int _y1 = 0, int _y2 = 0, int _add = 0){
		x = _x, y1 = _y1, y2 = _y2, add = _add;
	}
};

struct rect{
	int x1, x2, y1, y2;
	void read(){
		cin >> x1 >> y1 >> x2 >> y2;
	}
};

void solve(){
	int n, m, q; cin >> n >> m >> q;
	segtree seg((1<<18));
	vector<segment>sweepx, sweepy;
	vector<rect>rec(n);
	for (int i = 0; i<n; i++){
		rec[i].read();
		// sweepx.emplace_back(rec[i].x1, rec[i].y1, rec[i].y1, 1);
		// sweepx.emplace_back(rec[i].x2, rec[i].y2+1, rec[i].y2+1, -1);
	}
	for (int i = 0; i<m; i++){
		int v, x, d; cin >> v >> x >> d;
		x--;
		if (v == 0){ //w prawo
			
		}
		if (v == 2){//w gore
			sweepx.emplace_back(rec[x].x1, rec[x].y1, rec[x].y1+d, 1);
			sweepx.emplace_back(rec[x].x1, rec[x].y2+1, rec[x].y2+d+1, -1);

			sweepx.emplace_back(rec[x].x2, rec[x].y1, rec[x].y1+d, -1);
			sweepx.emplace_back(rec[x].x2, rec[x].y2+1, rec[x].y2+d+1, 1);
		}	
		if (v == 4){//w lewo
			
		}
		if (v == 6){//w dol
			sweepx.emplace_back(rec[x].x1, rec[x].y1-d-1, rec[x].y1-1, 1);
			sweepx.emplace_back(rec[x].x1, rec[x].y2-d, rec[x].y2, -1);

			sweepx.emplace_back(rec[x].x2, rec[x].y1-d-1, rec[x].y1-1, -1);
			sweepx.emplace_back(rec[x].x2, rec[x].y2-d, rec[x].y2, 1);
		}
	}
	vector<pair<int, int>>query(q);
	for (int i = 0; i<q; i++){
		cin >> query[i].first >> query[i].second;
		sweepx.emplace_back(query[i].first, query[i].second, i, 0);
	}
	sort(sweepx.begin(), sweepx.end(), [&](auto a, auto b){
		if (a.x == b.x) return a.add > b.add;
		return a.x < b.x;
	});
	vector<int>ans(q);
	for (auto [x, y1, y2, add]:sweepx){
		debug(x, y1, y2, add);
		if (add == 0) ans[y2] = seg.query(1, 0, seg.size-1, 0, y1);
		else seg.update(1, 0, seg.size-1, y1, y2, add);
	}
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
