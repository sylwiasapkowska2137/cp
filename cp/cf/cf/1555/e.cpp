#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back

struct interval{
	int l, r, val;
};

bool cmp(interval a, interval b){ return a.val < b.val; }

struct segtree{
	vector<int>tab, lazy;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		lazy.assign(2*size+1, 0);
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x]+=lazy[x];
		tab[2*x+1]+=lazy[x];
		lazy[2*x]+=lazy[x];
		lazy[2*x+1]+=lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r) {
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
	
	int query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return INT_MAX;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<interval>a(n);
	segtree seg;
	seg.init(m);
	m--;
	for (int i = 0; i<n; i++){
		cin >> a[i].l >> a[i].r >> a[i].val;
		a[i].r--;
	}
	sort(a.begin(), a.end(), cmp);
	
	int koniec = 0, ans = INT_MAX;
	for (int start = 0; start<n; start++){
		while (koniec < n && seg.query(1, 1, seg.size, 1, m) <= 0) {
			seg.update(1, 1, seg.size, a[koniec].l, a[koniec].r, 1);
			koniec++;
		}
		if (seg.query(1, 1, seg.size, 1, m) >= 1) ans = min(ans, a[koniec-1].val - a[start].val);
		seg.update(1, 1, seg.size, a[start].l, a[start].r, -1);
	}
	cout << ans << "\n";
	return 0;
}
