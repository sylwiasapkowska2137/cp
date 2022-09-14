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
#define memo(x) memset(x, 0, sizeof(x))

#define PI 3.14159265359

void debug(LL x){
	if (x <= -1e18) cerr << "x ";
	else cerr << x << " ";
}

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const LL INF = 1e18;

struct Node{
	LL val11 = -INF, val12 = -INF, val21 = -INF, val22 = -INF;
};

struct segtree{
	vector<Node>tab;
	int size = 1;
	
	Node leaf(int v, int val){
		if (v&1) return {-INF, -INF, -INF, val};
		return {val, -INF, -INF, -INF};
	}
	
	Node merge(Node a, Node b){
		Node ans;
		ans.val11 = max(max(a.val12+b.val11, a.val11+b.val21), max(a.val11, b.val11));
		ans.val12 = max(max(a.val12+b.val12, a.val11+b.val22), max(a.val12, b.val12));
		ans.val21 = max(max(a.val22+b.val11, a.val21+b.val21), max(a.val21, b.val21));
		ans.val22 = max(max(a.val22+b.val12, a.val21+b.val22), max(a.val22, b.val22));
		return ans;
	}
	
	void init(int n){
		while (size < n) size*=2;
		tab.resize(2*size+2);
	}
	
	void build(vi &a){
		rep(i, 0, sz(a)) tab[i+size] = leaf(i+1, a[i]);
		repd(i, size-1, 0) tab[i] = merge(tab[2*i], tab[2*i+1]);
	}
	
	void update(int x, int lx, int rx, int pos, int val){
		if (lx == rx){
			tab[x] = leaf(pos+1, val);
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) update(2*x, lx, m, pos, val);
		else update(2*x+1, m+1, rx, pos, val);
		tab[x] = merge(tab[2*x], tab[2*x+1]);
	}
	
	Node query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return {-INF, -INF, -INF, -INF};
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return merge(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	segtree seg;
	seg.init(n+1);
	seg.build(a);
	//return;
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int pos, val; cin >> pos >> val;
			seg.update(1, 0, seg.size-1, pos-1, val);
		} else{
			int l, r; cin >> l >> r;
			--l;--r;
			Node x = seg.query(1, 0, seg.size-1, l, r);
			cout << max(max(x.val11, x.val22), max(x.val12, x.val21)) << "\n";
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
