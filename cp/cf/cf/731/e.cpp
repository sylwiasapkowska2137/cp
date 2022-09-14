#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)
const LL INF = 1e18;

struct segtree{
	vector<LL>tab, lazy;
	int size = 1;
	
	void init(int n, vector<pii>&a){
		tab.clear();
		lazy.clear();
		size = 1;
		while (size < n) size*=2;
		tab.assign(2*size+1, INF);
		lazy.assign(2*size+1, 0LL);
		for (int i = 0; i<(int)a.size(); i++) tab[size+a[i].st-1] = (LL)a[i].st+a[i].nd-1;
		for (int i = size-1; i>0; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
		//for (auto x: tab) debug(x);
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x]+=lazy[x];
		tab[2*x+1]+=lazy[x];
		lazy[2*x]+=lazy[x];
		lazy[2*x+1]+=lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, LL val){
		if (lx > r || l > rx) return;
		if (lx >= l && rx <= r){
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
		if (lx > r || l > rx) return LLONG_MAX;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};


segtree seg;

void solve(){
	string s;
	getline(cin, s);
	int n, k;
	cin >> n >> k;
	vector<pii>a(k);
	vector<LL>ans(n+1);
	rep(i, 0, k) cin >> a[i].st;
	rep(i, 0, k) cin >> a[i].nd;
	seg.init(n+2, a);
	rep(i, 1, n+1){
		ans[i] = seg.query(1, 1, seg.size, 1, n+1);
		seg.update(1, 1, seg.size, 1, i, 1);
		seg.update(1, 1, seg.size, i+1, n+1, -1);
	}
	rep(i, 1, n+1) cout << ans[i] << ' ';
	cout << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}

