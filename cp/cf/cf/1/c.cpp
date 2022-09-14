#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
#define debug(x) cerr << x << " "

struct segtree{
	vll tab, lazy;
	int size = 1;
	
	void init(int n, vll a){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		lazy.assign(2*size, 0);
		rep(i, 0, sz(a)) tab[i+size] = a[i];
		repd(i, size-1, 1) tab[i] = min(tab[2*i], tab[2*i+1]);
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, LL val){
		if (lx > r || rx < l) return;
		if (lx>=l && rx<=r){
			tab[x]+=val;
			lazy[x]+=val;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}
	
	LL query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return LLONG_MAX;
		if (lx>=l && rx<=r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void solve(){
	int n; cin >> n;
	vll a(n);
	rep(i, 0, n) cin >> a[i];
	segtree seg;
	seg.init(n, a);
	int m; cin >> m;
	while (m--){
		string s; getline(cin, s);
		int l, r, val;
		int x = 0;
		bool is = 0;
		rep(i, 0, sz(s)) if (s[i]==' ') x++;
		if (x == 2) is = 1;
		int k = 0;
		rep(i, 0, x+1){
			string tmp;
			while (k<sz(s) && s[k]!=' '){
				tmp+=s[k];
				k++;
			}
			if (i == 0) l = stoi(tmp);
			else if (i == 1) r = stoi(tmp);
			else val = stoi(tmp);
			k++;
		}
		
		if (is){
			if (r>=l) cout << seg.query(1, 0, seg.size-1, l, r) << "\n";
			else cout << min(seg.query(1, 0, seg.size-1, 0, r), seg.query(1, 0, seg.size-1, l, seg.size-1)) << "\n";
		} else {
			LL val;cin >> val;
			if (r>=l) seg.update(1, 1, seg.size-1, l, r, val);
			else {
				seg.update(1, 1, seg.size-1, 0, r, val);
				seg.update(1, 1, seg.size-1, l, seg.size-1, val);
			}
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
