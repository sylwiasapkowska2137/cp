#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
const LL MOD = 1e9+7;

struct segtree{
	vector <LL> operations, values;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		operations.assign(2*size, 0LL);
		values.assign(2*size, 0LL);
	}
	
	LL modify(LL a, LL b, LL len){
		return a+(b*len);
	}
	LL calc(LL a, LL b){
		return a+b;
	}
	
	void propagate(int x, int lx, int rx){
		if (rx == lx) return;
		int m = (lx+rx)/2;
		values[2*x] = modify(values[2*x], operations[x], m-lx+1);
		values[2*x+1] = modify(values[2*x+1], operations[x], rx-m);
		operations[2*x] = modify(operations[2*x], operations[x], 1);
		operations[2*x+1] = modify(operations[2*x+1], operations[x], 1);
		operations[x] = 0;
	}
	
	void update(int l, int r, int val, int x, int lx, int rx){
		propagate(x, lx, rx);
		if (lx > r || l > rx) return;
		if (lx >= l && r >= rx){
			operations[x] = modify(operations[x], val, 1);
			values[x] = modify(values[x], val, rx-lx+1);
			return;
		}
		int m = (lx+rx)/2;
		update(l, r, val, 2*x, lx, m);
		update(l, r, val, 2*x+1, m+1, rx);
		values[x] = calc(values[2*x], values[2*x+1]);
		//values[x] = modify(values[x], operations[x]); niepotrzebne ze wzgledu na propagacje
	}
	
	LL query(int l, int r, int x, int lx, int rx){
		propagate(x, lx, rx);
		if (lx > r || l > rx) return 0LL; //neutral element wzgledem calc
		if (lx >= l && r >= rx) return values[x];
		int m = (lx+rx)/2;
		auto m1 = query(l, r, 2*x, lx, m);
		auto m2 = query(l, r, 2*x+1, m+1, rx);
		auto res = calc(m1, m2);
		//res = modify(res, operations[x]);
		return res;
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, t, l, r, v;
	cin >> n >> m;
	segtree seg;
	seg.init(n);
	while (m--){
		cin >> t;
		if (t == 1){
			cin >> l >> r >> v;
			seg.update(l+1, r, v, 1, 1, seg.size);
		} else {
			cin >> l >> r;
			cout << seg.query(l+1, r, 1, 1, seg.size) << "\n";
		}
	}
	return 0;
}
