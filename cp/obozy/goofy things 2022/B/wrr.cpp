//Sylwia Sapkowska
#include <bits/stdc++.h>
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

const int oo = 1e9, K = 30;

struct segtree{
	vector<int>tab;
	tuple<int, int, int>base;
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}

	void query(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			if (tab[x] > val && get<0>(base) == -1){
				base = {x, lx, rx};
			}
			return;
		}
		int m = (lx+rx)/2;
		query(2*x, lx, m, l, r, val);
		query(2*x+1, m+1, rx, l, r, val);
	}

	int search(int x, int lx, int rx, int v){
		if (lx == rx) return x-size;
		int m = (lx+rx)/2;
		if (tab[2*x] > v) return search(2*x, lx, m, v);
		return search(2*x+1, m+1, rx, v);
	}
	
	int find(int l, int r, int v){
		base = {-1, -1, -1};
		query(1, 0, size-1, l, r, v);
		if (get<0>(base) == -1) return -1;
		return search(get<0>(base), get<1>(base), get<2>(base), v);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	segtree seg(n+1, a);
	int prev = 0;
	while (q--){
		int a, b; cin >> a >> b;
		int nowy = a+(prev%100);
		if (nowy <= n) a = nowy;
		int ans = seg.find(a, seg.size-1, b);
		if (ans == -1) ans = 0;
		cout << ans << "\n";
		prev = ans;
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
