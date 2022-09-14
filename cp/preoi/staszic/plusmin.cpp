#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "

struct segtree{
	vector <LL> operations; //indeksowanie od 1
	vector <LL> mins; 
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		operations.assign(2*size, 0LL);
		mins.assign(2*size, 0LL);
	}
	
	void add(int l, int r, int val, int x, int lx, int rx){
		if (lx > r || l > rx) return;
		if (lx >= l && r >= rx){
			mins[x]+=(LL)val;
			operations[x]+=(LL)val;
			return;
		}
		int m = (lx+rx)/2;
		add(l, r, val, 2*x, lx, m);
		add(l, r, val, 2*x+1, m+1, rx);
		mins[x] = min(mins[2*x], mins[2*x+1]) + operations[x];
	}
	
	LL query(int l, int r, int x, int lx, int rx){
		if (lx > r || l > rx) return LLONG_MAX;
		if (lx >= l && r >= rx) return mins[x];
		int m = (lx+rx)/2;
		return min(query(l, r, 2*x, lx, m), query(l, r, 2*x+1, m+1, rx)) + operations[x];
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q, t, l, r, v;
	cin >> n >> q;
	segtree seg;
	seg.init(n);
	while (q--){
		cin >> t;
		if (t == 1){
			cin >> l >> r >> v;
			seg.add(l+1, r, v, 1, 1, seg.size);
		} else {
			cin >> l >> r;
			cout << seg.query(l+1, r, 1, 1, seg.size) << "\n";
			//cerr << "\n";
		}
	}
	return 0;
}
