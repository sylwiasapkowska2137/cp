#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "

struct segtree{
	vector<LL> tab, tree;
	int size = 1;
	
	void init(int n){
		while (size < n) size *= 2;
		tab.assign(2*size+1, 0LL);
		tree.assign(2*size+1, 0LL);
	}
	
	
	void push(int x){
		tab[x<<1] += tree[x];
		tab[x<<1|1] += tree[x]; 
		tree[x<<1] += tree[x];
		tree[x<<1|1] += tree[x]; 
		tree[x] = 0;
	}
	
	void add(int x, int l, int r, int lx, int rx, int val){
		if (l > rx || r < lx) return;
		if (l >= lx && r <= rx){
			tab[x]+=(LL)val;
			tree[x]+=(LL)val;
			return;
		}
		push(x);
		int m = (lx+rx)/2;
		add(x<<1, l, r, lx, m, val);
		add(x<<1|1, l, r, m+1, rx, val);
		tab[x] = max(tab[x<<1], tab[x<<1|1]);
	}
	
	LL query(int x, int l, int r, int lx, int rx){
		if (l > rx || r < lx) return LLONG_MIN;
		if (l >= lx && r <= rx) return tab[x];
		push(x);
		int m = (lx+rx)/2;
		return max(query(x<<1, l, r, lx, m), query(x<<1|1, l, r, m+1, rx));
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, z, l, r, v;
	cin >> n >> m >> z;
	segtree seg;
	seg.init(n+2);
	for (int i = 0; i<z; i++){
		cin >> l >> r >> v;
		int maxi = seg.query(1, l, r-1, 0, seg.size-1);
		if (m-maxi>=v){
			cout << "T\n";
			seg.add(1, l, r-1, 0, seg.size-1, v);
		} else cout << "N\n";
	}
	return 0;
}
