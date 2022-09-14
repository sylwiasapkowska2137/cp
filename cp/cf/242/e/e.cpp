/*
	Author: sysia
	16.01.2022 14:20:22
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const int M = 21;

struct segtree{
	vll tab[M], lazy;
	int size = 1;
	
	void build(vi &a, int bit){
		int n = sz(a);
		while (size < n) size*=2;
		tab[bit].assign(2*size+1, 0);
		lazy.assign(2*size+1, 0);
		rep(i, 0, n){
			if (a[i]&(1<<bit)){
				tab[bit][i+size] = 1;
			}
		}
		repd(i, size-1, 1) tab[bit][i] = tab[bit][2*i]+tab[bit][2*i+1];
	}
	
	void push(int x, int lx, int rx){
		if (!lazy[x] || lx == rx) return;
		int len = rx-lx+1;
		rep(i, 0, M){
			if (lazy[x]&(1<<i)){
				tab[i][2*x] = len/2-tab[i][2*x];
				tab[i][2*x+1] = len/2-tab[i][2*x+1];
			}
		}
		lazy[2*x]^=lazy[x];
		lazy[2*x+1]^=lazy[x];
		lazy[x] = 0;
	}
	
	void invert(int x, int lx, int rx, int l, int r, int val){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			rep(i, 0, M){
				if (val&(1<<i)){
					tab[i][x] = rx-lx+1-tab[i][x];
				}
			}
			lazy[x]^=val;
			return;
		}
		int m = (lx+rx)/2;
		invert(2*x, lx, m, l, r, val);
		invert(2*x+1, m+1, rx, l, r, val);
		rep(i, 0, M) tab[i][x] = tab[i][2*x]+tab[i][2*x+1];
	}
	
	LL query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return 0LL;
		if (lx >= l && rx <= r){
			LL ans = 0LL;
			rep(i, 0, M) ans += (LL)(1LL<<i)*tab[i][x];
			return ans;
		}
		int m = (lx+rx)/2;
		return query(2*x, lx, m, l, r)+query(2*x+1, m+1, rx, l, r);
	}
} seg;

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, M) seg.build(a, i);
	int m; cin >> m;
	while (m--){
		int t; cin >> t;
		if (t == 1){
			int l, r; cin >> l >> r;
			--l;--r;
			cout << seg.query(1, 0, seg.size-1, l, r) << "\n";
		} else {
			int l, r, val; cin >> l >> r >> val;
			--l;--r;
			seg.invert(1, 0, seg.size-1, l, r, val);
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
