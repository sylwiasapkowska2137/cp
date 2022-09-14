//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

struct segtree{
	vll sum, maxi;
	int size = 1;
	
	void init(int n, vi&a){
		while (size < n) size*=2;
		sum.assign(2*size+1, 0);
		maxi.assign(2*size+1, 0);
		rep(i, 0, n) sum[i+size] = maxi[i+size] = a[i];
		repd(i, size-1, 1) {
			sum[i] = sum[2*i]+sum[2*i+1];
			maxi[i] = max(maxi[2*i], maxi[2*i+1]);
		}
	}
	
	void mod(int x, int lx, int rx, int l, int r, int v){
		if (lx > r || rx < l || maxi[x] < v) return;
		if (lx == rx){
			int val = maxi[x]%v;
			maxi[x] = sum[x] = val;
			return;
		}
		int m = (lx+rx)/2;
		mod(2*x, lx, m, l, r, v);
		mod(2*x+1, m+1, rx, l, r, v);
		sum[x] = sum[2*x]+sum[2*x+1];
		maxi[x] = max(maxi[2*x], maxi[2*x+1]);
	}
	
	void update(int x, int lx, int rx, int pos, int val){
		if (lx == rx){
			sum[x] = val;
			maxi[x] = val;
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) update(2*x, lx, m, pos, val);
		else update(2*x+1, m+1, rx, pos, val);
		sum[x] = sum[2*x]+sum[2*x+1];
		maxi[x] = max(maxi[2*x], maxi[2*x+1]);
	}
	
	LL query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return 0;
		if (lx >= l && rx <= r) return sum[x];
		int m = (lx+rx)/2;
		//maciuś tu był 
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	segtree seg;
	seg.init(n, a);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r; cin >> l >> r;
			--l;--r;
			cout << seg.query(1, 0, seg.size-1, l, r) << "\n";
		}
		if (t == 2){
			int l, r, x; cin >> l >> r >> x;
			--l;--r;
			seg.mod(1, 0, seg.size-1, l, r, x);
		}
		if (t == 3){
			int pos; LL val; cin >> pos >> val;
			--pos;
			seg.update(1, 0, seg.size-1, pos, val);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
