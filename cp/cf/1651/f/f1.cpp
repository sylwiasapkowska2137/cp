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

#define int long long
const int oo = 1e18, K = 30;

struct TreeSum{
	vector<int>tab, lazy;
	int size = 1;

	int f(int a, int b){return a+b;}

	TreeSum(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]);
		lazy.assign(2*size, 0);
	}

	void push(int x, int lx, int rx){
		if (!lazy[x] || lx == rx) return;
		tab[2*x] = tab[2*x+1] = 0;
		lazy[2*x] = lazy[2*x+1] = 1;
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] = 0;
			lazy[x] = 1;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r);
		update(2*x+1, m+1, rx, l, r);
		tab[x] = f(tab[2*x], tab[2*x+1]);
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return f(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void solve(){
	int n; cin >> n;
	vector<int>c(n+1), r(n+1), pR(n+1);
	for (int i = 1; i<=n; i++){
		cin >> c[i] >> r[i];
		pR[i] = pR[i-1] + r[i];
	}
	vector<int>curr = c;
	int prev = 0;
	const int mx = 12;
	vector<int>que(mx, -1);
	int q; cin >> q;
	for (int i = 0; i<q; i++){
		int t, h; cin >> t >> h;
		que[t] = h;
	}
	int ans = 0;
	TreeSum seg(n+1, c);
	for (int i = 0; i<mx; i++){
		if (que[i] == -1) continue;
		int all = seg.query(1, 0, seg.size-1, 1, n) + (i-prev)*pR[n];
		debug(all);
		int H = que[i];
		if (H > all){
			seg.update(1, 0, seg.size-1, 1, n);
		} else {
			
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}