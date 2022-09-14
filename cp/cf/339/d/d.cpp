/*
	Author: sysia
	12.01.2022 20:02:01
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

struct segtree{
	int size = 1;
	vll tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL); 
	}
	
	void build(int x, vi &a, int layer){
		if (!layer){
			tab[x] = a[x-size];
			return;
		}
		build(2*x, a, layer-1);
		build(2*x+1, a, layer-1);
		if (layer&1) tab[x] = tab[2*x]|tab[2*x+1];
		else tab[x] = tab[2*x]^tab[2*x+1];
	}
	
	void update(int x, int lx, int rx, int pos, int val, int layer){
		if (lx == rx){
			tab[x] = val;
			return;
		}
		int mid = (lx+rx)/2;
		if (pos <= mid) update(2*x, lx, mid, pos, val, layer-1);
		else update(2*x+1, mid+1, rx, pos, val, layer-1);
		if (layer&1) tab[x] = tab[2*x]|tab[2*x+1];
		else tab[x] = tab[2*x]^tab[2*x+1];
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vi a((1<<n));
	rep(i, 0, (1<<n)) cin >> a[i];
	segtree seg;
	seg.init((1<<n));
	seg.build(1, a, n);
	//for (auto x: seg.tab) debug(x);
	//cerr << "\n";
	
	while (q--){
		int pos, val; cin >> pos >> val;
		--pos;
		seg.update(1, 0, seg.size-1, pos, val, n);
		cout << seg.tab[1] << "\n";
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
