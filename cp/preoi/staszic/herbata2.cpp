#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct segtree{
	int size = 1;
	vector <LL> tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void build(vector <LL> &a){
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>0; i--) tab[i] = tab[2*i] + tab[2*i+1];
	}
	
	void set(int pos, LL val){
		pos=pos+size-1;
		tab[pos] = val;
		while (pos>1){
			pos/=2;
			tab[pos] = tab[pos<<1]+tab[pos<<1|1];
		}
	}
	
	LL sum(int l, int r, int x, int lx, int rx){
		if (lx > r || l > rx) return 0;
		if (lx >= l && r >= rx) return tab[x];
		int m = (lx+rx)/2;
		return sum(l,r,2*x,lx,m)+sum(l,r,2*x+1,m+1,rx);
	}
};

int main(){
	fastio;
	int n, q, type, l, r;
	cin >> n >> q;
	vector <LL> arr(n), sq(n);
	for (int i = 0; i<n; i++) {
		cin >> arr[i];
		sq[i] = arr[i]*arr[i];
	}
	segtree seg;
	seg.init(n);
	seg.build(arr);
	segtree square;
	square.init(n);
	square.build(sq);
	while (q--){
		cin >> type >> l >> r;
		if (type == 0) {
			seg.set(l, r);
			square.set(l, r*r);
		} else {
			LL u = seg.sum(l, r, 1, 1, seg.size);
			LL v = square.sum(l, r, 1, 1, square.size);
			LL val = (u*u-v)/2;
			cout << val << "\n";
		}
	}
	return 0;
}
