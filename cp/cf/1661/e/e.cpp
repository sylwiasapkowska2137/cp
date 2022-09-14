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

#define int long long
const int oo = 1e18;

struct segtree{
	vector<int>tab;
	vector<vector<int>>a;
	vector<int> prev, next;
	int size = 1;
	int N;

	segtree(int n, vector<vector<int>>&b){
		a = b, N = n;
		prev.assign(N, oo);
		next.assign(N, oo);
		int p = -oo;
		for (int i = 0; i<N; i++){
			if (a[1][i]){
				p = i;
			}
			prev[i] = p;
		}
		p = oo;
		for (int i = N-1; i>=0; i--){
			if (a[1][i]){
				p = i;
			}
			next[i] = p;
		}
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		build(1, 0, size-1);
	}

	int merge(int A, int b, int lx, int pos, int rx){ //pos, pos+1
		if (pos == N-1 || b == oo) return A;
		if (A == oo) return b;
		int cc = A+b;
		int sum = 0, st = 0, nd = 0;
		for (int j = 0; j<3; j++) sum += a[j][pos]+a[j][pos+1], st += a[j][pos], nd += a[j][pos+1];
		if (sum <= 1) return cc;
		if (sum == 2){
			bool ok = (a[0][pos]+a[0][pos+1] == 2 || a[1][pos]+a[1][pos+1] == 2 || a[2][pos]+a[2][pos+1] == 2);
			return cc-ok;
		} if (sum == 6)	return cc-1;
		else if (sum == 3){
			if (st == 3 || nd == 3) return cc;
			bool ok = 1;
			for (int i = 0; i<3; i++) ok &= (a[i][pos]^a[i][pos+1] == 1);
			if (ok) return cc;
			return cc-1;
		} else if (sum >= 4){
			cc--;
			if (a[0][pos]+a[0][pos+1]+a[2][pos]+a[2][pos+1] == 4){
				if (prev[pos] >= lx || next[pos+1] <= rx){
					cc--;
				}
				if (prev[pos] >= lx && next[pos+1] <= rx) cc++;
			} 
			return cc;
		}
	}

	void build(int x, int lx, int rx){
		if (lx == rx){
			if (lx < N) {
				if (a[0][lx] == 1 && a[1][lx] == 0 && a[2][lx] == 1) tab[x] = 2;
				else {
					bool ok = a[0][lx] || a[1][lx] || a[2][lx];
					tab[x] = ok;
				}
			} else {
				tab[x] = oo;
			}
			return;
		}
		int m = (lx+rx)/2;
		build(2*x, lx, m);
		build(2*x+1, m+1, rx);
		tab[x] = merge(tab[2*x], tab[2*x+1], lx, m, rx); //m ---- m+1
	}
	

	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return oo;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return merge(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r), lx, m, rx);
	}

};

void solve(){
	int n; cin >> n;
	vector<vector<int>>tab(3, vector<int>(n));
	for (int i = 0; i<3; i++){
		for (int j = 0; j<n; j++){
			char c; cin >> c;
			tab[i][j] = (int)(c-'0');
		}
	}
	segtree seg(n, tab);
	//debug(seg.tab);
	//return;
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		--l, --r;
		cout << seg.query(1, 0, seg.size-1, l, r) << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}
