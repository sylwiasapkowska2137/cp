#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define pb push_back
#define st first
#define nd second

const int MAX = 2e5+7;
const LL INF = 1e18;
vector<pii>koniec[MAX];

struct segtree{
	int size = 1;
	vector<LL>tab, lazy;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		lazy.assign(2*size+1, 0);
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
		if (lx >= l && rx <= r){
			tab[x]+=val;
			lazy[x]+=val;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = max(tab[2*x], tab[2*x+1]);
	}
	
	LL query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return -INF;
		if (lx >= l && rx <= r) return tab[x];
		//push(x, lx, rx);
		int m = (lx+rx)/2;
		return max(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
	
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, l, r, val;
	cin >> n >> m;
	vector<LL>start(n+2, 0);
	for (int i = 0; i<m; i++){
		cin >> l >> r >> val;
		start[l]+=val;
		koniec[r+1].pb({l, val});
	}
	segtree seg;
	seg.init(n+2);
	for (int i = 1; i<=n+1; i++){
		seg.update(1, 0, seg.size-1, 0, i-1, start[i]);
		for (auto x: koniec[i]) seg.update(1, 0, seg.size-1, 0, x.st-1, -x.nd);
		seg.update(1, 0, seg.size-1, i, i, seg.query(1, 0, seg.size-1, 0, i-1));
	}
	cout << seg.query(1, 0, seg.size-1, 0, seg.size-1) << "\n";
	return 0;
}
