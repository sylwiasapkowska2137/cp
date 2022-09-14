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
	vector<vector<pair<int, int>>>g;
	int n, size = 1;

	segtree(int N){
		n = N;
		while (size < n) size*=2;
		g.resize(5*size);
		for (int i = 1; i<size; i++){
			g[i].emplace_back(2*i, 0);
			g[i].emplace_back(2*i+1, 0);
			if (2*i >= size){
				//od lisci w gore
				g[2*i].emplace_back(i+2*size, 0);
				g[2*i+1].emplace_back(i+2*size, 0);
			} else {
				g[2*i+2*size].emplace_back(i+2*size, 0);
				g[2*i+1+2*size].emplace_back(i+2*size, 0);
			}
		}
		
	}

	void dijkstra(int src){
		src+=size;
		vector<int>dist(5*size, oo);
		set<pair<int, int>>s;
		s.insert({0, src});
		dist[src] = 0;
		while (!s.empty()){
			int d = s.begin()->first;
			int v = s.begin()->second;
			s.erase(s.begin());
			if (dist[v] < d) continue;
			for (auto [x, c]:g[v]){
				if (d+c < dist[x]){
					dist[x] = d+c;
					s.insert({dist[x], x});
				}
			}
		}
		for (int i = 1; i<=n; i++){
			if (dist[i+size] == oo) cout << "-1 ";
			else cout << dist[i+size] << " ";
		}
		cout << "\n";
	}

	void update_up(int x, int lx, int rx, int l, int r, int w, int from){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			g[from+size].emplace_back(x, w);
			return;
		}
		int m = (lx+rx)/2;
		update_up(2*x, lx, m, l, r, w, from);
		update_up(2*x+1, m+1, rx, l, r, w, from);
	}

	void update_down(int x, int lx, int rx, int l, int r, int w, int from){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			if (lx == rx) g[x].emplace_back(from+size, w);
			else g[x+2*size].emplace_back(from+size, w);
			return;
		}
		int m = (lx+rx)/2;
		update_down(2*x, lx, m, l, r, w, from);
		update_down(2*x+1, m+1, rx, l, r, w, from);
	}

	void print(){
		for (int i = 1; i<(int)g.size(); i++){
			if (g[i].empty()) continue;
			debug(i, g[i]);
		}
	}
};

void solve(){
	int n, q, s; cin >> n >> q >> s;
	segtree seg(n);
	// seg.print();
	// cerr << endl;
	while(q--){
		int t; cin >> t;
		if (t == 1){
			int v, u, w; cin >> v >> u >> w;
			seg.update_up(1, 0, seg.size-1, u, u, w, v);
		} else {
			int v, l, r, w; cin >> v >> l >> r >> w;
			if (t == 2)	seg.update_up(1, 0, seg.size-1, l, r, w, v);
			else seg.update_down(1, 0, seg.size-1, l, r, w, v);
		}
	}
	// seg.print();
	seg.dijkstra(s);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
