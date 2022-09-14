#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
	vi tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void update(int x, int lx, int rx, int pos, int val){
		if (lx == rx){
			tab[x] = max(tab[x], val);
			return;
		}
		int m = (lx+rx)/2;
		if (pos <= m) update(2*x, lx, m, pos, val);
		else update(2*x+1, m+1, rx, pos, val);
		tab[x] = max(tab[2*x], tab[2*x+1]);
	}
	
	int query(int x, int lx, int rx, int l, int r){
		if (lx>r || rx < l) return 0;
		if (lx>=l && rx<=r)	return tab[x];
		int m = (lx+rx)/2;
		return max(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void solve(){
	int n, d; cin >> n >> d;
	vi scaler, a, dp(n);
	rep(i, 0, n){
		int x; cin >> x;
		a.pb(x);
		scaler.pb(x);
		if (x-d>=1) scaler.pb(x-d);
		scaler.pb(x+d);
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int, int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	segtree seg;
	seg.init(sz(scaler));
	rep(i, 0, n){
		dp[i] = max(seg.query(1, 0, seg.size-1, 1, mapa[a[i]-d]), seg.query(1, 0, seg.size-1, mapa[a[i]+d], seg.size-1))+1;
		seg.update(1, 0, seg.size-1, a[i], dp[i]);
	}
	cout << seg.query(1, 0, seg.size-1, 0, seg.size-1) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
